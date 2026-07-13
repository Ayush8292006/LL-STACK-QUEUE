#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head == NULL || head->next == NULL)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {
                return true;            // Cycle Found
            }
        }

        return false;                   // No Cycle
    }
};

int main() {

    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Create linked list
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle
    fourth->next = second;
   

    Solution obj;

    if (obj.hasCycle(head))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}