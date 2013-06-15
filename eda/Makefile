#Makefile hecho para las pruebas de los archivos dentro de esta carpeta

FLAGS=-g -DDEBUG

OUT_TCHP=TCostHoraProf
OUT_TCAP=TCostAsigProf

.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(FLAGS) -c $*.c
.cc.o: ; gcc $(FLAGS) -c $*.cc
.cpp.o: ; g++ $(FLAGS) -c $*.cpp

TCostAsigProf: TCostAsigProf.o TCostAsigProfTest.o
	g++ TCostAsigProf.o TCostAsigProfTest.o -o $(OUT_TCAP)
TCostAsigProf.o: TCostAsigProf.cpp TCostAsigProf.h
TCostAsigProfTest.o: TCostAsigProfTest.cpp TCostAsigProf.h

TCostHoraProf: TCostHoraProf.o TCostHoraProfTest.o
	g++ TCostHoraProf.o TCostHoraProfTest.o -o $(OUT_TCHP)
TCostHoraProf.o: TCostHoraProf.cpp TCostHoraProf.h
TCostHoraProfTest.o: TCostHoraProfTest.cpp TCostHoraProf.h
clean:
	rm -f *.o $(OUT_TCHP)
