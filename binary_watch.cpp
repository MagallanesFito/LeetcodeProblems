#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> res;
//4 para hrs
//6 para minutos
int numDigits = 10;
//set digits to 0
bool digits[10];
int currentDigits =0;
vector<string> nums = {"0","1","2","3","4","5","6","7","8","9"};

string hourstoString(int h){
    string res = "";
    if(h<10){
        string a = nums[h];
        return a;
    }
    if(h==10) return "10";
    return "11";
}
string minutestoString(int m){
   if(m<10){
     return "0" + nums[m];
   }
   return nums[m/10] + nums[m%10];
}
void processResponse(){
    int hrs = 8*digits[0] + 4*digits[1] + 2*digits[2] + digits[3];
    int mins = 32*digits[4] + 16*digits[5] + 8*digits[6] + 4*digits[7] + 2*digits[8] + digits[9];
    //ignore cases where hours are more than 11
    if(hrs>11 || mins>59){
        return;
    }

    string hours = hourstoString(hrs);
    string minutes= minutestoString(mins);
    res.push_back(hours + ":" + minutes);

}
void readBinaryWatchUtil(int n,int start){
    if(currentDigits==n){
        //printDigits();
        processResponse();
        return;
    }
    for(int i=start;i<numDigits;i++){
        digits[i] = true;
        currentDigits++;
        readBinaryWatchUtil(n,i+1);
        digits[i] = false;
        currentDigits--;
    }
}
vector<string> readBinaryWatch(int num) {
    readBinaryWatchUtil(num,0);
    return res;
}
int main(){
    vector<string> result = readBinaryWatch(1);

    for(auto x:result){
        cout << x << endl;
    }
    return 0;
}
