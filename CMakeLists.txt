cmake_minimum_required(VERSION 2.7)
project(Breakout)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.h main.cpp
    Ball.h Ball.cpp
    Board.h Board.cpp
    Entity.h Entity.cpp
    Game.h Game.cpp
    Paddle.h Paddle.cpp
    )

# include_directories (common)

add_executable(Breakout ${SOURCE_FILES})

target_link_libraries (Breakout -lSDL2 -lSDL2_image)

