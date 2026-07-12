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

// Delete node
Node* deleteNode(Node *head, int key) {

    // Agar head hi delete karna ho
    if (head == NULL)
        return NULL;

    if (head->data == key) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // Node nahi mili
    if (curr == NULL) {
        cout << "Node not found!" << endl;
        return head;
    }

    prev->next = curr->next;
    delete curr;

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

    // 10 -> 20 -> 30 -> 40
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before Deletion: ";
    print(head);

    head = deleteNode(head, 30);

    cout << "After Deletion: ";
    print(head);

    return 0;
}