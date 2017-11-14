/*!
@author	Ger Dobbs
@date 29/10/2017
@version 1.0
*/

#include "Semaphore.h"
/*! \class Semaphore
    \brief Mutual Exclusion Implementation

*/

#include <mutex>

class Barrier{
public:
 	// int threadCount;
	int threadNumber;
	static void taskOne(std::shared_ptr<Semaphore> ,std::shared_ptr<Semaphore>,std::shared_ptr<Semaphore>,int,int,int);
	
};
