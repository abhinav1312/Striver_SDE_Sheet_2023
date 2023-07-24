#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<string>
#include <algorithm> 
vector<int> buildLPS(string str){
    int n = str.size();
    vector<int> lps(n, 0);
    for(int i=1; i<n; i++){
        int j = lps[i-1];
        while(j>0 && str[i] != str[j]) j = lps[j-1];
        if(str[i] == str[j]) j++;
        lps[i] = j;
    }
    return lps;
}

int minCharsforPalindrome(string str) {
    int n = str.size();
	string rev = str;
    reverse(rev.begin(), rev.end());
    
    str = str + '$' + rev;

    vector<int> lps =  buildLPS(str);

    int ans = n - lps[lps.size()-1];
    return ans;
	
}

using namespace std;
int main()
{
    return 0;
}