#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void deleteNode(ListNode* node) {
    ListNode *temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}

void print(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // 4 -> 5 -> 1 -> 9
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Before: ";
    print(head);

    // 5 ko delete karna hai
    deleteNode(head->next);

    cout << "After: ";
    print(head);

    return 0;
}