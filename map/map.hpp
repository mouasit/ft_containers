#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>

class Tree
{
    private:
    struct Node{
        int data;
        Node *left;
        Node *right;
    };


    Node *createNode(int value){
        Node *newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void    insertHelper(Node *tmp, int value)
    {
        if(value <= tmp->data)
        {
            if(tmp->left == nullptr)
                tmp->left = createNode(value);
            else
                insertHelper(tmp->left, value);
        }
        else{
            if(tmp->right == nullptr)
                tmp->right = createNode(value);
            else
                insertHelper(tmp->right, value);
        }
    }

    Node   *earseHelper(Node *root, int value)
    {
        if(root == nullptr)
            return root;
        if (value < root->data)
            root->left = earseHelper(root->left,value);
        else if (value > root->data)
            root->right = earseHelper(root->right, value);
        else{
            //leaf node 
            if (root->left == nullptr && root->right == nullptr)
            {
                root = nullptr;
                delete root;
                return nullptr;
            }
        }
        return root;
    };
    public:
        Node    *root = nullptr;
        void    insert(int value){
            if (root == nullptr)
                root = createNode(value);
            else
                insertHelper(root,value);
        }

        void  earse(int value){

            this->root = earseHelper(this->root, value);
        }

        void printTree(Node *root){
            if (root == nullptr) {
                return;
            } 
            printTree(root->left);
            std::cout << root->data << std::endl;
            printTree(root->right);
        };
};

#endif