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

Node *firstNode(Node *head)
{
    if(!head || !head->next) return NULL;
        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) break;
        }

        // loop broke because reached end
        if(slow != fast) return NULL;

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
}

int main()
{
    return 0;
}