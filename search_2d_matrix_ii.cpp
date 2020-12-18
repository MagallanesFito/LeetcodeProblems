#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(int row,vector<vector<int>> matrix,int target){
    int l=0;
    int r = matrix[0].size()-1;
    while(l<r){
        int m = l + (r-l)/2;
        if(matrix[row][m] == target) return true;
        if(matrix[row][m] > target){
            r =m;
        }
        else{
            l = m+1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0) return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m-1;

    while(i<n && j>=0){
        if(matrix[i][j] == target) return true;
        if(matrix[i][j] > target){
           j--;
        }
        else{
          i++;
        }
    }
    return false;
}
/*bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i=0;i<matrix.size();i++){
        //search in current row
        if(binarySearch(i,matrix,target)) return true;
    }
    return false;
}*/

int main(){
    /*
    {{1,3,4,5,7,7,12,13},{2,7,12,17,17,19,23,25},{6,11,12,21,26,27,30,30},{6,13,17,24,28,33,38,43},{10,15,21,25,33,33,43,44},{10,19,25,28,36,36,45,50},{11,22,26,28,37,41,50,52},{13,22,29,29,42,46,54,55}}*/
    vector<vector<int>> m = {{1,3,4,5,7,7,12,13},{2,7,12,17,17,19,23,25},{6,11,12,21,26,27,30,30},{6,13,17,24,28,33,38,43},{10,15,21,25,33,33,43,44},{10,19,25,28,36,36,45,50},{11,22,26,28,37,41,50,52},{13,22,29,29,42,46,54,55}};
    cout << searchMatrix(m,19);
    return 0;
}
