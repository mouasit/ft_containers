#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "../utils/pair.hpp"
#include "../utils/avlTree.hpp"
#include "../utils/iterator.hpp"
#include "../utils/Node.hpp"

namespace ft{
    template <typename key, typename value, typename compare = std::less<key>,
    typename Alloc = std::allocator<ft::pair<key, value> > >

    class map{

        public:
        typedef key                                                     key_type;
        typedef value                                                  mapped_type;
        typedef compare                                                key_compare;
        typedef typename ft::pair<key_type, mapped_type>                            value_type;
        typedef Alloc                                                  allocator_type;
        typedef Node<value_type>                                       node_type;
        typedef avl_tree<key_type, mapped_type, node_type,key_compare, allocator_type> avl;

        typedef typename ft::iterator<value_type, node_type, avl>            iterator;
        typedef size_t                                                  size_type;

        avl                                                             avl_inst;
       
       /* explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
            
        }*/

        map(){}
        /*
        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){

        }

        map(const map& x){

        }*/

        // insert

        ft::pair<iterator,bool> insert(const value_type& val){
            ft::pair<iterator,bool> tmp;
            const size_type size = avl_inst.size;

            avl_inst.insert(val);
            tmp.first = iterator(avl_inst.node_insert,&avl_inst);
            if(size == avl_inst.size)
                tmp.second = false;
            else
                tmp.second = false;
            return tmp;
        }

        iterator insert (iterator, const value_type& val){
            return this->insert(val).first;
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last){
            while (first != last) {
                this->insert(*first);
                first++;
            }
        }

        // erase

        void erase (iterator position){
            this->avl_inst.erase(position->first);
        }

        size_type erase (const key_type& k){
            const size_type size = this->avl_inst.size;
            
            this->avl_inst.erase(k);
            if (size == this->avl_inst.size)
                return 0;
            return 1;
        }

        void erase (iterator first, iterator last){
            iterator tmp(first);

            while(first != last){
                tmp++;
                this->erase(first);
                first = tmp;
            }
        }

        bool    empty() const{
            return avl_inst.size == 0;
        }

        iterator begin(){
            node_type *node = NULL;
            if(this->empty())
                node = avl_inst.tmp_node;
            else
                node = avl_inst.getMinValue(avl_inst.root);

            return iterator(node,&avl_inst);
        }

        iterator end(){
            node_type *node = avl_inst.tmp_node;
            return iterator(node,&avl_inst,true);
        }

        size_type size() const{
            return avl_inst.size;
        }
    };

}
#endif