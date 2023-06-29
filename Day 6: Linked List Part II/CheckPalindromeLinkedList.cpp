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

template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

bool isPalindrome(LinkedListNode<int> *head) {
    LinkedListNode<int>* tempHead = head;
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    LinkedListNode<int>* curr = slow;
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* forw = NULL;

    while(curr){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    while(prev){
        if(prev->data != tempHead->data) return false;
        prev = prev->next;
        tempHead = tempHead->next;
    }

    return true;
}

int main()
{
    return 0;
}