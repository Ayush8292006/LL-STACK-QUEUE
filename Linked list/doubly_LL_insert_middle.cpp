#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int value){
        val = value;
        next = prev = NULL;
    }
};

// Print DLL
void printDLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at Beginning
void insertAtHead(Node* &head, Node* &tail, int value){

    Node* newNode = new Node(value);

    if(head == NULL){
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at End
void insertAtTail(Node* &head, Node* &tail, int value){

    Node* newNode = new Node(value);

    if(head == NULL){
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Insert at Any Position
void insertAtPosition(Node* &head, Node* &tail, int pos, int value){

    // Beginning
    if(pos == 1){
        insertAtHead(head, tail, value);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1 && temp->next != NULL){
        temp = temp->next;
        cnt++;
    }

    // End
    if(temp->next == NULL){
        insertAtTail(head, tail, value);
        return;
    }

    // Middle
    Node* newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

int main(){

    int arr[5] = {1,2,3,4,5};

    Node* head = NULL;
    Node* tail = NULL;

    // Create DLL
    for(int i=0;i<5;i++){

        if(head == NULL){
            head = new Node(arr[i]);
            tail = head;
        }
        else{
            Node* temp = new Node(arr[i]);

            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    cout << "Original DLL : ";
    printDLL(head);

    insertAtHead(head, tail, 100);
    cout << "After Insert At Head : ";
    printDLL(head);

    insertAtTail(head, tail, 200);
    cout << "After Insert At Tail : ";
    printDLL(head);

    insertAtPosition(head, tail, 4, 300);
    cout << "After Insert At Position 4 : ";
    printDLL(head);

    return 0;
}