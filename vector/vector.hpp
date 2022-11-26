#ifndef vector_HPP
#define vector_HPP

#include <iostream>
#include "vector_iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/equal.hpp"
#include "../utils/lexicographical_compare.hpp"

namespace ft{
    
    template <class T, class Alloc = std::allocator<T> >
    class vector{
        public:
            typedef T                                               value_type;
            typedef Alloc                                           allocator_type;
            typedef size_t                                          size_type;
            typedef typename allocator_type::reference             reference;
            typedef typename allocator_type::const_reference       const_reference;
	        typedef typename allocator_type::pointer			    pointer;
	        typedef typename allocator_type::const_pointer			const_pointer;
	        typedef ptrdiff_t								        difference_type;
            typedef typename ft::vector_iterator<T>                        iterator;
            typedef typename ft::const_vector_iterator<T>                  const_iterator;
            typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;


           explicit vector (const allocator_type& alloc = allocator_type()): _array(), _allocation(alloc), _size(), _capacity(){};

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
                : _array(), _allocation(alloc), _size(n), _capacity(n)
            {
                size_type i = 0;

                this->_array = this->_allocation.allocate(n);
                while(i < n)
                {
                    this->_allocation.construct(this->_array + i, val);
                    i++;
                }
            };
            
            template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				typename ft::enable_if<!std::is_integral<InputIterator>::value, allocator_type>::type const alloc = allocator_type())
                    : _array(), _allocation(alloc), _size(), _capacity()
            {
            	this->_size = this->_capacity = std::distance(first, last);

            	this->_array = this->_allocation.allocate(this->_capacity);
            	for (size_type i = 0; first != last; ++first, ++i) {
            		this->_allocation.construct(this->_array + i, *first);
            	}
            }
            
            vector(const vector  &x):_array(), _allocation(x._allocation), _size(x._size), _capacity(x._capacity){
                	
                    this->_array = this->_allocation.allocate(this->_size);
	                for (size_type i = 0; i < this->_size; i++) 
                    {
		                this->_allocation.construct(this->_array + i, *(x._array + i));
	                }
            }

            ~vector(){
                	for (size_type	i = 0; i < this->_size; i++)
		                this->_allocation.destroy(this->_array + i);
	                this->_allocation.deallocate(this->_array, this->_capacity);
            };


            vector operator=(vector const & x)
        {
            this->clear();
            this->_allocation.deallocate(this->_array, this->_capacity);

        this->_size = this->_capacity = x._size;
        this->_array = this->_allocation.allocate(this->_size);

        for (size_type i = 0; i < this->_size; i++) {
            this->_allocation.construct(this->_array + i, *(x._array + i));
        }

        return (*this);
    }

            // ITERATORS

            iterator begin(){
                value_type *it = &this->_array[0];
                return(iterator(it));
            };

            const_iterator begin()const{
                value_type *it = &this->_array[0];
                return(const_iterator(it));
            };

            iterator end(){
                value_type *it = &this->_array[this->_size];
                return(iterator(it));
            }
            
            const_iterator end()const{
                value_type *it = &this->_array[this->_size];
                return(const_iterator(it));
            }

            reverse_iterator rbegin(){
                value_type *it = &this->_array[this->_size];
                return(reverse_iterator(it));
            }
            
            const_reverse_iterator rbegin()const{
                value_type *it = &this->_array[this->_size];
                return(const_reverse_iterator(it));
            }
            
            reverse_iterator rend(){
                value_type *it = &this->_array[0];
                return(reverse_iterator(it));
            }
            
            const_reverse_iterator rend() const{
                value_type *it = &this->_array[0];
                return(const_reverse_iterator(it));
            }


            // CAPACITY 

            size_type size() const{
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

            void assign (size_type n, const value_type& val){
                this->clear();
                if(n > this->capacity())
                    this->reserve(n);
                for (size_t i = 0; i < n; i++)
                    this->_allocation.construct(this->_array + i, val);
                this->_size = n;
            }

            template<class InputIterator>
	        void	assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
            {
                const size_type		updateSize = std::distance(first, last);

                for (size_type i = 0; i < this->_size; i++) {
		        this->_allocation.destroy(this->_array + i);
                }
                
                if (updateSize > this->_capacity) {
                    this->_allocation.deallocate(this->_array, this->_capacity);
                    this->_size = this->_capacity = updateSize;
                    this->_array = this->_allocation.allocate(updateSize);
                    }
                    else {
                        this->_size = updateSize;
                        }
	            for (size_type i = 0; first != last; ++i, ++first) {
		        this->_allocation.construct(this->_array + i, *first);
	            }
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

            size_type get_capacity(size_type n)
            {
	            const size_type		updateCapacity = this->_capacity * 2;
	
	            if (updateCapacity < n)
		            return (n);
	            return (updateCapacity);
            }
            
            void right_shift(const size_type start_position, const size_type n)
            {
                if ((this->_capacity - this->_size) >= n)
                {
                    for(size_type i = this->_size - 1; i >= start_position; i--)
                    {
                        this->_allocation.construct(this->_array + i + n, *(this->_array + i));
	    	            this->_allocation.destroy(this->_array + i);
	                }
	            }
	            else
	            {
		            size_type	updateCapacity = this->get_capacity(this->_size + n);
		            pointer		updateArray = this->_allocation.allocate(updateCapacity);
		
		            for (size_type i = 0; i < start_position; i++)
		            {
			            this->_allocation.construct(updateArray + i, *(this->_array + i));
			            this->_allocation.destroy(this->_array + i);
		            }
		            for(size_type i = start_position; i < this->_size; i++)
		            {
			            this->_allocation.construct(updateArray + i + n, *(this->_array + i));
			            this->_allocation.destroy(this->_array + i);
		            }
		            this->_allocation.deallocate(this->_array, this->_capacity);
		            this->_array = updateArray;
		            this->_capacity = updateCapacity;
	            }
	            this->_size += n;
            }

            iterator insert (iterator position, const value_type& val)
            {
                const size_type		start_position = position - this->begin();

                this->right_shift(start_position,1);
	            this->_allocation.construct(this->_array + start_position, val);
	            return (this->begin() + start_position);
            }
            
            void insert (iterator position, size_type n, const value_type& val){

                const size_type		start_position = position - this->begin();

                this->right_shift(start_position,n);
	            for(size_type i = 0; i < n; i++) {
		                this->_allocation.construct(this->_array + start_position + i, val);
	            }
            }

	        template<class InputIterator>
            void		insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
            {
                const size_type		start_position = position - this->begin();
	            const size_type		n = std::distance(first, last);

	            this->right_shift(start_position, n);
	            for(size_type i = 0; i < n; ++i, ++first)
                {
		            this->_allocation.construct(this->_array + start_position + i, *first);
	            }
            }

            iterator eraseHelper(size_type position, const size_type n)
            {
                size_type index = position;

                while(index < this->_size)
                {
                    this->_allocation.destroy(this->_array + index);
		            if (index + n < this->_size)
			            this->_allocation.construct(this->_array + index, *(this->_array + index + n));
                    index++;
                }

                this->_size -= n;
                return (iterator(this->_array + position));
            }


            iterator erase (iterator position){
                size_type start_position = position - this->begin();
               return eraseHelper(start_position,1);
            }

            iterator erase (iterator first, iterator last){
	            const size_type		start_position = first - this->begin();
                const size_type		n = last - first;

	            return (eraseHelper(start_position, n));
                // size_type range = get_range(first,last);
                // for (; first != last; first++)
                //     _allocation.destroy(&(*first));
                // this->_size -= range;
                // return last;
                
            }

            void swap (vector& x){
                std::swap(this->_array, x._array);
	            std::swap(this->_allocation, x._allocation);
	            std::swap(this->_size, x._size);
	            std::swap(this->_capacity, x._capacity);
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

	        allocator_type	get_allocator(void) const
            {
                return (this->_allocation);
            }
            private:
                value_type     *_array;
                allocator_type  _allocation;
                size_type _size;
                size_type _capacity;
    };

    template<class T, class Alloc>
    void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
    
    template<class T, class Alloc>
    bool	operator==(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs)
    {
        return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    };
    template<class T, class Alloc>
    bool	operator!=(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs){return (!(lhs == rhs));};
    template<class T, class Alloc>
    bool	operator<(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    };
    template<class T, class Alloc>
    bool	operator<=(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs){return (!(rhs < lhs));};
    template<class T, class Alloc>
    bool	operator>(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs){return (rhs < lhs);};
    template<class T, class Alloc>
    bool	operator>=(vector<T,Alloc> const & lhs, vector<T,Alloc> const & rhs){return (!(lhs < rhs));};

}

#endif