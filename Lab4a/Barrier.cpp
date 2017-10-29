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

/**
This Static function will be passed to each thread we wish to run.
The threads will rendezvous before running the Code.
They will then wait for each other again at the last barrier so that they can be run together again in a loop.
*/

void Barrier::taskOne(	std::shared_ptr<Semaphore>theMutex,std::shared_ptr<Semaphore> barrierA, std::shared_ptr<Semaphore> barrierB,int threadNumber,int numThreads,int threadCount){
  	theMutex->Wait();
        threadCount=threadCount+1;
       	if(threadCount == numThreads){
	     //2 barriers used to implement a turnstile.
	    barrierB->Wait();
	    barrierA->Signal();
  	}
	    
  	theMutex->Signal();
	std::cout<<"Count = "<<threadCount<<std::endl;
      	std::cout<<"Thread Number = "<<threadNumber<<std::endl;
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

	


