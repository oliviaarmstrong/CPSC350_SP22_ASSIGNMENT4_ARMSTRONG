#ifndef SyntaxChecker_h
#define SyntaxChecker_h

#include <stdio.h>
#include <string>
#include "GenStack.h"
using namespace std;

class SyntaxChecker{
private:
    GenStack<char>* s;
public:
    SyntaxChecker();
    ~SyntaxChecker();
    string CheckSyntax(string currline);
    string ReplaceSyntax();

};

#endif 
