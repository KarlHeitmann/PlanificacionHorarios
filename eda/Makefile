#Makefile hecho para las pruebas de los archivos dentro de esta carpeta

FLAGS=-g -DDEBUG

OUT_TCHP=TCostHoraProf

.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(FLAGS) -c $*.c
.cc.o: ; gcc $(FLAGS) -c $*.cc
.cpp.o: ; g++ $(FLAGS) -c $*.cpp

TCostHoraProf: TCostHoraProf.o TCostHoraProfTest.o
	g++ TCostHoraProf.o TCostHoraProfTest.o -o $(OUT_TCHP)

TCostHoraProf.o: TCostHoraProf.cpp
TCostHoraProfTest.o: TCostHoraProfTest.cpp
clean:
	rm -f *.o $(OUT_TCHP)
