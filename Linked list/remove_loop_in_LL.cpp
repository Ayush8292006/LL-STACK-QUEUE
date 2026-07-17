#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// Remove Loop
void removeLoop(Node* head){

    if(head == NULL || head->next == NULL)
        return;

    Node *slow = head, *fast = head;

    // Step 1: Detect Loop
    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    // No Loop
    if(fast == NULL || fast->next == NULL)
        return;

    // Step 2: Loop starts at head
    slow = head;

    if(slow == fast){

        while(fast->next != slow){
            fast = fast->next;
        }

        fast->next = NULL;
        return;
    }

    // Step 3: Loop starts somewhere else
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    // Step 4: Remove Loop
    fast->next = NULL;
}

// Print Linked List
void print(Node* head){

    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create Loop : 5 -> 3
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    cout << "Linked List after removing loop:\n";
    print(head);

    return 0;
}