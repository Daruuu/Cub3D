# 📌 PARTE 1: PARSING (Configuración y Carga de Datos)

### 🎯 Objetivo
Entender cómo se cargan y procesan los archivos `.cub`.

---

## 📋 Archivos a estudiar (en orden)

### 1. Archivos principales
- **main.c** (líneas 122-138) → `load_args()`
- **srcs/parser/cub_file.h** → headers del parser
- **srcs/parser/parser_file_loader.c** → carga principal de archivos
- **srcs/parser/cub_parser.h** → headers del parser de argumentos
- **srcs/parser/parser_main.c** → parseo de argumentos

### 2. Archivos de configuración
- **srcs/parser/cub_setter.h** → headers de configuración
- **srcs/parser/parser_setter.c** → configuración de valores
- **srcs/parser/cub_map_setter.h** → headers de configuración del mapa
- **srcs/parser/parser_map_setter.c** → configuración específica del mapa

### 3. Archivos de parseo del mapa
- **srcs/parser/cub_map_parser.h** → headers del parser del mapa
- **srcs/parser/parser_map_parser.c** → parseo del mapa

### 4. Archivos de utilidades (necesarios para parsing)
- **srcs/utils/cub_line_reader.h** → lectura de líneas
- **srcs/utils/load_file.c** → implementación de lectura
- **srcs/utils/cub_error.h** → manejo de errores
- **srcs/utils/cub_error.c** → implementación de errores
- **srcs/utils/parser_map_validator.h** → validaciones
- **srcs/utils/parser_map_validator.c** → implementación de validaciones

### 5. Archivos de estructuras (necesarios)
- **include/cub_player_struct.h** → estructura del jugador
- **include/cub_sprite_struct.h** → estructura de sprites
- **srcs/world/cub_map.h** → estructura del mapa
- **srcs/world/game_map.c** → implementación del mapa

---

## 🔍 Flujo de estudio para *Parsing*
``` c
1. main.c (load_args)
   ↓
2. parser_file_loader.c (load_f)
   ↓
3. parser_main.c (read_argument)
   ↓
4. parser_setter.c (configuración)
   ↓
5. parser_map_parser.c (parseo del mapa)
   ↓
6. parser_map_setter.c (configuración del mapa)

``` 