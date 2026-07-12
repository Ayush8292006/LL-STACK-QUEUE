#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert before a particular node value
Node* insertBefore(Node *head, int key, int value) {

    // Agar first node ke pehle insert karna ho
    if (head != NULL && head->data == key) {
        Node *newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Node not found!" << endl;
        return head;
    }

    Node *newNode = new Node(value);

    newNode->next = curr;
    prev->next = newNode;

    return head;
}

// Print Linked List
void print(Node *head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // 10 -> 20 -> 30
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Before Insertion: ";
    print(head);

    // 20 ke pehle 25 insert karo
    head = insertBefore(head, 20, 25);

    cout << "After Insertion: ";
    print(head);

    return 0;
}