#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft{
    
    template <typename T, typename Alloc = std::allocator<T> >
    class Vector{
        private:
            Alloc  _allocation;
            T*     _array;
            size_t _size;
            size_t _capacity;
        public:
            typedef T       _type;
            typedef Alloc    _allocation_type;
    
            Vector()
                : _array(NULL), _size(0), _capacity(0){};

            Vector(const size_t len, const T value = T())
                : _array(NULL), _size(len), _capacity(len){

            this->_array = this->_allocation.allocate(len);
            for (size_t i = 0; i < len; i++)
                this->_allocation.construct(this->_array + i, value);
        };
            ~Vector(){};
            T operator[](int index){
                return this->_array[index];
            }

            int size(){
                return this->_size;
            }

            int capacity(){
                return this->_capacity;
            }
    };
}

#endif