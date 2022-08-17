#ifndef vector_HPP
#define vector_HPP

#include <iostream>

namespace ft{
    
    template <typename T, typename Alloc = std::allocator<T> >
    class vector{
        private:
            Alloc  _allocation;
            T*     _array;
            size_t _size;
            size_t _capacity;
        public:
            typedef T       value_type;
            typedef Alloc    _allocation_type;
    
            vector()
                : _array(NULL), _size(0), _capacity(0){};

            vector(const size_t len, const value_type val = value_type())
                : _array(NULL), _size(len), _capacity(len){

            this->_array = this->_allocation.allocate(len);
            for (size_t i = 0; i < len; i++)
                this->_allocation.construct(this->_array + i, val);
        };
            ~vector(){};
            T operator[](int index){
                return this->_array[index];
            }


            int size(){
                return this->_size;
            }

            int capacity(){
                return this->_capacity;
            }

            void resize (size_t n, value_type val = value_type())
            {
                T* arrayTmp = this->_array;
                size_t  doubleCapacity = this->_capacity * 2 ;

                this->_size = n;

                if (n > this->_capacity)
                {
                    if (n > doubleCapacity)
                    {
                        this->_array = this->_allocation.allocate(n);
                        this->_capacity = n;
                    }
                    else
                    {
                        this->_array = this->_allocation.allocate(doubleCapacity);
                        this->_capacity = doubleCapacity;
                    }
                }

                else
                {
                    if (n == this->_capacity)
                    {
                        this->_array = this->_allocation.allocate(n);
                        this->_capacity = n;
                    }
                }

                for (size_t i = 0; i < n; i++)
                {
                    if(arrayTmp[i])
                    {
                        this->_array[i] = arrayTmp[i];
                    }
                    else
                        this->_array[i] = val;
                }
            }
    };
}

#endif