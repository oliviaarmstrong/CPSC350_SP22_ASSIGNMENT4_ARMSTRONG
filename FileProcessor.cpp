#include "FileProcessor.h"
#include "SyntaxChecker.h"
#include <iostream>
#include <fstream>

using namespace std;

FileProcessor::FileProcessor() {
  linenum = 0;
  checker = SyntaxChecker();

}

FileProcessor::~FileProcessor() {}

void FileProcessor::processFile(string file) {
  //s = new GenStack<char>();
  ifstream inFS;
  string line;
  inFS.open(file);
  while(getline(inFS,line)) {
    //Variable to keep track of line number
    ++linenum;
    //If check syntax returns anything other than empty string, something went wrong and it contains the error message
    if (checker.CheckSyntax(line).compare("") != 0) {
      cout << "Line " << to_string(linenum) << checker.CheckSyntax(line) <<endl;
    }
  }

   cout << "Finished file processing" << endl;

   //If the stack is not empty, that means a closing delimiter is missing.
   //if (!s.isEmpty()) {
     //cout << "Reached end of file, delimiter is missing." << endl;
   //}

  inFS.close();
}
