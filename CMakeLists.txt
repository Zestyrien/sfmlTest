cmake_minimum_required(VERSION 3.19)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(thevillage VERSION 0.1.1)

# add the executable
add_executable(
  thevillage  
  ./src/main.cpp
  ./src/assets.cpp
  ./src/village.cpp
)

#link libs
find_package(spdlog REQUIRED)
target_link_libraries(thevillage PRIVATE spdlog::spdlog)

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)
target_link_libraries(thevillage PRIVATE sfml-graphics sfml-window)