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
    Node* child;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};


Node* mergeTwoLists(Node* a, Node* b) {

    

    Node *temp = new Node(0);
    Node *res = temp; 
    while(a != NULL && b != NULL) {

        if(a->data < b->data) {

            temp->child = a; 

            temp = temp->child; 

            a = a->child; 

        }

        else {

            temp->child = b;

            temp = temp->child; 

            b = b->child; 

        }

    }

    

    if(a) temp->child = a; 

    else temp->child = b; 

    

    return res -> child; 

    

}

Node* flattenLinkedList(Node* head) 

{

    if(head == NULL || head->next == NULL) return head;

 

    Node* L2 = flattenLinkedList(head->next);

    head->next = NULL;

    Node* nhead = mergeTwoLists(head, L2);

    return nhead;

}

int main()
{
    return 0;
}