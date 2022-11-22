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
        typedef Iterator                                                  iterator_type;
        typedef typename iterator_traits<Iterator>::pointer               pointer;
        typedef typename iterator_traits<Iterator>::reference            reference;
        typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;
        typedef typename iterator_traits<Iterator>::difference_type      difference_type;


        reverse_iterator():base_it(){};

        explicit reverse_iterator(iterator_type it):base_it(it){}

        template <class Iter>  reverse_iterator (reverse_iterator<Iter> const & rev_it):base_it(rev_it.base()){}

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

        reference operator*() const{
            iterator_type temp = this->base_it;
            return (*(--temp));
        }

        pointer operator->() const{
            iterator_type temp = this->base_it;
            return ((--temp).operator->());
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
}

    #endif
