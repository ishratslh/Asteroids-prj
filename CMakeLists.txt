cmake_minimum_required(VERSION 3.0.0)
project(asteroids-prj)

set(CMAKE_CXX_STANDARD 17)

# Add the SDL2 include directory to the include search path
include_directories(${CMAKE_SOURCE_DIR}/include/SDL2)

# Set the path to the SDL2 library directory
set(SDL2_LIBRARY_PATH "C:/Users/Ishra/git/L3_efrei/asteroids-prj/lib") # Adjust the path as needed
link_directories(${SDL2_LIBRARY_PATH})

add_executable(asteroids-prj main.cpp framework.hpp framework.cpp
        Asteroid.cpp
        Asteroid.hpp
        FlyingObject.cpp
        FlyingObject.hpp
        Missile.cpp
        Missile.hpp
        Spaceship.cpp
        Spaceship.hpp)

# Link your executable with the necessary libraries
target_link_libraries(asteroids-prj mingw32 SDL2main SDL2)


