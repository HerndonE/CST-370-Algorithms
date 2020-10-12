// A simple implementation of a binary tree with "struct" in C++.
// It displays all nodes using the inorder traversal.
// Written by EIR and Dr. Byun for CST370.

#include <iostream>
#include<string>

using namespace std;

struct Node 
{
	// Data part for a node. 
    int data;
    Node* left;
    Node* right;

    // Constructor for a new node.
    Node(int d) 
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};


Node* mkTree(int data, Node* left, Node* right) 
{
    Node* root = new Node(data);
    root->left = left;
    root->right = right;
    return root;
}


void inorder(Node* root) 
{
    if (root != nullptr)  // Or simply "if (root)"
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}


// A sample main to create a binary tree like below.
//       5
//      / \
//     3   4
//    / \
//   1   2
//
int main() 
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = mkTree(3, n1, n2);
    Node* n4 = new Node(4);
    Node* n5 = mkTree(5, n3, n4);
    
    inorder(n5);
    
    return 0;
}


