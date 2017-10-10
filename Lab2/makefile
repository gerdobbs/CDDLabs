#Ger Dobbs 10/10/2017
# Makefile with a CLEAN rule
#Used to contain commands to compile projects
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread -I.

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: signal.o Semaphore.o
	$(CC) -o rendevous  Semaphore.o signal.o $(CFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
