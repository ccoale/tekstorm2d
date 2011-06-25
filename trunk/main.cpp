#include <iostream>
#include "threads/Mutex.h"
#include "threads/Thread.h"
using namespace Tekstorm;
using namespace Threads;


void MySecondThread(ThreadStartArgs *args)
{
	for (int i = 0; i < 5; i++)
		std::cout << i << "\n";
}

void MyThread(ThreadStartArgs *args)
{
	for (int i = 0; i < 5; i++) {
		std::cout << i << "\n";
	}
}

int main()
{
	Thread thread(MyThread);
	Thread thread2(MySecondThread);
	thread2.Start();
	thread.Start();
	std::cout << "test";

	while (true) ;
	
	std::cout << "We made it!";
}
