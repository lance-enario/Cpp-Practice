#include <iostream>
#include <cmath>
#include "node.hpp"
#include "AVL.hpp"
using namespace std;

class AVL_Tree : AVL {

    node* root;

    int getBalanceFactor(node* z){
        if (!z) return 0;

        int leftHeight = (z->left) ? z->left->height : -1;
        int rightHeight = (z->right) ? z->right->height : -1;

        return rightHeight - leftHeight;
    }


    node* zigRight(node* x){
        if (!x || !x->parent || !x->parent->parent) {
            return nullptr;
        }

        node* y = x->parent;
        node* z = y->parent;
        node* z_parent = z->parent;

        bool isRoot = (z==root);
        bool isZLeftChild = (z_parent && z_parent->left == z);

        //parent connections
        y->parent = z_parent;
        z->parent = y;

        //if y has a child on the left
        if (y->left){
            //connect child from y to z 
            z->right = y->left;
            y->left->parent = z;
        } else {
            //set as nullptr if no child
            z->right = nullptr;
        }
        
        // finishes connection to z (z as left child of y)
        y->left = z;

        if (isRoot){
            root = y;
        } else if (z_parent) {
            if (isZLeftChild){
                z_parent->left = y;
            } else {
                z_parent->right = y;
            }
        }
        
        updateHeights(z);

        return y;
    }

    node* zigLeft(node* x){
        if (!x || !x->parent || !x->parent->parent) {
            return nullptr;
        }

        node* y = x->parent;
        node* z = y->parent;
        node* z_parent = z->parent;

        bool isRoot = (z==root);
        bool isZLeftChild = (z_parent && z_parent->left == z);

        y->parent = z_parent;
        z->parent = y;

        if (y->right){
            z->left = y->right;
            y->right->parent = z;
        } else {
            z->left = nullptr;
        }

        y->right = z;

        if (isRoot){
            root = y;
        } else if (z_parent) {
            if (isZLeftChild){
                z_parent->left = y;
            } else {
                z_parent->right = y;
            }
        }
        
        updateHeights(z);

        return y;
    }

    void updateHeights(node* n){
        if (n == nullptr){
            return;
        }

        int leftHeight;
        int rightHeight;

        if (n->left){
            leftHeight = n->left->height;
        } else {
            leftHeight = -1;
        }

        if (n->right){
            rightHeight = n->right->height;
        } else {
            rightHeight = -1;
        }

        n->height = 1 + max(leftHeight, rightHeight);

        if (n != root){
            updateHeights(n->parent);
        }
    }


    public:
    AVL_Tree(){

    }
    
    void insert(int data){
        if (!root){
            root = new node;
            root->data = data;
            root->left = nullptr;
            root->right = nullptr;
            root->parent = nullptr;
        } else {
            node* curr = root;
            
            while(true){
                if (data < curr->data){
                    if (curr->left == nullptr){
                        break;
                    } 
                    curr = curr->left; 
                } else if (data > curr->data){
                    if (curr->right == nullptr){
                        break;
                    } 
                    curr = curr->right;
                } else {
                    return;
                }
            }

            node* n = new node;
            n->data = data;
            n->height = 0;

            if (data < curr->data){
                curr->left = n;
                n->parent = curr;
                n->left = nullptr;
                n->right = nullptr;
            } else if (data > curr->data){
                curr->right = n;
                n->parent = curr;
                n->left = nullptr;
                n->right = nullptr;
            }

            updateHeights(n);
            
            if (n->parent){
                restructure(n->parent);
            }
        }
    }

    node* remove(int data) {
        // Find the node to remove
        node* curr = root;
        while (curr != nullptr) {
            if (data == curr->data) {
                break;
            } else if (data < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        
        // Node not found
        if (curr == nullptr) {
            return nullptr;
        }
        
        // Store the parent before removing
        node* parent = curr->parent;
        
        // Case 1: Leaf node
        if (!curr->left && !curr->right) {
            // If this is the root
            if (curr == root) {
                root = nullptr;
            } else {
                // Update parent's pointer
                if (parent->left == curr) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            }
            delete curr;
        }
        // Case 2: Node with only one child
        else if (!curr->left || !curr->right) {
            node* child = curr->left ? curr->left : curr->right;
            
            // If this is the root
            if (curr == root) {
                root = child;
                child->parent = nullptr;
            } else {
                // Update parent's pointer
                if (parent->left == curr) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
                
                // Update child's pointer
                child->parent = parent;
            }
            delete curr;
        }
        // Case 3: Node with two children
        else {
            // Find successor (smallest value in right subtree)
            node* successor = curr->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            
            // Copy successor's data
            curr->data = successor->data;
            
            // Store successor's parent for rebalancing later
            node* successorParent = successor->parent;
            
            // Remove successor (it has at most one right child)
            if (successor->parent->left == successor) {
                successor->parent->left = successor->right;
            } else {
                successor->parent->right = successor->right;
            }
            
            if (successor->right) {
                successor->right->parent = successor->parent;
            }
            
            // Reset parent for restructuring - it will be the node that had successor as child
            if (successorParent != curr) {
                parent = successorParent;
            }
            
            delete successor;
        }
        
        // Update heights and rebalance
        if (parent) {
            updateHeights(parent);
            restructure(parent);
        } else if (root) {
            updateHeights(root);
            restructure(root);
        }
        
        return parent;
    }

    bool search(int data){

    }

    void print(){

    }

    void restructure(node* z){
        int balFact = getBalanceFactor(z); 

        // right heavy
        if (balFact >= 2){
            node* y = z->right;

            //checks for child of y to do zig operations on based on right heavy or left heavy status
            // right heavy
            if (getBalanceFactor(y) >= 1){
                if (y->right){
                    zigLeft(y->right);
                } else {
                    zigLeft(y);
                }
            } else {
            // left heavy
                if (y->left){
                    node* x = y->left;
                    node* newY = zigRight(x);
                    if (newY) zigLeft(newY);
                }
            }

        // left heavy
        } else if (balFact <= -2){
            node* y = z->left;

            if (getBalanceFactor(y) <= -1){
                if (y->left){
                    zigRight(y->left);
                } else {
                    zigRight(y);
                }
            } else {
                if (y->right){
                    node* x = y->right;
                    node* newY = zigLeft(x);
                    if (newY) zigRight(newY);
                }
            }
        }

        updateHeights(z);

        if (z->parent && (getBalanceFactor(z->parent) <= -2 || getBalanceFactor(z->parent) >= 2)){
            restructure(z->parent);    
        }
    }




};