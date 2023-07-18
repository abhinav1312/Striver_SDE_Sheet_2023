#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int> >& grid) {
        // find the rotten orange
        int rotCol=-1, rotRow=-1;
        int rowSize = grid.size();
        int colSize = grid[0].size();

        cout<<"Rowsize: "<<rowSize<<" colsize: "<<colSize<<endl;
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(grid[i][j] == 2){
                    rotCol = j;
                    rotRow = i;
                    break;
                }
            }
        }

        // no rotten roanges
        if(rotCol == -1 || rotRow == -1){
            cout<<"Answer from here"<<endl;
            return 0;
        } 


        // store <row col>
        queue<pair<int, int> > q;
        q.push(make_pair(rotRow, rotCol));
        int ans = 0;
        cout<<"Row: "<<rotRow<<" Col: "<<rotCol<<" pushed"<<endl;

        while(!q.empty()){
            int size = q.size();
            cout<<"Size: "<<size<<endl;
            bool flag = 0;
            for(int i=0; i<size; i++){
                pair<int, int> front = q.front();
                int row = front.first;
                int col = front.second;
                q.pop();
                cout<<"Row: "<<row<<" Col: "<<col<<" popped"<<endl;

                // go down
                 if((row+1)<rowSize && grid[row+1][col] != 0 && grid[row+1][col] != 2){
                    q.push(make_pair(row+1, col));
                    // if()
                    cout<<"Row: "<<row+1<<" Col: "<<col<<" pushed"<<endl;
                    grid[row+1][col] = 2;
                    flag = 1;
                }

                // go left
                 if(col-1>=0 && grid[row][col-1] != 0 && grid[row][col-1] != 2){
                    q.push(make_pair(row, col-1));
                    cout<<"Row: "<<row<<" Col: "<<col-1<<" pushed"<<endl;
                    grid[row][col-1] = 2;
                    flag = 1;
                }

                // go right
                if((col+1)<colSize){
                    if(grid[row][col+1] == 1){
                        q.push(make_pair(row, col+1));
                        cout<<"Row: col+1 "<<row<<" Col: "<<col+1<<" pushed"<<endl;
                        grid[row][col+1] = 2;
                        flag = 1;
                    }
                }

                // go up
                 if(row-1>=0 && grid[row-1][col] != 0 && grid[row-1][col] != 2){
                    q.push(make_pair(row-1, col));
                    cout<<"Row: "<<row-1<<" Col: "<<col<<" pushed"<<endl;
                    grid[row-1][col] = 2;
                    flag = 1;
                }

            }
            if(flag){
                ans++;
                cout<<"ans: "<<ans<<endl;
            } 
        }


        cout<<"Out of loppp"<<endl;
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int> > v;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(2);
    v.push_back(temp);

    Solution s;
    cout<<s.orangesRotting(v)<<endl;

    return 0;
}