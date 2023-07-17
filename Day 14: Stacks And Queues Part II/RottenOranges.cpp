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

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // find the rotten orange
        int rotCol=-1, rotRow=-1;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    rotCol = i;
                    rotRow = j;
                    break;
                }
            }
        }

        // no rotten roanges
        if(rotCol == -1 || rotRow == -1){
            cout<<"Answer from here"<<endl;
            return 0;
        } 

        vector<vector<int> > visited(n, vector<int>(n, 0));
        // store <row col>
        queue<pair<int, int> > q;
        q.push({rotRow, rotCol});
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<int, int> front = q.front();
                int row = front.first;
                int col = front.second;
                q.pop();

                bool flag = 0;
                // go right
                if(col+1<n && visited[row][col+1] != 1 && grid[row][col+1] != 0 && grid[row][col+1] != 2){
                    q.push({row, col+1});
                    flag = 1;
                }

                // go down
                 if(row+1<n && visited[row+1][col] != 1 && grid[row+1][col] != 0 && grid[row+1][col] != 2){
                    q.push({row+1, col});
                    flag = 1;
                }

                // go left
                 if(col-1>=0 && visited[row][col-1] != 1 && grid[row][col-1] != 0 && grid[row][col-1] != 2){
                    q.push({row, col-1});
                    flag = 1;
                }

                // go up
                 if(row-1>=0 && visited[row-1][col] != 1 && grid[row-1][col] != 0 && grid[row-1][col] != 2){
                    q.push({row-1, col});
                    flag = 1;
                }

                if(flag) ans;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}