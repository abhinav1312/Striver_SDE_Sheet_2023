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

string longestPalinSubstring(string str)
{
    int s = 0, e = 0; // initial indices of the palindromic string
    int n = str.size();
    
    for(int i=1; i<n; i++){
        // odd length substring with str[i] as center
        int l = i-1;
        int r = i+1;
        while(l>=0 && r<n && str[l] == str[r]){
            if((r+1-l) > (e+1-s)){
                s = l;
                e = r;
            }
            l--; r++;
        }

        // even length with str[i] as left mid
        l=i;
        r = i+1;
        while(l>=0 && r<n && str[l] == str[r]){
            if((r+1-l) > (e+1-s)){
                s = l;
                e = r;
            }
            l--; r++;
        }
    }

    return str.substr(s, e+1-s);
}

int main()
{
    return 0;
}