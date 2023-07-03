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

bool comparator(vector<int> a, vector<int> b){
    if(a[1] > b[1]) return true;
    return false;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int maxDeadline = 0;
    int maxProfit = 0;
    for(int i=0; i<jobs.size(); i++){
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }
    
    vector<int> v(maxDeadline+1, 0);

    sort(jobs.begin(), jobs.end(), comparator);

    for(int i=0; i<jobs.size(); i++){
        int deadline = jobs[i][0];
        int profit = jobs[i][1];

        if (!v[deadline]) {
          maxProfit += profit;
          v[deadline] = 1;
        }

        else{
            while(deadline > 0 && v[deadline] != 0) deadline--;
            if(deadline != 0){
                maxProfit += profit;
                v[deadline] = 1;
            }
        }
    }

    return maxProfit;
}


int main()
{
    return 0;
}