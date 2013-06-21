#Project name
project(PlanificacionHorarios)

cmake_minimum_required(VERSION 2.6)

include_directories("${PROJECT_SOURCE_DIR}/ae" "${PROJECT_SOURCE_DIR}/interfaz")
add_subdirectory(interfaz)
add_subdirectory(ae)
# add interfaz library
#include_directories ("${PROJECT_SOURCE_DIR}/interfaz")
#add_subdirectory (interfaz)
add_executable(main main.cpp)
target_link_libraries(main TUI)
target_link_libraries(main general ncurses)
#set (EXTRA_LIBS ${EXTRA_LIBS} interfaz)


