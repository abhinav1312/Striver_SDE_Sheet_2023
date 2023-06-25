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

void insertAtTail(Node* &tail, int data){
    Node* node = new Node(data);

    tail->next = node;
    tail = tail->next;
}

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // base cases
    if(!num1 && !num2) return 0;
    if(num1 && !num2) return num1;
    if(!num1 && num2) return num2;

    // reverse the linked list
    Node* revHead1 = num1;
    Node* revHead2 = num2;

    Node* dummyNode = new Node(-1);
    Node* tail = dummyNode;
    int carry = 0;
    
    while(revHead1 && revHead2){
        int num1 = revHead1->data;
        int num2 = revHead2->data;
        int sum = num1 + num2 + carry;

        insertAtTail(tail, sum%10);
        carry = sum/10;

        revHead1 = revHead1->next;
        revHead2 = revHead2->next;
    }

    while(revHead1){
        int sum = carry + revHead1->data;
        insertAtTail(tail, sum%10);
        carry = sum/10;
        revHead1 = revHead1->next;
    }

    while(revHead2){
        int sum = carry + revHead2->data;
        insertAtTail(tail, sum%10);
        carry = sum/10;
        revHead2 = revHead2->next;
    }

    if(carry) insertAtTail(tail, carry);

    return dummyNode->next;

}

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head1 = new Node(9);
    Node* head2 = new Node(9);

    Node* ans = addTwoNumbers(head1, head2);
    cout<<"Sum in reverse order: "<<endl;
    print(ans);
    return 0;
}