#include <iostream>
#include <vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

// Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* left, ListNode* right){

    if(left == NULL) return right;
    if(right == NULL) return left;

    ListNode* ans = new ListNode(-1);
    ListNode* mptr = ans;

    while(left && right){

        if(left->val <= right->val){
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else{
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    while(left){
        mptr->next = left;
        mptr = left;
        left = left->next;
    }

    while(right){
        mptr->next = right;
        mptr = right;
        right = right->next;
    }

    return ans->next;
}

// Divide & Conquer
ListNode* merge(vector<ListNode*>& arr, int start, int end){

    if(start == end)
        return arr[start];

    int mid = start + (end - start) / 2;

    ListNode* head1 = merge(arr, start, mid);
    ListNode* head2 = merge(arr, mid + 1, end);

    return mergeTwoLists(head1, head2);
}

// Merge K Lists
ListNode* mergeKLists(vector<ListNode*>& lists){

    if(lists.size() == 0)
        return NULL;

    return merge(lists, 0, lists.size() - 1);
}

// Print List
void printList(ListNode* head){

    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){

    // List 1 : 1 -> 4 -> 7
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);

    // List 2 : 2 -> 5 -> 8
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(8);

    // List 3 : 3 -> 6 -> 9
    ListNode* l3 = new ListNode(3);
    l3->next = new ListNode(6);
    l3->next->next = new ListNode(9);

    vector<ListNode*> lists;

    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode* ans = mergeKLists(lists);

    printList(ans);

    return 0;
}