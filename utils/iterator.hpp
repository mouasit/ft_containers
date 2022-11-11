#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "../map/map.hpp"
#include "./pair.hpp"
namespace ft{
    template <typename T, typename Node, typename Avl>
    class iterator{
        public:
        iterator(){};

        iterator(Node *node, Avl *avl_tree, bool past_last = false){
            if(past_last)
                this->past_last = true;
            this->avl_tree = avl_tree;
            this->node = node;
        }
        
        iterator operator= (const iterator &it){
            this->node = it.node;
            this->avl_tree = it.avl_tree;
            return *this;
        }


        iterator operator++(int){

            iterator copy = *this;
            this->node = this->avl_tree->inorder_successor(this->avl_tree->root, this->node->data.first);
            return copy;
        }

        iterator operator--(int){
            iterator copy = *this;
            if(this->past_last)
            {
                this->node = this->avl_tree->getMaxValue(this->avl_tree->root);
                this->past_last = false;
            }
            else
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
            return copy;
        }

        bool operator== (const iterator &it){
            return this->pair == it.pair;
        }
        
        bool operator!= (const iterator &it){
            return this->pair != it.pair;
        }

        T *operator->(void){
            return &this->node->data;
        }

        ~iterator(){};
        
        private:
            Avl   *avl_tree;
            Node  *node;
            bool past_last;
    };
}
#endif