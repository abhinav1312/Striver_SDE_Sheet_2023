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

void immediateSmaller(vector<int>& a)
{
	int smaller = -1;
	for(int i=a.size() -1; i>=0; i--){
		if(a[i] > smaller){
			int temp = a[i];
			a[i] = smaller;
			smaller = temp;
		}
		else{
			smaller = a[i];
			a[i] = -1;
		}
	}
}


int main()
{
    return 0;
}