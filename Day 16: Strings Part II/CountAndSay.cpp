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

string lookAndSaySequence(int n) 
{
    if(n==1) return "1";
    string prev = lookAndSaySequence(n-1);

    string res = "";
    int cnt = 1;
    
    for(int i=1; i<prev.size(); i++){
        if(prev[i] == prev[i-1]) cnt++;
        else{
            res += to_string(cnt) + prev[i-1];
            cnt = 1;
        }
    }

    res += to_string(cnt) + prev[prev.size()-1];

    return res;
}

int main()
{
    return 0;
}