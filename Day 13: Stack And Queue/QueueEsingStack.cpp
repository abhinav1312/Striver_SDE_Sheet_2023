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

class MyQueue {
public:

    stack<int> st;

    void pushUtil(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }

        int topElem = st.top();
        st.pop();
        pushUtil(st, x);
        st.push(topElem);
    }

    MyQueue() {
    }
    
    void push(int x) {
        pushUtil(st, x);    
    }
    
    int pop() {
        int topElem = st.top();
        st.pop();
        return topElem;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    return 0;
}