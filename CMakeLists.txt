cmake_minimum_required(VERSION 3.22.1)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# ============================= #
# ====== COMPILAR LIBFT ====== #
# ============================= #
add_custom_target(libft ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libft
        COMMENT "🛠️  Compilando libft..."
)

# ============================= #
# ====== COMPILAR MLX ======== #
# ============================= #
add_custom_target(libmlx ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux
        COMMENT "🛠️  Compilando minilibx..."
)

# ============================= #
# ======== HEADERS =========== #
# ============================= #
include_directories(
        includes
        libft
        minilibx-linux
)

# ============================= #
# ======= FUENTES ============ #
# ============================= #
file(GLOB SRC_FILES
        srcs/*.c
        srcs/init/*.c
        srcs/parser_file/*.c
        srcs/parser_map/*.c
)

# ============================= #
# ===== EJECUTABLE =========== #
# ============================= #
add_executable(cub3d ${SRC_FILES})

add_dependencies(cub3d libmlx libft)

# ============================= #
# === ENLACES SEGÚN SISTEMA == #
# ============================= #
if(APPLE)
    target_link_libraries(cub3d
            ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx_Darwin.a
            ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a
            "-framework OpenGL"
            "-framework AppKit"
            "-L/opt/X11/lib"
            "-lX11"
            "-lXext"
            "-lXpm"
            "-lXrandr"
    )
else()
    target_link_libraries(cub3d
            ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx.a
            ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a
            X11
            Xext
            Xpm
            Xrandr
            m
            z
            bsd
    )
endif()
