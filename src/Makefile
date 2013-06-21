
#Definicion de flags de compilacion
FLAGS=-g -DDEBUG

NCURSES=-lncurses

OUT=main

#CPP=g++
#Comandos para la compilacion:
.SUFFIXES: .cpp .c .h .o
.c.o: ; cc $(FLAGS) -c $*.c
.cc.o: ; gcc $(FLAGS) -c $*.cc
.cpp.o: ; g++ $(FLAGS) -c $*.cpp



all: $(OUT) 
	
$(OUT): main.o interfaz/CMainWindow.o
	g++ main.o interfaz/CMainWindow.o -o $(OUT) $(NCURSES)
main.o: main.cpp

interfaz/CMainWindow.o: interfaz/CMainWindow.cpp
	g++ -c interfaz/CMainWindow.cpp -o interfaz/CMainWindow.o

clean: 
	rm -f *.o $(OUT)
	rm -f interfaz/*.o 
