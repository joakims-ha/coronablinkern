cb: ui.o list.o menu.o sim.o main.o
	gcc -o coronablinkern ui.o list.o menu.o sim.o main.o

test: list.o test.o
	gcc -o test list.o test.o -lcunit 