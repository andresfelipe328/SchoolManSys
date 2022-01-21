CC = g++
OBJ = main.o studentsImp.o
HEADER = headers/Students.h 
CFLAGS = -c -Wall -Iinclude

exec: $(OBJ) 
	$(CC) $(OBJ) -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) $< -o $@

studentsImp.o: studentsImp.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf *o exec