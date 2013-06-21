#Project name
project(PlanificacionHorarios)

cmake_minimum_required(VERSION 2.6)

add_executable(TProfesorTest TProfesorTest.cpp TProfesor.cpp
               TCostAsigProf.cpp TCostHoraProf)

# add interfaz library
#include_directories ("${PROJECT_SOURCE_DIR}/interfaz")
#add_subdirectory (interfaz)
add_library(AEDataStructure STATIC TProfesor.cpp TCostHoraProf.cpp
	TCostAsigProf.cpp TAula.cpp TAsignatura.cpp)
#set (EXTRA_LIBS ${EXTRA_LIBS} interfaz)


