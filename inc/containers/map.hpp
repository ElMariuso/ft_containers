/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:46 by root              #+#    #+#             */
/*   Updated: 2022/12/15 15:48:24 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

/* Includes ***************************************************************** */

# include <memory>
# include <stdexcept>
# include <iostream>

# include <map>
# include <iterator>

/* Includes.h *************************************************************** */

# include "../utils/algorithm.hpp"
# include "../utils/iterator.hpp"
# include "../utils/type_traits.hpp"
# include "../utils/utility.hpp"
# include "../utils/functional.hpp"
# include "../utils/tree.hpp"

/* Class ******************************************************************** */

namespace ft
{   
    /* map_iterator ************************************************************* */
    template <class TreeIterator>
    class map_iterator
    {
        
    };

    /* const_map_iterator ******************************************************* */
    template <class TreeIterator>
    class const_map_iterator
    {
        
    };

    /* map ********************************************************************** */
    template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        /* Member types ************************************************************* */
        public:
            typedef Key                                     key_type;
            typedef T                                       mapped_type;
            typedef typename ft::pair<const Key, T>         value_type;
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef Compare                                 key_compare;
            typedef Allocator                               allocator_type;
            typedef value_type&                             reference;
            typedef const value_type&                       const_reference;
            typedef typename allocator_type::pointer        pointer;
            typedef typename allocator_type::const_pointer  const_pointer;
            typedef 
            // Need to make iterators
            typedef ft::reverse_iterator<iterator>          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;
        
        /* Member classes *********************************************************** */
        class value_compare: ft::binary_function<value_type, value_type, bool>
        {
            friend class ft::map;
            
            /* Member types ************************************************************* */
            public:
                typedef bool        result_type;
                typedef value_type  first_argument_type;
                typedef value_type  second_argument_type;
            
            /* Attributes *************************************************************** */
            protected:
                /* Reals attributes */
                Compare comp;
                /* Constructor */
                value_compare(Compare c): comp(c) {}
            
            public:
            /* Member functions ********************************************************* */
            /* operator() */
            bool operator()(const value_type &x, const value_type &y) const
            { return (comp(x.first, y.first)); }
        }

        /* Attributes *************************************************************** */
        private:
        protected:

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        explicit map(const Compare &comp, const Allocator &alloc = Allocator())
        {

        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator())
        {

        }

        map(const map &x)
        {

        }

        /* Destructor */
        ~map() {}

        /* operator= */
        map& operator=(const map &x)
        {

        }

        /* get_allocator */
        allocator_type get_allocator() const
        {
            
        }

        /***** Element access *****/
        /* at */
        mapped_type& at(const key_type &key)
        {

        }
        const mapped_type& at(const key_type &key) const
        {

        }

        /* operator[] */
        mapped_type& operator[](const key_type &key)
        {
            
        }

        /***** Iterators *****/
        /* begin */
        iterator begin()
        {

        }
        const_iterator begin() const
        {

        }

        /* end */
        iterator end()
        {

        }
        const_iterator end() const
        {

        }

        /* rbegin */
        reverse_iterator rbegin()
        {

        }
        const_reverse_iterator rbegin() const
        {

        }

        /* rend */
        reverse_iterator rend()
        {

        }
        const_reverse_iterator rend() const
        {

        }

        /***** Capacity *****/
        /* empty */
        bool empty() const
        {

        }
        
        /* size */
        size_type size() const
        {
            
        }

        /* max_size */
        size_type max_size() const
        {

        }

        /***** Modifiers *****/
        /* clear */
        void clear()
        {

        }

        /* insert */
        ft::pair<iterator, bool> insert(const value_type &val)
        {

        }

        iterator insert(iterator position, const value_type &val)
        {

        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {

        }

        /* erase */
        void erase(iterator position)
        {

        }

        size_type erase(const key_type &key)
        {

        }

        void erase(iterator first, iterator last)
        {

        }

        /* swap */
        void swap (map &x)
        {

        }

        /***** Lookup *****/
        /* count */
        size_type count(const key_type &key) const
        {

        }

        /* find */
        iterator find(const key_type &key)
        {

        }

        const_iterator find(const key_type &key) const
        {

        }

        /* equal_range */
        ft::pair<iterator, iterator> equal_range(const key_type &key)
        {

        }

        ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
        {

        }

        /* lower_bound */
        iterator lower_bound(const key_type &key)
        {

        }

        const_iterator lower_bound(const key_type &key) const
        {

        }

        /* upper_bound */
        iterator lower_bound(const key_type &key)
        {

        }

        const_iterator lower_bound(const key_type &key) const
        {
            
        }

        /***** Observers *****/
        /* key_comp */
        key_compare key_comp() const
        {

        }

        /* value_comp */
        ft::map::value_compare value_comp() const
        {
            
        }

        /***** Utils Functions *****/
        private:
    };
    /* Non-member function overloads ******************************************** */
    /* relational operators */
    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        
    }
}

#endif