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

bool issafe(int row,int col,int board[][9],int c){
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == c)
      return false;
    if (board[i][col] == c)
      return false;
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
    return true;

}
bool solve(int board[][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == 0){
                for(int c = 1; c<=9; c++){
                    if(issafe(i,j,board,c) == true){
                        board[i][j] = c;
                        if(solve(board) == true)
                        return true;
                        else
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

 

bool sudokuSolver(int board[][9]) {
    return solve(board); 
}

int main()
{
    return 0;
}