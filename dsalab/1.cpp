#include <bits/stdc++.h>
using namespace std;

class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);
        LLNode* createWithIterators(int arr1[] , int n);
        void printList(LLNode* head);
};
void printList(LLNode* head){
    while(head){
        cout << head ->val << " ";
        head = head -> next;
    }
}
LLNode* createWithIterators(int arr[] , int n){
    LLNode* head = new LLNode(arr[0], nullptr);
    LLNode* p = head;
    for(int i = 1; i < n; i++){
        LLNode* temp = new LLNode(arr[i], nullptr);
        p -> next = temp;
        p = p ->next;
    }
    return head;
}
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    if(!l0 && !l1) return nullptr;
    if(!l0) return l1;
    if(!l1) return l0;
    int nho = 0;
    LLNode* p0 = l0;
    LLNode* p1 = l1;
    LLNode* p2 = new LLNode(-1, nullptr);
    LLNode* phead = p2;
    while(p0 || p1){
        if(!p0){
            while(p1){
                int sum = p1->val + nho;
                nho = 0;
                if(sum <= 9){
                    LLNode* temp = new LLNode(sum, nullptr);
                    p2 -> next = temp;
                    p2 = p2 ->next;
                    p1 = p1->next;
                }else{
                    nho = sum - 9;
                    sum -= nho;
                    LLNode* temp = new LLNode(sum, nullptr);
                    p2 -> next = temp;
                    p2 = p2 ->next;
                    p1 = p1->next;
                }
            }
        }
        if(!p1){
            while(p0){
                int sum = p0->val + nho;
                nho = 0;
                if(sum <= 9){
                    LLNode* temp = new LLNode(sum, nullptr);
                    p2 -> next = temp;
                    p2 = p2 ->next;
                    p0 = p0->next;
                }else{
                    nho = 1;
                    sum -= 10;
                    LLNode* temp = new LLNode(sum, nullptr);
                    p2 -> next = temp;
                    p2 = p2 ->next;
                    p0 = p0->next;
                }
            }
        }
        int sum = p0->val + p1->val + nho;
        nho = 0;
        if(sum <= 9){
            LLNode* temp = new LLNode(sum, nullptr);
            p2 -> next = temp;
            p2 = p2 ->next;
            p0 = p0->next;
            p1 = p1->next;
        }
        else if(sum > 9){
            nho = 1;
            sum -= 10;
            LLNode* temp = new LLNode(sum, nullptr);
            p2 -> next = temp;
            p2 = p2 ->next;
            p0 = p0->next;
            p1 = p1->next;
        }
    }
    if(nho > 0){
        LLNode* temp = new LLNode(nho, nullptr);
        p2 -> next = temp;
        p2 = p2->next;
        nho = 0;
    }
    return phead ->next;
}
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    LLNode* res = NULL;
    LLNode *temp, *head = NULL;
    int carry = 0, sum = 0;
    while(l0 || l1){
        int a1 = (l0 ? l0->val : 0), a2 = (l1 ? l1->val : 0);
        sum = carry + a1+ a2;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new LLNode(sum, nullptr);
        if (res == NULL) {
            res = temp;
            head = res;
        }
        else
            res->next = temp;
        if (l0)
            l0 = l0->next;
        if (l1)
            l1 = l1->next;
        
    }
    if (carry > 0)
        temp->next = new LLNode(carry, nullptr);
        return res;
}

int main(){
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode* head1 = createWithIterators(arr1, 2);
    LLNode* head2 = createWithIterators(arr2, 2);
    LLNode* newhead = addLinkedList(head1, head2);
    printList(newhead);
}