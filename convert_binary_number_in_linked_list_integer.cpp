#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int getDecimalValue(ListNode* head) {
    int decimal = 0;
    while(head!=NULL){
        decimal = decimal | head->val;
        //cout << decimal << " ";
        decimal = (decimal<<1);
        head = head->next;
    }
    return decimal>>1;
}
int main(){
    ListNode* head = new ListNode(0);
    //head->next = new ListNode(1);
    //head->next->next = new ListNode(1);

    int res = getDecimalValue(head);
    cout << res;
    return 0;
}
