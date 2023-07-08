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

bool isPalindrome(string &s, int start, int end){
    while(start <= end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void helper(int idx, string s, vector<string> &substring, vector<vector<string> > &ans){
    if(idx >= s.size()){
        ans.push_back(substring);
    }

    for(int i=idx; i<s.size(); i++){
        if(isPalindrome(s, idx, i)){
            substring.push_back(s.substr(idx, i+1-idx));
            helper(i+1, s, substring, ans);
            substring.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > ans;
    vector<string> substring;
    helper(0, s, substring, ans);
    return ans;

}


int main()
{
    return 0;
}