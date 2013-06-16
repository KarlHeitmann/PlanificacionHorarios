#Makefile hecho para las pruebas de los archivos dentro de esta carpeta

FLAGS=-g -DDEBUG

OUT_TI=TIndividuo

.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(FLAGS) -c $*.c
.cc.o: ; gcc $(FLAGS) -c $*.cc
.cpp.o: ; g++ $(FLAGS) -c $*.cpp

$(OUT_TI): TIndividuo.o TGen.o TIndividuoTest.o
	g++ TIndividuo.o TGen.o TIndividuoTest.o -o $(OUT_TI)
TIndividuo.o: TIndividuo.cpp TIndividuo.h TGen.h
TGen.o: TGen.cpp TGen.h

clean:
	rm -f *.o $(OUT_TI)

