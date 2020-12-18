#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> absolutePermutation(int n, int k) {
    vector<int> res;
    vector<int> resno;
    bool flag = false;
    for(int i=1;i<=n;i++){
        int ai1 = k+i;
        int ai2 = i-k;
        //cout << ai1 << " , " << ai2 << endl;
        if(ai1<=n){
            res.push_back(ai1);
        }
        else{
            if(ai2>0){
                res.push_back(ai2);
            }
            else{
                //cout << -1 << endl;
                flag= true;
                break;
            }
        }
    }
    if(flag){
        resno.push_back(-1);
        return resno;
    }
    return res;

}
int main(){
    /*
    2 1
3 0
3 2
    */
    vector<int> a = absolutePermutation(3,2);
    for(int i = 0 ;i<a.size();i++){
        cout << a[i] << " " << endl;
    }
    return 0;
}
