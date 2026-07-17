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

void printDLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main(){

    int arr[5] = {1,2,3,4,5};

    Node* head = NULL;

    for(int i=0;i<5;i++){

        if(head == NULL){
            head = new Node(arr[i]);
        }
        else{
            Node* temp = new Node(arr[i]);

            temp->next = head;
            head->prev = temp;

            head = temp;
        }
    }

    printDLL(head);

    return 0;
}