#ifndef vector_HPP
#define vector_HPP

#include <iostream>

namespace ft{
    
    template <typename T, typename Alloc = std::allocator<T> >
    class vector{
        public:
            typedef T       value_type;
            typedef Alloc    allocation_type;
            typedef size_t   size_type;
    
            vector()
                : _array(NULL), _size(0), _capacity(0){};

            vector(const size_type len, const allocation_type& alloc = allocation_type(), const value_type& val = value_type())
                : _array(NULL),_allocation(alloc), _size(len), _capacity(len){

            this->_array = this->_allocation.allocate(len);
            for (size_type i = 0; i < len; i++)
                this->_allocation.construct(this->_array + i, val);
        };
            ~vector(){};
            T operator[](int index){
                return this->_array[index];
            }

            // CAPACITY 

            size_type size(){
                return this->_size;
            }
            
            size_type max_size() const{
                return this->_allocation.max_size();
            }

            void resize (size_type n, value_type val = value_type())
            {
                size_type doubleCapacity = this->_size * 2;

                if(n < this->_size)
                {
                    for(size_type i = n; i < this->_size; i++)
                        _allocation.destroy(this->_array + i);
                }
                else if (n > this->_size && n <= this->_capacity)
                {
                    for (size_type i = this->_size; i < n; i++)
                        _allocation.construct(this->_array + i, val);
                }
                else if (n > this->_capacity)
                {
                    if (n > doubleCapacity)
                        this->reserve(n);
                    else
                        this->reserve(doubleCapacity);
                    for (size_type i = this->_size; i < this->_capacity; i++)
                        _allocation.construct(this->_array + i,val);
                }
                this->_size = n;
            }
            
            size_type capacity(){
                return this->_capacity;
            }
            
            bool empty() const{
                if (!this->_size)
                    return true;
                return false;
            }

            void reserve (size_type n)
            {
                T*  tmpArray;
                size_type tmpCapacity = this->_capacity;

                if (n > this->_capacity)
                {
                    tmpArray = this->_allocation.allocate(n);
                    this->_capacity = n;

                    for (size_type i = 0; i < this->_size; i++)
                        _allocation.construct(tmpArray + i,this->_array[i]);
                    
                    for (size_type i = 0; i < this->_size; i++)
                        _allocation.destroy(this->_array + i);
                    _allocation.deallocate(this->_array, tmpCapacity);
                    this->_array = tmpArray;
                }
            }

            private:
                T*     _array;
                Alloc  _allocation;
                size_type _size;
                size_type _capacity;
    };
}

#endif