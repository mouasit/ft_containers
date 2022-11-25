#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> > 
    class stack{
        public:
            typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

        protected:
            container_type      container;

        public:
            explicit stack (const container_type& ctnr = container_type()):container(ctnr){};
        
            stack(stack const & rhs) : container(rhs.container) {}
			stack&		operator=(stack const & rhs)
			{
				this->container = rhs.container;
				return *this;
			}
			~stack(){}
            
            bool empty() const 
            { 
                return container.empty();
            }

			size_type size() const
            { 
                return container.size();
            }

            
			value_type& top()
            {
                return container.back();
            }

			const value_type& top() const
            {
                return container.back();
            }

			void push (const value_type& val)
            { 
                container.push_back(val);
            }

			void pop()
            {
                container.pop_back();
            }
        private:
            template <class t, class container>
                friend bool operator== (const stack<t,container>& lhs, const stack<t,container>& rhs);
            template <class t, class container>
                friend bool operator!= (const stack<t,container>& lhs, const stack<t,container>& rhs);
            template <class t, class container>
                friend bool operator<  (const stack<t,container>& lhs, const stack<t,container>& rhs);
            template <class t, class container>
                friend bool operator<= (const stack<t,container>& lhs, const stack<t,container>& rhs);;
            template <class t, class container>
                friend bool operator>  (const stack<t,container>& lhs, const stack<t,container>& rhs);
            template <class t, class container>
                friend bool operator>=  (const stack<t,container>& lhs, const stack<t,container>& rhs);
    };

    template <class t, class container>
    bool operator== (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.container == rhs.container;
    }

	template <class t, class container>
    bool operator!= (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.container != rhs.container;
    }
    
	template <class t, class container>
    bool operator<  (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.container < rhs.container;
    }
	template <class t, class container>
    bool operator<= (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.container <= rhs.container;
    }
	template <class t, class container>
    bool operator>  (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.container > rhs.container;
    }
	template <class t, class container>
    bool operator>=  (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.container >= rhs.container;
    }
}

#endif 