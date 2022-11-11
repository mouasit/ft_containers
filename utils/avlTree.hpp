#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP


template <typename T1, typename T2, typename Node , typename key_compare>
class avl_tree
{
    public:
    Node    *root = nullptr;
    key_compare compare;
    size_t  size = 0;

    Node  *inorder_successor(Node *root)
    {
        Node    *parent;

        if(root->right != nullptr)
            return this->getMinValue(root->right);
        parent = root->parent;
        while (parent != nullptr && root == parent->right)
        {
            root = parent;
            parent = parent->parent;
        }
        return parent;
    }

    Node    *inorder_predecessor(Node *root)
    {
        Node    *parent;

        if(root->left != nullptr)
            return this->getMaxValue(root->left);
        parent = root->parent;
        while (parent != nullptr && root == parent->left)
        {
            root = parent;
            parent = parent->parent;
        }
        return parent;
    }
    
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
        if(compare(pair.first,root->data.first))
        {
            if(root->left == nullptr)
            {
                root->left = createNode(pair);
                root->left->parent = root;
                this->size++;
            }
            else
                root->left =  insertHelper(root->left, pair);
        }
        else if (compare(root->data.first,pair.first))
        {
            if(root->right == nullptr)
            {
                root->right = createNode(pair);
                root->left->parent = root;
                this->size++;
            }
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
        if (compare(key,root->data.first))
            root->left = earseHelper(root->left,key);
        else if (compare(root->data.first,key))
            root->right = earseHelper(root->right, key);
        else{
            //leaf node 
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                this->size--;
                return nullptr;
            }
            // --------------------------------
            //node with one child only

            else{
                if (root->left == nullptr)
                {
                    Node *tmp = root->right;
                    delete root;
                    this->size--;
                    return tmp;
                }
                else if (root->right == nullptr)
                {
                    Node *tmp = root->left;
                    delete root;
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
        /*avl_tree(key_compare &compe){
            this->root = nullptr;
            compare = compe;
        };
        ~avl_tree(){};*/
        void    insert(const pair<T1,T2> pair){
            if (root == nullptr)
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

            while (tmp->right != nullptr)
                tmp = tmp->right;
            return tmp;
            
        }
        
        Node *getMinValue(Node *root)
        {
            Node *tmp = root;

            while (tmp->left != nullptr)
                tmp = tmp->left;
            return tmp;
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