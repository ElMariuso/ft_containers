/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:26:52 by mthiry            #+#    #+#             */
/*   Updated: 2022/12/21 18:55:47 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>

# include "../containers/map.hpp"

namespace ft
{
    /* tree_next */
    template <class NodePtr>
    NodePtr tree_next(NodePtr x)
    {
        NodePtr xx;

        if (x->right != NULL)
            return (tree_min(x->right));
        xx = x;
        while (!tree_is_left_child(xx))
            xx = xx->parent_unsafe();
        return (xx->parent_unsafe());
    }

    /* tree_prev */
    template <class NodePtr>
    NodePtr tree_prev(NodePtr x)
    {
        NodePtr xx;
        
        if (x->left != NULL)
            return (tree_max(x->left));
        xx = x;
        while (tree_is_left_child(xx))
            xx = xx->parent_unsafe();
        return (xx->parent_unsafe()); 
    }
    /* tree_node **************************************************************** */
    template <typename T>
    class tree_node
    {
        public:
            typedef T   value_type;

            value_type  value;
            tree_node   *parent;
            tree_node   *left;
            tree_node   *right;
        
        /* Constructor */
        tree_node(): value(), parent(NULL), left(NULL), right(NULL) {}
        tree_node(tree_node *left = NULL, tree_node *right = NULL, tree_node *parent = NULL):
            value(), parent(parent), left(left), right(right) {}
        tree_node(const value_type &val, tree_node *left = NULL, tree_node *right = NULL, tree_node *parent = NULL):
            value(val), parent(parent), left(left), right(right) {}
        tree_node(const tree_node &x): value(x.value), left(x.left), right(x.right), parent(x.parent) {}

        /* Destructor */
        virtual ~tree_node() {}

        /* operator= */
        tree_node& operator=(const tree_node &x)
        {
            if (x == *this)
                return (*this);
            this->value = x.value;
            this->parent = x.parent;
            this->left = x.left;
            this->right = x.right;
            return (*this);
        }

        /* operator== */
        bool operator==(const tree_node &x) { return (this->value == x.value); }

        /* parent_unsafe */
        tree_node *parent_unsafe() const { return (this->parent); }

        /* set_parent */
        void set_parent(tree_node *p) { this->parent = p; }
    };
    
    /* tree_iterator ************************************************************ */
    template <typename T, class Compare>
    class tree_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        /* Member types ************************************************************* */
        public:
            typedef typename T::value_type                                                                  value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;
            typedef T*                                                                                      iter_pointer;

        /* Attributes *************************************************************** */
        private:
            iter_pointer    node;
            iter_pointer    last_node;
            Compare         comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree_iterator(const Compare &comp = Compare()): node(), last_node(), comp(comp) {}
        tree_iterator(iter_pointer node, iter_pointer last_node, const Compare &comp = Compare()): node(node), last_node(last_node), comp(comp) {}
        tree_iterator(const tree_iterator &x): node(x.node), last_node(x.last_node), comp() {}

        /* Destructor */
        virtual ~tree_iterator() {}

        /* operator= */
        tree_iterator& operator=(const tree_iterator &x)
        {
            if (*this == x)
                return (*this);
            this->node = x.node;
            this->last_node = x.last_node;
            this->comp = x.comp;
            return (*this);
        }

        /* operator* */
        reference operator*() const { return (this->node->value); }

        /* operator-> */
        pointer operator->() { return (&this->node->value); }

        /* operator++ */
        tree_iterator& operator++()
        {
            this->node = static_cast<iter_pointer>(tree_next<iter_pointer>(this->node));
            return (*this);
        }

        /* operator++(int) */
        tree_iterator operator++(int)
        {
            tree_iterator t(*this);
            
            ++(*this);
            return (t);
        }

        /* operator-- */
        tree_iterator& operator--()
        {
            this->node = static_cast<iter_pointer>(tree_prev<iter_pointer>(this->node));
            return (*this);
        }

        /* operator--(int) */
        tree_iterator operator--(int)
        {
            tree_iterator t(*this);
            
            --(*this);
            return (t);
        }

        /* operator== */
        bool operator==(const tree_iterator &x)
        { return (this->node == x.node); }

        /* operator!= */
        bool operator!=(const tree_iterator &x)
        { return (this->node != x.node); }

        /***** Utils Functions *****/
        private:
    };

    /* tree_const_iterator ********************************************************** */
    template <typename T, class Compare>
    class tree_const_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        /* Member types ************************************************************* */
        public:
            typedef typename T::value_type                                                                  value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;
            typedef T*                                                                                      iter_pointer;

        /* Attributes *************************************************************** */
        private:
            iter_pointer    node;
            iter_pointer    last_node;
            Compare         comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree_const_iterator(const Compare &comp = Compare()): node(), last_node(), comp(comp) {}
        tree_const_iterator(iter_pointer node, iter_pointer last_node, const Compare &comp = Compare()): node(node), last_node(last_node), comp(comp) {}
        tree_const_iterator(const tree_const_iterator &x): node(x.node), last_node(x.last_node), comp() {}

        /* Destructor */
        virtual ~tree_const_iterator() {}

        /* operator= */
        tree_const_iterator& operator=(const tree_const_iterator &x)
        {
            if (*this == x)
                return (*this);
            this->node = x.node;
            this->last_node = x.last_node;
            this->comp = x.comp;
            return (*this);
        }

        /* operator* */
        reference operator*() const { return (this->node->value); }

        /* operator-> */
        pointer operator->() { return (&this->node->value); }

        /* operator++ */
        tree_const_iterator& operator++()
        {
            this->node = static_cast<iter_pointer>(tree_next<iter_pointer>(this->node));
            return (*this);
        }

        /* operator++(int) */
        tree_const_iterator operator++(int)
        {
            tree_const_iterator t(*this);
            
            ++(*this);
            return (t);
        }

        /* operator-- */
        tree_const_iterator& operator--()
        {
            this->node = static_cast<iter_pointer>(tree_prev<iter_pointer>(this->node));
            return (*this);
        }

        /* operator--(int) */
        tree_const_iterator operator--(int)
        {
            tree_const_iterator t(*this);
            
            --(*this);
            return (t);
        }

        /* operator== */
        bool operator==(const tree_const_iterator &x)
        { return (this->node == x.node); }

        /* operator!= */
        bool operator!=(const tree_const_iterator &x)
        { return (this->node != x.node); }

        /***** Utils Functions *****/
        private:
    };

    /* tree ********************************************************************* */
    template <class T, class Compare = ft::less<T>, class Node = ft::tree_node<T>,
        class Allocator = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class tree
    {
        /* Member types ************************************************************* */
        public:
            typedef T                                           value_type;
            typedef Compare                                     value_compare;
            typedef Allocator                                   allocator_type;
            typedef Node_Alloc                                  node_alloc;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef Node                                        node_type;
            typedef Node*                                       node_pointer;
            typedef ft::tree_iterator<Node, Compare>            iterator;
            typedef ft::tree_const_iterator<Node, Compare>      const_iterator;

        /* Attributes *************************************************************** */
        private:
            node_pointer    last_node;
            node_alloc      _node_alloc;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree(const node_alloc &node_alloc_t = node_alloc()): _node_alloc(node_alloc_t)
        {
            this->last_node = this->_node_alloc.allocate(1);
            this->_node_alloc.construct(this->last_node, Node(this->last_node, this->last_node, this->last_node));
        }

        /* Destructor */
        ~tree()
        {
            this->_node_alloc.destroy(this->last_node);
            this->_node_alloc.deallocate(this->last_node, 1);
        }

        /* insert */
        ft::pair<iterator, bool> insert(value_type insert)
        {
            bool    side;
            Node    *new_node;
            Node    *prev_node;
            Node    *first_node;

            side = true;
            new_node = this->_node_alloc.allocate(1);
            prev_node = this->last_node;
            first_node = this->last_node->parent;
            while (first_node != this->last_node)
            {
                int curkey;
                curkey = first_node->value.first;
                if (curkey == insert.first)
                    return (ft::make_pair(iterator(first_node, last_node), false));
                prev_node = first_node;
                if (insert.first > curkey)
                {
                    side = true;
                    first_node = first_node->right;
                }
                else
                {
                    side = false;
                    first_node = first_node->left;
                }
            }
            this->_node_alloc.construct(new_node, Node(insert, this->last_node, this->last_node, prev_node));
            if (prev_node == this->last_node)
                this->last_node->parent = new_node;
            else if (side == true)
                prev_node->right = new_node;
            else
                prev_node->left = new_node;
            this->last_node->left = this->tree_min(this->last_node->parent);
            this->last_node->right = this->tree_max(this->last_node->parent);
            this->last_node->value.first++;
            return (ft::make_pair(iterator(new_node, last_node), true));
        }

        /* destroy */
        void    destroy(node_pointer node, value_type remove)
        {
            if (remove.first < node->value.first)
            {
                this->destroy(node->left, remove);
                return ;
            }
            if (remove.first > node->value.first)
            {
                this->destroy(node->right, remove);
                return ;
            }
            if (node->left != this->last_node && node->right != this->last_node)
            {
                node_pointer    successor;
                
                successor = this->tree_min(node->right);
                this->replaceDoubleChildren(node, successor);
                return ;
            }
            else if (node->left != this->last_node)
                this->replaceAndReset(node, node->left);
            else if (node->right != this->last_node)
                this->replaceAndReset(node, node->right);
            else
                this->replaceAndReset(node, this->last_node);
        }

        /* search */
        node_pointer search(value_type search)
        {
            node_pointer    node;

            node = this->last_node->parent;
            while (node != this->last_node)
            {
                if (node->value.first == search.first)
                    return (node);
                if (node->value.first > search.first)
                    node = node->left;
                else
                    node = node->right;
            }
            return (node);
        }

        /* swap */
        void swap(tree &x)
        {
            if (*this == x)
                return ;
            ft::swap(this->last_node, x.last_node);
			ft::swap(this->_node_alloc, x._node_alloc);
        }

        /* max_size */
        size_type max_size() const { return (this->_node_alloc.max_size()); }

        /***** Utils Functions *****/
        private:
        /* replaceAndReset */
        void    replaceAndReset(node_pointer node, node_pointer new_node)
        {
            if (node->parent != this->last_node)
            {
                if (this->last_node->parent == node)
                    this->last_node->parent = new_node;
                if (node == node->parent->left)
                    node->parent->left = new_node;
                else
                    node->parent->right = new_node;
            }
            else
                this->last_node->parent = node->parent;
            this->last_node->left = this->tree_min(this->last_node->parent);
            this->last_node->right = this->tree_max(this->last_node->parent);
            this->last_node->value.first--;
            new_node->parent = node->parent;
            this->_node_alloc.destroy(node);
            this->_node_alloc.deallocate(node, 1);
        }

        /* replaceDoubleChildren */
        void    replaceDoubleChildren(node_pointer &remove, node_pointer new_node)
        {
            if (new_node->parent != this->last_node)
            {
                if (new_node->parent != remove)
                    new_node->parent->left = new_node->right;  
            }
            new_node->parent = remove->parent;
            if (remove->left != new_node)
                new_node->left = remove->left;
            if (remove->right != new_node)
                new_node->right = remove->right;
            if (remove->parent != this->last_node)
            {
                if (remove->parent->left == remove)
                    remove->parent->left = new_node;
                else if (remove->parent->right == remove)
                    remove->parent->right = new_node;
            }
            else
                this->last_node->parent = new_node;
            if (remove->left != this->last_node && remove->left != new_node)
                remove->left->parent = new_node;
            if (remove->right != this->last_node && remove->right != new_node)
                remove->right->parent = new_node;
            if (remove->parent != this->last_node)
            {
                remove->left = this->last_node;
                remove->right = this->last_node;
                remove->parent = new_node;
            }
            this->last_node->left = this->tree_min(this->last_node->parent);
            this->last_node->right = this->tree_max(this->last_node->parent);
            this->last_node->value.first--;
            this->_node_alloc.destroy(remove);
            this->_node_alloc.deallocate(remove, 1);
        }

        /* functions_utils ********************************************************** */
        /* tree_is_left_child */
        bool tree_is_left_child(node_pointer x)
        {
            return (x == x->parent->left);
        }

        /* tree_min */
        node_pointer tree_min(node_pointer x)
        {
            while (x->left != NULL)
                x = x->left;
            return (x);
        }

        /* tree_max */
        node_pointer tree_max(node_pointer x)
        {
            while (x->right != NULL)
                x = x->right;
            return (x);
        }

        /* tree_next */
        node_pointer tree_next(node_pointer x)
        {
            node_pointer xx;

            if (x->right != NULL)
                return (tree_min(x->right));
            xx = x;
            while (!tree_is_left_child(xx))
                xx = xx->parent_unsafe();
            return (xx->parent_unsafe());
        }

        /* tree_prev */
        node_pointer tree_prev(node_pointer x)
        {
            node_pointer xx;
        
            if (x->left != NULL)
                return (tree_max(x->left));
            xx = x;
            while (tree_is_left_child(xx))
                xx = xx->parent_unsafe();
            return (xx->parent_unsafe()); 
        }

        /* tree_leaf */
        node_pointer tree_leaf(node_pointer x)
        {
            while (true)
            {
                if (x->left != NULL)
                {
                    x = x->left;
                    continue ;
                }
                if (x->right != NULL)
                {
                    x = x->right;
                    continue ;
                }
                break ;
            }
            return (x);
        }

        /* tree_left_rotate */
        void tree_left_rotate(node_pointer x)
        {
            node_pointer y;

            y = x->right;
            x->right = y->left;
            if (x->right != NULL)
                x->right->set_parent(x);
            y->parent = x->parent;
            if (tree_is_left_child(x))
                x->parent->left = y;
            else
                x->parent_unsafe()->right = y;
            y->left = x;
            x->set_parent(y);
        }

        /* tree_right_rotate */
        void tree_right_rotate(node_pointer x)
        {
            node_pointer y;

            y = x->left;
            x->left = y->right;
            if (x->left != NULL)
                x->left->set_parent(x);
            y->parent = x->parent;
            if (tree_is_left_child(x))
                x->parent->left = y;
            else
                x->parent_unsafe()->right = y;
            y->right = x;
            x->set_parent(y);
        }
    };
}

#endif