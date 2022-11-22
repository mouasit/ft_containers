#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft{
    template <typename T>
    class iterator{
        public:
	        typedef std::random_access_iterator_tag	iterator_category;
            typedef T                               value_type;
            typedef T*                              pointer;
	        typedef T&								reference;
	        typedef ptrdiff_t						difference_type;
            	
            iterator(void):ptr(){};
	        iterator(iterator const & src):ptr(src.ptr){};
            iterator(pointer ptr):ptr(ptr){};
	        ~iterator(void){};

            operator iterator<T const>() const
            {
                return (iterator<T const>(this->ptr));
            }

	        iterator&	operator=(iterator const & rhs){
                this->ptr = rhs.ptr;
                return *this;
            };

            bool operator != (const iterator val) const{return this->ptr != val.ptr;}
            bool operator == (const iterator val) const{return this->ptr == val.ptr;}
            bool operator > (const iterator val) const{return this->ptr > val.ptr;}
            bool operator < (const iterator val) const{return this->ptr < val.ptr;}
            bool operator >= (const iterator val) const{return this->ptr >= val.ptr;}
            bool operator <= (const iterator val) const{return this->ptr <= val.ptr;}


            iterator operator + (int n)const {return iterator(this->ptr + n);}
            iterator operator - (int n)const {return iterator(this->ptr - n);}
            difference_type	operator - (iterator const & rhs) const
            {
                return (this->ptr - rhs.ptr);
            }
            


            iterator  &operator++ (void){
                this->ptr++;
                return *this;
            }
            iterator operator++ (int){
                iterator copy = *this;
                this->ptr++;
                return copy;
            }
            iterator  &operator-- (void){
                this->ptr--;
                return *this;
            }
            iterator operator-- (int){
                iterator copy = *this;
                this->ptr--;
                return copy;
            }
            
            value_type& operator* () const{return *this->ptr;}
            reference	operator[] (difference_type n) const{return (*(this->ptr + n));};
            pointer		operator->(void) const{return (this->_ptr);};


            iterator&	operator+=(difference_type n){
                this->ptr += n;
	            return (*this);
            }
            iterator&	operator-=(difference_type n){
                this->_ptr -= n;
	            return (*this);
            }

        private:
        value_type *ptr;
    };

    template<class T>
        iterator<T>	operator + ( typename iterator<T>::difference_type n, iterator<T> const & rhs)
        {
	        return (rhs + n);
        }
}

#endif