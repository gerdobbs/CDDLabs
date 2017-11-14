/*!
@author	Ger Dobbs
@date 13/11/2017
@version 1.0
*/
#pragma once
#include "Semaphore.h"
#include <queue>

class SafeBuffer{
public:

	std::shared_ptr<Semaphore> mutex;
	std::shared_ptr<Semaphore> items;
	std::shared_ptr<Semaphore> spaces;
	
	std::queue<char> bufferQueue;
	SafeBuffer(); 
	void addToBuffer(char);
	char removeFromBuffer();

};
