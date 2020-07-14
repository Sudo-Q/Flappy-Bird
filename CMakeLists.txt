cmake_minimum_required(VERSION 3.16)
project(Clion)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS system window graphics)
add_executable(Clion main.cpp Game.cpp Game.h Background.cpp Background.h Bird.cpp Bird.h)
target_link_libraries(Clion sfml-system sfml-window sfml-graphics sfml-audio)