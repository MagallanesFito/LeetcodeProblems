#include<iostream>
#include<vector>
using namespace std;

const int BOARD_SIZE = 9;
vector<vector<char>> res;
bool valid(vector<vector<char>> board,int pos,int k){
    int r = pos/BOARD_SIZE;
    int c = pos%BOARD_SIZE;
    char currchar = 48+k;
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[r][i] == currchar) return false;
    }
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i][c] == currchar) return false;
    }
    int row = pos/BOARD_SIZE;
    int col = pos%BOARD_SIZE;
    int nrow = 3*(row/3);
    int ncol = 3*(col/3);

    for(int i=nrow;i<=nrow+2;i++){
        for(int j=ncol;j<=ncol+2;j++){
            if(board[i][j] == currchar) return false;
        }
    }
    return true;
}
void printBoard(vector<vector<char>> board){
      for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
//origen,destino
void copyBoard(vector<vector<char>> board){
    for(int i=0;i<board.size();i++){
        vector<char> cur;
        for(int j=0;j<board[0].size();j++){
            cur.push_back(board[i][j]);
        }
        res.push_back(cur);
    }
}
void solveSudokuUtil(vector<vector<char>>& board,int pos){
    if(pos == BOARD_SIZE*BOARD_SIZE){
        copyBoard(board);//printBoard(board);
        return;
    }

      /*while(board[pos/BOARD_SIZE][pos%BOARD_SIZE] != '.'){

        cout << pos << endl;
        pos++;
        if(pos==BOARD_SIZE*BOARD_SIZE-1) break;
      }*/


    //cout << pos << endl;
    if(board[pos/BOARD_SIZE][pos%BOARD_SIZE] != '.'){
        solveSudokuUtil(board,pos+1);
    }
    else{
        for(int i=1;i<=BOARD_SIZE;i++){
        if(valid(board,pos,i)){
            board[pos/BOARD_SIZE][pos%BOARD_SIZE] = 48+i;
            solveSudokuUtil(board,pos+1);
            //printBoard(board);
            //return;

            board[pos/BOARD_SIZE][pos%BOARD_SIZE] = '.';
        }
    }
    }

}
void solveSudoku(vector<vector<char>>& board) {
  solveSudokuUtil(board,0);
  for(int i=0;i<res.size();i++){
        vector<char> cur;
        for(int j=0;j<res[0].size();j++){
            board[i][j] = res[i][j];
        }
        //res.push_back(cur);
    }
  //printBoard(board);
    //board = t;
}
int main(){
    vector<vector<char>> t = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    /*for(int i=0;i<t.size();i++){
        for(int j=0;j<t[0].size();j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }*/
    solveSudoku(t);
    //printBoard(t);

    return 0;
}


