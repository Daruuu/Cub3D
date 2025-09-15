# Cub3D - Team Configuration & Development Guidelines

## 👥 **Team Members**
- **[Ana Gabriela](https://github.com/Anagamedina)** - Lead: Rendering, Graphics, Mathematics
- **[Daru](https://github.com/Daruuu)** - Lead: Parser, Game Logic, Input Handling

## 📋 **Code Conventions**

### **Naming Conventions**
- **Functions**: `snake_case` (e.g., `render_next_frame`)
- **Variables**: `snake_case` (e.g., `player_pos`)
- **Constants**: `UPPER_CASE` (e.g., `FPS_BONUS`)
- **Structs**: `t_` prefix (e.g., `t_game`)
- **Enums**: `e_` prefix (e.g., `e_cardinal`)

### **File Structure**
- **Headers**: One header per module
- **Source**: One `.c` file per main function
- **Documentation**: Comments in English for public functions

### **Commit Messages**
- **Format**: `[module] brief description`
- **Examples**:
  - `[render] fix raycasting collision detection`
  - `[parser] add map validation for doors`
  - `[game] implement player movement`

## 🔧 **Environment Setup**

### **Required Tools**
- GCC with C99 support
- Make
- MLX (included in project)
- Valgrind (for memory checking)
- Norminette (for code style)

### **Recommended IDE**
- **CLion** (already configured)
- **VS Code** with C/C++ extensions

## 📁 **Directory Structure**

```
Cub3D/
├── include/           # Centralized headers
├── src/              # Reorganized source code
├── assets/           # Textures and sounds
├── maps_and_textures/ # Test maps
├── scripts/          # Development scripts
├── docs/             # Documentation
└── tests/            # Unit tests
```

## 🚀 **Development Workflow**

### **1. Before Starting Work**
```bash
git pull origin master
./scripts/dev.sh setup
```

### **2. During Development**
```bash
# Compile
./scripts/dev.sh build

# Check style
./scripts/dev.sh norm

# Test memory
./scripts/dev.sh memcheck
```

### **3. Before Committing**
```bash
# Clean and recompile
./scripts/dev.sh clean
./scripts/dev.sh build

# Run tests
./scripts/dev.sh test

# Check memory
./scripts/dev.sh memcheck
```

### **4. Making Commits**
```bash
git add .
git commit -m "[module] description of change"
git push origin dev
```

## 🐛 **Debugging**

### **Debug Flags**
```bash
# Compile with debug
make debug

# Compile with sanitizers
make sanitize
```

### **Memory Leaks**
```bash
# Check with valgrind
./scripts/dev.sh memcheck

# Check with AddressSanitizer
make sanitize
./cub3D maps_and_textures/correct_maps/demo.cub
```

## 📝 **Documentation Standards**

### **Function Comments**
```c
/**
 * Brief description of what the function does
 * 
 * @param param1 Description of parameter 1
 * @param param2 Description of parameter 2
 * @return Description of return value
 */
int function_name(int param1, char *param2);
```

### **Structure Comments**
```c
/**
 * Represents the main game state
 * Contains all game objects and rendering data
 */
typedef struct s_game
{
    // Game window and rendering
    void    *mlx;
    void    *win;
    t_img   img;
    
    // Player data
    t_player player;
    
    // ... more fields
} t_game;
```

## 🔄 **Merge Strategy**

### **Integrating Changes**
1. **Create feature branch**: `git checkout -b feature/feature-name`
2. **Develop**: Make small, frequent commits
3. **Testing**: Verify everything works
4. **Merge to dev**: `git checkout dev && git merge feature/feature-name`
5. **Test on dev**: Verify integration
6. **Merge to master**: Only when stable

### **Conflict Resolution**
- **Communication**: Always discuss major changes
- **Testing**: Run tests after resolving conflicts
- **Documentation**: Update docs if necessary

## 📊 **Quality Metrics**

### **Objectives**
- **0 memory leaks** ✅
- **0 norminette errors** ✅
- **Test coverage > 80%**
- **Compilation time < 30s**

### **Monitoring Tools**
- Valgrind for memory leaks
- Norminette for code style
- Development scripts for automation

## 🔒 **Code Review Process**

### **Pull Request Requirements**
- All tests must pass
- No memory leaks detected
- Norminette compliance
- Documentation updated
- Performance impact assessed

### **Review Checklist**
- [ ] Code follows naming conventions
- [ ] Functions are properly documented
- [ ] Memory management is correct
- [ ] Error handling is implemented
- [ ] Performance is acceptable

## 🚨 **Emergency Procedures**

### **Critical Bugs**
1. Create hotfix branch: `git checkout -b hotfix/bug-description`
2. Fix the issue with minimal changes
3. Test thoroughly
4. Merge directly to master
5. Update dev branch

### **Build Failures**
1. Check recent commits
2. Verify environment setup
3. Clean and rebuild
4. Contact team if issue persists

## 📈 **Performance Guidelines**

### **Optimization Targets**
- **Frame rate**: 60 FPS minimum
- **Memory usage**: < 100MB
- **Load time**: < 5 seconds
- **Compilation**: < 30 seconds

### **Profiling Tools**
- `gprof` for function profiling
- `valgrind --tool=callgrind` for call graphs
- `perf` for system-level profiling
