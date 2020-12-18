#include<iostream>
#include<vector>
using namespace std;

int dp[102][102];
void printDp(int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[0][0] == 1) return 0;

    obstacleGrid[0][0]  =1;
    for(int i=1;i<m;i++){
       if(obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] ==1){
        obstacleGrid[i][0] =1;
       }
       else{
       obstacleGrid[i][0] =0;
       }
    }
    for(int i=1;i<n;i++){
        if(obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 1){
            obstacleGrid[0][i] =1;
        }
        else{
            obstacleGrid[0][i] = 0;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(!obstacleGrid[i][j]) obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            else obstacleGrid[i][j] = 0;
        }
    }
    return obstacleGrid[m-1][n-1];
}

//MAKE BACKTRACKING (too slow)
/*int numpaths = 0;
bool visited[102][102];
void uniquePathsUtil(vector<vector<int>> grid,int startRow,int startCol,int finishRow,int finishCol){
    int m = grid.size();
    int n = grid[0].size();
    if(startRow == finishRow && startCol == finishCol){
        numpaths++;
        return;
    }
    visited[startRow][startCol] = true;
    //right

    int newRowRight = startRow + 0;
    int newColRight = startCol + 1;
    if(newRowRight<m && newColRight<n && grid[newRowRight][newColRight] != 1){
        if(!visited[newRowRight][newColRight]){
            //visited[newRowRight][newColRight] = true;
            uniquePathsUtil(grid,newRowRight,newColRight,finishRow,finishCol);

        }
    }
    //visited[startRow][startCol] = false;
    //down
    int newRowDown =  startRow+1;
    int newColDown = startCol+0;
    if(newRowDown < m && newColDown<n && grid[newRowDown][newColDown] != 1){
        if(!visited[newRowDown][newColDown]){
            //visited[newRowDown][newColDown] = true;
            uniquePathsUtil(grid,newRowDown,newColDown,finishRow,finishCol);

        }
    }
    visited[startRow][startCol] = false;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int startRow = 0;
    int startCol = 0;
    int finishRow = obstacleGrid.size()-1;
    int finishCol = obstacleGrid[0].size()-1;
    if(obstacleGrid[0][0] == 1) return 0;
    if(startRow == finishRow && startCol == finishCol){
        return !obstacleGrid[startRow][startCol];
    }
    uniquePathsUtil(obstacleGrid,startRow,startCol,finishRow,finishCol);
    for(int i=0;i<=finishRow;i++){
        for(int j=0;j<=finishCol;j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    return numpaths;
}*/
int main(){
    vector<vector<int>> grid = {{0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,0}};
    int res = uniquePathsWithObstacles(grid);
    cout << res << endl;
    return 0;
}

