cmake_minimum_required(VERSION 3.22.1)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# ======== OPTIONS =========== #
option(BONUS "Compile bonus version" OFF)

# ======== HEADERS =========== #
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/bass
        ${CMAKE_SOURCE_DIR}/bonus
        ${CMAKE_SOURCE_DIR}/delay
        ${CMAKE_SOURCE_DIR}/other
        ${CMAKE_SOURCE_DIR}/parser
        ${CMAKE_SOURCE_DIR}/pathfinder
        ${CMAKE_SOURCE_DIR}/render
        ${CMAKE_SOURCE_DIR}/sprites
        ${CMAKE_SOURCE_DIR}/utils
        ${CMAKE_SOURCE_DIR}/world
        ${CMAKE_SOURCE_DIR}/mlx
        main.h
        cub3D.h
)

if(BONUS)
    message(STATUS "🚀 Compiling BONUS version")
    include_directories(${CMAKE_SOURCE_DIR}/bonus)
else()
    message(STATUS "🛠️ Compiling NORMAL version")
    include_directories(${CMAKE_SOURCE_DIR}/other)
endif()

# ====== COMPILE LIBFT & COMPILE MLX ====== #
#[[
add_custom_target(libft ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libft
        COMMENT "🛠️  Compiling libft..."
)
]]

add_custom_target(libmlx ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/mlx
        COMMENT "🛠️  Compiling minilibx..."
)

# ======= SOURCES ========= #
if(BONUS)
    file(GLOB SRC_FILES
            main.c
            bonus/*.c
            srcs/delay/*.c
            srcs/parser/*.c
            srcs/pathfinder/*.c
            srcs/render/*.c
            srcs/sprites/*.c
            srcs/utils/*.c
            srcs/world/*.c
    )
else()
    file(GLOB SRC_FILES
            main.c
            srcs/other/*.c
            srcs/delay/*.c
            srcs/parser/*.c
            srcs/pathfinder/*.c
            srcs/render/*.c
            srcs/sprites/*.c
            srcs/utils/*.c
            srcs/world/*.c
    )
endif()

#file(GLOB UNIT_C_TESTING testing/*.c)

# ===== EXECUTABLE: cub3d =========== #
add_executable(cub3d ${SRC_FILES}
)

#add_dependencies(cub3d libmlx libft)
add_dependencies(cub3d libmlx)

# === LINK OF SYSTEM === #
if(APPLE)
    target_link_libraries(cub3d
            ${CMAKE_CURRENT_SOURCE_DIR}/mlx/libmlx_Darwin.a
            "-framework OpenGL"
            "-framework AppKit"
            "-L/opt/X11/lib"
            "-lX11"
            "-lXext"
            "-lXpm"
            "-lXrandr"
            ${CMAKE_CURRENT_SOURCE_DIR}/bass/libbass.dylib
    )
else()
    # Macro LINUX para condicionales
    add_compile_definitions(LINUX=1)
    target_link_libraries(cub3d
            ${CMAKE_CURRENT_SOURCE_DIR}/mlx/libmlx.a
            m
            z
            bsd
            X11
            Xext
            Xrandr
            ${CMAKE_CURRENT_SOURCE_DIR}/bass/libbass.so
    )
endif()

# ===== EXECUTABLE: test =========== #
#[[
add_executable(test
        ${UNIT_C_TESTING}
        ${SRC_FILES}
        testing/parser_map_parsing.c
)
]]

#add_dependencies(test libmlx)
#add_dependencies(test libmlx libft)

# === LINK LIBRARIES test === #
#[[
target_link_libraries(test
        ${CMAKE_CURRENT_SOURCE_DIR}/mlx/libmlx.a
        ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a
)
]]

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")#
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")#