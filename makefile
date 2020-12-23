all: file0.o file1.o
	gcc -o file0 file0.c
	gcc -o file1 file1.c

file0.o: file0.c
	gcc -c file0.c

file1.o: file1.c
	gcc -c file1.c

run: 
	./file0 & ./file1
	
clean:
	rm *.o
	rm outpu
	rm inpu
	rm file1
	rm file0