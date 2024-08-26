#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
    int rows, columns, sum=0;
    
    cout << "Enter the number of rows: ";
    
    cin >> rows;
    
    cout << "Enter the number of columns: ";
    
    cin >> columns; 

    int arr[rows][columns];    

    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            cout << "Element at [" << i << "][" << j << "]: "; 
            cin >> arr[i][j];
        }
    }
        
    cout << "Averages of each row: "<< endl;
    
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            sum += arr[i][j]; 
        }
        cout << "Row "<< i+1 << ": "<< fixed << setprecision(2) << (float) sum / columns << endl;
        sum=0;
    }

}