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

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


bool detectCycle(Node *head)
{
	Node* slow = head;
	Node* fast = head;

    while(fast != NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) return true;
    }

    return false;
}

int main()
{
    return 0;
}