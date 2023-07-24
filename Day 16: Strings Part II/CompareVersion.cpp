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

int compareVersions(string a, string b) 
{
    int i=0, j=0;
    while(i<a.size() || j<b.size()){
        long long x = 0;
        long long y = 0;

        while(i<a.size() && a[i] != '.') x = x*10 + (a[i++]-'0');
        while(j<b.size() && b[j] != '.') y = y*10 + (b[j++]-'0');

        if(x > y) return 1;
        else if(x < y) return -1;
        i++;
        j++;
    }

    return 0;
}

int main()
{
    return 0;
}