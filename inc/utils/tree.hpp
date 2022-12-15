/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:26:52 by mthiry            #+#    #+#             */
/*   Updated: 2022/12/15 22:27:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>

# include "../containers/map.hpp"

namespace ft
{
    /* functions_utils ********************************************************** */
    /* tree_is_left_child */
    template <class NodePtr>
    bool tree_is_left_child(NodePtr x)
    {
        return (x == x->parent->left);
    }

    /* tree_min */
    template <class NodePtr>
    NodePtr tree_min(NodePtr x)
    {
        while (x->left != NULL)
            x = x->left;
        return (x);
    }

    /* tree_max */
    template <class NodePtr>
    NodePtr tree_max(NodePtr x)
    {
        while (x->right != NULL)
            x = x->right;
        return (x);
    }

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

    /* tree_leaf */
    template <class NodePtr>
    NodePtr tree_leaf(NodePtr x)
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
    template <class NodePtr>
    void tree_left_rotate(NodePtr x)
    {
        NodePtr y;

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
    template <class NodePtr>
    void tree_right_rotate(NodePtr x)
    {
        NodePtr y;

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

    /* tree_balance_after_insert */

    /* tree_remove */

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
        parent parent_unsafe() const { return (this->parent); }

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
            iter_pointer    nptr;
            Compare         comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree_iterator(iter_pointer p): nptr(p) {}

        /* operator* */
        reference operator*() const { return (*(this->nptr)); }

        /* operator-> */
        pointer operator->() { return (std::addressof(this->operator*())); }

        /* operator++ */
        tree_iterator& operator++()
        {
            this->nptr = static_cast<iter_pointer>(tree_next<iter_pointer>(this->nptr));
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
            this->nptr = static_cast<iter_pointer>(tree_prev<iter_pointer>(this->nptr));
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
        bool operator==(const tree_iterator &x, const tree_iterator &y)
        { return (x.nptr == y.nptr); }

        /* operator!= */
        bool operator!=(const tree_iterator &x, const tree_iterator &y)
        { return (!(x == y)); }

        /* has_next */
        bool has_next() const { return (this->nptr->next != NULL) };

        /* has_prev */
        bool has_prev() const { return (this->nptr->prev != NULL) };

        /***** Utils Functions *****/
        private:
    };

    // /* tree_const_iterator ********************************************************** */
    // template <typename T, class Compare>
    // class tree_const_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    // {
    //     /* Member types ************************************************************* */
    //     public:

    //     /* Attributes *************************************************************** */
    //     private:
    //         T       *node;
    //         Compare comp;

    //     public:
    //     /* Member functions ********************************************************* */
    //     /***** Basic *****/
    //     /* Constructor */

    //     /***** Utils Functions *****/
    //     private:
    // };

    /* tree ********************************************************************* */
    template <class T, class Compare = ft::less<T>, class Node = ft::tree_node<T>,
        class Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class tree
    {
        public:

        private:

        public:

        private:  
    };
}

#endif