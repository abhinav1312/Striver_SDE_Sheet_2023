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

int maximumProfit(vector<int> &prices){
    int maxPrf = 0;
    int leastPrice = INT_MAX;
    for(int i=0; i<prices.size(); i++){
        leastPrice = min(leastPrice, prices[i]);
        int currProfit = prices[i] - leastPrice;
        maxPrf = max(maxPrf, currProfit);
    }

    return maxPrf;
}

int main()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(4);
    int maxPrf = maximumProfit(prices);
    cout<<maxPrf<<endl;
    return 0;
}