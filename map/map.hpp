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
        int height;
        int bf;
    };


    Node *createNode(int value){
        Node *newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    int max(int heightLeft, int heightRight)
    {
        if (heightLeft > heightRight)
            return heightLeft;
        else
            return heightRight;
    }

    int     updateHeight(Node *root)
    {
        int leftHeight = 0;
        int rightHeight = 0;

        if(root->left)
            leftHeight = root->left->height;
        if(root->right)
            rightHeight = root->right->height;
        return (max(leftHeight, rightHeight) + 1);
    }

    int   getBalanceFactor(Node *root)
    {
        int leftHeight = 0;
        int rightHeight = 0;

        if(root->left)
            leftHeight = root->left->height;
        if(root->right)
            rightHeight = root->right->height;
        return (leftHeight - rightHeight);
    }

    void    leftRotation(Node *root)
    {
        std::cout << root->data << std::endl;
    }

    Node    *rightRotation(Node *root)
    {
        Node  *tmp = root;
        delete root;
        tmp->left->right->data = tmp->data;
        return tmp->left;
    }
    Node    *insertHelper(Node *root, int value)
    {
        if(value < root->data)
        {
            if(root->left == nullptr)
                root->left = createNode(value);
            else
                root->left =  insertHelper(root->left, value);
        }
        else if (value > root->data)
        {
            if(root->right == nullptr)
                root->right = createNode(value);
            else
                root->right = insertHelper(root->right, value);
        }
        root->height = updateHeight(root);
        root->bf = getBalanceFactor(root);
        if (root->bf == 2 || root->bf == -2)
        {
            if (root->bf == 2)
            {
                //check if right rotation or left right rotation

                // right rotation
                if (root->left->bf == 1)
                {
                    Node *newNode;
                    Node *tmp = root->left->right;
                    root->left->right = root;
                    newNode = root->left;
                    newNode->right->left = tmp;

                    newNode->left->height = updateHeight(newNode->left);
                    newNode->left->bf = getBalanceFactor(newNode->left);
                    newNode->right->height = updateHeight(newNode->right);
                    newNode->right->bf = getBalanceFactor(newNode->right);
                    newNode->height = updateHeight(newNode);
                    newNode->bf = getBalanceFactor(newNode);
                    return newNode;
                }

                //left right rotation
                if(root->left->bf == -1)
                {

                }
            }
            if (root->bf == -2)
            {
                //check if left rotation or right left rotation
                
                // left rotation
                if (root->right->bf == -1)
                {

                }

                //right left rotation
                if(root->right->bf == 1)
                {

                }
                
            }
        }
        return root;
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
                delete root;
                return nullptr;
            }
            // --------------------------------
            //node with one child only

            else{
                if (root->left == nullptr)
                {
                    Node *tmp = root->right;
                    delete root;
                    return tmp;
                }
                else if (root->right == nullptr)
                {
                    Node *tmp = root->left;
                    delete root;
                    return tmp;
                }
                // node with two children
                else{
                    int maxValue = getMaxValue(root->left);
                    root->data = maxValue;
                    root->left = earseHelper(root->left, maxValue);
                }
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
                root = insertHelper(root,value);
        }

        void  earse(int value){

            this->root = earseHelper(this->root, value);
        }

        int getMaxValue(Node *root)
        {
            Node *tmp = root;

            while (tmp->right != nullptr)
                tmp = tmp->right;
            return tmp->data;
            
        }

        void printTree(Node *root){
            if (root == nullptr) {
                return;
            } 
            printTree(root->left);
            std::cout <<"data: " << root->data << " | " << "height: " << root->height << " | " << "bf: " << root->bf << std::endl;
            printTree(root->right);
        };
};

#endif