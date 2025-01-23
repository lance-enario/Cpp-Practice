#include <iostream>
#include "arraylist.hpp"
using namespace std;

int main (){
    ArrayList* list = new ArrayList();
    char choice;
    int num, pos;

    do {
        cout << "Array Operations" << '\n';
        cout << "Select choice: ";
        cin >> choice;
        switch (choice){
            case 'a':
                cout << "Enter number to add to array: ";
                cin >> num;
                list->addLast(num);
                break;
            case 'A':
                cout << "Enter number to add: ";
                cin >> num;
                cout << "Enter position for adding: ";
                cin >> pos;
                list->addAt(num, pos);
                break;
            case 'r':
                cout << "Enter number to remove: ";
                cin >> num;
                list->remove(num);
                break;
            case 'R':
                cout << "Enter position for removal: ";
                cin >> pos;
                list->removeAt(pos);
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
