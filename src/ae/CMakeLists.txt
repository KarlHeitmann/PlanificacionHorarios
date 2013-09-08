
include_directories("${PROJECT_SOURCE_DIR}/eda")
add_subdirectory(eda)
set (EXTRA_LIBS ${EXTRA_LIBS} AEDataStructure)

add_executable(TIndividuoTest CandidatoHorario.cpp TIndividuo.cpp
	TGen.cpp TIndividuoTest.cpp GeneradorDatos.cpp)

add_executable(AlgoritmoEvolutivoTest AlgoritmoEvolutivoTest.cpp
	AlgoritmoEvolutivo.cpp CandidatoHorario.cpp TIndividuo.cpp 
	TGen.cpp GeneradorDatos.cpp DataPackage.cpp)

target_link_libraries(TIndividuoTest AEDataStructure)
target_link_libraries(AlgoritmoEvolutivoTest AEDataStructure)
