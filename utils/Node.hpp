#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
    private:
    
    public:
        T data;
        Node *left;
        Node *right;
        int height;

        Node(T &data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->height = 1;
        }
};

#endif