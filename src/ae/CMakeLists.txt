#Project name

#project(PlanificacionHorarios)

#cmake_minimum_required(VERSION 2.6)

include_directories("${PROJECT_SOURCE_DIR}/eda")
add_subdirectory(eda)
set (EXTRA_LIBS ${EXTRA_LIBS} AEDataStructure)

add_executable(TIndividuoTest CandidatoHorario.cpp TIndividuo.cpp
	TGen.cpp TIndividuoTest2.cpp)

target_link_libraries(TIndividuoTest AEDataStructure)

