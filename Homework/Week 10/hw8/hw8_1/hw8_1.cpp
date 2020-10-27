/*
 * Title: hw8_1.cpp
 * Abstract: A program that provides a few functions for a binary tree.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 10/29/2020
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

//Reference: https://www.geeksforgeeks.org/check-if-a-binary-tree-is-bst-simple-and-efficient-approach/
//           https://repl.it/@YBYUN/InorderTraversal#main.cpp
//           https://www.geeksforgeeks.org/height-complete-binary-tree-heap-n-nodes/

struct Node {
  // Data part for a node.
  int data;
  Node * left;
  Node * right;
  Node * parent;

  // Constructor for a new node.
  Node(int d) {
    data = d;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }
};

vector < Node * > nodes;
bool check = false;

void append(Node * root, int data) {
  if (!root) {
    return;
  }
  if (!root -> left) {
    Node * temp = new Node(data);
    root -> left = temp;
    temp -> parent = root;
    nodes.push_back(temp);
    check = true;
  } else if (!root -> right) {
    Node * temp = new Node(data);
    root -> right = temp;
    temp -> parent = root;
    nodes.push_back(temp);
    check = true;
  }
}

void inOrder(Node * root) {
  if (root == nullptr){ // Or simply "if (root)"
    return;
  }
  inOrder(root -> left);
  cout << root -> data << " ";
  inOrder(root -> right);
}

void preOrder(Node * root) {
  if (root == nullptr){
    return;
  }
  cout << root -> data << " ";
  preOrder(root -> left);
  preOrder(root -> right);

}

void postOrder(Node * root) {
  if (root == nullptr){
    return;
  }
  postOrder(root -> left);
  postOrder(root -> right);
  cout << root -> data << " ";

}

bool checkIfBST(Node * root, int & prev) {
  if (root) {
    if (!checkIfBST(root -> left, prev))
      return false;

    if (root -> data <= prev)
      return false;

    prev = root -> data;

    return checkIfBST(root -> right, prev);
  }

  return true;
}

void isBST(Node * root) {
  if (root) {
    int prev = INT_MIN;
    bool check = checkIfBST(root, prev);
    if (check) {
      cout << "true" << endl;
    } else {
      cout << "false" << endl;
    }
  }

}

void levelOrder(Node * root) {
  if (root) {
    for (int i = 0; i < nodes.size(); i++) {
      cout << nodes[i] -> data << " ";
    }
    cout << endl;
  }
}

void findFirstNode(Node * root) {
  if (root -> left == nullptr) {
    cout << root -> data << endl;
    return;
  }
  findFirstNode(root -> left);
}

int height(int N) {
  return ceil(log2(N + 1)) - 1;
}

int main() {
  int rootValue;
  int numOfCmds;
  cin >> rootValue;
  Node * root = new Node(rootValue);
  nodes.push_back(root);

  cin >> numOfCmds;

  for (int i = 0; i < numOfCmds; i++) {

    string command;
    cin >> command;

    if (command == "append") {
      int appendValue;
      cin >> appendValue;
      if (nodes.empty()) {
        Node * command = new Node(appendValue);
        nodes.push_back(command);
      } else {
        for (int i = 0; check != true; i++) {

          append(nodes[i], appendValue);
        }
        check = false;
      }
    } else if (command == "isBST") {
      isBST(nodes[0]);
    } else if (command == "height") {
      cout << height(nodes.size()) << endl;

    } else if (command == "levelOrder") {
      if (!nodes.empty()) {
        levelOrder(nodes[0]);
      }
    } else if (command == "findFirstNode") {
      if (!nodes.empty()) {
        findFirstNode(nodes[0]);
      }
    } else if (command == "preOrder") {
      if (!nodes.empty()) {
        preOrder(nodes[0]);
        cout << endl;
      }
    } else if (command == "inOrder") {
      if (!nodes.empty()) {
        inOrder(nodes[0]);
        cout << endl;
      }
    } else if (command == "postOrder") {
      if (!nodes.empty()) {
        postOrder(nodes[0]);
        cout << endl;
      }
    }
  }

  return 0;
}
