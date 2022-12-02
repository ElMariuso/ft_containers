/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:52 by root              #+#    #+#             */
/*   Updated: 2022/12/02 20:12:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* Includes ***************************************************************** */

# include <memory>
# include <stdexcept>

/* Includes.h *************************************************************** */

# include "../utils/algorithm.hpp"
# include "../utils/iterator.hpp"
# include "../utils/type_traits.hpp"
# include "../utils/utility.hpp"

/* Class ******************************************************************** */

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        /* Member types ************************************************************* */
        public:
            typedef T                                                           value_type;
            typedef Alloc                                                       allocator_type;
            typedef value_type&                                                 reference;
            typedef const value_type&                                           const_reference;
            typedef typename allocator_type::size_type                          size_type;
            typedef typename ft::iterator_traits<value_type>::difference_type   difference_type;
            typedef typename ft::iterator_traits<value_type>::pointer           pointer;
            typedef const typename ft::iterator_traits<value_type>::pointer     const_pointer;
            typedef pointer                                                     iterator;
            typedef const_pointer                                               const_iterator;
            typedef ft::reverse_iterator<iterator>                              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;
        
        /* Attributes *************************************************************** */
        private:
            allocator_type  _alloc;
            pointer         _begin;
            size_type       _size;
            size_type       _capacity;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        vector(): _alloc(Alloc()), _begin(NULL), _size(0), _capacity(0) {}

        explicit vector(const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) { }

        explicit vector(size_type n, const value_type &val = value_type(),
            const allocator_type &alloc = allocator_type())
        {
            this->_alloc = alloc;
            this->_begin = this->_alloc.allocate(n);
            this->_size = n;
            this->_capacity = n;
            for (size_t i = 0; i != n; i++)
                this->_alloc.construct(this->_begin + i, val);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
            const allocator_type &alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
        {
            difference_type n;

            n = ft::distance(first, last);
            this->_alloc = alloc;
            this->_begin = this->_alloc.allocate(n);
            this->_size = n;
            this->_capacity = n;
            for (size_t i = 0; first != last; ++first, ++i)
            {
                this->_alloc.construct(this->begin + i, *first);
            }
        }

        vector(const vector &x): _alloc(x._alloc), _begin(_alloc.allocate(x._size)),
            _size(x._size), _capacity(x._capacity)
        {
            for (size_t i = 0; i != this->_size; i++)
                this->_alloc.construct(this->_begin + i, x[i]);
        }

        /* Destructor */
        virtual ~vector()
        {
            for (size_t i = 0; i < this->_size; i++)
                this->_alloc.destroy(this->_begin + i);
            this->_alloc.deallocate(this->_begin, this->_count);
        }

        // /* operator= */
        vector& operator=(const vector& x)
        {
            this->_alloc = x._alloc;
            this->_begin = x._begin;
            this->_size = x._size;
            this->_capacity = x._capacity;
            for (size_t i = 0; i != this->_size; i++)
                this->_alloc.construct(this->_begin + i, x[i]);
        }

        // /* assign */
        // template <class InputIterator> 
        // void assign (InputIterator first, InputIterator last)
        // {
        //     // size_type new_size = blablabla();
        // }

        // void    assign(size_type n, const value_type& val)
        // {
            
        // }

        /* get_allocator */
        allocator_type get_allocator() const { return (this->_alloc); }

        /***** Element access *****/
        /* at */
        reference at (size_type n)
        {
            if (n > this->_size)
                throw (std::out_of_range());
            return (this->_start + n);
        }

        const_reference at (size_type n) const
        {
            if (n > this->_size)
                throw (std::out_of_range());
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
        size_type   size() const { return (this->_size); }

        /* max_size */
        size_type   max_size() const { return (this->_alloc.max_size()); }

        // /* reserve */
        // void    reserve(size_type n)
        // {
            
        // }

        // /* capacity */
        // size_type   capacity() const { return (this->_capacity); }

        // /***** Modifiers *****/
        // /* clear */
        // void    clear()
        // {
            
        // }

        // /* insert */
        // iterator insert (iterator position, const value_type& val)
        // {

        // }

        // void    insert (iterator position, size_type n, const value_type& val)
        // {

        // }

        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last)
        // {
            
        // }

        // /* erase */
        // iterator erase (iterator position)
        // {
            
        // }

        // iterator erase (iterator first, iterator last)
        // {

        // }

        // /* push_back */
        // void    push_back (const value_type& val)
        // {
            
        // }

        // /* pop_back */
        // void    pop_back()
        // {
            
        // }

        // /* resize */
        // void    resize(size_type n, value_type val = value_type())
        // {

        // }

        // /* swap */
        // void    swap(vector& x)
        // {
            
        // }
    };

    /* Non-member function overloads ******************************************** */
    /* relational operators */
    // template <class T, class Alloc>
    // bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    // {

    // }

    // template <class T, class Alloc>
    // bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    // {

    // }

    // /* swap */
    // template <class T, class Alloc>
    // void    swap (vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }
}

#endif