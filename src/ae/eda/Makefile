#Makefile hecho para las pruebas de los archivos dentro de esta carpeta
ifeq ($(mode), release)
	CFLAGS=-Wall
else
	mode=debug
	CFLAGS=-g -Wall
endif

CC=g++

#FLAGS=-g -DDEBUG

OUT_TP=TProfesor
OUT_TCHP=TCostHoraProf
OUT_TCAP=TCostAsigProf
OUT_TA=TAula
OUT_TASIG=TAsignatura

.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(CFLAGS) -c $*.c
.cc.o: ; gcc $(CFLAGS) -c $*.cc
.cpp.o: ; g++ $(CFLAGS) -c $*.cpp

#Static library build
libAEeda.a: TAula.o TCostAsigProf.o TCostHoraProf.o TProfesor.o TAsignatura.o
	ar rc libAEeda.a TAula.o TCostAsigProf.o TCostHoraProf.o TProfesor.o TAsignatura.o
	ranlib libAEeda.a
$(OUT_TASIG): TAsignatura.o TAsignaturaTest.o
	g++ TAsignatura.o TAsignaturaTest.o -o $(OUT_TASIG)
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
	rm -f *.o $(OUT_TCHP) $(OUT_TCAP) $(OUT_TP) $(OUT_TA) $(OUT_TASIG) libAEeda.a
