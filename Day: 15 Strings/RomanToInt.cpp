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

int romanToInt(string s) {
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int prev = 0, ans =0;

    for(auto ch : s){
        ans += m[ch];
        if(prev < m[ch]) ans -= 2*prev;
        prev=m[ch];
    }

    return ans;
}

int main()
{
    return 0;
}