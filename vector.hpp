/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:52 by root              #+#    #+#             */
/*   Updated: 2022/11/25 19:13:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* Includes ***************************************************************** */

# include <memory>
# include <iostream>
# include <stdexcept>
# include <vector>

/* Includes.h *************************************************************** */

# include "iterators/iterator.hpp"

/* Class ******************************************************************** */

namespace ft
{
    template <class T, class Alloc = std::allocator<T>>
    class vector
    {
        public:

        /* Member types ************************************************************* */
        typedef T                                                       value_type;
        typedef Alloc                                                   allocator_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef ft::random_access_iterator<value_type>                  iterator;
        typedef ft::random_access_iterator<value_type>                  const_iterator;
        typedef ft::reverse_iterator<iterator>                          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
        // typedef typename ft::iterator_traits<iterator>::difference_type difference_type
        typedef typename allocator_type::size_type                      size_type

        /* Member function ********************************************************** */
        /***** Basic *****/
        /* Constructor */
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            this->_alloc(alloc);
            this->_begin = NULL;
            this->_size = 0;
            this->_capacity = 0;
        }

        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        {
            this->_alloc(alloc);
            this->_size = n;
            this->_capacity = n;
            // begin
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
        {
            
        }

        vector (const vector& x)
        {

        }

        /* Destructor */
        virtual ~vector()
        {
            
        }

        /* operator= */
        vector& operator=(const vector& x)
        {
            
        }

        /* assign */
        template <class InputIterator> 
        void assign (InputIterator first, InputIterator last)
        {
            // size_type new_size = blablabla();
        }

        void    assign(size_type n, const value_type& val)
        {
            
        }

        /* get_allocator */
        allocator_type get_allocator() const
        {
            
        }

        /***** Element access *****/
        /* at */
        reference at (size_type n)
        {
            if (n > this->_size)
                throw (out_of_range());
            return (this->_start + n);
        }

        const_reference at (size_type n) const
        {
            if (n > this->_size)
                throw (out_of_range());
            return (this->_start + n);
        }
        
        /* operator[] */
        reference operator[]  (size_type n) { return (this->_start + n); }

        const_reference operator[] (size_type n) const { return (this->_start + n); }

        /* front */
        reference front() { return (this->_start); }

        const_reference front() const { return (this->_start); }

        /* back */
        reference back() { return (this->_start + this->_size - 1); }

        const_reference back() const { return (this->_start + this->_size - 1); }

        /***** Iterators *****/
        /* begin */
        iterator begin() { return (this->_begin); }

        const_iterator begin() const { return (this->_begin); }

        /* end */
        iterator end() { return (this->_start + this->_size); }

        const_iterator end() const { return (this->_start + this->_size); }

        /* rbegin */
        reverse_iterator    rbegin() { return (reverse_iterator(this->end())); }

        const_reverse_iterator rbegin() const { return (reverse_iterator(this->end())); }

        /* rend */
        reverse_iterator    rend() { return (reverse_iterator(this->begin())); }

        const_reverse_iterator  rend() const { return (reverse_iterator(this->begin())); }

        /***** Capacity *****/
        /* empty */
        bool    empty() const { return (this->size() == 0 ? true : false); }
        
        /* size */
        size_type   size() const { return (this->_size) }

        /* max_size */
        size_type   max_size() const { return (this->_alloc.max_size()); }

        /* reserve */
        void    reserve(size_type n)
        {
            
        }

        /* capacity */
        size_type   capacity() const { return (this->_capacity); }

        /***** Modifiers *****/
        /* clear */
        void    clear()
        {
            
        }

        /* insert */
        iterator insert (iterator position, const value_type& val)
        {

        }

        void    insert (iterator position, size_type n, const value_type& val)
        {

        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {
            
        }

        /* erase */
        iterator erase (iterator position)
        {
            
        }

        iterator erase (iterator first, iterator last)
        {

        }

        /* push_back */
        void    push_back (const value_type& val)
        {
            
        }

        /* pop_back */
        void    pop_back()
        {
            
        }

        /* resize */
        void    resize(size_type n, value_type val = value_type())
        {

        }

        /* swap */
        void    swap(vector& x)
        {
            allocator_type  tmp_alloc;
            pointer         tmp_begin;
            size_type       tmp_size;
            size_type       tmp_capacity;

            if (x == *this)
                return ;
            tmp_alloc = this->_alloc;
            tmp_begin = this->_begin;
            tmp_size = this->_size;
            tmp_capacity = this->_capacity;
            this->_alloc = x._alloc;
            this->_begin = x._begin;
            this->_size = x._size;
            this->_capacity = x._capacity;
            x._alloc = tmp_alloc;
            x._begin = tmp_begin;
            x._size = tmp_size;
            x._capacity = tmp_capacity;
        }

        /* Attributes *************************************************************** */
        private:
            allocator_type  _alloc;
            pointer         _begin;
            size_type       _size;
            size_type       _capacity;
    };

    /* Non-member function overloads ******************************************** */
    /* relational operators */
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {

    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {

    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {

    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {

    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {

    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {

    }

    /* swap */
    template <class T, class Alloc>
    void    swap (vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }
}

#endif