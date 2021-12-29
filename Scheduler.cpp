#include "Arduino.h"
#include "Scheduler.h"

Scheduler::Constructor(){

}

int Scheduler::_size = 0; // The variable must be initialized, if not it wont be at the scope.
// now that we have initialized the varialb '_size' it is wornking.


void Scheduler::threadsBegin(int size){
	pinMode(2, INPUT);
	Serial.begin(9600);
	Serial.println("Ok we are beggining: ");
	attachInterrupt(digitalPinToInterrupt(2), (Scheduler::caller), FALLING);
	_threadsPointers  = malloc(size);
	_size = size;
}


void Scheduler::createThread(int(*funcPointer)()){
	_threadsPointers[_threadsIndex] = funcPointer;
	_threadsPointers[_threadsIndex]();
	_threadsIndex++;
	Scheduler::changeThread(_threadsPointers, true);
	if(_threadsIndex > _size){
		_threadsIndex = _size;
	}
}

void Scheduler::caller(){
	Scheduler::changeThread(NULL, false);
}

void Scheduler::changeThread(int(**pointers)() = NULL, bool flag = false){
	int next_run = random(_size);
	static int(**internal_pointears)();
	static bool internalFlag = true;
	if(flag){
		if(internalFlag){
			internal_pointears = malloc(_size);
		}
		internalFlag = false;
		internal_pointears = pointers;
	}else{
		internal_pointears[next_run](); // and this line here too.
	}
}