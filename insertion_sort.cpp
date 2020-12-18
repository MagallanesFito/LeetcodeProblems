#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertionSort(vector<int>& A){

    for(int i=1;i<A.size();i++){
        int j = i;
        while(j>0 && A[j-1] > A[j]){
            int tmp = A[j-1];
            A[j-1] = A[j];
            A[j] = tmp;
            j--;
        }

    }
}
void printArray(vector<int> a){
    for(auto x:a) cout << x << " ";
    cout << endl;
}
int main(){
    vector<int> a = { 12, 11, 13, 5, 6 };
    insertionSort(a);
    printArray(a);
    return 0;
}


