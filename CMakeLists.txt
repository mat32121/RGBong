cmake_minimum_required(VERSION 3.10.0)
project(RGBong VERSION 0.1.0 LANGUAGES CXX)
file(GLOB src_sources src/*.cpp)
add_executable(rgbong main.cpp ${src_sources})
target_include_directories(rgbong PUBLIC include)
target_link_libraries(rgbong sfml-graphics sfml-system sfml-window)
configure_file(font.ttf font.ttf COPYONLY)