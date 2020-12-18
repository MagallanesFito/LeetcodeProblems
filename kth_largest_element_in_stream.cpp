#include<iostream>
#include<queue>
using namespace std;

class KthLargest{
public:
    int k1;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for(auto e:nums){
            pq.push(e);
        }
        while(pq.size()>k){
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }

};
int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    cout << pq.top() << endl;
    return 0;
}
