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


bool comparator(pair<int, int> p1, pair<int, int> p2){
    double valuePerWeightP1 = ((double)p1.second)/((double)p1.first);
    double valuePerWeightP2 = ((double)p2.second)/((double)p2.first);

    return valuePerWeightP1 > valuePerWeightP2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{

    sort(items.begin(), items.end(), comparator);

    double weight=0, value=0;
    int i=0; 
    while(i < n && weight < w){
        if(weight + items[i].first < w){
            weight += items[i].first;
            value += items[i].second;
            i++;
        }
        else{
            int reqWeight = w - weight;
            double itemWeight = items[i].first;
            double itemValue = items[i].second;
            double temp = (itemValue*reqWeight)/itemWeight;
            value += temp;
            break;
            
        }
    }

    return value;
}

int main()
{
    return 0;
}