#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP


#include <cstddef>
template <typename T1, typename T2, typename Node , typename key_compare, typename Alloc>
class avl_tree
{
    private:
        Alloc  _allocator;
		typename Alloc::template rebind<Node>::other	_node_allocator;
    public:
        Node    *root;
        Node    *node_insert;
        Node    *tmp_node;
        key_compare compare;
        size_t  size;


        avl_tree(){
            this->size = 0;
            this->root = NULL;
            this->node_insert = NULL;
            this->tmp_node = createNode(pair<T1,T1>(T1(),T2()));
        }

    Node *inorder_successor(Node *root, T1 key){
        Node *successor = NULL;
        
        while (true) {
            if (key < root->data.first) {
                successor = root;
                root = root->left;
            }
            else if (key > root->data.first){
                    root = root->right;
                }
                else 
                {
                    if (root->right != NULL)
                        successor = getMinValue(root->right);
            break;
      }

      if (root == NULL){
        return NULL;
      }
    }

    if(successor)
        return successor;
    return NULL;
}

Node *inorder_predecessor(Node *root, T1 key){

    Node *predecessor = NULL;

  while (true) {
      if (key < root->data.first)
        root = root->left;

      else if (key > root->data.first){
        predecessor = root;
        root = root->right;
      }
      else {
        if (root->left != NULL)
            predecessor= getMaxValue(root->left);
        break;
      }

      if (root == NULL){
        return NULL;
      }
    }

    if(predecessor)
        return predecessor;
    return NULL;

}

Node *createNode(pair<T1,T2> data){
        Node *newNode = _node_allocator.allocate(1);
        _node_allocator.construct(newNode,data);
        this->node_insert = newNode;
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

    Node    *rightRotation(Node *root)
    {
        Node *tmp = root->left->right;
        Node *newNode;

        root->left->right = root;
        newNode = root->left;
        newNode->right->left = tmp;

        newNode->right->height = updateHeight(newNode->right);
        newNode->height = updateHeight(newNode);
        return newNode;
    }
        Node    *leftRotation(Node *root)
        {
            Node *tmp = root->right->left;
            Node *newNode;
            
            root->right->left = root;
            newNode = root->right;
            newNode->left->right = tmp;
            newNode->left->height = updateHeight(newNode->right);
            newNode->height = updateHeight(newNode);
            return newNode;
        }

    Node    *insertHelper(Node *root, pair<T1,T2> pair)
    {
        int bf = 0;
        if(compare(pair.first,root->data.first))
        {
            if(root->left == NULL)
            {
                root->left = createNode(pair);
                this->size++;
            }
            else
                root->left =  insertHelper(root->left, pair);
        }
        else if (compare(root->data.first,pair.first))
        {
            if(root->right == NULL)
            {
                root->right = createNode(pair);
                this->size++;
            }
            else
                root->right = insertHelper(root->right, pair);
        }
        root->height = updateHeight(root);
        bf = getBalanceFactor(root);
        if (bf == 2 || bf == -2)
        {
            if (bf == 2)
            {
                //check if right rotation or left right rotation

                // right rotation
                if (getBalanceFactor(root->left) == 1)
                   return rightRotation(root);

                //left right rotation
                if(getBalanceFactor(root->left) == -1)
                {
                    Node *tmpNode = root->left;
                    Node *tmp = root->left->right->left;
                    root->left = root->left->right;
                    root->left->left = tmpNode;
                    root->left->left->right = tmp;

                    root->left->left->height = updateHeight(root->left->left);
                    root->left->height = updateHeight(root->left);
                    root->height = updateHeight(root);

                    return (rightRotation(root));
                }
            }
            if (bf == -2)
            {
                //check if left rotation or right left rotation
                
                // left rotation
                if (getBalanceFactor(root->right) == -1)
                    return leftRotation(root);

                //right left rotation
                if(getBalanceFactor(root->right) == 1)
                {
                    Node *tmpNode = root->right;
                    Node *tmp = root->right->left->right;

                    root->right = root->right->left;
                    root->right->right = tmpNode;
                    root->right->right->left = tmp;

                    root->right->right->height = updateHeight(root->right->right);
                    root->right->height = updateHeight(root->right);
                    root->height = updateHeight(root);
                    return (leftRotation(root));
                }
                
            }
        }
        return root;
    }

    

    Node   *earseHelper(Node *root, T1 key)
    {
        int bf = 0;
        if(root == NULL)
            return root;
        if (compare(key,root->data.first))
            root->left = earseHelper(root->left,key);
        else if (compare(root->data.first,key))
            root->right = earseHelper(root->right, key);
        else{
            //leaf node 
            if (root->left == NULL && root->right == NULL)
            {
                this->_node_allocator.destroy(root);
                this->_node_allocator.deallocate(root,1);
                this->size--;
                return NULL;
            }
            // --------------------------------
            //node with one child only

            else{
                if (root->left == NULL)
                {
                    Node *tmp = root->right;
                    this->_node_allocator.destroy(root);
                    this->_node_allocator.deallocate(root,1);
                    this->size--;
                    return tmp;
                }
                else if (root->right == NULL)
                {
                    Node *tmp = root->left;
                    this->_node_allocator.destroy(root);
                    this->_node_allocator.deallocate(root,1);
                    this->size--;
                    return tmp;
                }
                // node with two children
                else{
                    Node *maxValue = getMaxValue(root->left);
                    root->data.first = maxValue->data.first;
                    root->left = earseHelper(root->left, maxValue);
                }
            }
        }
        root->height = updateHeight(root);
        bf = getBalanceFactor(root);
        if (bf == 2 || bf == -2)
        {
            if (bf == 2)
            {
                //check if right rotation or left right rotation

                // right rotation
                if (getBalanceFactor(root->left) == 1)
                   return rightRotation(root);

                //left right rotation
                if(getBalanceFactor(root->left) == -1)
                {
                    Node *tmpNode = root->left;
                    Node *tmp = root->left->right->left;
                    root->left = root->left->right;
                    root->left->left = tmpNode;
                    root->left->left->right = tmp;

                    root->left->left->height = updateHeight(root->left->left);
                    root->left->height = updateHeight(root->left);
                    root->height = updateHeight(root);

                    return (rightRotation(root));
                }
            }
            if (bf == -2)
            {
                //check if left rotation or right left rotation
                
                // left rotation
                if (getBalanceFactor(root->right) == -1)
                    return leftRotation(root);

                //right left rotation
                if(getBalanceFactor(root->right) == 1)
                {
                    Node *tmpNode = root->right;
                    Node *tmp = root->right->left->right;

                    root->right = root->right->left;
                    root->right->right = tmpNode;
                    root->right->right->left = tmp;

                    root->right->right->height = updateHeight(root->right->right);
                    root->right->height = updateHeight(root->right);
                    root->height = updateHeight(root);
                    return (leftRotation(root));
                }
                
            }
        }
        return root;
    };
        /*avl_tree(key_compare &compe){
            this->root = NULL;
            compare = compe;
        };
        ~avl_tree(){};*/
        void    insert(const pair<T1,T2> pair){
            if (root == NULL)
            {
                root = createNode(pair);
                this->size++;
            }
            else
                root = insertHelper(root,pair);
        }

        void  earse(T1 key){

            this->root = earseHelper(this->root, key);
        }

        Node *getMaxValue(Node *root)
        {
            Node *tmp = root;

            while (tmp->right != NULL)
                tmp = tmp->right;
            return tmp;
            
        }
        
        Node *getMinValue(Node *root)
        {
            Node *tmp = root;

            while (tmp->left != NULL)
                tmp = tmp->left;
            return tmp;
        }

        void printTree(Node *root){
            if (root == NULL) {
                return;
            } 
            printTree(root->left);
            std::cout <<"data: " << root->data.first << " | " << "height: " << root->height << " | " << std::endl;
            printTree(root->right);
        };
    };

    #endif