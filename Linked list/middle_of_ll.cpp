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

class Solution {
public:

    // ------------------ Method 1 : Using Length ------------------

    int getLength(ListNode* head) {
        int len = 0;

        while (head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* middleNode_Length(ListNode* head) {

        int len = getLength(head);
        int mid = len / 2;

        ListNode* temp = head;

        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp;
    }

    // ------------------ Method 2 : Slow & Fast Pointer ------------------

    ListNode* middleNode_SlowFast(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Print Linked List
void print(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Linked List: ";
    print(head);

    Solution obj;

    // Method 1
    ListNode* ans1 = obj.middleNode_Length(head);
    cout << "Middle Node (Length Method): " << ans1->val << endl;

    // Method 2
    ListNode* ans2 = obj.middleNode_SlowFast(head);
    cout << "Middle Node (Slow & Fast Method): " << ans2->val << endl;

    return 0;
}