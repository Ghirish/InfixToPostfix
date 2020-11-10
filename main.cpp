#include <iostream>
#include <stack>
#include <string>
#include <string.h> 


using namespace std;

stack<char> stk;

int percedence(char x){
  if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
void convertToPostfix(string str){
  stk.push('e'); 
  int l = str.length(); 
  string postfix;
  for(int c = 0; c < l; c++) {
    if(isalpha(str[c])){ 
      postfix += str[c];
    }
    if(isdigit(str[c])){ 
      postfix += str[c];
    }
    switch(str[c]){
      case('^'):
        stk.push('^');
        break;
      case '+': case '-': case '*': case '/':
        while(stk.top() != 'e' && percedence(str[c]) <=  percedence(stk.top())) { 
          char c = stk.top(); 
          stk.pop(); 
          postfix += c; 
        } 
        stk.push(str[c]);
        break;
      case ('('):
        stk.push('(');
        break;
      case(')'):
        while(stk.top() != 'e' && stk.top() != '(') { 
          char c = stk.top(); 
          stk.pop(); 
          postfix += c; 
        } 
        if(stk.top() == '(') { 
          char c = stk.top(); 
          stk.pop(); 
        }
    }
  }
    
  while(stk.top() != 'e') 
    { 
        char c = stk.top(); 
        stk.pop(); 
        postfix += c; 
    }
    cout << "postFix " << postfix << endl; 
}
int main(){
  string str = "a+b*(c+d)";
  char c;
  convertToPostfix(str);
}