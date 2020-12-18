#include<iostream>
#include<vector>
#include<map>
using namespace std;

void printVector(vector<int> v){
    for(auto x:v) cout << x << " ";
    cout << endl;
}
int candy(vector<int>& ratings) {

   vector<int> b(ratings.size(),1);

   for(int i=1;i<ratings.size();i++){
      if(ratings[i] > ratings[i-1]){
        b[i] = b[i-1] + 1;
      }
   }
   for(int i=ratings.size()-2;i>=0;i--){
     if(ratings[i] > ratings[i+1]){
        b[i] = max(b[i],b[i+1]+1);
     }
   }
   int sum = 0;
   for(auto x:b) sum+=x;
   return sum;
}

int main(){
    vector<int> a = {0};
    int res=  candy(a);
    cout << res << endl;
    return 0;
}
