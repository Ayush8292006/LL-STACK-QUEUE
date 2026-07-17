#include<iostream>

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

    int arr[5]= {1,2,3,4,5};

    Node* head=NULL;
    Node* tail=NULL;

    for(int i=0;i<5;i++){
        if(!head) {
            head=new Node(arr[i]);
            tail=head;
        }
        else{
            Node* temp = new Node(arr[i]);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    printDLL(head);
}