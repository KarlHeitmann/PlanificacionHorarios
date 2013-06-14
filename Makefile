
#Definicion de flags de compilacion
FLAGS=-g -DDEBUG

NCURSES=-lncurses

OUT=PlanificacionHorarios

#CPP=g++
#Comandos para la compilacion:
.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(FLAGS) -c $*.c
.cc.o: ; gcc $(FLAGS) -c $*.cc
.cpp.o: ; g++ $(FLAGS) -c $*.cpp



all: $(OUT)
	
$(OUT): main.o
	g++ main.o -o $(OUT) $(NCURSES)
main.o: main.cpp

clean: 
	rm -f *.o PlanificacionHorarios
