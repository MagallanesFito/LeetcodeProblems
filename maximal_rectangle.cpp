#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> heights){
    stack<int> s;
    int i = 0;
    int maxArea = 0;
    int n = heights.size();
    while(i<n){
        if(s.empty() || heights[s.top()]<=heights[i]){
            s.push(i++);
        }
        else{
            int tp = s.top();
            s.pop();
            int area = 0;
            if(s.empty()){
                area = heights[tp]*i;
            }
            else{
                /*intervalo (no inclusivo) entre i y s.top...
                cada elemento que esta en la pila
                */
                area = heights[tp]*(i-s.top()-1);
            }
            //int area = heights[tp]*(s.empty()?i:i-s.top()-1);
            //cout << area << endl;
            maxArea = max(maxArea,area);
        }
    }
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        int area = 0;
        if(s.empty()){
            area = heights[tp]*i;
        }
        else{
            area= heights[tp]*(i-s.top()-1);
        }
        //area = heights[tp]*(s.empty()?i:i-s.top()-1);
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int aux[202][202];
int maximalRectangle(vector<vector<char>>& matrix) {
      if(matrix.size() == 0) return 0;
      int m = matrix.size();
      int n = matrix[0].size();
      int maxArea= 0;
      for(int i=0;i<n;i++){
         if(matrix[0][i] == '1') aux[0][i] = 1;
      }
      for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == '1'){
               int cur = matrix[i][j] - '0';
               aux[i][j] = aux[i-1][j] + cur;
            }
            else{
                aux[i][j] = 0;
            }
        }
      }

      for(int i=0;i<m;i++){
        vector<int> heights;
        for(int j=0;j<n;j++){
            heights.push_back(aux[i][j]);
        }
        int area = largestRectangleArea(heights);
        maxArea = max(maxArea,area);
      }
      /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<< aux[i][j] << " ";
        }
        cout << endl;
      }*/
      return maxArea;
}
int main(){
    vector<vector<char>> in = {{'1'}};
    int res= maximalRectangle(in);
    cout << res<< endl;
    return 0;
}

