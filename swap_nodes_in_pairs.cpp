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
void printList(ListNode* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout<< endl;
}
void printRecursiveList(ListNode* head){
    if(head==NULL){
        cout << endl;
    }
    else{
        cout<<head->val << " ";
        printRecursiveList(head->next);
    }
}
ListNode* swapPairs(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        int tmp = head->val;
        head->val = head->next->val;
        head->next->val = tmp;
        head->next->next = swapPairs(head->next->next);
        return head;
    }
}
int main(){
    ListNode* head = new ListNode(1);
    ListNode* n1 = new ListNode(2);
    ListNode* n2 =  new ListNode(3);
    ListNode* n3 =  new ListNode(4);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    ListNode* otherHead = swapPairs(head);
    printList(otherHead);
    return 0;

}
