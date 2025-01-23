#include <iostream>
#include "linkedlist.hpp"
using namespace std;

int main (){
    LinkedList* list = new LinkedList();
    char choice;
    int num, pos;

    do {
        cout << "Linked List Operations" << '\n';
        cout << "Select choice: ";
        cin >> choice;
        switch (choice){
            case 'a':
                cout << "Enter number to add to Head: ";
                cin >> num;
                list->addHead(num);
                break;
            case 'A':
                cout << "Enter number to add to Tail: ";
                cin >> num;
                list->addTail(num);
                break;
            case 'i':
                cout << "Enter number to insert: ";
                cin >> num;
                cout << "Enter position to insert at: ";
                cin >> pos;
                list->insert(num, pos);
                break;
            case 'r':
                cout << "Removing head";
                list->removeHead();
                break;
            case 'R':
                cout << "Removing tail";
                list->removeTail();
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout << "Goodbye!";
                break;
        }
    } while (choice != 'x');



}
