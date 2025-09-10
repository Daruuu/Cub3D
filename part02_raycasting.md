# 📁 PARTE 2: RAYCASTING (Motor de Renderizado)

### 🎯 Objetivo
Entender cómo funciona el motor de **raycasting** y el proceso de **renderizado 3D**.

---

## 📋 Archivos a estudiar (en orden)

### 1. Archivos principales de Raycasting
- **main.c** (líneas 56-81) → `render_next_frame()`
- **srcs/render/cub_raycast.h** → headers del raycasting
- **srcs/render/cub_raycast.c** → motor principal de raycasting
- **srcs/render/cub_raycast2.c** → funciones auxiliares de raycasting
- **srcs/render/cub_raycast3.c** → algoritmo DDA (núcleo del raycasting)

### 2. Archivos de Renderizado
- **srcs/render/cub_texture.h** → headers de texturas
- **srcs/render/cub_texture.c** → gestión de texturas
- **srcs/render/cub_floor.h** → headers del suelo
- **srcs/render/cub_floor.c** → renderizado del suelo
- **srcs/render/cub_hud.h** → headers del HUD
- **srcs/render/cub_hud.c** → interfaz de usuario (HUD)

### 3. Archivos de utilidades de renderizado
- **srcs/utils/cub_utils.h** → utilidades de imagen
- **srcs/utils/cub_utils.c** → implementación de utilidades
- **srcs/utils/cub_vec.h** → operaciones con vectores
- **srcs/utils/cub_vec.c** → implementación de vectores
- **srcs/utils/cub_rot.h** → rotaciones y ángulos
- **srcs/utils/cub_rot.c** → implementación de rotaciones

### 4. Archivos de estructuras (necesarios)
- **include/cub_raycast_struct.h** → estructuras de raycasting
- **include/cub_cardinal_enum.h** → direcciones cardinales
- **srcs/world/cub_cardinal.h** → headers de direcciones
- **srcs/world/cub_cardinal.c** → implementación de direcciones
- **srcs/world/cub_collide.h** → headers de colisiones
- **srcs/world/cub_collide.c** → implementación de colisiones

### 5. Archivos de sprites *(opcional para raycasting básico)*
- **srcs/sprites/cub_sprites.h** → headers de sprites
- **srcs/sprites/cub_sprites.c** → sistema de sprites

---

## 🔍 Flujo de estudio para *Raycasting*
```c
1. main.c (render_next_frame)
   ↓
2. cub_raycast.c (ray) ← función principal
   ↓
3. cub_raycast.c (get_init_ray) ← inicialización
   ↓
4. cub_raycast.c (do_ray) ← loop de rayos
   ↓
5. cub_raycast3.c (cast_forward) ← algoritmo DDA
   ↓
6. cub_raycast2.c (get_collide_pos) ← detección de colisión
   ↓
7. cub_raycast.c (setup_line) ← configuración de línea
   ↓
8. cub_texture.c (renderizado de texturas)
```
