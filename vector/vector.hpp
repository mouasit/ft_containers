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

            Vector(const int len)
                : _array(NULL), _size(0), _capacity(0){
            this->_array = this->_allocation.allocate(len);

        };;
            ~Vector(){};
};
}

#endif