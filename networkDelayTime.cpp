#include<iostream>
#include<vector>
#include<pair>
#include<queue>
using namespace std;

const intintMax = 2<<32;
int networkDelayTime(vector<vector<int>>& times, int N, int K){
    vector<int> dist(N+1,intMax);
    dist[K]  =0;
    vector<vector<pair<int,int>>> adj(N+1);
    //[u,v,w]
    for(auto time:times){
        adj[time[0]].push_back({time[1],time[2]});
    }

    queue<pair<int,int>> q;
    q.push({K,0});

    while(!q.empty()){
        auto current = q.front();q.pop();
        int currNode = current.first;
        int currDist = current.second;

        for(auto nextNode : adj[currNode]){
            int newDist = currDist + nextNode.second;
            if(newDist < dist[nextNode.first]){
                dist[nextNode.first] = newDist;
                q.push({nextNode.first,nextNode.second + currDist});
            }
        }
    }
    int maxTime = 0;
    for(int i=1;i<=N;i++){
        if(dist[i] == intMax) return -1;
        maxTime = max(maxTime,dist[i]);
    }
    return maxTime;
}
int main(){
    return 0;
}
