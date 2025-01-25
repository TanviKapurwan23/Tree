#include<iostream>
using namespace std;

// Definition of Node for Binary tree
struct Node{
    int key;
    Node *left, *right;

    Node(int data){
        key = data;
        left = right = NULL;
    }
};

int maxLevel = 0; // Variable to store the maximum level of the tree



// function to print the left view of the binary tree
void printLeft(Node *root, int level){
    if(root == NULL){
        return;
    }
    if(maxLevel < level){
        cout<<root->key<< " ";
        maxLevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}

void printLeftView(Node *root){
    printLeft(root, 1);
}

// helper function to create a new node
Node* newNode(int data){
    return new Node(data);
}
int main(){

    Node *root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);

    cout<<"Left View of the Binary Tree is: ";
    printLeftView(root);

    return 0;
}
