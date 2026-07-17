#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


    // Reverse Linked List
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return true;

        // Find Middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse Second Half
        ListNode* secondHalf = reverse(slow->next);

        // Compare Both Halves
        ListNode* temp1 = head;
        ListNode* temp2 = secondHalf;

        while (temp2 != NULL) {
            if (temp1->val != temp2->val)
                return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }


int main() {

   
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

   

    if (isPalindrome(head))
        cout << "Palindrome Linked List" << endl;
    else
        cout << "Not a Palindrome Linked List" << endl;

    return 0;
}