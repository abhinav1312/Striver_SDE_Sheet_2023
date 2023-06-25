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

int uniqueSubstrings(string input)
{
    vector<int> arr(257, -1);
    int maxLen = 0, currLen = 0, startIndex = 0;

    for(int i=0; i<input.size(); i++){
        int ch  = input[i] - 0;

        if(arr[ch] == -1) currLen++;
        else{
            if(arr[ch] < startIndex) currLen++;
            else{
                startIndex = arr[ch] + 1;
                currLen = i+1-startIndex;
            }
        }

        arr[ch] = i;
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}

int main()
{
    string s = "abcaabcad";
    int ans = uniqueSubstrings(s);

    cout<<ans<<endl;
    return 0;
}