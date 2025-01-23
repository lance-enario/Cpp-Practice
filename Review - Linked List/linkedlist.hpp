#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public List{
    node* head;
    node* tail;
    int size;

    node* add_between (int elem, node* pred, node* succ){
        //    1    1
        node* n = new node;
        //      1
        n->elem = elem;
        //      1
        n->next = succ;
        //      1
        n->prev = pred;
        //         1
        pred->next = n;
        //         1
        succ->prev = n;
        // 1  
        size++;
        return n;

        // T(n) = 8
    }

    void remove_node(node* n){
        //         1
        node* pred = n->prev;
        //         1
        node* succ = n->next;
        //         1
        pred->next = succ;
        //         1
        succ->prev = pred;
        //  1
        size--;
        //  1
        delete n;

        // T(n) = 6
    }

    public:
    LinkedList(){
        head = new node;
        tail = new node;
        head->next = tail;
        tail->next = head;
        size = 0;
    }

    void addHead(int num){
        add_between(num, head, head->next);
    }

    void addTail(int num){
        add_between(num, tail->prev, tail);
    }

    void insert(int num, int pos){
        node* curr = head;
        int ctr = 1;
        while (ctr < pos){
            curr = curr->next;
            ctr++;
        }

        add_between(num, curr, curr->next);
    }
    int getHead(){
        return head->elem;
    }

    int getTail(){
        return tail->elem;
    }

    void removeHead(){
        remove_node(head->next);
    }

    void removeTail(){
        remove_node(tail->prev);
    }

    void getSize(){

    }

    void print(){
        cout << "FROM HEAD: ";
        node* curr = head->next;
        while(curr != tail){
            cout << curr->elem << " -> ";
            curr = curr->next;
        }
        cout << '\n';

        cout << "FROM TAIL: ";
        curr = tail->prev;
        while(curr != head){
            cout << curr->elem << " <- ";
            curr = curr->prev;
        }
        cout << '\n';
    }
};