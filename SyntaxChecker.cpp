#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker() {
  s = new GenStack<char>();
}

SyntaxChecker::~SyntaxChecker() {}

string SyntaxChecker::CheckSyntax(string currline) {
  //Loop through current line
  for (int i = 0; i < currline.size(); i++) {
    //if i at current line is an opening delimiter, push that onto the stack
    if (currline[i] == '{' || currline[i] == '(' || currline[i] ==  '[') {
      s->push(currline[i]);
    }
    //if i at current line is a closing delimiter
    if(currline[i] == '}' || currline[i] == ']' || currline[i] == ')'){
      //if the stack is not empty
      if(!s->isEmpty()) {
      //if i at current line is a closing '}' and the top of the stack is NOT an opening '{'
      if (currline[i] == '}' && s->peek() != '{') {
      //return a string containing the expected delimter and what was instead found
      string result = " expected " + ReplaceSyntax() + " and found " + currline[i];
      return result;
    }
      //if i at current line is a closing ')' and the top of the stack is NOT an opening '('
      else if (currline[i] == ')' && s->peek() != '(') {
      //return a string containing the expected delimter and what was instead found
      string result = " expected " + ReplaceSyntax() + " and found " + currline[i];
      return result;
    }
      //if i at current line is a closing ']' and the top of the stack is NOT an opening '['
      else if (currline[i] == ']' && s->peek() != '[') {
      //return a string containing the expected delimter and what was instead found
      string result = " expected " + ReplaceSyntax() + " and found " + currline[i];
      return result;
    }
      //else if inproper delimiter was not detetcted and the stack is not empty, pop off the char at the top of the stack
      else if (!s->isEmpty()) {
          s->pop();
        }
      }
    }
  }
  return "";
}

//Method that looks at the top of the stack and returns the correct/matching delimiter
string SyntaxChecker::ReplaceSyntax() {
  if (s->peek() == '{') {
    return "}";
  }
  if (s->peek() == '(') {
    return ")";
  }
  if (s->peek() == '[') {
    return "]";
  }
  return "";
}
