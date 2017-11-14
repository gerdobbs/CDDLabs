/*!
@author	Ger Dobbs
@date 13/11/2017
@version 1.0
*/
#include "SafeBuffer.h"
#include <iostream>

/*! 
    \Thread Safe Buffer Class

*/

SafeBuffer::SafeBuffer() {
  mutex = std::make_shared<Semaphore>(1);
  items = std::make_shared<Semaphore>(0) ;
  spaces = std::make_shared<Semaphore>(100);
  // stop =0;
}

void SafeBuffer::addToBuffer(char character){
  //Decrease the number of spaces available
  spaces->Wait();
  mutex->Wait();
  bufferQueue.push(character);
  mutex->Signal();
  //Increase the number of items in the buffer
  items->Signal();
}

char SafeBuffer::removeFromBuffer(){
  char character;
  items->Wait();
  mutex->Wait();
  character = bufferQueue.front();
  bufferQueue.pop();
  mutex->Signal();
  spaces->Signal();
  return character;

}
