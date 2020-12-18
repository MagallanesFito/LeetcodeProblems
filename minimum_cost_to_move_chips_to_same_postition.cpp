#include<iostream>
#include<vector>
using namespace std;
//par,impar
int table[2];
int minCostToMoveChips(vector<int>& position) {
    for(int i=0;i<position.size();i++){
        //cuenta pares e impares.
        table[position[i] & 1]++;
    }
    //es mas barato trasladar menos monedas de un punto a otro.
    //convertir de par->impar o impar->par cuesta 1
    return min(table[0],table[1]);

}
int main(){
    vector<int> pos = {1,1000};
    int res=  minCostToMoveChips(pos);

    cout << res << endl;
    return 0;
}
