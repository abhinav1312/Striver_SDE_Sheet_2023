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

int atoi(string str) {
    int ans = 0;
    int minusIndex = -1;
    int firstDigitIndex = -1;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '-') minusIndex = i;
        else if(str[i] - '0' >=0 && str[i] - '0' <= 9){
            if(ans == 0) firstDigitIndex = i;
            ans = ans*10 + (str[i]-'0');
        }
    }

    if(minusIndex == -1) return ans;
    else if(firstDigitIndex > minusIndex) return 0-ans;
    return ans;
}

int main()
{
    return 0;
}