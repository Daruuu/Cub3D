# Cub3D

A 3D raycasting game engine implementation in C, inspired by Wolfenstein 3D. This project features real-time 3D rendering, sprite management, and interactive gameplay mechanics.

## 👥 Team

- **[Ana Gabriela](https://github.com/Anagamedina)** - Lead: Rendering, Graphics, Mathematics
- **[Daru](https://github.com/Daruuu)** - Lead: Parser, Game Logic, Input Handling

## 🎮 Features

- **Real-time 3D rendering** using raycasting algorithm
- **Dynamic sprite system** with enemies, doors, and collectibles
- **Portal mechanics** for advanced gameplay
- **Audio system** with ambient sounds and effects
- **Interactive HUD** with health and minimap
- **Map parsing** from `.cub` configuration files
- **Cross-platform support** (Linux/macOS)

## 🚀 Quick Start

### Prerequisites
- GCC with C99 support
- Make
- MLX library (included)
- Valgrind (optional, for memory checking)

### Installation
```bash
git clone https://github.com/yourusername/Cub3D.git
cd Cub3D
make
```

### Usage
```bash
# Run mandatory version
./cub3D maps_and_textures/correct_maps/demo.cub

# Run bonus version with enhanced features
make bonus
./cub3D_bonus maps_and_textures/correct_maps/demo.cub

# Save screenshot (BMP format)
./cub3D maps_and_textures/correct_maps/demo.cub --save
```

## 🎯 Controls

| Key | Action |
|-----|--------|
| `WASD` | Move player |
| `←→` | Rotate camera |
| `↑↓` | Look up/down |
| `Space` | Shoot |
| `E` | Interact with doors |
| `ESC` | Exit game |

## 📁 Project Structure

```
Cub3D/
├── srcs/                    # Source code
│   ├── core/               # Core game logic
│   ├── render/             # Rendering engine
│   ├── parser/             # Map parsing
│   ├── game/               # Game mechanics
│   └── math/               # Mathematical utilities
├── include/                 # Header files
├── assets/                  # Textures and sounds
├── maps_and_textures/       # Test maps
└── scripts/                # Development tools
```

## 🛠️ Development

### Build Options
```bash
make          # Build mandatory version
make bonus    # Build bonus version
make debug    # Build with debug symbols
make clean    # Clean object files
make fclean   # Clean everything
```

### Code Quality
```bash
# Check code style
make norm

# Memory leak detection
valgrind --leak-check=full ./cub3D demo.cub

# Address sanitizer
make sanitize && ./cub3D demo.cub
```

## 📊 Performance

- **Memory**: 0 leaks detected ✅
- **Frame Rate**: 60 FPS target
- **Memory Usage**: < 100MB
- **Compilation**: < 30 seconds

## 🧪 Testing

The project includes comprehensive memory testing using both Valgrind and AddressSanitizer:

```bash
# Memory leak test
valgrind --leak-check=full ./cub3D demo.cub

# Address sanitizer test
make sanitize
timeout 10s ./cub3D demo.cub
```

**Results**: 0 memory leaks, 0 errors, perfect memory management.

## 📝 Map Format

Maps are defined in `.cub` files with the following structure:
- Resolution settings
- Texture paths (North, South, East, West)
- Floor and ceiling colors
- Map grid with walls, sprites, and player spawn


## 📄 License

This project is part of the 42 School curriculum.

---

*Built with ❤️ at 42 Barcelona*