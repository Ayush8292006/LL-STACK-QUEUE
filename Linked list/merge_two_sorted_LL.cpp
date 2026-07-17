#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {

        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(left && right){
            if(left->val < right->val){
                mptr->next = left;
                mptr=left;
                left = left->next;
            }else{
                mptr->next = right;
                mptr = right;
                right = right->next;

            }
        }
        while(left){
            mptr->next = left;
            mptr=left;
            left = left->next;
        }
         while(right){
            mptr->next = right;
            mptr=right;
            right = right->next;
        }
        return ans->next;
    }


// Print Linked List
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    // First List : 1 -> 3 -> 5
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);

    // Second List : 2 -> 4 -> 6
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(6);


    ListNode* ans = mergeTwoLists(head1, head2);

    cout << "Merged List : ";
    printList(ans);

    return 0;
}