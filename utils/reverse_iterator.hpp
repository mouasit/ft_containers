#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator{
        private:
        Iterator                                                            base_it;
        public:
        typedef Iterator                                                    iterator_type;
        typedef typename iterator_traits<Iterator>::value_type              value_type;
        typedef typename iterator_traits<Iterator>::pointer                 pointer;
        typedef typename iterator_traits<Iterator>::reference               reference;
        typedef typename iterator_traits<Iterator>::difference_type         difference_type;
        typedef	typename iterator_traits<Iterator>::iterator_category	    iterator_category;


        reverse_iterator():base_it(){};

        explicit reverse_iterator(iterator_type it):base_it(it){}
        template<class Iter>
		reverse_iterator(reverse_iterator<Iter> const & rev_it):base_it(rev_it.base()){}
        ~reverse_iterator(){}

        iterator_type base() const{
            return this->base_it;
        }


	    reverse_iterator& operator++(void){
            this->base_it--;
            return *this;
        }

        reverse_iterator operator++(int){
            reverse_iterator copy = *this;
            this->base_it--;
            return copy;
        }

        reverse_iterator& operator--(void){
            this->base_it++;
            return *this;
        }

        reverse_iterator operator--(int){
            reverse_iterator copy = *this;
            this->base_it++;
            return copy;
        }

        reference operator*(void) const{
            iterator_type temp = this->base_it;
            return (*(--temp));
        }

        pointer operator->(void) const{
            iterator_type temp = this->base_it;
            return ((--temp).operator->());
        }
        
        reference operator[](difference_type n) const{
	        iterator_type	position = this->base_it - 1;
            return (position[-n]);
        }

        reverse_iterator operator + (difference_type n) const
        {
	        return (reverse_iterator(this->base_it - n));
        }

        reverse_iterator operator - (difference_type n) const
        {
            return (reverse_iterator(this->base_it + n));
        }

        reverse_iterator<Iterator>&	operator+=(difference_type n)
        {
	        this->base_it -= n;
	        return (*this);
        }

        reverse_iterator &operator-=(difference_type n)
        {
	        this->base_it += n;
	        return (*this);
        } 
    };
        
        template<class Iterator1, class Iterator2 >
        bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
            return (lhs.base() == rhs.base());
        }

        template<class Iterator1, class Iterator2 >
        bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
            return (lhs.base() != rhs.base());
        }
        
        template<class Iterator1, class Iterator2 >
        bool operator >( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
            return (lhs.base() < rhs.base());
        }

        template<class Iterator1, class Iterator2 >
        bool operator >= ( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
            return (lhs.base() <= rhs.base());
        }

        template<class Iterator1, class Iterator2 >
        bool operator < ( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
            return (lhs.base() > rhs.base());
        }

        template<class Iterator1, class Iterator2 >
        bool operator <= ( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
            return (lhs.base() >= rhs.base());
        }

        template<class Iterator>
        reverse_iterator<Iterator>	operator + (typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> const & rev_it)
        {
            return (rev_it + n);
        }

        template<class Iterator>
        typename reverse_iterator<Iterator>::difference_type	operator-(reverse_iterator<Iterator> const & lhs, reverse_iterator<Iterator> const & rhs)
        {
	        return (rhs.base() - lhs.base());
        }
}

    #endif
