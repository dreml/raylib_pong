cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_COMPILER E:/Tools/msys64/mingw64/bin/gcc.exe)
set(CMAKE_CXX_COMPILER E:/Tools/msys64/mingw64/bin/g++.exe)
project(pong)

# Генерация compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Добавляем директорию с заголовочными файлами
include_directories(${PROJECT_SOURCE_DIR}/include)

# Явно указываем все исходные файлы
set(SOURCES
    src/main.cpp
    src/game/ball.cpp
    src/game/paddle.cpp
    src/game/game.cpp
)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Подключаем библиотеки
target_link_libraries(${PROJECT_NAME} 
    raylib
    winmm
    gdi32
    opengl32
)
