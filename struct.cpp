#include <iostream> 
using namespace std;

typedef struct {
    char name[50];
    char email [50];
}User;

int main () {
    User u;


    cout << "Enter name: ";
    cin >> u.name;
    cout << "Enter email: ";
    cin >> u.email;

    cout << u.name;
    cout << u.email;
}