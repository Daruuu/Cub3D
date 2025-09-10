# 🎮 DIAGRAMA DE FLUJO COMPLETO - PROYECTO CUB3D

## 📋 FLUJO PRINCIPAL DESDE MAIN.C

```
┌─────────────────────────────────────────────────────────────────┐
│                        🚀 MAIN.C                               │
│                     (Punto de entrada)                         │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  📋 INICIALIZACIÓN                                              │
│  • init_default(&vars)                                          │
│  • set_bonus(&vars.bonus)                                       │
│  • vars.mlx = mlx_init()                                        │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  📁 PARSER/ - Carga de Configuración                            │
│  • load_args(argc, argv, &vars)                                │
│  • check_iscub(argv[1])                                         │
│  • load_f(argv[1], vars)                                        │
│  • read_argument(vars, file)                                    │
│  • read_argument_sounds(vars, file)                             │
│  • read_argument_custom(vars, file)                             │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  🔧 UTILS/ - Configuración y Validación                         │
│  • check_define(&vars)                                          │
│  • setup_render(&vars)                                          │
│  • make_image(mlx, resx, resy)                                 │
│  • make_blur_struct(mlx, img, shape)                           │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  🎯 DECISIÓN: Modo BMP o Juego                                  │
│  if (vars.bmp) {                                                │
│    • render_and_save(&vars)                                     │
│    • clean_and_exit(0, &vars)                                   │
│  } else {                                                       │
│    • Crear ventana del juego                                    │
│    • Configurar hooks de eventos                                │
│    • Iniciar loop principal                                     │
│  }                                                              │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  🎮 LOOP PRINCIPAL DEL JUEGO                                    │
│  mlx_loop_hook(mlx, render_next_frame, &vars)                  │
│  mlx_loop(mlx)                                                  │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  🖼️ RENDER_NEXT_FRAME()                                         │
│  (Función llamada cada frame)                                   │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  ❓ ¿Jugador muerto?                                             │
│  if (vars.player.health <= 0) {                                │
│    • draw_death(vars)                                           │
│  } else {                                                       │
│    • Continuar con renderizado                                  │
│  }                                                              │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  🌍 UPDATE_WORLD() - Actualización del Mundo                   │
│  • update_keybinds(vars)                                        │
│  • update_motion(&player, vars)                                 │
│  • refresh_pathfinding(vars)                                    │
│  • draw_sprites(vars, true) [si bonus]                          │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  🎨 RENDERIZADO DE LA ESCENA                                   │
│  • draw_floor(vars)                                             │
│  • draw_skybox(vars) [si no BMP]                               │
│  • ray(vars, &img) ← RAYCASTING                                 │
│  • draw_sprites(vars, false)                                    │
│  • draw_cursor(vars) [si no BMP]                               │
│  • draw_hud(vars) [si no BMP]                                   │
│  • render_hand(vars) [si no BMP]                                │
└─────────────────────┬───────────────────────────────────────────┘
                      │
                      ▼
┌─────────────────────────────────────────────────────────────────┐
│  🔄 SINCRONIZACIÓN Y REPETIR                                    │
│  • mlx_put_image_to_window()                                   │
│  • mlx_do_sync(mlx)                                            │
│  • vars.time++                                                  │
│  • Volver al inicio del loop                                    │
└─────────────────────────────────────────────────────────────────┘
```

## 🔍 DETALLES DE CADA MÓDULO

### 📁 PARSER/ - Flujo de Parseo
```
load_args() → check_iscub() → load_f() → read_argument()
    ↓              ↓              ↓           ↓
Validar args   Verificar .cub   Cargar archivo  Parsear contenido
    ↓              ↓              ↓           ↓
    └──────────────┼──────────────┼───────────┘
                   ▼
            read_argument_sounds()
                   ↓
            read_argument_custom()
                   ↓
            Configuración completa
```

### 🎨 RENDER/ - Flujo de Renderizado
```
ray() → get_init_ray() → do_ray() → cast_forward()
  ↓           ↓            ↓           ↓
Lanzar    Inicializar   Procesar   Algoritmo
rayos     cada rayo     colisión   DDA
  ↓           ↓            ↓           ↓
  └───────────┼────────────┼───────────┘
              ▼
        get_collide_pos()
              ↓
        check_colide()
              ↓
        setup_line()
              ↓
        set_img_strip()
```

### 🌍 WORLD/ - Flujo del Mundo
```
update_motion() → should_bob() → get_collide_pos()
      ↓              ↓              ↓
  Actualizar      Verificar      Calcular
  movimiento      bobing         colisión
      ↓              ↓              ↓
      └──────────────┼──────────────┘
                     ▼
              refresh_pathfinding()
                     ↓
              cub_pathfinder()
                     ↓
              cub_astar()
```

### 🎮 SPRITES/ - Flujo de Sprites
```
draw_sprites() → cub_sprite_list() → cub_doors()
      ↓               ↓                ↓
  Renderizar      Gestionar        Sprites
  todos los       lista de         específicos
  sprites         sprites          (puertas)
      ↓               ↓                ↓
      └───────────────┼────────────────┘
                      ▼
                cub_goomba()
                      ↓
                Sprite enemigo
```

### 🔧 UTILS/ - Flujo de Utilidades
```
update_keybinds() → set_keystate() → make_keybinds()
      ↓                ↓                ↓
  Actualizar        Establecer      Crear
  controles         estado tecla    keybinds
      ↓                ↓                ↓
      └────────────────┼────────────────┘
                       ▼
                Gestión de input
```

## 🎯 FLUJO DE EVENTOS

### ⌨️ Eventos de Teclado
```
key_press() → set_keystate() → update_keybinds()
     ↓             ↓              ↓
  Tecla        Establecer      Actualizar
  presionada   estado          controles
     ↓             ↓              ↓
     └─────────────┼──────────────┘
                   ▼
            update_motion()
                   ↓
            Movimiento del jugador
```

### 🖱️ Eventos de Ventana
```
clean_and_exit_z() → clean_all() → clean_images()
        ↓               ↓             ↓
    Cerrar          Limpiar        Destruir
    ventana         todo           imágenes
        ↓               ↓             ↓
        └───────────────┼─────────────┘
                        ▼
                  exit(0)
```

## 🚀 FLUJO DE INICIALIZACIÓN COMPLETO

```
main() → init_default() → set_bonus() → mlx_init()
  ↓           ↓              ↓            ↓
Inicio    Valores        Modo bonus   Inicializar
          por defecto                 MLX
  ↓           ↓              ↓            ↓
  └───────────┼──────────────┼────────────┘
               ▼
        load_args()
               ↓
        check_iscub()
               ↓
        load_f()
               ↓
        read_argument()
               ↓
        check_define()
               ↓
        setup_render()
               ↓
        Crear ventana y hooks
               ↓
        Iniciar loop principal
```

## 🎮 FLUJO DE GAMEPLAY

```
Cada Frame:
  ↓
update_world()
  ↓
update_keybinds() → update_motion() → refresh_pathfinding()
  ↓                    ↓                    ↓
Procesar input      Mover jugador        IA enemigos
  ↓                    ↓                    ↓
  └────────────────────┼────────────────────┘
                       ▼
                draw_floor()
                       ↓
                draw_skybox()
                       ↓
                ray() ← RAYCASTING
                       ↓
                draw_sprites()
                       ↓
                draw_hud()
                       ↓
                render_hand()
                       ↓
                mlx_put_image_to_window()
                       ↓
                Siguiente frame
```

## 🔧 FLUJO DE LIMPIEZA

```
clean_and_exit() → clean_all() → clean_images()
       ↓              ↓             ↓
   Salir del      Limpiar        Destruir
   programa       memoria         imágenes
       ↓              ↓             ↓
       └──────────────┼─────────────┘
                      ▼
                clear_map()
                      ↓
                clear_sounds()
                      ↓
                free_file()
                      ↓
                exit(0)
```

## 📊 RESUMEN DE MÓDULOS Y SUS RESPONSABILIDADES

| Módulo | Responsabilidad Principal | Función Clave |
|--------|---------------------------|---------------|
| **main.c** | Punto de entrada y loop principal | `main()`, `render_next_frame()` |
| **parser/** | Parseo de archivos .cub | `load_args()`, `read_argument()` |
| **world/** | Lógica del mundo y jugador | `update_motion()`, `check_colide()` |
| **render/** | Motor de renderizado | `ray()`, `cast_forward()` |
| **sprites/** | Sistema de sprites | `draw_sprites()` |
| **pathfinder/** | IA y pathfinding | `refresh_pathfinding()` |
| **utils/** | Utilidades y controles | `update_keybinds()`, `clean_all()` |
| **other/** | Versión sin sonido | `init_sound_empty()` |

## 🎯 PUNTOS CLAVE DEL FLUJO

1. **Inicialización**: main.c → parser → utils → world
2. **Loop Principal**: render_next_frame() → update_world() → renderizado
3. **Raycasting**: ray() → get_init_ray() → cast_forward() (DDA)
4. **Input**: key_press() → update_keybinds() → update_motion()
5. **IA**: refresh_pathfinding() → cub_astar()
6. **Sprites**: draw_sprites() → gestión de lista → renderizado
7. **Limpieza**: clean_and_exit() → clean_all() → exit()

¡Este es el flujo completo de tu proyecto Cub3D! 🚀
