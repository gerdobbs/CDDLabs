/*!
@author	Ger Dobbs
@date 13/11/2017
@version 1.0
*/
#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! 
    \Create a program that has two parts. A producer and a consumer.
    \The producer generates random characters from 'a' to 'z' at random intervals (between 0 and 1 second in length). It adds these to a thread safe buffer that has a finite holding capacity of N characters. It generates a preset number of characters (determined at runtime) and when it has finished it adds an 'X' character to the buffer and exits.

The consumer takes these letters from the buffer at random intervals (between 0 and 1 secs in length) and records how many of each letter it consumes. Once it sees an 'X' in the buffer it adds its character count to a central buffer and exits.

The main file should demonstrate your producer consumer implementation in action by creating a number of consumers and producers and showing them in action.

*/

int countChars[26] ={};
const int lowerCaseA = 97;
const int lowerCaseZ = 126;

/**
Producer will add characters to the Safe buffer. The amount of characters entered will be determined at runtime
`**/

void producer(std::shared_ptr<SafeBuffer> safeBuffer, int numOfCharacters){
       char character;
       for (int count=0;count<numOfCharacters;++count){
	      std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
	      character = std::rand()%26 + lowerCaseA;
	      safeBuffer->addToBuffer(character);
	      std::cout<<character<<" Produced"<<std::endl;
	      countChars[character]++;
       }
       character='X';
       safeBuffer->addToBuffer(character);
}

void consumer(std::shared_ptr<SafeBuffer> safeBuffer){
      char character;
      while(character != 'X'){
            character = safeBuffer->removeFromBuffer();
	    if(character != 'X'){
	         std::cout<<character<<" Consumed." <<std::endl;
	    }
            std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
       }
}

void printCharacterCounts(){
       for(char character = lowerCaseA; character<lowerCaseZ; character++){
             if(countChars[character] != 0){
                   std::cout<<"Character "<<character<<" appears "<<countChars[character]<<std::endl;
	     }
       }
}

int main(void){
       int numOfCharacters;    //The number of characters produced in each producer
       const int numOfThreads = 20;
       std::thread producerThread[numOfThreads];
       std::thread consumerThread[numOfThreads];
       std::shared_ptr<SafeBuffer> safeBuffer(new SafeBuffer);

       std::cout<<"How many characters in each producer "<< std::endl;
       std::cin>>numOfCharacters;
  
       for(int i=0; i<numOfThreads; i++){
           producerThread[i] = std::thread(producer,safeBuffer, numOfCharacters);
	   consumerThread[i] = std::thread(consumer,safeBuffer);
       }
       for(int i=0;i<numOfThreads;i++){
           producerThread[i].join();
	   consumerThread[i].join();
       }
       printCharacterCounts();  //Print the occurrences of each character
}
