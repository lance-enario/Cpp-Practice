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

    void addHead (int num){
        node* n = (node*) calloc (1, sizeof(node));
        n->elem = num;
        n->next = head;
        head = n;
        cout << num << " added is now the head" << '\n';
        size++;
    }

    void addAt(int num, int pos){
        if (pos == 0){
            return addAtHead(num);
        } else if (pos == size){
            return add(num);
        } else if (pos > size){
            cout << "Position is out of bounds from current size of List" << '\n';
            return;
        }

        node* curr = head;
        node* previous;
        int ctr = 0;
        while (ctr < pos){
            previous = curr;
            curr = curr->next;
            ctr++;
        } 
            node* n = (node*)calloc(1,sizeof(node));
            n->elem = num;
            previous->next = n;
            n->next = curr;
            size++;
    }

    void removeAt(int pos){
        node* curr = head;
        node* previous;
        int i = 0;
        while (i < pos){
            previous = curr;
            curr = curr->next;
            i++;
        }
        previous->next = curr->next;
        free(curr);
        curr = curr->next;
        size--;
    }

    int removeHead(){
        node* temp = head;
        int num = head->elem;
        head = head->next;
        free(temp);
        cout << "Removed " << num << " at head" << '\n';
        size--;
        return num;
    }

    void removeTail(){
        node* curr = head;
        while (curr->next != tail){
            curr = curr->next;
        } 
            free(curr->next);
            tail = curr;
            tail->next = NULL; 
            size--;
            cout << "Tail removed" << '\n';
    }

    void remove(int num){
        node* curr = head;
        node* previous;

        while (curr->elem != num){
            previous = curr;
            curr = curr->next;
        }

        previous->next = curr->next;
        free(curr);
        size--;
        cout << "Removed " << num <<'\n';
    }

    void removeDuplicates(int num){
        int dupCount = 0;
        node* curr = head;
        node* previous;

            while (curr != NULL){  
                if (curr->elem == num){
                    remove(num);
                    curr = previous;
                    dupCount++;
                }
                previous = curr;
                curr = curr->next;
            }

        cout << "Removed " << dupCount << " duplicates of " << num <<'\n';
    }

    void reverse(){
        node* previous = head;
        node* curr = head;
        node* next = head->next;
        while (curr != NULL){
            next = curr->next;
            curr->next = previous;
            previous = curr;
            curr = next;
        }
        tail = head;
        head = previous;
        tail->next = NULL;
    }

    void sort(){
        node* curr = head;
        node* temp = curr;
        int ctr = size;
        int i = 0;

        while (ctr != 0){
            while (i != ctr){
                if (curr->elem < temp->elem){
                    temp = curr;
                }
                curr = curr->next;
                i++;
            }

            add(temp->elem);
            remove(temp->elem);
            curr = head;
            temp = curr;
            ctr--;
            i=0;
        }
         
    }

    int get (int pos){

    }

};