#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Reverse Linked List
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Remove Nodes
    ListNode* removeNodes(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        // Step 1: Reverse
        head = reverse(head);

        int maxVal = head->val;
        ListNode* curr = head;

        // Step 2: Delete smaller nodes
        while (curr != NULL && curr->next != NULL) {

            if (curr->next->val < maxVal) {

                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;      

            } else {

                curr = curr->next;
                maxVal = curr->val;
            }
        }

        // Step 3: Reverse Again
        return reverse(head);
    }
};

// Print Linked List
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.removeNodes(head);

    cout << "After Removing Nodes: ";
    printList(head);

    return 0;
}