/*!
@author	Ger Dobbs
@date 03/10/2017
@version 1.0
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore1, std::shared_ptr<Semaphore> theSemaphore2){
  std::cout <<"I ";
  std::cout << "must ";
  theSemaphore2 -> Signal();
  theSemaphore1 -> Wait();
  std::cout << "print ";
  std::cout << "first "<<std::endl;
  theSemaphore2->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore1, std::shared_ptr<Semaphore> theSemaphore2){
  theSemaphore2->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  theSemaphore1 -> Signal();
  theSemaphore2 -> Wait();
  std::cout << "appear ";
  std::cout << "second "<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2);
  threadTwo=std::thread(taskOne,sem1,sem2);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
