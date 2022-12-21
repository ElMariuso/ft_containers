/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:46 by root              #+#    #+#             */
/*   Updated: 2022/12/21 18:37:20 by mthiry           ###   ########.fr       */
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
    // /* map_iterator ************************************************************* */
    // template <class TreeIterator>
    // class map_iterator
    // {
        
    // };

    // /* const_map_iterator ******************************************************* */
    // template <class TreeIterator>
    // class const_map_iterator
    // {
        
    // };

    /* map ********************************************************************** */
    template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        /* Member types ************************************************************* */
        public:
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef typename ft::pair<const Key, T>                             value_type;
            typedef std::size_t                                                 size_type;
            typedef std::ptrdiff_t                                              difference_type;
            typedef Compare                                                     key_compare;
            typedef Allocator                                                   allocator_type;
            typedef value_type&                                                 reference;
            typedef const value_type&                                           const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef typename ft::tree<value_type, key_compare>::iterator        iterator;
            typedef typename ft::tree<value_type, key_compare>::const_iterator  const_iterator;
            typedef ft::reverse_iterator<iterator>                              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;
        
        /* Member classes *********************************************************** */
        class value_compare: ft::binary_function<value_type, value_type, bool>
        {
            friend class ft::map<key_type, mapped_type, key_compare, Allocator>;
            
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
        };

        /* Attributes *************************************************************** */
        private:
        protected:
            allocator_type                  _alloc;
            Compare                         _comp;
            ft::tree<value_type, Compare>   _tree;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        explicit map(const Compare &comp, const Allocator &alloc = Allocator()): _alloc(alloc), _comp(comp), _tree() { }

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL):
            _alloc(alloc), _comp(comp), _tree()
        { this->insert(first, last); }

        map(const map &x): _alloc(x._alloc), _comp(x._comp), _tree()
        { this->insert(x.begin(). x.end()); }

        /* Destructor */
        ~map() { this->clear(); }

        /* operator= */
        map& operator=(const map &x)
        {
            if (x == *this)
                return (*this);
            this->clear();
            this->insert(x.begin(), x.end());
            return (*this);
        }

        /* get_allocator */
        allocator_type get_allocator() const { return (this->_alloc); }

        /***** Element access *****/
        /* at */
        // mapped_type& at(const key_type &key)
        // {

        // }
        // const mapped_type& at(const key_type &key) const
        // {

        // }

        /* operator[] */
        mapped_type& operator[](const key_type &key)
        {
            iterator    tmp;

            tmp = this->find(key);
            if (tmp == this->end())
                this->insert(ft::make_pair(key, mapped_type()));
            tmp = this->find(key);
            return ((*tmp).second);
        }

        /***** Iterators *****/
        /* begin */
        iterator begin() { return (iterator(this->_tree.last_node->left, this->_tree.last_node)); }
        const_iterator begin() const { return (const_iterator(this->_tree.last_node->left, this->_tree.last_node)); }

        /* end */
        iterator end() { return (iterator(this->_tree.last_node, this->_tree.last_node)); }
        const_iterator end() const { return (const_iterator(this->_tree.last_node, this->_tree.last_node)); }

        /* rbegin */
        reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }

        /* rend */
        reverse_iterator rend() { return (reverse_iterator(this->begin())); }
        const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }

        /***** Capacity *****/
        /* empty */
        bool empty() const { return (this->_tree.node->parent == this->_tree.node); }
        
        /* size */
        size_type size() const { return (this->_tree.node->value.first); }

        /* max_size */
        size_type max_size() const { return (this->_tree.max_size()); }

        /***** Modifiers *****/
        /* clear */
        void clear() { this->erase(this->begin(), this->end()); }

        /* insert */
        ft::pair<iterator, bool> insert(const value_type &val) { return (this->_tree.insert(val)); }

        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            return (this->_tree.insert(val).first);
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            difference_type n;
            
            n = last - first;
            while (n--)
                this->insert(*(first++));
        }

        /* erase */
        void erase(iterator position) { this->erase((*position).first); }

        size_type erase(const key_type &key)
        {
            if (this->find(key) == this->end())
                return (0);
            this->_tree.destroy(ft::make_pair(key, mapped_type()));
            return (1);
        }

        void erase(iterator first, iterator last)
        {
            while (first != last)
                this->erase((*(first++)).first);
        }

        /* swap */
        void swap (map &x) { this->_tree.swap(x._tree); }

        /***** Lookup *****/
        /* count */
        size_type count(const key_type &key) const
        {
            const_iterator  begin;
            const_iterator  end;

            begin = this->begin();
            end = this->end();
            while (begin != end)
                if ((*(begin++)).first == key)
                    return (1);
            return (0);
        }

        /* find */
        iterator find(const key_type &key) { return (iterator(this->_tree.search(ft::make_pair(key, mapped_type())), this->_tree.last_node)); }
        const_iterator find(const key_type &key) const { return (const_iterator(this->_tree.search(ft::make_pair(key, mapped_type())), this->_tree.last_node)); }

        /* equal_range */
        ft::pair<iterator, iterator> equal_range(const key_type &key) { return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); }
        ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const { return (ft::make_pair(this->lower_bound(key), this->upper_bound(key))); }

        /* lower_bound */
        iterator lower_bound(const key_type &key)
        {
            iterator    begin;
            iterator    end;

            begin = this->begin();
            end = this->end();
            while (begin != end)
            {
                if (this->_comp((*begin).first, key) == false)
                    break ;
                begin++;
            }
            return (begin);
        }

        const_iterator lower_bound(const key_type &key) const { return (const_iterator(this->lower_bound(key))); }

        /* upper_bound */
        iterator upper_bound(const key_type &key)
        {
            iterator    begin;
            iterator    end;

            begin = this->begin();
            end = this->end();
            while (begin != end)
            {
                if (this->_comp(key, (*begin).first))
                    break ;
                begin++;
            }
            return (begin);
        }

        const_iterator upper_bound(const key_type &key) const { return (const_iterator(this->upper_bound(key))); }

        /***** Observers *****/
        /* key_comp */
        key_compare key_comp() const { return (key_compare()); }

        /* value_comp */
        value_compare value_comp() const { return (value_compare(key_compare())); }

        /***** Utils Functions *****/
        private:
    };
    // /* Non-member function overloads ******************************************** */
    // /* relational operators */
    // template <class Key, class T, class Compare, class Alloc>
    // bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    // {
        
    // }

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    // {
        
    // }

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    // {
        
    // }

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    // {
        
    // }

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    // {
        
    // }

    // template <class Key, class T, class Compare, class Alloc>
    // bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    // {
        
    // }
}

#endif