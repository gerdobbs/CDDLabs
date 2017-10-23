/*!
@author	Ger Dobbs
@date 23/10/2017
@version 1.0
*/
/*!
Demonstration of a reusable barrier.

*/
#include "Semaphore.h"
#include <iostream>
#include <thread>

int numThreads = 5;
int threadCount = 0;
void taskOne(std::shared_ptr<Semaphore> theMutex, std::shared_ptr<Semaphore> barrierA, std::shared_ptr<Semaphore> barrierB,int threadNumber){
  	theMutex->Wait();
  	threadCount++;
  	if(threadCount == numThreads){
  	  barrierB->Wait();
  	  barrierA->Signal();
  	}
  	theMutex->Signal();
  	barrierA->Wait();
	barrierA->Signal();
	std::cout<<"We Will all rendevous here first before running important code. Thread Number "<<threadNumber<<std::endl;
       	theMutex->Wait();
       	threadCount--;
       	if(threadCount == 0){
       	  barrierA->Wait();
	  barrierB->Signal();
       	}
	theMutex->Signal();
	barrierB->Wait();
	barrierB->Signal();
	std::cout<<"We have run the important Code and will all meet up here. Thread Number "<<threadNumber<<std::endl;
}

int main(void){
 
	std::thread threadArray[numThreads];
	std::shared_ptr<Semaphore> theMutex(new Semaphore(1));
	///Two Semaphores to implement a turnstile
	std::shared_ptr<Semaphore> barrierA(new Semaphore(0));
	std::shared_ptr<Semaphore> barrierB(new Semaphore(1));
	for(int i=0;i<numThreads; i++){
	  threadArray[i] = std::thread(taskOne,theMutex, barrierA, barrierB,i);
	}
	for(int i=0;i<numThreads;i++){
	  threadArray[i].join();
	  	

	}
	return 0;
}
