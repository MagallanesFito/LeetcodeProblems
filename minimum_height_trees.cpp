#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> res;
    if(n<=0) return res;
    if(n==1){
      res.push_back(0);
      return res;
    }
    vector<int> degree(n,0);
    vector<vector<int>> adjList;
    for(int i=0;i<n;i++){
        vector<int> curr;
        adjList.push_back(curr);
    }
    for(auto edge:edges){
        degree[edge[0]]++;
        degree[edge[1]]++;
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(degree[i]==1){
            q.push(i);
        }
    }
    while(n>2){
        int size_ = q.size();
        n-=size_;

        while(size_-->0){
            int v = q.front();
            q.pop();
            for(auto curr:adjList[v]){
                degree[curr]--;
                if(degree[curr]==1){
                    q.push(curr);
                }
            }
        }
    }
    while(!q.empty()){
        res.push_back(q.front());
        q.pop();
    }
    return res;
}
int main(){
    vector<vector<int>> v = {{0,1}};
    int n = 2;
    vector<int> res = findMinHeightTrees(n,v);

    for(auto x:res) cout << x << " ";
    cout << endl;
    return 0;
}
