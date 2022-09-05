#ifndef vector_HPP
#define vector_HPP

#include <iostream>
#include "iterator.hpp"
namespace ft{
    
    template <typename T, typename Alloc = std::allocator<T> >
    class vector{
        public:
            typedef T                                               value_type;
            typedef Alloc                                           allocation_type;
            typedef size_t                                          size_type;
            typedef typename allocation_type::reference             reference;
            typedef typename allocation_type::const_reference       const_reference;
            typedef typename ft::iterator<T>                        iterator;
            typedef typename ft::const_iterator<T>                  const_iterator;
            typedef typename ft::reverse_iterator<T>                reverse_iterator;
    
            vector()
                : _array(NULL), _size(0), _capacity(0){};

            vector(const size_type len,const value_type& val = value_type(),const allocation_type& alloc = allocation_type())
                : _array(NULL),_allocation(alloc), _size(len), _capacity(len){

            this->_array = this->_allocation.allocate(len);
            for (size_type i = 0; i < len; i++)
                this->_allocation.construct(this->_array + i, val);
        };
            ~vector(){};

            // ITERATOR

            iterator begin(){
                value_type *it = &this->_array[0];
                return(iterator(it));
            }
            
            iterator end(){
                value_type *it = &this->_array[this->_size];
                return(iterator(it));
            }

            reverse_iterator rbegin(){
                value_type *it = &this->_array[this->_size];
                return(reverse_iterator(it));
            }
            
            reverse_iterator rend(){
                value_type *it = &this->_array[0];
                return(reverse_iterator(it));
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

            // ELEMENT ACCESS
            
             reference operator[] (size_type n){
                return this->_array[n];
            }
            
            const_reference operator[] (size_type n) const{
                return this->_array[n];
            }

            reference at(size_type n){
                if(n >= this->_size)
                    throw std::out_of_range("vector");
                return this->_array[n];
            }

            const_reference at(size_type n) const {
                if(n >= this->_size)
                    throw std::out_of_range("vector");
                return this->_array[n];
            }
            
            reference front(){
                return this->_array[0];
            }

            const_reference front() const {
                return this->_array[0];
            }
            
            reference back(){
                return this->_array[this->_size - 1];
            }

            const_reference back() const {
                return this->_array[this->_size - 1];
            }

            // MODIFIERS
            
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last){
                size_type range = get_range(first,last);

                this->clear();
                if(range > this->capacity())
                    this->reserve(range);
                for (size_t i = 0; i < range; i++)
                {
                    this->_allocation.construct(this->_array + i, *first);
                    first++;
                }
                this->_size = range;
                
            }

            void push_back (const value_type& val){
                size_type  doubleCapacity = this->_size * 2;

                if (this->_size < this->_capacity)
                    _allocation.construct(this->_array + this->_size, val);
                else{
                    if (this->_capacity == 0)
                        doubleCapacity = 1;
                    this->reserve(doubleCapacity);
                    _allocation.construct(this->_array + this->_size, val);
                }
                    this->_size++;
            }

            void pop_back(){
                _allocation.destroy(this->_array + (this->_size - 1));
                this->_size--;
            }

            void swap (vector& x){
                vector<T>  tmpVector;

                tmpVector._size = x._size;
                tmpVector._capacity = x._capacity;
                tmpVector._array = x._array;
                x._size = this->_size;
                x._capacity = this->_capacity;
                x._array = this->_array;
                this->_size = tmpVector._size;
                this->_capacity = tmpVector._capacity;
                this->_array = tmpVector._array;
            }

            void clear(){

                for (size_t i = 0; i < this->_size; i++)
                    _allocation.destroy(this->_array + i);
                this->_size = 0;
            }

            template <class InputIterator>
            size_type get_range(InputIterator first, InputIterator last){
                size_type range = 0;
                for (; first != last; first++)
                    range++;
                return range;
            }

            private:
                value_type     *_array;
                Alloc  _allocation;
                size_type _size;
                size_type _capacity;
    };
}

#endif