#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "../map/map.hpp"
namespace ft{
    template <typename value_type>
    class iterator{
        public:
        iterator(){};

        iterator(value_type *pair){
            this->pair = pair;
        }
        
        iterator operator= (const iterator &it){
            this->pair = it.pair;
            return *this;
        }

        bool operator== (const iterator &it){
            return this->pair == it.pair;
        }
        
        bool operator!= (const iterator &it){
            return this->pair != it.pair;
        }

        value_type *operator->(void){
            return pair;
        }

        ~iterator(){};
        
        private:
        value_type *pair;
    };
}
#endif