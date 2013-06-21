
add_executable(TProfesorTest TProfesorTest.cpp TProfesor.cpp
               TCostAsigProf.cpp TCostHoraProf)

add_library(AEDataStructure STATIC TProfesor.cpp TCostHoraProf.cpp
	TCostAsigProf.cpp TAula.cpp TAsignatura.cpp)


