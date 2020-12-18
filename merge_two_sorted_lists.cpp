#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  void printList(ListNode* head){
    while(head!= NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout<< endl;
  }
int main(){
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);


    printList(l1);
    printList(l2);
    return 0;
}


