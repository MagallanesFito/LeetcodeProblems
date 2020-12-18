#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* insertionSortList(ListNode* head) {
 ListNode* i = head;
 while(i != NULL){
    ListNode* j = i->next;
    while(j!=NULL){
        if(i->val > j->val){
            int tmp = i->val;
            i->val = j->val;
            j->val = tmp;
        }
        j = j->next;
    }
    i = i->next;
 }
 return head;
}
void printList(ListNode* head){
    ListNode* cur = head;
    while(cur != NULL){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main(){
    ListNode* head = NULL;
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(1);
    //head->next->next->next = new ListNode(3);

    ListNode* sorted = insertionSortList(head);
    printList(head);
    return 0;
}


