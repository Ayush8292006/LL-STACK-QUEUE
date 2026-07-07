#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){

    // -------------------------------
    // Static Allocation
    // -------------------------------

    // Node A1(4);

    // -------------------------------
    // Dynamic Allocation
    // -------------------------------

    // Node* Head;
    // Head = new Node(5);
    // cout << Head->data << endl;

    // -------------------------------
    // Insert at the Beginning
    // -------------------------------

    int arr[] = {1,2,3,4,5};

    // Linked List does not exist
    Node* Head = NULL;

    for(int i = 0; i < 5; i++){

        if(Head == NULL){
            Head = new Node(arr[i]);
        }

        // Linked List exists
        else{
            Node* temp = new Node(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }

    // -------------------------------
    // Print the Linked List
    // -------------------------------

    Node* temp = Head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}