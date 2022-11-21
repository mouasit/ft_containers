#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair() : first(), second(){}

        template<class U, class V>
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {} 

        pair (const first_type& a, const second_type& b) :first(a), second(b) {}

        pair& operator= (const pair &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
    };
    template <typename T1, typename T2>
    pair<T1,T2> make_pair(const T1 value1, const T2 value2)
    {
        pair<T1,T2> pair(value1,value2);
        return (pair);
    }

        /* ----- Relational Operators ----- */
    
    template<class T1, class T2>
    bool	operator==(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
    {
	    return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

template<class T1, class T2>
bool	operator!=(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (!(lhs == rhs));
}

template<class T1, class T2>
bool	operator<(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	if (lhs.first < rhs.first)
		return (true);
	return (!(rhs.first < lhs.first) && (lhs.second < rhs.second));
}

template<class T1, class T2>
bool	operator<=(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (!(rhs < lhs));
}

template<class T1, class T2>
bool	operator>(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (rhs < lhs);
}

template<class T1, class T2>
bool	operator>=(pair<T1,T2> const & lhs, pair<T1,T2> const & rhs)
{
	return (!(lhs < rhs));
}

}

#endif