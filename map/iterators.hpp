#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "../utils/pair.hpp"
namespace ft{
    template <typename value_type, typename Node, typename Avl>
    class const_iterator;

    template <typename T, typename Node, typename Avl>
    class iterator{
        public:
        typedef T           value_type;
        typedef value_type* pointer;
        typedef value_type& reference;
        typedef ptrdiff_t   difference_type;
	    typedef std::bidirectional_iterator_tag	iterator_category;

        iterator():avl_tree(),node(){
            this->increase = true;
            this->past_last = false;
        };

        iterator(Node *node, Avl *avl_tree, bool past_last = false):avl_tree(avl_tree),node(node),past_last(past_last){
            this->increase = true;
            this->avl_tree = avl_tree;
            this->node = node;
        }

        iterator(iterator const & src):avl_tree(src.avl_tree),node(src.node)
        {
            this->avl_tree = src.avl_tree;
            this->node = src.node;
            this->past_last = src.past_last;
            this->increase = src.increase;
        }

        ~iterator(){};

        operator const_iterator<value_type,Node, Avl>(){
            return const_iterator<value_type,Node, Avl>(this->node, this->avl_tree,this->past_last);
        }
        
        iterator operator= (const iterator &it){
            this->node = it.node;
            this->avl_tree = it.avl_tree;
            this->past_last =it.past_last;
            return *this;
        }


        iterator operator++(int){

            iterator copy = *this;
            this->node = this->avl_tree->inorder_successor(this->avl_tree->root, this->node->data.first);
            if(this->node == NULL && increase)
            {
                this->node = this->avl_tree->tmp_node;
                increase = false;
            }
            return copy;
        }
        
        iterator operator++(void){

            this->node = this->avl_tree->inorder_successor(this->avl_tree->root, this->node->data.first);
            if(this->node == NULL && increase)
            {
                this->node = this->avl_tree->tmp_node;
                increase = false;
            }
            return *this;
        }

        iterator operator--(int){
            iterator copy = *this;

            if(this->past_last)
            {
                this->node = this->avl_tree->getMaxValue(this->avl_tree->root);
                this->past_last = false;
            }
            else
            {
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
            }
            return copy;
        }


        iterator operator--(void){
            if(this->past_last)
            {
                
                this->node = this->avl_tree->getMaxValue(this->avl_tree->root);
                this->past_last = false;
            }
            else
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
            return *this;
        }

        bool operator== (const iterator &it) const{
            return this->node == it.node;
        }
        
        bool operator!= (const iterator &it){
            return this->node != it.node;
        }

        pointer operator->(void) const{
            return &this->node->data;
        }
        
        reference operator*(void) const{

            return this->node->data;
        }
        
        private:
            Avl   *avl_tree;
            Node  *node;
            bool  past_last;
            bool  increase;
    };

    template <typename T, typename Node, typename Avl>
    class const_iterator{
        public:
        typedef T                               value_type;
        typedef const                           value_type* pointer;
        typedef const                           value_type& reference;
        typedef ptrdiff_t                       difference_type;
	    typedef std::bidirectional_iterator_tag	iterator_category;

        
        const_iterator():avl_tree(),node(){
            this->increase = true;
            this->past_last = false;
        };

        const_iterator ( const Node *node, const Avl *avl_tree,const bool past_last = false):avl_tree(avl_tree),node(node),past_last(past_last){
            this->increase = true;
            this->avl_tree = avl_tree;
            this->node = node;
        }

        const_iterator(const_iterator const & src):avl_tree(src.avl_tree),node(src.node)
        {
            this->avl_tree = src.avl_tree;
            this->node = src.node;
            this->past_last = src.past_last;
            this->increase = src.increase;
        }

        ~const_iterator(){};

        
        const_iterator operator= (const const_iterator &it){
            this->node = it.node;
            this->avl_tree = it.avl_tree;
            this->past_last = it.past_last;
            return *this;
        }

        const_iterator operator++(int){

            const_iterator copy = *this;
            this->node = this->avl_tree->inorder_successor(this->avl_tree->root, this->node->data.first);
            if(this->node == NULL && increase)
            {
                this->node = this->avl_tree->tmp_node;
                increase = false;
            }
            return copy;
        }
        
        const_iterator operator++(void){

            this->node = this->avl_tree->inorder_successor(this->avl_tree->root, this->node->data.first);
            if(this->node == NULL && increase)
            {
                this->node = this->avl_tree->tmp_node;
                increase = false;
            }
            return *this;
        }

        const_iterator operator--(int){
            const_iterator copy = *this;

            if(this->past_last)
            {
                this->node = this->avl_tree->getMaxValue(this->avl_tree->root);
                this->past_last = false;
            }
            else
            {
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
            }
            return copy;
        }


        const_iterator operator--(void){
            if(this->past_last)
            {
                this->node = this->avl_tree->getMaxValue(this->avl_tree->root);
                this->past_last = false;
            }
            else
            {
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
            }
            return *this;
        }

        bool operator== (const const_iterator &it) const{
            return this->node == it.node;
        }
        
        bool operator!= (const const_iterator &it){
            return this->node != it.node;
        }

        pointer operator->(void) const{
            return &this->node->data;
        }
        
        reference operator*(void) const{

            return this->node->data;
        }
        
        private:
            const Avl   *avl_tree;
            const Node  *node;
            bool  past_last;
            bool  increase;
    };
}
#endif