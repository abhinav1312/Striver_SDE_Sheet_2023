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

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<vector<int> > v; 
    // v[i][0] = end, v[i][1] = start, v[i][2]= meeting number

    for(int i=0; i<start.size(); i++){
        v.push_back({end[i], i+1, start[i]});
    }

    // sort according to finish time
    sort(v.begin(), v.end());

    vector<int> ans;
    int prevMeetEndTime = -1;
    
    for(int i=0; i<v.size(); i++){
        int endTime = v[i][0];
        int startTime = v[i][2];
        int meetNum = v[i][1];
        if(startTime > prevMeetEndTime){
            ans.push_back(meetNum);
            prevMeetEndTime = endTime;
        } 

    }
    return ans;
}

int main()
{
    return 0;
}