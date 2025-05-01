cmake_minimum_required(VERSION 3.22.1)

project(cub3D C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRCS_DIR srcs/*.c)
file(GLOB MINILIBX_DIR minilibx-linux/*.c)
file(GLOB LIBFT_DIR libft/*.c)

# include the headers
include_directories(includes)
include_directories(maps)
include_directories(textures)

# Añadir rutas de búsqueda para cabeceras X11 si estás usando XQuartz
if(APPLE)
    include_directories(/opt/X11/include)
    link_directories(/opt/X11/lib)
endif()

# Comando para compilar libmlx.a
add_custom_target(libmlx ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux
        COMMENT "Compilando libmlx.a"
)

# Añadir el ejecutable
add_executable(cub3d
        ${SRCS}/main.c
        ${MINILIBX}
)

# Asegurarse de que el target so_long_anaa dependa de libmlx.a
add_dependencies(cub3D libmlx)

# Enlazar el ejecutable con libmlx.a y las bibliotecas X11 o alternativas para macOS
if(APPLE)
    target_link_libraries(so_long_anaa
            ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx_Darwin.a
            "-framework OpenGL"
            "-framework AppKit"
            "-L/opt/X11/lib"
            "-lX11"
            "-lXext"
            "-lXpm"
            "-lXrandr"
    )
else()
    target_link_libraries(cub3D
            ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx.a
            X11
            Xext
            Xpm
            Xrandr
    )
endif()