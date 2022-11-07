#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

template <typename T1, typename T2>
class avlTree
{
    private:
    struct Node{
        pair<T1,T2> data;
        Node *left;
        Node *right;
        int height;
        int bf;
    };


    Node *createNode(pair<T1,T2> pair){
        Node *newNode = new Node;
        newNode->data.first = pair.first;
        newNode->data.second = pair.second;
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

    Node    *rightRotation(Node *root)
    {
        Node *tmp = root->left->right;
        Node *newNode;

        root->left->right = root;
        newNode = root->left;
        newNode->right->left = tmp;

        newNode->right->height = updateHeight(newNode->right);
        newNode->right->bf = getBalanceFactor(newNode->right);
        newNode->height = updateHeight(newNode);
        newNode->bf = getBalanceFactor(newNode);
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
            newNode->left->bf = getBalanceFactor(newNode->right);
            newNode->height = updateHeight(newNode);
            newNode->bf = getBalanceFactor(newNode);
            return newNode;
        }

    Node    *insertHelper(Node *root, pair<T1,T2> pair)
    {
        if(this->less(pair.first,root->data.first))
        {
            if(root->left == nullptr)
                root->left = createNode(pair);
            else
                root->left =  insertHelper(root->left, pair);
        }
        else if (this->less(root->data.first,pair.first))
        {
            if(root->right == nullptr)
                root->right = createNode(pair);
            else
                root->right = insertHelper(root->right, pair);
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
                   return rightRotation(root);

                //left right rotation
                if(root->left->bf == -1)
                {
                    Node *tmpNode = root->left;
                    Node *tmp = root->left->right->left;
                    root->left = root->left->right;
                    root->left->left = tmpNode;
                    root->left->left->right = tmp;

                    root->left->left->height = updateHeight(root->left->left);
                    root->left->left->bf = getBalanceFactor(root->left->left);
                    root->left->height = updateHeight(root->left);
                    root->left->bf = getBalanceFactor(root->left);
                    root->height = updateHeight(root);
                    root->bf = getBalanceFactor(root);

                    return (rightRotation(root));
                }
            }
            if (root->bf == -2)
            {
                //check if left rotation or right left rotation
                
                // left rotation
                if (root->right->bf == -1)
                {
                    return leftRotation(root);
                }

                //right left rotation
                if(root->right->bf == 1)
                {
                    Node *tmpNode = root->right;
                    Node *tmp = root->right->left->right;

                    root->right = root->right->left;
                    root->right->right = tmpNode;
                    root->right->right->left = tmp;

                    root->right->right->height = updateHeight(root->right->right);
                    root->right->right->bf = getBalanceFactor(root->right->right);
                    root->right->height = updateHeight(root->right);
                    root->right->bf = getBalanceFactor(root->right);
                    root->height = updateHeight(root);
                    root->bf = getBalanceFactor(root);
                    return (leftRotation(root));
                }
                
            }
        }
        return root;
    }

    

    Node   *earseHelper(Node *root, T1 key)
    {
        if(root == nullptr)
            return root;
        if (this->less(key,root->data.first))
            root->left = earseHelper(root->left,key);
        else if (this->less(root->data.first,key))
            root->right = earseHelper(root->right, key);
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
                    T1 maxValue = getMaxValue(root->left);
                    root->data.first = maxValue;
                    root->left = earseHelper(root->left, maxValue);
                }
            }
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
                   return rightRotation(root);

                //left right rotation
                if(root->left->bf == -1)
                {
                    Node *tmpNode = root->left;
                    Node *tmp = root->left->right->left;
                    root->left = root->left->right;
                    root->left->left = tmpNode;
                    root->left->left->right = tmp;

                    root->left->left->height = updateHeight(root->left->left);
                    root->left->left->bf = getBalanceFactor(root->left->left);
                    root->left->height = updateHeight(root->left);
                    root->left->bf = getBalanceFactor(root->left);
                    root->height = updateHeight(root);
                    root->bf = getBalanceFactor(root);

                    return (rightRotation(root));
                }
            }
            if (root->bf == -2)
            {
                //check if left rotation or right left rotation
                
                // left rotation
                if (root->right->bf == -1)
                {
                    return leftRotation(root);
                }

                //right left rotation
                if(root->right->bf == 1)
                {
                    Node *tmpNode = root->right;
                    Node *tmp = root->right->left->right;

                    root->right = root->right->left;
                    root->right->right = tmpNode;
                    root->right->right->left = tmp;

                    root->right->right->height = updateHeight(root->right->right);
                    root->right->right->bf = getBalanceFactor(root->right->right);
                    root->right->height = updateHeight(root->right);
                    root->right->bf = getBalanceFactor(root->right);
                    root->height = updateHeight(root);
                    root->bf = getBalanceFactor(root);
                    return (leftRotation(root));
                }
                
            }
        }

        return root;
    };
    public:
        Node    *root = nullptr;
        std::less<T1> less;
        void    insert(const pair<T1,T2> pair){
            if (root == nullptr)
                root = createNode(pair);
            else
                root = insertHelper(root,pair);
        }

        void  earse(T1 key){

            this->root = earseHelper(this->root, key);
        }

        T1 getMaxValue(Node *root)
        {
            Node *tmp = root;

            while (tmp->right != nullptr)
                tmp = tmp->right;
            return tmp->data.first;
            
        }

        void printTree(Node *root){
            if (root == nullptr) {
                return;
            } 
            printTree(root->left);
            std::cout <<"data: " << root->data.first << " | " << "height: " << root->height << " | " << "bf: " << root->bf << std::endl;
            printTree(root->right);
        };
    };

    #endif