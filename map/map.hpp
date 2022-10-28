#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <map>

class Tree
{
    private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };
    
    Node *root = nullptr;
    public:
        void insert(int value){
            if (root == nullptr)
            {
                Node *newNode = new Node;
                newNode->data = value;
                newNode->left = nullptr;
                newNode->right = nullptr;
                root = newNode;
                std::cout << "root" << std::endl;
                return ;
            }
            else
                insertHelper(root,value);
        };

        void    insertHelper(Node *node, int value)
        {
            int i = 0;
            if (value <= node->data)
            {
                if (node->left == nullptr)
                {
                    Node *newNode = new Node;
                    newNode->data = value;
                    newNode->left = nullptr;
                    newNode->right = nullptr;
                    node->left = newNode;
                    i = 8;
                }
                else
                    insertHelper(node->left,value);
            }

            else{
                if (node->right == nullptr)
                {
                    Node *newNode = new Node;
                    newNode->data = value;
                    newNode->left = nullptr;
                    newNode->right = nullptr;
                    node->left = newNode;
                }
                else
                    insertHelper(node->right,value);
            }
        }
};


#endif