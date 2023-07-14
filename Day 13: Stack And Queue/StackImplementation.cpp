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
private:
    int *arr;
    int size;
    int topElem;

public:
    
    Stack(int capacity) {
        size = capacity;
        topElem = -1;
        arr = new int[size];
    }

    void push(int num) {
        if(topElem < size-1){
            topElem++;
            arr[topElem] = num;
        }
    }

    int pop() {
        if(topElem >= 0 ){
            int temp = arr[topElem];
            topElem--;
            return temp;
        }

        return -1;
    }
    
    int top() {
        if(topElem <= -1) return -1;
        return arr[topElem];
    }
    
    int isEmpty() {
        return topElem == -1;
    }
    
    int isFull() {
        return topElem == size-1;
    }
    
};


int main()
{
    return 0;
}