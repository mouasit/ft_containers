#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "../map/map.hpp"
#include "./pair.hpp"
namespace ft{
    template <typename value_type, typename Node, typename Avl>
    class const_iterator;

    template <typename value_type, typename Node, typename Avl>
    class iterator{
        public:
        typedef value_type* pointer;
        typedef value_type& reference;
        iterator(){
            this->increase = true;
            this->past_last = false;
        };

        iterator(Node *node, Avl *avl_tree, bool past_last = false){
            if(past_last)
                this->past_last = true;
            this->increase = true;
            this->avl_tree = avl_tree;
            this->node = node;
        }

        operator const_iterator<value_type,Node, Avl>(){
            return const_iterator<value_type,Node, Avl>(this->node, this->avl_tree);
        }
        
        iterator operator= (const iterator &it){
            this->node = it.node;
            this->avl_tree = it.avl_tree;
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
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
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

        bool operator== (const iterator &it){
            return this->node == it.node;
        }
        
        bool operator!= (const iterator &it){
            return this->node != it.node;
        }

        pointer operator->(void){
            return &this->node->data;
        }
        
        reference operator*(void){

            return this->node->data;
        }
        
        

        ~iterator(){};
        
        private:
            Avl   *avl_tree;
            Node  *node;
            bool  past_last;
            bool  increase;
    };
    
    template <typename value_type, typename Node, typename Avl>
    class const_iterator{
        public:
        
        typedef const value_type* pointer;
        typedef const value_type& reference;
        const_iterator(){
            this->increase = true;
            this->past_last = false;
        };

        const_iterator(Node *node, Avl *avl_tree, bool past_last = false){
            if(past_last)
                this->past_last = true;
            this->increase = true;
            this->avl_tree = avl_tree;
            this->node = node;
        }
        
        const_iterator operator= (const const_iterator &it){
            this->node = it.node;
            this->avl_tree = it.avl_tree;
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
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
            return copy;
        }


        const_iterator operator--(void){
            if(this->past_last)
            {
                this->node = this->avl_tree->getMaxValue(this->avl_tree->root);
                this->past_last = false;
            }
            else
                this->node = this->avl_tree->inorder_predecessor(this->avl_tree->root, this->node->data.first);
            return *this;
        }

        bool operator== (const const_iterator &it){
            return this->node == it.node;
        }
        
        bool operator!= (const const_iterator &it){
            return this->node != it.node;
        }

        pointer operator->(void){
            return &this->node->data;
        }
        
       reference operator*(void){

            return this->node->data;
        }

        ~const_iterator(){};
        
        private:
            Avl   *avl_tree;
            Node  *node;
            bool  past_last;
            bool  increase;
    };
}
#endif