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

int combination(int N, int r){
	long long den = 1, num=1;
	while(r>0){
		den = den*r;
		num = num*N;
		r--;
		N--;
	}

	return num/den;
}

int uniquePaths(int m, int n) {
	int totalDirections = n+m-2;
	int rightDirections = n-1;

	int uniquePaths = combination(totalDirections, rightDirections);
	return uniquePaths;
	
}

int main()
{   
    int ans = uniquePaths(2, 3);
    cout<<ans<<endl;
    
    return 0;
}