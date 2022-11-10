#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "../utils/pair.hpp"
#include "../utils/avlTree.hpp"
#include "../utils/iterator.hpp"

namespace ft{
    template <typename key, typename value, typename compare = std::less<key>,
    typename Alloc = std::allocator<pair<key, value>>>

    class map{

        public:
        typedef key                                          key_type;
        typedef value                                        mapped_type;
        typedef compare                                      key_compare;
        typedef pair<key_type, mapped_type>                  value_type;
        typedef Alloc                                        allocator_type;
        typedef avl_tree<key_type, mapped_type, key_compare> avl;
        typedef typename ft::iterator<value_type>            iterator;
        typedef size_t                                       size_type;

        avl avl_inst;
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
            
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){

        }

        map(const map& x){

        }

        void    insert (const value_type& val){
            avl_inst.insert(val);
        }

        bool    empty() const{
            return avl_inst.size == 0;
        }

        iterator begin(){
            value_type *pair = &avl_inst.getMinValue(avl_inst.root);
            return iterator(pair);
        }

        size_type size() const{
            return avl_inst.size;
        }
    };

}
#endif