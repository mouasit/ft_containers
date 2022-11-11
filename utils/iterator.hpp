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

        iterator(Node *node){
            this->node = node;
        }
        
        iterator operator= (const iterator &it){
            this->node = it.node;
            return *this;
        }


        iterator operator++(int){

            iterator copy = *this;
            this->node = avl_tree->inorder_successor(this->node);
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
    };
}
#endif