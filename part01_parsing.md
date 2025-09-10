# 📌 PARTE 1: PARSING (Configuración y Carga de Datos)

### 🎯 Objetivo
Entender cómo se cargan y procesan los archivos `.cub`.

---

## 📋 Archivos a estudiar (en orden)

### 1. Archivos principales
- **main.c** (líneas 122-138) → `load_args()`
- **srcs/parser/cub_file.h** → headers del parser
- **srcs/parser/cub_file.c** → carga principal de archivos
- **srcs/parser/cub_parser.h** → headers del parser de argumentos
- **srcs/parser/cub_parser.c** → parseo de argumentos

### 2. Archivos de configuración
- **srcs/parser/cub_setter.h** → headers de configuración
- **srcs/parser/cub_setter.c** → configuración de valores
- **srcs/parser/cub_map_setter.h** → headers de configuración del mapa
- **srcs/parser/cub_map_setter.c** → configuración específica del mapa

### 3. Archivos de parseo del mapa
- **srcs/parser/cub_map_parser.h** → headers del parser del mapa
- **srcs/parser/cub_map_parser.c** → parseo del mapa

### 4. Archivos de utilidades (necesarios para parsing)
- **srcs/utils/cub_line_reader.h** → lectura de líneas
- **srcs/utils/cub_line_reader.c** → implementación de lectura
- **srcs/utils/cub_error.h** → manejo de errores
- **srcs/utils/cub_error.c** → implementación de errores
- **srcs/utils/cub_checker.h** → validaciones
- **srcs/utils/cub_checker.c** → implementación de validaciones

### 5. Archivos de estructuras (necesarios)
- **include/cub_player_struct.h** → estructura del jugador
- **include/cub_sprite_struct.h** → estructura de sprites
- **srcs/world/cub_map.h** → estructura del mapa
- **srcs/world/cub_map.c** → implementación del mapa

---

## 🔍 Flujo de estudio para *Parsing*
``` c
1. main.c (load_args)
   ↓
2. cub_file.c (load_f)
   ↓
3. cub_parser.c (read_argument)
   ↓
4. cub_setter.c (configuración)
   ↓
5. cub_map_parser.c (parseo del mapa)
   ↓
6. cub_map_setter.c (configuración del mapa)

``` 