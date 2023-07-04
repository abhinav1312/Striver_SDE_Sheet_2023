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

int findMinimumCoins(int amount) 
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int minCoins = 0, i = coins.size()-1;
    while(amount != 0){
        minCoins = minCoins + amount/coins[i];
        amount = amount%coins[i];
        i--;
    }

    return minCoins;
}


int main()
{
    int amount = 1300;
    int ans = findMinimumCoins(amount);
    cout<<ans<<endl;
    return 0;
}