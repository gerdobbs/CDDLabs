/*!
@author	Ger Dobbs
@date 29/10/2017
@version 1.0
*/
/*!
Demonstration of a reusable barrier.

*/

#include "Barrier.h"
#include <iostream>
#include <thread>

int numThreads = 5;
int threadCount = 0;

/**
This main function will create an array of threads.
A mutex will be created to protect the thread count from being incremented/decremented bt more than 1 thread at a time.
2 Semaphores will be constructed to act as a turnstile
Each thread will run  the class Barrier static function taskOne.
*/
int main(void){
        std::thread threadArray[numThreads];
   	std::shared_ptr<Semaphore> theMutex(new Semaphore(1));
	///Two Semaphores to implement a turnstile
   	std::shared_ptr<Semaphore> barrierA(new Semaphore(0));
   	std::shared_ptr<Semaphore> barrierB(new Semaphore(1));
	for(int i=0;i<numThreads; i++){
	     threadArray[i] = std::thread(Barrier::taskOne,theMutex,barrierA,barrierB,i,numThreads,threadCount);
	}
	for(int i=0;i<numThreads;i++){ 
	     threadArray[i].join();
      	}

 return 0;
}
