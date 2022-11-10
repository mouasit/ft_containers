#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "../map/map.hpp"
namespace ft{
    template <typename T, typename Node>
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
            T     *pair;
            Node  *node;
    };
}
#endif