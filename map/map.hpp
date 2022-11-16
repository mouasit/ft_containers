#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include "../utils/pair.hpp"
#include "../utils/avlTree.hpp"
#include "../utils/iterators.hpp"
#include "../utils/Node.hpp"

namespace ft{
    template <typename key, typename value, typename Compare = std::less<key>,
    typename Alloc = std::allocator<ft::pair<key, value> > >

    class map{

        public:
        typedef key                                                     key_type;
        typedef value                                                  mapped_type;
        typedef Compare                                                key_compare;
        typedef typename ft::pair<key_type, mapped_type>               value_type;
        typedef Alloc                                                  allocator_type;
        typedef Node<value_type>                                       node_type;
        typedef avl_tree<key_type, mapped_type, node_type,key_compare, allocator_type> avl;

        typedef typename ft::iterator<value_type, node_type, avl>            iterator;
        typedef typename ft::const_iterator<value_type, node_type, avl>      const_iterator;
        typedef typename ft::reverse_iterator<iterator>                      reverse_iterator;
        typedef typename ft::reverse_iterator<iterator>                      const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>                       iterator_traits;
        typedef size_t                                                       size_type;

        avl                                                                  avl_inst;

        map(){}
        
    class value_compare : std::binary_function<value_type, value_type, bool>
	{
		friend class map;
	    protected:
		    Compare	comp;

		    value_compare(Compare c) : comp(c) { }
	    public:
		    bool	operator()(value_type const & x, value_type const & y) const {
			return (comp(x.first, y.first));
		    }
	};
        
        /* ----- Iterators ----- */

        iterator begin(){
            node_type *node = NULL;

            if(this->empty())
                node = avl_inst.tmp_node;
            else
                node = avl_inst.getMinValue(avl_inst.root);

            return iterator(node,&avl_inst);
        }

        const_iterator begin() const{
            
            node_type *node = NULL;
            if(this->empty())
                node = avl_inst.tmp_node;
            else
                node = avl_inst.getMinValue(avl_inst.root);

            std::cout << "return" << std::endl;
            return const_iterator(node,&avl_inst);

        }

        iterator end(){
            node_type *node = avl_inst.tmp_node;
            return iterator(node,&avl_inst,true);
        }

        const_iterator end() const{
            node_type *node = avl_inst.tmp_node;
            return const_iterator(node,&avl_inst,true);
        }

        reverse_iterator rbegin(){
            return reverse_iterator(this->end());
        }

        const reverse_iterator rbegin() const{
            return const_reverse_iterator(this->end());
        }

        reverse_iterator rend(){
            return reverse_iterator(this->begin());
        }

        const_reverse_iterator rend() const{
            return const_reverse_iterator(this->begin());
        }

        /* ----- Capacity ----- */

        bool    empty() const{
            return avl_inst.size == 0;
        }
        
        size_type size() const{
            return avl_inst.size;
        }

        size_type max_size() const{
            return avl_inst._allocator.max_size();
        }
        /* ----- Element access ----- */

        mapped_type& operator[] (const key_type& k){
            ft::pair<iterator,bool>     pair;
            pair = this->insert(ft::make_pair(k,mapped_type()));
            return pair.first->second;
        }

        /* ----- Modifiers ----- */

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

        void swap (map& x){
            this->avl_inst.swap(x.avl_inst);
        }

        void clear(){
            this->avl_inst.clear();
        }

        /* ----- Observers ----- */

        key_compare key_comp() const{
            return this->avl_inst.get_key_compare();
        }

        value_compare value_comp() const{
            return (value_compare(this->key_comp()));
        }

        /* ----- Operations ----- */

        iterator find (const key_type& k){
            node_type   *node = this->avl_inst.search(k);
            return iterator(node, &avl_inst);
        }

        size_type count (const key_type& k) const{
            return this->avl_inst.check_key(k);
        }
    };

}
#endif