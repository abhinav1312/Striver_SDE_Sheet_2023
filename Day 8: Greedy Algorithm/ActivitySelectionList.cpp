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

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int> > v;
    for(int i=0; i<start.size(); i++){
        v.push_back({finish[i], start[i]});
    }

    // sorting accoriding to finish time
    sort(v.begin(), v.end());
    int maxActivities = 1, lastActivityFinishTime = v[0].first;
    for(int i=1; i<v.size(); i++){
        if(v[i].second >= lastActivityFinishTime){
            maxActivities++;
            lastActivityFinishTime = v[i].first;
        }
    }
    return maxActivities;
}

int main()
{
    return 0;
}