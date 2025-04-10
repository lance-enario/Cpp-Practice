#include "node.hpp"

class AVL {
    public:
    virtual void insert(int data) = 0;
    virtual node* remove(int data) = 0;
    virtual bool search(int data) = 0;
    virtual void print() = 0;
    virtual void restructure(node* z) = 0;
};