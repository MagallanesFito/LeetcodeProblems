#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> a = {1,2,6,9,9,3,5,9};

    int max_ = -10000;
    for(int i=0;i<a.size();i++){
        if(a[i] > max_) max_ = a[i];
    }
    int freq[max_+1];
    for(int i=0;i<max_+1;i++) freq[i] = 0;
    for(int i=0;i<a.size();i++){
        freq[a[i]]++;
    }
    int index =0;
    for(int i=0;i<max_+1;i++){
      while(freq[i]>0){
        a[index++] = i;
        //cout << i << " ";
        freq[i]--;
      }
    }
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }

    //Increasing order
    /*sort(a.begin(),a.end());

    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
    //Decreasing order
    sort(a.rbegin(),a.rend());

    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }*/

    return 0;
}
