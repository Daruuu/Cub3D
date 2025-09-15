#!/bin/bash

# ===================== DEVELOPMENT SCRIPTS ===================== #
# Script para facilitar el desarrollo en equipo

set -e

# Colores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Función para mostrar ayuda
show_help() {
    echo -e "${BLUE}Cub3D Development Scripts${NC}"
    echo ""
    echo "Uso: $0 [comando]"
    echo ""
    echo "Comandos disponibles:"
    echo "  build     - Compilar el proyecto"
    echo "  test      - Ejecutar tests"
    echo "  clean     - Limpiar archivos generados"
    echo "  norm      - Verificar norminette"
    echo "  memcheck  - Verificar memoria con valgrind"
    echo "  format    - Formatear código"
    echo "  setup     - Configurar entorno de desarrollo"
    echo "  help      - Mostrar esta ayuda"
}

# Función para compilar
build_project() {
    echo -e "${GREEN}🔨 Compilando proyecto...${NC}"
    make clean
    make all
    echo -e "${GREEN}✅ Compilación completada${NC}"
}

# Función para ejecutar tests
run_tests() {
    echo -e "${GREEN}🧪 Ejecutando tests...${NC}"
    
    # Test básico
    if [ -f "./cub3D" ]; then
        echo -e "${YELLOW}Probando ejecución básica...${NC}"
        timeout 5s ./cub3D maps_and_textures/correct_maps/demo.cub || true
    fi
    
    echo -e "${GREEN}✅ Tests completados${NC}"
}

# Función para limpiar
clean_project() {
    echo -e "${GREEN}🧹 Limpiando proyecto...${NC}"
    make fclean
    echo -e "${GREEN}✅ Limpieza completada${NC}"
}

# Función para norminette
check_norm() {
    echo -e "${GREEN}🔍 Verificando norminette...${NC}"
    make norm
    echo -e "${GREEN}✅ Norminette completado${NC}"
}

# Función para verificar memoria
check_memory() {
    echo -e "${GREEN}🔍 Verificando memoria con valgrind...${NC}"
    
    if ! command -v valgrind &> /dev/null; then
        echo -e "${RED}❌ Valgrind no está instalado${NC}"
        return 1
    fi
    
    if [ -f "./cub3D" ]; then
        valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps_and_textures/correct_maps/demo.cub
    else
        echo -e "${RED}❌ Ejecutable no encontrado. Ejecuta 'build' primero${NC}"
    fi
}

# Función para formatear código
format_code() {
    echo -e "${GREEN}🎨 Formateando código...${NC}"
    
    # Formatear archivos C
    find srcs/ -name "*.c" -exec clang-format -i {} \;
    find srcs/ -name "*.h" -exec clang-format -i {} \;
    find include/ -name "*.h" -exec clang-format -i {} \;
    
    echo -e "${GREEN}✅ Formateo completado${NC}"
}

# Función para configurar entorno
setup_environment() {
    echo -e "${GREEN}⚙️ Configurando entorno de desarrollo...${NC}"
    
    # Crear directorios necesarios
    mkdir -p logs
    mkdir -p temp
    
    # Configurar git hooks si no existen
    if [ ! -f ".git/hooks/pre-commit" ]; then
        echo "#!/bin/bash" > .git/hooks/pre-commit
        echo "make norm" >> .git/hooks/pre-commit
        chmod +x .git/hooks/pre-commit
        echo -e "${GREEN}✅ Git hook creado${NC}"
    fi
    
    echo -e "${GREEN}✅ Entorno configurado${NC}"
}

# Función principal
main() {
    case "${1:-help}" in
        "build")
            build_project
            ;;
        "test")
            run_tests
            ;;
        "clean")
            clean_project
            ;;
        "norm")
            check_norm
            ;;
        "memcheck")
            check_memory
            ;;
        "format")
            format_code
            ;;
        "setup")
            setup_environment
            ;;
        "help"|*)
            show_help
            ;;
    esac
}

# Ejecutar función principal
main "$@"
