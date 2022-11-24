/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:52 by root              #+#    #+#             */
/*   Updated: 2022/11/24 20:56:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* Includes ***************************************************************** */

# include <memory>

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
        // Constructor
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

        // Destructor
        ~vector()
        {
            
        }

        // Assignement operator
        vector& operator=(const vector& x)
        {
            if (x == *this)
                return (*this);
            return (*this);
        }

        /* Iterators */
        // begin
        iterator begin()
        {

        }

        const_iterator begin() const
        {

        }

        // end
        iterator end()
        {

        }

        const_iterator end() const
        {
            
        }

        // rbegin
        reverse_iterator    rbegin()
        {

        }

        const_reverse_iterator rbegin() const
        {
            
        }

        // rend
        reverse_iterator    rend()
        {

        }

        const_reverse_iterator  rend() const
        {

        }

        // Others ?

        /* Capacity */
        // size
        size_type   size() const
        {

        }

        // max_size
        size_type   max_size() const
        {
            
        }

        // resize
        void    resize(size_type n, value_type val = value_type())
        {

        }

        // capacity
        size_type   capacity() const
        {
            
        }

        // empty
        bool    empty() const
        {

        }

        // reserve
        void    reserve(size_type n)
        {
            
        }

        // Others ?

        /* Element access */
        // operator[]
        reference operator[]  (size_type n)
        {

        }

        const_reference operator[] (size_type n) const
        {
            
        }

        // at
        reference at (size_type n)
        {

        }

        const_reference at (size_type n) const
        {

        }

        // front
        reference front()
        {

        }

        const_reference front() const
        {
            
        }

        // data
        reference back()
        {

        }

        const_reference back() const
        {
            
        }

        // Others ?

        /* Modifiers */
        // assign

        // push_back
        void    push_back (const value_type& val)
        {
            
        }

        // pop_back
        void    pop_back()
        {
            
        }

        // insert
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

        // erase
        iterator erase (iterator position)
        {

        }

        iterator erase (iterator first, iterator last)
        {

        }

        // swap
        void    swap(vector& x)
        {
            
        }

        // clear
        void    clear()
        {
            
        }

        // Others ?

        /* Allocator */

        // Others ?

        private:
    };

    /* Non-member function overloads ******************************************** */
    // relational operators
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

    // swap
    template <class T, class Alloc>
    void    swap (vector<T, Alloc>& x, vector<T, Alloc>& y)
    {
        
    }
}

#endif