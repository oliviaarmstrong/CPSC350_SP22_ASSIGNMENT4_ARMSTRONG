#include "FileProcessor.h"
#include <iostream>

int main(int argc, char **argv){
GenStack<char> *myStack = new GenStack<char>();

FileProcessor processor;
processor.processFile(argv[1]);


return 0;
}
