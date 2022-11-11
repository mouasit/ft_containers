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
        Node *parent;
        int height;
        int bf;
};

#endif