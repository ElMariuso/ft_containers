/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:52 by root              #+#    #+#             */
/*   Updated: 2022/11/25 11:33:53 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* Includes ***************************************************************** */

# include <memory>
# include <iostream>
# include <stdexcept>

/* Class ******************************************************************** */

namespace ft
{
    template <class T, class Alloc = std::allocator<T>>
    class vector
    {
        public:

        /* Member types ************************************************************* */
        /* The first template parameter (T) */
        typedef T                                                       value_type;
        /* The second template parameter (Alloc) */
        typedef Alloc                                                   allocator_type;
        /* allocator_type::reference */
        typedef typename allocator_type::reference                      reference;
        /* allocator_type::const_reference */
        typedef typename allocator_type::const_reference                const_reference;
        /* allocator_type::pointer */
        typedef typename allocator_type::pointer                        pointer;
        /* allocator_type::const_pointer */
        typedef typename allocator_type::const_pointer                  const_pointer;
        /* a random access iterator to value_type */
        typedef ft::random_access_iterator<value_type>                  iterator;
        /* a random access iterator to const value_type */
        typedef ft::random_access_iterator<value_type>                  const_iterator;
        /* reverse_iterator<iterator> */
        typedef ft::reverse_iterator<iterator>                          reverse_iterator;
        /* reverse_iterator<const_iterator> */
        typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
        /* a signal type identical to: iterator_traits<iterator>::difference_type */
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type
        /* an unsigned integral type that can represent any non-negative value of difference_type */
        typedef typename allocator_type::size_type                      size_type

        /* Member function ********************************************************** */
        /***** Basic *****/
        /* Constructor */
        explicit vector (const allocator_type& alloc = allocator_type())
        {

        }

        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        {
            
        }

        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
        {
            
        }

        vector (const vector& x)
        {

        }

        /* Destructor */
        ~vector()
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
        reference front()
        {
            return (this->_start);
        }

        const_reference front() const
        {
            
        }

        /* back */
        reference back()
        {

        }

        const_reference back() const
        {
            
        }

        /***** Iterators *****/
        /* begin */
        iterator begin() { return (_begin); }

        const_iterator begin() const { return (_begin); }

        /* end */
        iterator end() { return (_end); }

        const_iterator end() const { return (_end); }

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
        size_type   max_size() const { return (allocator_type.max_size()); }

        /* reserve */
        void    reserve(size_type n)
        {
            
        }

        /* capacity */
        size_type   capacity() const
        {
            
        }

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
            
        }

        private:
            // value_type      *_data;
            allocator_type  _alloc;
            pointer         _begin;
            pointer         _end;
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
    void    swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
    {
        
    }
}

#endif