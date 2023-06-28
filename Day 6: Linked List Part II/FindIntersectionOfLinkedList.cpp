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

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(ListNode* head){
    ListNode* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        while(tempA->next) tempA = tempA->next;
        tempA->next = headA;

        ListNode* slow = headB;
        ListNode* fast = headB;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) break;
        }

        if(fast == NULL || fast -> next == NULL){
            tempA->next = NULL;
            return NULL;
        } 

        slow = headB;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        tempA->next = NULL;
        return slow;
    }
};


int main()
{
    
    return 0;
}