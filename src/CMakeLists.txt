#Project name
project(PlanificacionHorarios)

cmake_minimum_required(VERSION 2.6)

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_COLOR_MAKEFILE ON)
#SET(CMAKE_CXX_FLAGS "-Wall")
include_directories("${PROJECT_SOURCE_DIR}/ae" "${PROJECT_SOURCE_DIR}/interfaz")
add_subdirectory(ae)

add_executable(main main.cpp)
add_library(TUI STATIC CMainWindow.cpp CAdminWindow.cpp)
target_link_libraries(main TUI)
target_link_libraries(main general ncurses sqlite3)
#set (EXTRA_LIBS ${EXTRA_LIBS} interfaz)


