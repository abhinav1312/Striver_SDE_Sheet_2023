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

Node* sortTwoLists(Node* first, Node* second)
{
    if(!first && !second) return NULL;
        if(first && !second) return first;
        if(!first && second) return second;

        Node* dummyNode = new Node(-1);
        Node* tail = dummyNode;

        // keep two pointers at heads of the lists
        Node* head1 = first;
        Node* head2 = second;

        while(head1 && head2){
            if(head1->data <= head2->data){
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            }
            else{
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
        }

        while(head1){
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }

         while(head2){
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }

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
    Node* head1 = new Node(1);
    head1->next = new Node(2);

    Node* head2 = new Node(3);
    head2->next = new Node(4);

    Node* newHead = sortTwoLists(head1, head2);
    print(newHead);
    return 0;
}