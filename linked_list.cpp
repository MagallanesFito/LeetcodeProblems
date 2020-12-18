#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode* start){
    //ListNode* start = head;
    while(start!=NULL){
        cout<< start->val << " ";
        start = start->next;
    }
    cout << endl;
}
ListNode* sortedMerge(ListNode* a,ListNode* b){
    ListNode* result = NULL;

    if(a==NULL) return(b);
    else if(b==NULL) return(a);

    if(a->val <= b->val){
        result = a;
        result->next = sortedMerge(a->next,b);
    }
    else{
        result = b;
        result->next = sortedMerge(a,b->next);
    }
    return result;
}
void frontBackSplit(ListNode* source,ListNode** frontRef,ListNode** backRef){
    ListNode* fast;
    ListNode* slow;

    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void mergeSort(ListNode** headref){
    ListNode* head = *headref;
    //printList(head);
    ListNode* a;
    ListNode* b;

    if((head == NULL) || (head->next == NULL)){
        return;
    }
    frontBackSplit(head,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    *headref = sortedMerge(a,b);


}
ListNode* sortList(ListNode* head){
    mergeSort(&head);
    return head;
}
int main(){
    ListNode* head = new ListNode(4);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(1);
    ListNode* finale = new ListNode(3);

    head->next = second;
    second->next = third;
    third->next = finale;
    finale->next = NULL;


    ListNode* node = sortList(head);
    printList(node);
    return 0;
}
