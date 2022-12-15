/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:26:52 by mthiry            #+#    #+#             */
/*   Updated: 2022/12/15 17:13:05 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>

# include "../containers/map.hpp"

namespace ft
{
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
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            referencel

        /* Attributes *************************************************************** */
        private:
            T       *node;
            T       *last_node;
            Compare comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree_iterator() {}
        tree_iterator() {}
        tree_iterator() {}

        /* Destructor */
        virtual ~tree_iterator() {}

         /***** Utils Functions *****/
        private:
    };

    /* tree_const_iterator ********************************************************** */
    template <typename T, class Compare>
    class tree_const_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        /* Member types ************************************************************* */
        public:

        /* Attributes *************************************************************** */
        private:
            T       *node;
            T       *last_node;
            Compare comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */

         /***** Utils Functions *****/
        private:
    };

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