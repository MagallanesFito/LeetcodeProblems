#include<iostream>
#include<vector>
using namespace std;

int qpartition(vector<int> &lst,int lo,int hi){
    int pivot = lst[hi];
    int i = lo;
    for (int j = lo; j < hi; ++j) {
      if (lst[j] < pivot) {
        int tmp = lst[i];
        lst[i] = lst[j];
        lst[j] = tmp;
        i++;
      }
    }
    int tmp = lst[i];
    lst[i] = lst[hi];

    lst[hi] = tmp;
    return i;
}
void qsort(vector<int> &a,int lo,int hi){
    if(lo<hi){
        int p = qpartition(a,lo,hi);
        qsort(a,lo,p-1);
        qsort(a,p+1,hi);
    }
}
int partQuickSelect(vector<int>& a,int lo,int hi){
    int pivot = a[hi];
    int i = lo;
    for(int j=lo;j<hi;j++){
        if(a[j] < pivot){
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            i++;
        }

    }
    int tmp = a[i];
    a[i] = a[hi];
    a[hi] = tmp;
    return i;
}
//kth smallest element in array
int quickSelect(vector<int>& a,int lo,int hi, int k){
    if(lo>=hi) return a[lo];
        int pivot = partQuickSelect(a,lo,hi);
        if(k == pivot){
            return a[k];
        }
        else if(k<pivot){
            return quickSelect(a,lo,pivot-1,k);
        }
        else{
            return quickSelect(a,pivot+1,hi,k);
        }

}
int main(){
    vector<int> a = {5,4,1,2,3};
    int p = quickSelect(a,0,a.size()-1,0);
    //print ar
    //for(auto x:a) cout<< x << " ";
    cout << endl << p << endl;
    return 0;
}
