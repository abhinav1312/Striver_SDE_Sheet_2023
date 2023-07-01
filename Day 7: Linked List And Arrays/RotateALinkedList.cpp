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
    int val;
    Node* next;
    Node* random;

    Node(int data){
        this->val = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int findSize(Node* head){
     if(!head) return 0;

     int cnt = 0;
     Node* temp = head;
     while(temp){
          temp = temp->next;
          cnt++;
     }

     return cnt;
}


Node *rotate(Node *head, int k) {
     if(!head || !head->next) return head;
     
     // find size of LL
     int n = findSize(head);
     k = k%n;
     if(k==0) return head;

     // reach n-k th position
     int cnt = 1;
     Node* temp = head;
     while(cnt < n-k){
          temp = temp->next;
          cnt++;
     }

     // save the next node
     Node* newShiftedHead = temp->next;
     temp->next = NULL;

     // reach the tail of the new head to join to head
     Node* tail = newShiftedHead;
     while(tail->next){
          tail = tail->next;
     }

     // join tail to previous head
     tail->next = head;

     // shift head pinter to new head
     head = newShiftedHead;
     return head;
}

int main()
{
    return 0;
}