#Makefile hecho para las pruebas de los archivos dentro de esta carpeta

FLAGS=-g -DDEBUG

OUT_TP=TProfesor
OUT_TCHP=TCostHoraProf
OUT_TCAP=TCostAsigProf
OUT_TA=TAula
OUT_TASIG=TAsignatura

.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(FLAGS) -c $*.c
.cc.o: ; gcc $(FLAGS) -c $*.cc
.cpp.o: ; g++ $(FLAGS) -c $*.cpp

$(OUT_TASIG): TAsignatura.o TAsignaturaTest.o
	g++ TAsignatura.o TAsignaturaTest.o
TAsignatura.o: TAsignatura.cpp TAsignatura.h
TAsignaturaTest.o: TAsignaturaTest.cpp TAsignatura.h

$(OUT_TA): TAula.o TAulaTest.o
	g++ TAula.o TAulaTest.o -o $(OUT_TA)
TAula.o: TAula.cpp TAula.h
TAulaTest.o: TAulaTest.cpp TAula.h

TProfesor: TProfesor.o TProfesorTest.o TCostAsigProf.o TCostHoraProf.o
	g++ TProfesor.o TProfesorTest.o TCostAsigProf.o TCostHoraProf.o -o $(OUT_TP)
TProfesor.o: TProfesor.cpp TProfesor.h
TProfesorTest.o: TProfesorTest.cpp TProfesor.h

TCostAsigProf: TCostAsigProf.o TCostHoraProf.o TCostAsigProfTest.o
	g++ TCostAsigProf.o TCostHoraProf.o TCostAsigProfTest.o -o $(OUT_TCAP)
TCostAsigProf.o: TCostAsigProf.cpp TCostAsigProf.h
TCostAsigProfTest.o: TCostAsigProfTest.cpp TCostAsigProf.h

TCostHoraProf: TCostHoraProf.o TCostHoraProfTest.o
	g++ TCostHoraProf.o TCostHoraProfTest.o -o $(OUT_TCHP)
TCostHoraProf.o: TCostHoraProf.cpp TCostHoraProf.h
TCostHoraProfTest.o: TCostHoraProfTest.cpp TCostHoraProf.h
clean:
	rm -f *.o $(OUT_TCHP) $(OUT_TCAP) $(OUT_TP) $(OUT_TA) $(OUT_TASIG)
