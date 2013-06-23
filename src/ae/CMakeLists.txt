
include_directories("${PROJECT_SOURCE_DIR}/eda")
add_subdirectory(eda)
set (EXTRA_LIBS ${EXTRA_LIBS} AEDataStructure)

add_executable(TIndividuoTest CandidatoHorario.cpp TIndividuo.cpp
	TGen.cpp TIndividuoTest.cpp GeneradorDatos.cpp)

target_link_libraries(TIndividuoTest AEDataStructure)

