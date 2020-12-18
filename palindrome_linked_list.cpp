#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* first;
bool res = true;
void isPalindromeUtil(ListNode* head){
    if(head==NULL){
        return;
    }
    else{
        isPalindromeUtil(head->next);
        int tmp = first->val;
        first = first->next;
        cout << "first: " << tmp << " head: " << head->val <<endl;
        if(tmp == head->val){
            return true;
        }
        return false;
    }
    return false;
}
bool isPalindrome(ListNode* head) {
    first = head;
    return isPalindromeUtil(head);
}
void printList(ListNode* root){
    while(root!=NULL){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}
int main(){
    ListNode* root = new ListNode(1);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(1);
    cout << isPalindrome(root) << endl;
    //printList(root);
    return 0;
}
