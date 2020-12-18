#include<iostream>
#include<cmath>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void push(ListNode** head_ref, int new_data){
    ListNode* new_node = new ListNode();
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
long a= 0;
int p = 0;
long getNumber(ListNode* head){
    if(head!=NULL){
        getNumber(head->next);
        a+=(head->val*(long)pow(10,p));
        p++;
    }
    return a;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

}
void printList(ListNode* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);
    head->next->next->next = new ListNode(9);

    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next = new ListNode(9);

    head->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(9);



    ListNode* head2 = new ListNode(7);
    //head2->next = new ListNode(6);
    //head2->next->next = new ListNode(4);
    //head->next->next->next = new ListNode(3);
    cout << getNumber(head);
    //ListNode* res = addTwoNumbers(head,head2);
    //printList(res);
    //cout << res << endl;
    //cout << reverseInt(res) << endl;
    return 0;
}
