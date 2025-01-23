#include <iostream>
#include <cmath>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
    int* arr = (int*) calloc (capacity, sizeof(int)); 
    int capacity;
    int size = 0;

    void increase_capacity(){
        //       1
        capacity *= 1.5;
        //  1           1                   1
        arr = (int*) realloc (arr, capacity * sizeof(int));

        // T(n) = 4
    }

    void decrease_capacity(){
        //       1    1          1
        capacity = floor(capacity*.80);
        //  1           1                   1
        arr = (int*) realloc (arr, capacity * sizeof(int));

        // T(n) = 6
    }

    public:
    ArrayList(){
        capacity = 5;
        arr = (int*) calloc (capacity, sizeof(int));
    }

    void addLast(int num){
        if (num < 0){
            throw logic_error("YOUR INPUT IS WRONG AF");
        }

        if (size >= capacity){
            increase_capacity();
        }
        arr[size] = num;
        size++;
    }

    void addAt(int num, int pos){
        if (num < 0 || pos < 0 || pos > size){
            throw logic_error("YOUR INPUT IS WRONG AF");
        }

        if (size >= capacity){
            increase_capacity();
        }

        size++;
        for (int i = size; i>pos; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = num;
        return;
    }

    int removeAt(int pos){
        //      1     1
        int ret = arr[pos];
        //         1          size-pos-1    n
        for (int i = pos; i<size-1; i++){
        //      n  n      n  
            arr[i] = arr[i+1];
        }
        // 1
        --size;
        return ret;
    }

    int remove(int num){
        int pos;
        for (int i = 0; i<size; i++){
            if (num == arr[i]){
                pos = i;
                break;
            }
        }
        removeAt(pos);
        return pos;
    }

	bool isEmpty(){

        return false;
    }

    int size_(){

        return size;
    }

    int get(int pos){

        return 0;
    }

	void print(){
        cout << "Elements in the Array: " << '\n';
        for (int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
};