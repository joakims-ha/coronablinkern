cb: actions.o menu.o ui.o list.o main.o
	gcc -o coronablinkern actions.o menu.o ui.o list.o main.o

test: list.o test.o
	gcc -o test list.o test.o -lcunit 

dox: Doxyfile
	doxygen Doxyfile && make -C latex && cp ./latex/refman.pdf .