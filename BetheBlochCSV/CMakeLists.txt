

















cmake_minimum_required(VERSION 3.8)
project(BetheBlochCSV)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

include_directories(include)

file(GLOB sources src/*.cc)
file(GLOB headers include/*.hh)

add_executable(betheBloch ${sources} ${headers})
target_link_libraries(betheBloch ${Geant4_LIBRARIES})
