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

// Insert after a particular node value
void insertAfter(Node *head, int key, int value) {

    Node *temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node not found!" << endl;
        return;
    }

    Node *newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
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

    // 20 ke baad 25 insert karo
    insertAfter(head, 20, 25);

    cout << "After Insertion: ";
    print(head);

    return 0;
}