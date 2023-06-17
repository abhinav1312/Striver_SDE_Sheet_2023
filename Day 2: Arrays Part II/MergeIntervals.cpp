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


vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int> > ans;
        
    // intervals empty
    if(!intervals.size()) return ans;

    // sort the interval
    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]); // push first interval

    int cnt = 0; // keep index reference of the latest added interval in the ans
    for(int i=1; i<intervals.size(); i++){

        vector<int> lastInterval = ans[cnt]; // most current interval in the ans
        int startingTimeLast = lastInterval[0];
        int endingTimeLast = lastInterval[1];

        vector<int> currInterval = intervals[i]; // currrent interval of the traversing 'intervals'
        int startingTimeCurr = currInterval[0];
        int endingTimeCurr = currInterval[1];

        if(endingTimeLast >= startingTimeCurr){
            ans[cnt][1] = max(endingTimeCurr, endingTimeLast); // doing max in case of test case like [[1, 4], [2, 3]] where if we dont do max, the ans returned would be [1, 3] which will be wrong
        }
        else{
            ans.push_back(currInterval);
            cnt++;
        }
    }

    return ans;

}


int main()
{
    return 0;
}