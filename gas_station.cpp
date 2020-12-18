#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int currCost=0;
    int currGas = 0;
    int currSpent= 0;
    int start = 0;
    for(int i=0;i<gas.size();i++){
        currCost += cost[i];
        currGas  += gas[i];
        currSpent += (gas[i]-cost[i]);
        if(currSpent < 0){
            currSpent = 0;
            start = i+1;
        }
    }
    //not possible to complete circuit when cost > available gas
    if(currCost > currGas) return -1;
    return start;
}
int main(){
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    int res = canCompleteCircuit(gas,cost);
    cout << res << endl;
    return 0;
}



