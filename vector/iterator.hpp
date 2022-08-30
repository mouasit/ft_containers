#include "vector.hpp"

namespace ft{
    template <typename T>
    class iterator{
        public:
            typedef T value_type;
            iterator(){};
            iterator(value_type *val){tmp = val;}
            ~iterator(){};
            
            value_type operator* (){return *tmp;}
        private:
        value_type *tmp;
    };
    
    template <typename T>
    class const_iterator{
        public:
            typedef T value_type;

            const_iterator(){};
            const_iterator(const value_type *val){tmp = val;}
            ~const_iterator(){};
            
            value_type operator* (){return *tmp;}
        private:
        value_type *tmp;
    };
}