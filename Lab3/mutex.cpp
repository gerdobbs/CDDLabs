/*!
@author	Ger Dobbs
@date 02/10/2017
@version 1.0
*/
/*!
Semaphore used to apply mutual exclusion.
Whichever thread runs first will apply a mutex.

*/
#include "Semaphore.h"
#include <iostream>
#include <thread>

int shared_variable = 0;

void taskOne(std::shared_ptr<Semaphore> theMutex){
	theMutex->Wait();
	shared_variable++;
	std::cout <<"(T1)Increase "<<std::endl;
	std::cout << "(T1)shared "<<std::endl;
	std::cout << "(T1)variable by 1 " <<std::endl;
	std::cout <<" (T1)Value is now: " ;  
        std::cout << shared_variable<<std::endl;
	theMutex->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theMutex){
	theMutex->Wait();
       
	 shared_variable= shared_variable+1;
	std::cout <<"(T2)Increase "<<std::endl;
	std::cout << "(T2)shared "<<std::endl;
	std::cout << "(T2)variable by 1 " <<std::endl;
	std::cout << "(T2)Value is now: " ;  
        std::cout <<  shared_variable <<std::endl;
	theMutex->Signal();
}

int main(void){
  int shared_variable = 0;
	std::thread threadOne, threadTwo;
	std::shared_ptr<Semaphore> theMutex( new Semaphore(1));
	/**< Launch the threads  */
	threadOne=std::thread(taskTwo,theMutex);
	threadTwo=std::thread(taskOne,theMutex);
	std::cout << "Launched from the main\n";
	threadOne.join();
	threadTwo.join();
	return 0;
}
