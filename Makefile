cb: actions.o io.o menu.o ui.o list.o sim.o main.o
	gcc -o coronablinkern actions.o io.o menu.o ui.o list.o sim.o main.o

test: list.o test.o
	gcc -o test list.o test.o -lcunit 

dox: Doxyfile
	doxygen Doxyfile && make -C latex && cp ./latex/refman.pdf .