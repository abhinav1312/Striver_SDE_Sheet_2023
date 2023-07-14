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

class Stack {
	// Define the data members.
    private:
    queue<int> primaryQueue;
    queue<int> secQueue;

    public:
    Stack() {
        // Implement the Constructor.

    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return primaryQueue.size();
    }

    bool isEmpty() {
        return primaryQueue.empty();
    }

    void push(int element) {
        while(!primaryQueue.empty()){
            secQueue.push(primaryQueue.front());
            primaryQueue.pop();
        }

        primaryQueue.push(element);
        while(!secQueue.empty()){
            primaryQueue.push(secQueue.front());
            secQueue.pop();
        }
    }

    int pop() {
        if(primaryQueue.empty()) return -1;
        int top = primaryQueue.front();
        primaryQueue.pop();
        return top;
    }

    int top(){
        if(primaryQueue.empty()) return -1;
        return primaryQueue.front();
    }
};

int main()
{
    return 0;
}