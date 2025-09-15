# UML - Sistema de Renderizado en Cub3D

## Diagrama de Secuencia - Bucle Principal de Renderizado

```mermaid
sequenceDiagram
    participant Main as main()
    participant MLX as mlx_loop_hook
    participant RenderFrame as render_next_frame()
    participant UpdateWorld as update_world()
    participant DrawFloor as draw_floor()
    participant DrawSkybox as draw_skybox()
    participant Raycast as ray()
    participant DrawSprites as draw_sprites()
    participant DrawHUD as draw_hud()
    participant DrawCursor as draw_cursor()
    participant RenderHand as render_hand()

    Main->>MLX: mlx_loop_hook(render_next_frame)
    MLX->>RenderFrame: render_next_frame(game)
    
    alt Si jugador está muerto
        RenderFrame->>RenderFrame: draw_death(game)
    else Si jugador está vivo
        Note over RenderFrame: FASE 1: ACTUALIZACIÓN DEL MUNDO
        RenderFrame->>UpdateWorld: update_world(game)
        UpdateWorld->>UpdateWorld: update_keybinds(game)
        UpdateWorld->>UpdateWorld: update_motion(player, game)
        
        Note over RenderFrame: FASE 2: RENDERIZADO DE FONDO
        RenderFrame->>DrawFloor: draw_floor(game)
        DrawFloor->>DrawFloor: setup_floor(game, &floor)
        loop Para cada fila del suelo
            DrawFloor->>DrawFloor: render_row_floor(game, f)
        end
        
        alt Si no es modo BMP
            RenderFrame->>DrawSkybox: draw_skybox(game)
        end
        
        Note over RenderFrame: FASE 3: RAYCASTING DE PAREDES
        RenderFrame->>Raycast: ray(game, &img)
        
        loop Para cada columna de píxeles
            Raycast->>Raycast: do_ray(game, &trace, img)
            alt Si hay colisión
                Raycast->>Raycast: setup_line(game, tr)
                alt Si hay portal
                    Raycast->>Raycast: portal_render_pf()
                else Si hay portal vacío
                    Raycast->>Raycast: e_portal_strip()
                else Si es pared normal
                    Raycast->>Raycast: set_img_strip()
                end
            else Si no hay colisión
                Raycast->>Raycast: cast_forward()
            end
        end
        
        Note over RenderFrame: FASE 4: RENDERIZADO DE SPRITES
        RenderFrame->>DrawSprites: draw_sprites(game, false)
        DrawSprites->>DrawSprites: sprite_sort(game, &sprites)
        loop Para cada sprite
            DrawSprites->>DrawSprites: draw_sprite(img, game, sprite)
            alt Si es puerta
                DrawSprites->>DrawSprites: handle_door()
            else Si es goomba
                DrawSprites->>DrawSprites: handle_goomba()
            end
        end
        
        Note over RenderFrame: FASE 5: INTERFAZ DE USUARIO
        alt Si no es modo BMP
            RenderFrame->>RenderFrame: mlx_put_image_to_window()
            RenderFrame->>DrawCursor: draw_cursor(game)
            RenderFrame->>DrawHUD: draw_hud(game)
            DrawHUD->>DrawHUD: draw_minimap(game)
            DrawHUD->>DrawHUD: rect() para barra de vida
            RenderFrame->>RenderHand: render_hand(game)
        end
        
        Note over RenderFrame: FASE 6: SINCRONIZACIÓN
        RenderFrame->>RenderFrame: mlx_do_sync(game->mlx)
    end
    
    RenderFrame-->>MLX: frame completado
    MLX->>MLX: siguiente frame
```

## Diagrama de Secuencia - Raycasting Detallado

```mermaid
sequenceDiagram
    participant Ray as ray()
    participant DoRay as do_ray()
    participant GetCollide as get_collide_pos()
    participant CheckCollide as check_colide()
    participant SetupLine as setup_line()
    participant GetCardinal as get_cardinal()
    participant GetTexture as get_texture()
    participant SetImgStrip as set_img_strip()
    participant CastForward as cast_forward()

    Ray->>Ray: trace.line.x = -1
    Ray->>Ray: max = render_distance * 1.41 + 1
    
    loop Para cada columna (x < resx)
        Ray->>Ray: game->depth[x] = 999
        Ray->>Ray: trace.newa = atan2((x/resx) - 0.5, fov)
        Ray->>Ray: trace.rot = make_rot(player.yaw + newa)
        Ray->>Ray: trace.ref = player.render.pos
        Ray->>Ray: trace.ray = get_init_ray()
        Ray->>Ray: trace.step = get_init_ray()
        Ray->>Ray: trace.i = 0
        
        loop Mientras trace.i < max
            Ray->>DoRay: do_ray(game, &trace, img)
            DoRay->>GetCollide: get_collide_pos(trace)
            GetCollide-->>DoRay: pos = posición de colisión
            DoRay->>CheckCollide: check_colide(game, pos)
            CheckCollide-->>DoRay: hay_colisión
            
            alt Si hay colisión
                DoRay->>SetupLine: setup_line(game, tr)
                SetupLine->>GetCardinal: get_cardinal(trace)
                GetCardinal-->>SetupLine: cardinal = dirección
                SetupLine->>GetTexture: get_texture(game, cardinal)
                GetTexture-->>SetupLine: texture = textura de pared
                SetupLine->>SetupLine: calcular altura y posición
                SetupLine->>SetupLine: calcular offset de textura
                SetupLine-->>DoRay: línea configurada
                
                alt Si hay portal
                    DoRay->>DoRay: portal_render_pf()
                else Si hay portal vacío
                    DoRay->>DoRay: e_portal_strip()
                else Si es pared normal
                    DoRay->>SetImgStrip: set_img_strip(img, line, offset)
                end
                
                DoRay->>DoRay: trace.i += 99
            else Si no hay colisión
                DoRay->>CastForward: cast_forward(&ray, step)
                DoRay->>DoRay: trace.i++
            end
        end
        
        Ray->>Ray: portal_foreach_free()
    end
```

## Diagrama de Secuencia - Renderizado de Sprites

```mermaid
sequenceDiagram
    participant DrawSprites as draw_sprites()
    participant SpriteSort as sprite_sort()
    participant DrawSprite as draw_sprite()
    participant DrawSpriteLine as draw_sprite_line()
    participant DrawSpriteColumn as draw_sprite_column()
    participant HandleDoor as handle_door()
    participant HandleGoomba as handle_goomba()

    DrawSprites->>SpriteSort: sprite_sort(game, &sprites)
    SpriteSort-->>DrawSprites: sprites ordenados por distancia
    
    loop Para cada sprite
        DrawSprites->>DrawSprite: draw_sprite(img, game, sprite)
        
        alt Si es puerta
            DrawSprite-->>DrawSprites: false (no renderizar)
            DrawSprites->>HandleDoor: handle_door(sprite, game)
            HandleDoor->>HandleDoor: verificar proximidad del jugador
            HandleDoor->>HandleDoor: animar apertura/cierre
        else Si es goomba
            DrawSprite->>DrawSprite: calcular posición relativa
            DrawSprite->>DrawSprite: calcular distancia
            DrawSprite->>DrawSprite: calcular ángulo sprite
            DrawSprite->>DrawSprite: calcular dimensiones
            
            DrawSprite->>DrawSpriteLine: draw_sprite_line(img, game, sprite, sp)
            
            loop Para cada columna del sprite
                DrawSpriteLine->>DrawSpriteColumn: draw_sprite_column(img, game, sprite, sp)
                
                loop Para cada fila del sprite
                    DrawSpriteColumn->>DrawSpriteColumn: calcular offset de textura
                    DrawSpriteColumn->>DrawSpriteColumn: obtener color del píxel
                    DrawSpriteColumn->>DrawSpriteColumn: aplicar oscurecimiento
                    DrawSpriteColumn->>DrawSpriteColumn: set_pixel()
                end
            end
            
            DrawSprite-->>DrawSprites: sprite renderizado
            DrawSprites->>HandleGoomba: handle_goomba(sprite, game)
            HandleGoomba->>HandleGoomba: actualizar IA del enemigo
            HandleGoomba->>HandleGoomba: calcular siguiente movimiento
        end
    end
```

## Diagrama de Clases - Sistema de Renderizado

```mermaid
classDiagram
    class TGame {
        +TImg img
        +TPlayer player
        +TMap map
        +TSprite* sprites
        +TWalls walls
        +TImg floor
        +TImg skybox
        +TImg gun
        +TImg dash
        +double* depth
        +int resx
        +int resy
        +double fov
        +double cam_width
        +double render_distance
        +bool should_dim
        +bool bonus
    }
    
    class TImg {
        +void* img
        +void* addr
        +int bits_per_pixel
        +int line_length
        +int pixel_len
        +int endian
        +int width
        +int height
    }
    
    class TTrace {
        +TRay ray
        +TRay step
        +TRot rot
        +TShape line
        +TVec pos
        +TVec ref
        +TPortalRender* portal
        +TCardinal card
        +TPortal* pt
        +int i
        +double newa
        +double len
        +double offset
    }
    
    class TRay {
        +TVec st_cos
        +TVec st_sin
        +double ln_cos
        +double ln_sin
    }
    
    class TShape {
        +int x
        +int y
        +int width
        +int height
        +bool mirror
        +double dim
        +TImg* img
    }
    
    class TSprite {
        +TSpriteKind kind
        +TVec pos
        +TImg* texture
        +bool dead
        +int last_hurt
        +int path_index
        +TVec* path
        +TSprite* next
    }
    
    class TSpriteR {
        +TVec pos
        +double dist
        +double sprite_angle
        +double view_dist
        +TShape draw
        +TVec v
        +TVec offset
        +double dim
        +int color
    }
    
    class TFloorRender {
        +TRot start
        +TRot end
        +TVec s
        +TVec step
        +TVec start_pos
        +TVec tex
        +int color
        +int midpi
        +double mid
        +double row_len
        +double dim
        +double ang
    }
    
    TGame --> TImg
    TGame --> TSprite
    TTrace --> TRay
    TTrace --> TShape
    TSprite --> TImg
    TSpriteR --> TShape
    TFloorRender --> TRot
```

## Diagrama de Flujo - Proceso de Renderizado

```mermaid
flowchart TD
    A[render_next_frame] --> B{¿Jugador muerto?}
    B -->|Sí| C[draw_death]
    B -->|No| D[update_world]
    
    D --> E[update_keybinds]
    E --> F[update_motion]
    F --> G[draw_floor]
    
    G --> H{¿Hay textura de suelo?}
    H -->|Sí| I[setup_floor]
    H -->|No| J[fill_img con color]
    
    I --> K[render_row_floor]
    K --> L{¿Más filas?}
    L -->|Sí| K
    L -->|No| M{¿Modo BMP?}
    
    J --> M
    M -->|No| N[draw_skybox]
    M -->|Sí| O[ray]
    
    N --> O
    O --> P[do_ray]
    P --> Q{¿Hay colisión?}
    
    Q -->|Sí| R[setup_line]
    Q -->|No| S[cast_forward]
    
    R --> T{¿Qué tipo de colisión?}
    T -->|Portal| U[portal_render_pf]
    T -->|Portal vacío| V[e_portal_strip]
    T -->|Pared| W[set_img_strip]
    
    U --> X{¿Más rayos?}
    V --> X
    W --> X
    S --> X
    
    X -->|Sí| P
    X -->|No| Y[draw_sprites]
    
    Y --> Z[sprite_sort]
    Z --> AA{¿Más sprites?}
    AA -->|Sí| BB[draw_sprite]
    AA -->|No| CC{¿Modo BMP?}
    
    BB --> DD{¿Tipo de sprite?}
    DD -->|Puerta| EE[handle_door]
    DD -->|Goomba| FF[handle_goomba]
    DD -->|Otro| GG[draw_sprite_line]
    
    EE --> AA
    FF --> AA
    GG --> AA
    
    CC -->|No| HH[mlx_put_image_to_window]
    CC -->|Sí| II[mlx_do_sync]
    
    HH --> JJ[draw_cursor]
    JJ --> KK[draw_hud]
    KK --> LL[render_hand]
    LL --> II
    
    II --> MM[Frame completado]
    C --> MM
```

## Diagrama de Estados - Ciclo de Renderizado

```mermaid
stateDiagram-v2
    [*] --> Inicializando
    Inicializando --> ActualizandoMundo : setup_render()
    ActualizandoMundo --> RenderizandoSuelo : update_world()
    RenderizandoSuelo --> RenderizandoCielo : draw_floor()
    RenderizandoCielo --> Raycasting : draw_skybox()
    Raycasting --> RenderizandoSprites : ray()
    RenderizandoSprites --> RenderizandoUI : draw_sprites()
    RenderizandoUI --> Sincronizando : draw_hud()
    Sincronizando --> [*] : mlx_do_sync()
    
    ActualizandoMundo --> JugadorMuerto : health <= 0
    JugadorMuerto --> PantallaMuerte : draw_death()
    PantallaMuerte --> [*]
    
    Raycasting --> CalculandoRayo : do_ray()
    CalculandoRayo --> DetectandoColision : get_collide_pos()
    DetectandoColision --> ConfigurandoLinea : setup_line()
    DetectandoColision --> AvanzandoRayo : cast_forward()
    ConfigurandoLinea --> RenderizandoPared : set_img_strip()
    ConfigurandoLinea --> RenderizandoPortal : portal_render_pf()
    AvanzandoRayo --> Raycasting : siguiente rayo
    RenderizandoPared --> Raycasting : siguiente rayo
    RenderizandoPortal --> Raycasting : siguiente rayo
```

## Funciones Principales del Sistema de Renderizado

| Función | Módulo | Responsabilidad |
|---------|--------|----------------|
| `render_next_frame()` | main.c | Bucle principal de renderizado |
| `update_world()` | main.c | Actualización del estado del juego |
| `draw_floor()` | render_floor.c | Renderizado del suelo texturizado |
| `draw_skybox()` | render_textures.c | Renderizado del cielo |
| `ray()` | raycast_engine.c | Motor de raycasting principal |
| `do_ray()` | raycast_engine.c | Procesamiento de un rayo individual |
| `setup_line()` | raycast_engine.c | Configuración de línea de pared |
| `draw_sprites()` | game_sprite_renderer.c | Renderizado de sprites |
| `draw_sprite()` | game_sprite_renderer.c | Renderizado de sprite individual |
| `draw_hud()` | render_hud.c | Interfaz de usuario |
| `draw_minimap()` | render_minimap.c | Minimapa |
| `draw_cursor()` | render_hud.c | Cruz de mira |
| `render_hand()` | render_hud.c | Arma en mano |

## Tipos de Renderizado

| Tipo | Función | Descripción |
|------|---------|-------------|
| **Paredes** | `set_img_strip()` | Raycasting con texturas |
| **Suelo** | `render_row_floor()` | Proyección perspectiva |
| **Cielo** | `draw_skybox()` | Textura panorámica |
| **Sprites** | `draw_sprite_line()` | Proyección billboard |
| **UI** | `rect()` | Elementos 2D |
| **Portales** | `portal_render_pf()` | Efectos especiales |

## Optimizaciones del Sistema

| Optimización | Implementación | Beneficio |
|--------------|----------------|-----------|
| **Depth Buffer** | `game->depth[]` | Evita overdraw |
| **Sprite Sorting** | `sprite_sort()` | Renderizado correcto |
| **Culling** | `render_distance` | Evita renderizado lejano |
| **Oscurecimiento** | `color_dim()` | Efecto de distancia |
| **Portal System** | `portal_render_pf()` | Efectos avanzados |
| **Big Pixels** | `set_big_pixel()` | Renderizado rápido del suelo |

## Configuración de Renderizado

| Parámetro | Variable | Descripción |
|-----------|----------|-------------|
| **Resolución** | `game->resx`, `game->resy` | Tamaño de pantalla |
| **FOV** | `game->fov` | Campo de visión |
| **Distancia** | `game->render_distance` | Distancia máxima de renderizado |
| **Oscurecimiento** | `game->should_dim` | Efecto de distancia |
| **Modo Bonus** | `game->bonus` | Funciones adicionales |
| **Modo BMP** | `game->bmp` | Modo de captura |

## Errores de Renderizado

| Error | Causa | Solución |
|-------|-------|----------|
| **Pantalla negra** | Texturas no cargadas | Verificar archivos .xpm |
| **Sprites incorrectos** | Depth buffer mal configurado | Verificar `game->depth` |
| **Distorsión** | FOV incorrecto | Ajustar `game->fov` |
| **Rendimiento bajo** | Render distance muy alta | Reducir `render_distance` |
| **Portales no funcionan** | Texturas de diferente tamaño | Verificar dimensiones |
