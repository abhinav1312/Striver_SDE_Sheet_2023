#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
using namespace std;

bool isValidParenthesis(string s)
{   
    stack<char> st;
    for(auto ch : s){
        if(
            ch == '[' ||
            ch == '(' ||
            ch == '{' 
        ){
            st.push(ch);
        } else {
            if(st.empty()) return false;
          if ((ch == ']' && st.top() != '[') ||
              (ch == '}' && st.top() != '{') ||
              (ch == ')' && st.top() != '(') 
          ){
              return false;
          }
          else{
              st.pop();
          }

        }
    }

    return st.empty();
}

int main()
{
    return 0;
}