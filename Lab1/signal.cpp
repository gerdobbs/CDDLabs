/*!
@author	Ger Dobbs
@date 02/10/2017
@version 1.0
*/

/*!
A Lab to show signalling in action.
The main function creartes 2 threads.
One thread signals the other using a semaphore
 */
#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1);
  threadTwo=std::thread(taskOne,sem1);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
