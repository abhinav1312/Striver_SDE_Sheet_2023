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

Node* helper(Node *head, int n, int b[], int &i){
	if(!head || !head->next || i>=n) return head;
	if(b[i] == 1){
		i++;
		Node* newHead = helper(head->next, n, b, i);
		head->next = newHead;
		return head;
	}
	if(b[i] == 0){
		i++;
		return helper(head, n, b, i);
	};

	Node* temp = head;
	Node* curr= head;
	Node* forw = NULL;
	Node* prev = NULL;
	
	int cnt = 0;

	while(curr && cnt<b[i]){
		forw = curr->next;
		curr->next = prev;
		prev = curr;
		curr = forw;
		cnt++;
	}
	i++;
	Node* newHead = helper(curr, n, b, i);
	temp->next = newHead;
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	int i=0;
	return helper(head, n, b, i);
}

int main()
{
    return 0;
}