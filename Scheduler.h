#ifndef Scheduler_h
#define Scheduler_h

#include "Arduino.h"

class Scheduler{
	public:
		Constructor();
		void threadsBegin(int size);
		void createThread(int(*funcPointer)());
		int(**_threadsPointers)();

	private:
		static void changeThread(int(**pointers)(), bool flag);
		int _threadsIndex;
		static int _size;
		static void caller();

};

#endif