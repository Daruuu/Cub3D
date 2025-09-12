# 🎮 FLOWCHART COMPLETO - PROYECTO CUB3D

## Diagrama de Flujo Principal - Desde Inicio hasta Bucle del Juego

```mermaid
flowchart TD
    A[🚀 main] --> B[init_default]
    B --> C[set_bonus]
    C --> D[mlx_init]
    D --> E{¿MLX inicializado?}
    E -->|No| F[handle_error - FAIL_MLX]
    E -->|Sí| G[load_args]
    
    G --> H{¿argc == 2?}
    H -->|No| I[handle_error - ERROR_USAGE_CUB]
    H -->|Sí| J[check_iscub]
    
    J --> K{¿Archivo .cub?}
    K -->|No| L[handle_error - ERROR_FILE_TYPE]
    K -->|Sí| M[load_f - Parser Principal]
    
    M --> N[load_file - Cargar archivo]
    N --> O[read_argument - Parsear argumentos]
    O --> P[get_map_size - Calcular tamaño mapa]
    P --> Q[make_empty - Crear estructura mapa]
    Q --> R[load_map - Parsear mapa]
    R --> S[set_map - Convertir caracteres]
    S --> T[is_map_valid - Validar mapa]
    T --> U{¿Mapa válido?}
    U -->|No| V[handle_error - ERROR_MAP_UNCLOSED]
    U -->|Sí| W[handle_door_rotation]
    
    W --> X[check_define - Validar configuración]
    X --> Y{¿Configuración válida?}
    Y -->|No| Z[handle_error - Configuración inválida]
    Y -->|Sí| AA[setup_render]
    
    AA --> BB[mlx_new_window - Crear ventana]
    BB --> CC{¿Ventana creada?}
    CC -->|No| DD[handle_error - Error ventana]
    CC -->|Sí| EE[play_sound_alt - Sonido ambiente]
    
    EE --> FF[mlx_hook - Configurar eventos]
    FF --> GG[mlx_loop_hook - Configurar bucle]
    GG --> HH[mlx_loop - INICIAR BUCLE PRINCIPAL]
    
    HH --> II[render_next_frame]
    II --> JJ{¿Jugador muerto?}
    JJ -->|Sí| KK[draw_death]
    JJ -->|No| LL[update_world]
    
    LL --> MM[update_keybinds]
    MM --> NN{¿Modo bonus?}
    NN -->|Sí| OO[get_delay]
    NN -->|No| PP[update_motion]
    
    OO --> QQ{¿delay > FPS_BONUS?}
    QQ -->|Sí| RR[update_motion]
    RR --> SS[draw_sprites]
    SS --> TT[game->time++]
    TT --> UU[game->delay -= FPS_BONUS]
    UU --> QQ
    QQ -->|No| PP
    
    PP --> VV[draw_floor]
    VV --> WW{¿Hay textura suelo?}
    WW -->|Sí| XX[setup_floor]
    WW -->|No| YY[fill_img con color]
    
    XX --> ZZ[render_row_floor]
    ZZ --> AAA{¿Más filas suelo?}
    AAA -->|Sí| ZZ
    AAA -->|No| BBB{¿Modo BMP?}
    
    YY --> BBB
    BBB -->|No| CCC[draw_skybox]
    BBB -->|Sí| DDD[ray - RAYCASTING]
    
    CCC --> DDD
    DDD --> EEE[do_ray]
    EEE --> FFF{¿Hay colisión?}
    
    FFF -->|Sí| GGG[setup_line]
    FFF -->|No| HHH[cast_forward]
    
    GGG --> III{¿Qué tipo colisión?}
    III -->|Portal| JJJ[portal_render_pf]
    III -->|Portal vacío| KKK[e_portal_strip]
    III -->|Pared| LLL[set_img_strip]
    
    JJJ --> MMM{¿Más rayos?}
    KKK --> MMM
    LLL --> MMM
    HHH --> MMM
    
    MMM -->|Sí| EEE
    MMM -->|No| NNN[draw_sprites]
    
    NNN --> OOO[sprite_sort]
    OOO --> PPP{¿Más sprites?}
    PPP -->|Sí| QQQ[draw_sprite]
    PPP -->|No| RRR{¿Modo BMP?}
    
    QQQ --> SSS{¿Tipo sprite?}
    SSS -->|Puerta| TTT[handle_door]
    SSS -->|Goomba| UUU[handle_goomba]
    SSS -->|Otro| VVV[draw_sprite_line]
    
    TTT --> PPP
    UUU --> PPP
    VVV --> PPP
    
    RRR -->|No| WWW[mlx_put_image_to_window]
    RRR -->|Sí| XXX[mlx_do_sync]
    
    WWW --> YYY[draw_cursor]
    YYY --> ZZZ[draw_hud]
    ZZZ --> AAAA[render_hand]
    AAAA --> XXX
    
    XXX --> BBBB[game->time++]
    BBBB --> CCCC[mlx_do_sync]
    CCCC --> II
    
    KK --> CCCC
    
    F --> DDDD[clean_and_exit]
    I --> DDDD
    L --> DDDD
    V --> DDDD
    Z --> DDDD
    DD --> DDDD
    
    DDDD --> EEEE[clean_all]
    EEEE --> FFFF[clean_images]
    FFFF --> GGGG[destroy_img]
    GGGG --> HHHH[free_memory]
    HHHH --> IIII[exit]
    
    style A fill:#ff9999
    style HH fill:#99ff99
    style II fill:#99ff99
    style DDDD fill:#ffcccc
    style IIII fill:#ffcccc
```

## Diagrama de Flujo Detallado - Sistema de Parsing

```mermaid
flowchart TD
    A[load_f] --> B[load_file]
    B --> C[init_file_reading]
    C --> D[open file]
    D --> E{¿Archivo abierto?}
    E -->|No| F[handle_error - ERROR_COULD_NOT_LOAD_FILE]
    E -->|Sí| G[read character by character]
    
    G --> H[process_character]
    H --> I{¿Es salto de línea?}
    I -->|Sí| J[add_line]
    I -->|No| K[ft_strcat]
    
    J --> L[Crear t_line]
    L --> M{¿Más caracteres?}
    K --> M
    
    M -->|Sí| G
    M -->|No| N[finalize_reading]
    
    N --> O[read_argument]
    O --> P{¿Es argumento válido?}
    P -->|Sí| Q[Procesar argumento]
    P -->|No| R[get_map_size]
    
    Q --> S{¿Qué argumento?}
    S -->|R| T[set_resolution]
    S -->|NO| U[set_texture north]
    S -->|SO| V[set_texture south]
    S -->|WE| W[set_texture west]
    S -->|EA| X[set_texture east]
    S -->|F| Y[set_color floor]
    S -->|C| Z[set_color ceiling]
    S -->|S| AA[set_texture sprite]
    S -->|Otros| BB[read_argument_custom]
    
    T --> CC{¿Más líneas?}
    U --> CC
    V --> CC
    W --> CC
    X --> CC
    Y --> CC
    Z --> CC
    AA --> CC
    BB --> CC
    
    CC -->|Sí| O
    CC -->|No| R
    
    R --> DD[make_empty]
    DD --> EE[load_map]
    EE --> FF[set_map]
    
    FF --> GG{¿Qué carácter?}
    GG -->|'0'| HH[MAP_AIR]
    GG -->|'1'| II[MAP_BLOCK]
    GG -->|'E','S','W','N'| JJ[set_player]
    GG -->|'2'| KK[set_sprite]
    GG -->|'D'| LL[set_sprite door]
    GG -->|'G'| MM[set_entity goomba]
    GG -->|'H'| NN[set_entity health]
    GG -->|'P'| OO[set_pathfinder]
    GG -->|' '| PP[MAP_EMPTY]
    GG -->|Otro| QQ[handle_error - ERROR_FORMAT]
    
    HH --> RR[map_set]
    II --> RR
    JJ --> RR
    KK --> RR
    LL --> RR
    MM --> RR
    NN --> RR
    OO --> RR
    PP --> RR
    
    RR --> SS{¿Más caracteres?}
    SS -->|Sí| FF
    SS -->|No| TT[is_map_valid]
    
    TT --> UU{¿Mapa válido?}
    UU -->|No| VV[handle_error - ERROR_MAP_UNCLOSED]
    UU -->|Sí| WW[handle_door_rotation]
    
    WW --> XX[Parseo completado]
    
    style A fill:#e1f5fe
    style XX fill:#c8e6c9
    style F fill:#ffcdd2
    style QQ fill:#ffcdd2
    style VV fill:#ffcdd2
```

## Diagrama de Flujo Detallado - Sistema de Renderizado

```mermaid
flowchart TD
    A[render_next_frame] --> B{¿Jugador muerto?}
    B -->|Sí| C[draw_death]
    B -->|No| D[update_world]
    
    D --> E[update_keybinds]
    E --> F{¿Modo bonus?}
    F -->|Sí| G[get_delay]
    F -->|No| H[update_motion]
    
    G --> I{¿delay > FPS_BONUS?}
    I -->|Sí| J[update_motion]
    J --> K[draw_sprites]
    K --> L[game->time++]
    L --> M[game->delay -= FPS_BONUS]
    M --> I
    I -->|No| H
    
    H --> N[draw_floor]
    N --> O{¿Hay textura suelo?}
    O -->|Sí| P[setup_floor]
    O -->|No| Q[fill_img con color]
    
    P --> R[render_row_floor]
    R --> S{¿Más filas?}
    S -->|Sí| R
    S -->|No| T{¿Modo BMP?}
    
    Q --> T
    T -->|No| U[draw_skybox]
    T -->|Sí| V[ray - RAYCASTING]
    
    U --> V
    V --> W[do_ray]
    W --> X{¿Hay colisión?}
    
    X -->|Sí| Y[setup_line]
    X -->|No| Z[cast_forward]
    
    Y --> AA{¿Qué tipo?}
    AA -->|Portal| BB[portal_render_pf]
    AA -->|Portal vacío| CC[e_portal_strip]
    AA -->|Pared| DD[set_img_strip]
    
    BB --> EE{¿Más rayos?}
    CC --> EE
    DD --> EE
    Z --> EE
    
    EE -->|Sí| W
    EE -->|No| FF[draw_sprites]
    
    FF --> GG[sprite_sort]
    GG --> HH{¿Más sprites?}
    HH -->|Sí| II[draw_sprite]
    HH -->|No| JJ{¿Modo BMP?}
    
    II --> KK{¿Tipo sprite?}
    KK -->|Puerta| LL[handle_door]
    KK -->|Goomba| MM[handle_goomba]
    KK -->|Otro| NN[draw_sprite_line]
    
    LL --> HH
    MM --> HH
    NN --> HH
    
    JJ -->|No| OO[mlx_put_image_to_window]
    JJ -->|Sí| PP[mlx_do_sync]
    
    OO --> QQ[draw_cursor]
    QQ --> RR[draw_hud]
    RR --> SS[render_hand]
    SS --> PP
    
    PP --> TT[game->time++]
    TT --> UU[mlx_do_sync]
    UU --> A
    
    C --> PP
    
    style A fill:#e3f2fd
    style V fill:#fff3e0
    style FF fill:#f3e5f5
    style PP fill:#e8f5e8
```

## Diagrama de Estados - Ciclo de Vida del Juego

```mermaid
stateDiagram-v2
    [*] --> Inicializando
    Inicializando --> ParseandoArchivo : init_default()
    ParseandoArchivo --> ValidandoConfig : load_f()
    ValidandoConfig --> ConfigurandoRender : check_define()
    ConfigurandoRender --> CreandoVentana : setup_render()
    CreandoVentana --> ConfigurandoEventos : mlx_new_window()
    ConfigurandoEventos --> BuclePrincipal : mlx_hook()
    
    BuclePrincipal --> ActualizandoMundo : render_next_frame()
    ActualizandoMundo --> RenderizandoFondo : update_world()
    RenderizandoFondo --> Raycasting : draw_floor()
    Raycasting --> RenderizandoSprites : ray()
    RenderizandoSprites --> RenderizandoUI : draw_sprites()
    RenderizandoUI --> Sincronizando : draw_hud()
    Sincronizando --> BuclePrincipal : mlx_do_sync()
    
    BuclePrincipal --> JugadorMuerto : health <= 0
    JugadorMuerto --> PantallaMuerte : draw_death()
    PantallaMuerte --> BuclePrincipal : siguiente frame
    
    BuclePrincipal --> Salir : ESC o cerrar ventana
    Salir --> LimpiandoMemoria : clean_and_exit()
    LimpiandoMemoria --> [*] : exit()
    
    ParseandoArchivo --> Error : archivo inválido
    ValidandoConfig --> Error : configuración inválida
    ConfigurandoRender --> Error : error MLX
    CreandoVentana --> Error : error ventana
    Error --> [*]
```

## Resumen de Fases del Proyecto

| Fase | Función Principal | Descripción |
|------|------------------|-------------|
| **1. Inicialización** | `main()` | Configuración inicial y MLX |
| **2. Parsing** | `load_f()` | Carga y parseo del archivo .cub |
| **3. Validación** | `check_define()` | Verificación de configuración |
| **4. Renderizado** | `setup_render()` | Preparación del sistema gráfico |
| **5. Ventana** | `mlx_new_window()` | Creación de la ventana |
| **6. Eventos** | `mlx_hook()` | Configuración de eventos |
| **7. Bucle** | `mlx_loop()` | **BUCLE PRINCIPAL DEL JUEGO** |

## Puntos Clave del Flujo

### 🚀 **Inicio del Programa**
- Validación de argumentos
- Inicialización de MLX
- Carga del archivo .cub

### 📁 **Sistema de Parsing**
- Lectura línea por línea
- Parseo de argumentos (texturas, colores, resolución)
- Conversión del mapa a estructura de datos
- Validación del mapa

### 🎮 **Bucle Principal**
- **60 FPS** en modo bonus
- Actualización del mundo del juego
- Renderizado completo de la escena
- Manejo de eventos de entrada

### 🎨 **Sistema de Renderizado**
- **Raycasting** para paredes
- **Proyección perspectiva** para suelo
- **Billboard** para sprites
- **2D** para interfaz de usuario

### 🔄 **Ciclo Continuo**
- El juego entra en un bucle infinito
- Espera eventos del usuario
- Renderiza frames continuamente
- Solo sale con ESC o cerrar ventana

¡Este flowchart muestra el flujo completo desde el inicio del programa hasta el bucle principal donde el juego espera el movimiento del jugador!
