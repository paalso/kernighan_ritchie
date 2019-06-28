all: sortlines

clean:
	rm -rf *.o

sortlines: main.o handle_lines.o sort.o
	gcc main.o handle_lines.o sort.o -o sortlines

main.o: main.c sort_lines.h
	gcc -c main.c

handle_lines.o: handle_lines.c sort_lines.h
	gcc -c handle_lines.c

sort.o: sort.c
	gcc -c sort.c

