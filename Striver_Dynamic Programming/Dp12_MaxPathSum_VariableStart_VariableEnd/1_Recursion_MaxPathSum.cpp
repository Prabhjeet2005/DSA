#include <iostream>
#include <vector>
using namespace std;

int maxPathSum(int row,int col,vector<vector<int>>&path){
  if(col < 0 || col >= path[0].size()){
    return -1e9;
  }
  if(row == 0 ){
    return path[row][col];
  }
  // Ques tell go down or downLeft or DownRight So while calling Recusion we can do opposite
  int up = path[row][col] + maxPathSum(row-1,col,path);
  int upLeft = path[row][col] + maxPathSum(row-1,col-1,path);
  int upRight = path[row][col] + maxPathSum(row-1,col+1,path);

  return max(up,max(upLeft,upRight));
}

int main()
{
  // Variable Start Point, Variable End Point
  vector<vector<int>> mat = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
  int rowSize = mat.size();
  int colSize = mat[0].size();

  int maxi = INT_MIN;
  for(int i = 0; i<colSize; i++){
    int ans = maxPathSum(rowSize-1,i,mat);
    maxi = max(maxi,ans);
  }
  cout<<"Maximum Path Sum: "<<maxi<<endl;
}