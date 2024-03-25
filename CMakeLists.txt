cmake_minimum_required(VERSION 3.14)
project(Particle)

set(SFML_DIR C:/StudentFiles/Student/SFML-2.6.1/lib/cmake/SFML)

set(SOURCE_FILES src/main.cpp src/App.cpp src/App.hpp src/includes.hpp src/Particle.cpp src/Particle.hpp)
add_executable(Particle ${SOURCE_FILES})
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Particle sfml-system sfml-window sfml-graphics)
