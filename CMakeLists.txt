cmake_minimum_required(VERSION 3.22.1)

project(cub3d C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRCS_DIR srcs/*.c srcs/init/*.c srcs/parser/*.c)

file(GLOB MINILIBX_DIR minilibx-linux/*.c)
file(GLOB LIBFT_DIR libft/*.c)

# include the headers .h
include_directories(
        includes
        maps
        libft
)

# Añadir rutas de búsqueda para cabeceras X11 si estás usando XQuartz
if(APPLE)
    include_directories(/opt/X11/include)
    link_directories(/opt/X11/lib)
endif()

# compile libmlx with make
add_custom_target(libmlx ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux
        COMMENT "-------------- Compiling libmlx.a ---------------"
)

add_custom_target(libft ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libft
        COMMENT "************ Compiling libft ******************"
)

add_executable(cub3d
        ${SRCS_DIR}
)

# Asegurarse de que el target so_long_anaa dependa de libmlx.a
# add_dependencies(cub3d libmlx)

# target_link_libraries(cub3d ${CMAKE_CURRENT_SOURCE_DIR})

# Enlazar el ejecutable con libmlx.a y las bibliotecas X11 y Xext

target_link_libraries(cub3d
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/minilibx-linux/libmlx_Linux.a
        X11
        Xext
        Xpm
        Xrandr
)

# Enlazar el ejecutable con libmlx.a y las bibliotecas X11 o alternativas para macOS
 
# if(APPLE)
#     target_link_libraries(cub3d
#             ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx_Darwin.a
#             ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a
#             "-framework OpenGL"
#             "-framework AppKit"
#             "-L/opt/X11/lib"
#             "-lX11"
#             "-lXext"
#             "-lXpm"
#             "-lXrandr"
#     )
# else()
#     target_link_libraries(cub3d
#             ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx.a
#             ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a
#             X11
#             Xext
#             Xpm
#             Xrandr
#     )
# endif()