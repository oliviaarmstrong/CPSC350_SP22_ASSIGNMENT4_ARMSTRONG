#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include "SyntaxChecker.h"
using namespace std;


class FileProcessor{
private:
  int linenum;
  SyntaxChecker checker;
public:

  FileProcessor();
  ~FileProcessor();

  void processFile(string file);
};


#endif

