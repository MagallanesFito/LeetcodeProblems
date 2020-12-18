#include<iostream>
#include<vector>
using namespace std;

vector<vector<string>> sols;
bool attack(vector<vector<char>> table,int row,int col,int n){
    //for rows
    for(int i=0;i<n;i++){
        if(table[i][col] == 'Q') return false;
    }
    //for cols
    for(int i=0;i<n;i++){
        if(table[row][i] == 'Q') return false;
    }
    int i = row;
    int j = col;
    //caso 3
    while(i>=0 && j>=0){
        if(table[i][j] == 'Q') return false;
        i--;
        j--;
    }
    i = row;
    j = col;
    //caso 2
    while(i<n && j<n){
        if(table[i][j] == 'Q') return false;
        i++;
        j++;
    }

    i=row;
    j=col;
    //caso 1
    while(i>=0 && j<n){
        if(table[i][j] == 'Q') return false;
        i--;
        j++;
    }
    i=row;
    j=col;
    //caso 4
    while(i<n && j>=0){
        if(table[i][j] == 'Q') return false;
        i++;
        j--;
    }
    return true;
}
void appendToSols(vector<vector<char>> table){
    vector<string> current;
    for(int i=0;i<table.size();i++){
        string cur = "";
        for(int j=0;j<table.size();j++){
            cur+=table[i][j];
        }
        current.push_back(cur);
    }
    sols.push_back(current);
}
void solveNQueens(vector<vector<char>> table,int n,int start){
    if(start==n){
        appendToSols(table);
        //printBoard(table);
        return;
    }
    bool res = false;
    for(int i=0;i<n;i++){
        if(attack(table,start,i,n)){
            table[start][i] = 'Q';
            solveNQueens(table,n,start+1);
            table[start][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
  vector<vector<char>> table;
  for(int i=0;i<n;i++){
    vector<char> curr;
    for(int j=0;j<n;j++){
        curr.push_back('.');
    }
    table.push_back(curr);
  }
  solveNQueens(table,n,0);
  return sols;
}
int main(){
    vector<vector<string>> solutions  =totalNQueens(4);
    cout << solutions.size() << endl;
    return 0;
}
