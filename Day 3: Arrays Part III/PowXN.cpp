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

double pow(int x, int n){
    double ans = 1;
    int absVal = abs(n);
    while(absVal){
        if(absVal&1){
            ans = ans*x;
        }

        x=x*x;
        absVal = absVal>>1;
    }
    if(n<0) return 1/ans;
    return ans;
}

int main()
{
    cout<<pow(2, -2)<<endl;
    return 0;
}