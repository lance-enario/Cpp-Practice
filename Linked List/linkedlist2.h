#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;

class LinkedList : public List {
    node* head;
    node* tail;
    
    int size;

    public:
    void add (int num){
        if (head == NULL){
            cout << "Adding " << num << " as head" << '\n';
            head = new node;
            head->elem = num;
            head->next = NULL;
            tail = head;
            size++;
        } else {
            cout << "Adding " << num << '\n';
            node* n = (node*) calloc(1, sizeof(node)); // creates new node
            n->elem = num;  // assigns value to created node
            tail->next = n; // used to connect the previous tail to this newly created note
            tail = n; // new node becomes tail of list 
            size++;
        }
    }

    void print (){ // used for traversal from head to tail
        node* curr = head;
        if (size == 0){
            cout << "yes";
            return;
        }
        cout << "First element: " << head->elem << '\n';
        cout << "Last element: " << tail->elem << '\n';
        while (curr != NULL){
            cout << curr->elem << " -> ";
            curr = curr->next;
        } 
        cout << '\n';
    }
};
