#Ger Dobbs 13/9/2017
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread -I.

ALL: signal.o Semaphore.o
	$(CC) -o signal  Semaphore.cpp signal.cpp $(CFLAGS)



