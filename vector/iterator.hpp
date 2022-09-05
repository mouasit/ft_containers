#include "vector.hpp"

namespace ft{
    template <typename T>
    class iterator{
        public:
            typedef T value_type;
            iterator(){};
            iterator(value_type *val){this->tmp = val;}
            ~iterator(){};
            
            value_type& operator* (){return *this->tmp;}
            bool operator != (const iterator val){return this->tmp != val.tmp;}
            iterator  operator++ (){
                this->tmp++;
                return *this;
            }
            iterator operator++ (int){
                iterator valuetmp = *this;
                this->tmp++;
                return valuetmp;
            }
        private:
        value_type *tmp;
    };
    
    template <typename T>
    class const_iterator{
        public:
            typedef T value_type;

            const_iterator(){};
            const_iterator(value_type *val){this->tmp = val;}
            ~const_iterator(){};
            
            value_type& operator* (){return *tmp;}
        private:
        value_type *tmp;
    };
    
    template <typename T>
    class reverse_iterator{
        public:
            typedef T value_type;

            reverse_iterator(){};
            reverse_iterator(value_type *val){this->tmp = val;}
            ~reverse_iterator(){};
            
            value_type& operator* (){return *(this->tmp - 1);}
            reverse_iterator operator++ (){
                this->tmp--;
                return *this;
            }
            reverse_iterator operator++ (int){
                reverse_iterator valuetmp = *this;
                this->tmp--;
                return valuetmp;
            }
            bool operator != (const reverse_iterator val){return this->tmp != val.tmp;}
            bool operator == (const reverse_iterator val){return this->tmp == val.tmp;}
            bool operator > (const reverse_iterator val){return this->tmp > val.tmp;}
            bool operator < (const reverse_iterator val){return this->tmp < val.tmp;}
            bool operator >= (const reverse_iterator val){return this->tmp >= val.tmp;}
            bool operator <= (const reverse_iterator val){return this->tmp <= val.tmp;}
        private:
        value_type *tmp;
    };
}