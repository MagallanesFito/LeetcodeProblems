#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void print(vector<bool> a){
    for(auto x:a) cout << x << " ";
    cout << endl;
}
//try doing a standard bfs... this will give TLE.. try some greedy approach.. .
struct element{
    int index;
    int distance;
    element(int Index,int Distance){
        index = Index;
        distance = Distance;
    }

};
int jumpBfs(vector<int>& nums) {
    queue<element> q;
    vector<bool> visited(nums.size()+2,false);
    element nuevo(0,0);
    q.push(nuevo);

    while(!q.empty()){
        element actual =  q.front();
        if(actual.index == nums.size()-1) return actual.distance;
        q.pop();
        visited[actual.index] = true;

        for(int i=1;i<=nums[actual.index];i++){
            int currindex = actual.index+i;
            if(!visited[currindex]){
                element nuevoq(currindex,actual.distance+1);
                q.push(nuevoq);
            }
        }
    }
    return -1;
}
//use some dp here
/*int jumpRecursive(vector<int> nums,int start){
    if(start == 0) return 0;
    for()
}*/
//recursive approach

//optimized bfs leads to greedy algorithm
int jump(vector<int> nums){
    int steps = 0;
    int currpos = 0;
    int i= 0;
    int n = nums.size();
    //while(!q.empty)
    while(currpos < n-1){
        steps++;
        int tmppos = currpos;
        //check all possibilities.
        while(i<=tmppos){
            currpos = max(currpos,i+nums[i]);
            i++;
        }
    }
    return steps;
}

//greedy (similar as jump game 1
int jump2(vector<int> nums){
    int canreach = 0;
    int lasreach = 0;
    int steps = 0;
    for(int i=0;i<nums.size();i++){
        //update new maximum range
        if(i>lasreach){
            steps++;
            lasreach = canreach;
        }
        canreach = max(canreach,i+nums[i]);
    }
    //jump game 1
    if(nums[lasreach] == 0) return -1;
    return steps;
}
int main(){
    vector<int> nums  = {3,2,1,0,4};
    int res = jump2(nums);
    cout << res << endl;
    return 0;
}


