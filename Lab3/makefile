#Ger Dobbs 10/10/2017
#Used to contain commands to compile projects
#
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread -I.

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: mutex.o Semaphore.o
	$(CC) -o mutex  Semaphore.o mutex.o $(CFLAGS) $(DEBUGFLAGS)


#this is a rule to run the debugger
DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
