#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iostream>

namespace ft{
    template <typename T>
    class const_vector_iterator;

    template <typename T>
    class vector_iterator{
        public:
	        typedef std::random_access_iterator_tag	iterator_category;
            typedef T                               value_type;
            typedef T*                              pointer;
	        typedef T&								reference;
	        typedef ptrdiff_t						difference_type;
            	
            vector_iterator(void):ptr(){};
	        vector_iterator(vector_iterator const & src):ptr(src.ptr){};
            vector_iterator(pointer ptr):ptr(ptr){};
	        ~vector_iterator(void){};

            operator const_vector_iterator<T>() const
            {
                return (const_vector_iterator<T>(this->ptr));
            }

	        vector_iterator&	operator=(vector_iterator const & rhs){
                this->ptr = rhs.ptr;
                return *this;
            };

            bool operator != (const vector_iterator &val) {return this->ptr != val.ptr;}
            bool operator == (const vector_iterator &val) {return this->ptr == val.ptr;}
            bool operator > (const vector_iterator &val) {return this->ptr > val.ptr;}
            bool operator < (const vector_iterator &val) {return this->ptr < val.ptr;}
            bool operator >= (const vector_iterator &val){return this->ptr >= val.ptr;}
            bool operator <= (const vector_iterator &val) {return this->ptr <= val.ptr;}

            bool operator != (const const_vector_iterator<T> &val) {return this->ptr != val.base();}
            bool operator == (const const_vector_iterator<T> &val) {return this->ptr == val.base();}
            bool operator > (const const_vector_iterator<T> &val) {return this->ptr > val.base();}
            bool operator < (const const_vector_iterator<T> &val) {return this->ptr < val.base();}
            bool operator >= (const const_vector_iterator<T> &val){return this->ptr >= val.base();}
            bool operator <= (const const_vector_iterator<T> &val) {return this->ptr <= val.base();}


            vector_iterator operator + (int n)const {return vector_iterator(this->ptr + n);}
            vector_iterator operator - (int n)const {return vector_iterator(this->ptr - n);}
            difference_type	operator - (vector_iterator const & rhs) const
            {
                return (this->ptr - rhs.ptr);
            }
            


            vector_iterator  &operator++ (void){
                this->ptr++;
                return *this;
            }
            vector_iterator operator++ (int){
                vector_iterator copy = *this;
                this->ptr++;
                return copy;
            }
            vector_iterator  &operator-- (void){
                this->ptr--;
                return *this;
            }
            vector_iterator operator-- (int){
                vector_iterator copy = *this;
                this->ptr--;
                return copy;
            }
            
            reference   operator* () const{return *this->ptr;}
            reference	operator[] (difference_type n) const{return (*(this->ptr + n));};
            pointer		operator->(void) const{return (this->ptr);};


            vector_iterator&	operator+=(difference_type n){
                this->ptr += n;
	            return (*this);
            }
            vector_iterator&	operator-=(difference_type n){
                this->ptr -= n;
	            return (*this);
            }

            value_type base() const{return ptr;}

        private:
        value_type *ptr;
    };

    template<class T>
        vector_iterator<T>	operator + (typename vector_iterator<T>::difference_type n, vector_iterator<T> const & rhs)
        {
	        return (rhs + n);
        }


    template <typename T>
    class const_vector_iterator{
        public:
	        typedef std::random_access_iterator_tag	iterator_category;
            typedef T                               value_type;
            typedef T*                              pointer;
	        typedef T&								reference;
	        typedef ptrdiff_t						difference_type;
            	
            const_vector_iterator(void):ptr(){};
	        const_vector_iterator(const_vector_iterator const & src):ptr(src.ptr){};
            const_vector_iterator(pointer ptr):ptr(ptr){};
	        ~const_vector_iterator(void){};

            operator const_vector_iterator<T const>() const
            {
                return (const_vector_iterator<T const>(this->ptr));
            }

	        const_vector_iterator&	operator=(const_vector_iterator const & rhs){
                this->ptr = rhs.ptr;
                return *this;
            };

            bool operator != (const const_vector_iterator &val) {return this->ptr != val.base();}
            bool operator == (const const_vector_iterator &val) {return this->ptr == val.base();}
            bool operator > (const const_vector_iterator &val) {return this->ptr > val.base();}
            bool operator < (const const_vector_iterator &val) {return this->ptr < val.base();}
            bool operator >= (const const_vector_iterator &val){return this->ptr >= val.base();}
            bool operator <= (const const_vector_iterator &val) {return this->ptr <= val.base();}

            const_vector_iterator operator + (int n)const {return const_vector_iterator(this->ptr + n);}
            const_vector_iterator operator - (int n)const {return const_vector_iterator(this->ptr - n);}
            difference_type	operator - (const_vector_iterator const & rhs) const
            {
                return (this->ptr - rhs.ptr);
            }
            


            const_vector_iterator  &operator++ (void){
                this->ptr++;
                return *this;
            }
            const_vector_iterator operator++ (int){
                const_vector_iterator copy = *this;
                this->ptr++;
                return copy;
            }
            const_vector_iterator  &operator-- (void){
                this->ptr--;
                return *this;
            }
            const_vector_iterator operator-- (int){
                const_vector_iterator copy = *this;
                this->ptr--;
                return copy;
            }
            
            reference   operator* () const{return *this->ptr;}
            reference	operator[] (difference_type n) const{return (*(this->ptr + n));};
            pointer		operator->(void) const{return (this->ptr);};


            const_vector_iterator&	operator+=(difference_type n){
                this->ptr += n;
	            return (*this);
            }
            const_vector_iterator&	operator-=(difference_type n){
                this->ptr -= n;
	            return (*this);
            }
            
            pointer base() const{return ptr;}

        private:
        value_type *ptr;
    };

    template<class T>
        const_vector_iterator<T>	operator + (typename const_vector_iterator<T>::difference_type n, const_vector_iterator<T> const & rhs)
        {
	        return (rhs + n);
        }
}

#endif