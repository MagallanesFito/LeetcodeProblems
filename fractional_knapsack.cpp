#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//custom coparator sorting
struct compare{
    inline bool operator()(const vector<int>& v1, const vector<int>& v2){
        //pair value/weight
        if((double)v1[1]/(double)v1[0] < (double)v2[1]/(double)v2[0]) return true;
        return false;
    }
};
/*sort the items by ratio value/weitght, then one by one add them up until no more space available.
Then add a fraction of the item that completes the weight*/
double fractionalKnapsack(vector<vector<int>> items,int w){
    sort(items.begin(),items.end(),compare());
    int curweight = 0;
    double finalValue = 0.0;

    for(int i=0;i<items.size();i++){
        if(curweight + items[i][1] <= w){
            curweight += items[i][1];

            finalValue += items[i][0];
        }
        else{
            int remain = w-curweight;
            finalValue += items[i][0]*((double)remain/(double)items[i][1]);
            break;
        }
    }
    return finalValue;
}
int main(){
    //value 0
    //weight 1
    vector<vector<int>> items = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int w = 50; // weight capacity
    cout << fractionalKnapsack(items,w) << endl;
    return 0;
}

