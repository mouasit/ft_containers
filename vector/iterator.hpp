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
            const_iterator(value_type *val){tmp = val;}
            ~const_iterator(){};
            
            value_type operator* (){return *tmp;}
        private:
        value_type *tmp;
    };
    
    template <typename T>
    class reverse_iterator{
        public:
            typedef T value_type;

            reverse_iterator(){};
            reverse_iterator(value_type *val){tmp = val;}
            ~reverse_iterator(){};
            
            value_type operator* (){return *(tmp - 1);}
            bool operator!= (const reverse_iterator &val){return this->_tmp == val.tmp;}
        private:
        value_type *tmp;
    };
}