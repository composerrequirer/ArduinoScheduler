# ArduinoScheduler
This Arduino library heps create threads to divide the workflow on arduino, it requires an external clock on pin two to work, this clock will determinate the time slice that the
threads will get, the the library uses the 'threadBeging(threads Number);' to know how many threads will be created, and the it uses the method 'createThread(function pointer);'
to call the function, which will be the thread it self.

This library only allows you to creat threads using int type functions, that doesn't any arguments, you can make the library be able to receive more types of functions by father
developing it.

It is a really simple library and you should figureout how to use it by lookint at its code. if any daubt you can contact me and I will give you some help ;)
