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

class minStack
{
	// Write your code here.
	stack<pair<int, int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty()){
				st.push({num, num});
			}
			else{
				if(st.top().second > num){
					st.push({num, num});
				}
				else{
					st.push({num, st.top().second});
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty()) return -1;
			int temp = st.top().first;
			st.pop();
			return temp;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty()) return -1;
			int temp = st.top().first;
			return temp;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty()) return -1;
			int temp = st.top().second;
			return temp;
		}
};

int main()
{
    return 0;
}