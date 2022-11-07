#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "../utils/pair.hpp"
#include "../utils/avlTree.hpp"

namespace ft{
    template <typename key, typename value, typename compare = std::less<key>,
    typename Alloc = std::allocator<pair<key, value>>>

    class map{

        public:
        typedef key    ketype;
        typedef value mappd_type;
        typedef compare key_compare;
        
    };

}
#endif