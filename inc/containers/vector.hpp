/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:52 by root              #+#    #+#             */
/*   Updated: 2022/12/13 17:05:07 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* Includes ***************************************************************** */

# include <memory>
# include <stdexcept>
# include <iostream>

# include <vector>

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
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef ft::vt_iterator<pointer>                    iterator;
            typedef ft::vt_iterator<const_pointer>              const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
        
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
        explicit vector(const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) { }

        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _size(n), _capacity(n)
        {
            if (n > this->max_size())
                throw (std::length_error("vector"));
            this->_begin = this->_alloc.allocate(n);
            for (size_type i = 0; i != n; i++)
                this->_alloc.construct(this->_begin + i, val);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            : _alloc(alloc), _size(0)
        {
            this->_size = last - first;
            this->_capacity = this->_size;
            this->_begin = this->_alloc.allocate(this->_size);
            for (size_type i = 0; first != last; ++first, ++i)
                this->_alloc.construct(this->_begin + i, *first);
        }

        vector(const vector &x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
        {
            this->_begin = this->_alloc.allocate(this->_size);
            for (size_type i = 0; i != this->_size; i++)
                this->_alloc.construct(this->_begin + i, x[i]);
        }

        /* Destructor */
        virtual ~vector()
        {
            this->clear();
            this->_alloc.deallocate(this->_begin, this->_capacity);
        }

        /* operator= */
        vector& operator=(const vector& x)
        {
            if (*this == x)
                return (*this);
            this->clear();
            this->assign(x.begin(), x.end());
            return (*this);
        }

        /* assign */
        template <class InputIterator> 
        void assign (InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type* = 0)
        {
            this->clear();
            this->insert(this->begin(), first, last);
        }
        
        void    assign(size_type n, const value_type& val)
        {
            this->clear();
            this->insert(this->begin(), n, val);
        }

        /* get_allocator */
        allocator_type get_allocator() const { return (this->_alloc); }

        /***** Element access *****/
        /* at */
        reference at (size_type n)
        {
            if (n > this->_size)
                throw (std::out_of_range("vector"));
            return (this->_begin[n]);
        }
        const_reference at (size_type n) const
        {
            if (n > this->_size)
                throw (std::out_of_range("vector"));
            return (this->_begin[n]);
        }
        
        /* operator[] */
        reference operator[]  (size_type n) { return (*(this->_begin + n)); }
        const_reference operator[] (size_type n) const { return (*(this->_begin + n)); }

        /* front */
        reference front() { return (*(this->_begin)); }
        const_reference front() const { return (*(this->_begin)); }

        /* back */
        reference back() { return (*(this->_begin + this->_size - 1)); }
        const_reference back() const { return (*(this->_begin + this->_size - 1)); }

        /***** Iterators *****/
        /* begin */
        iterator begin() { return (iterator(this->_begin)); }
        const_iterator begin() const { return (const_iterator(this->_begin)); }

        /* end */
        iterator end() { return (iterator(this->_begin + this->_size)); }
        const_iterator end() const { return (const_iterator(this->_begin + this->_size)); }

        /* rbegin */
        reverse_iterator    rbegin() { return (reverse_iterator(this->end())); }
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }

        /* rend */
        reverse_iterator    rend() { return (reverse_iterator(this->begin())); }
        const_reverse_iterator  rend() const { return (const_reverse_iterator(this->begin())); }

        /***** Capacity *****/
        /* empty */
        bool    empty() const { return (this->size() == 0 ? true : false); }
        
        /* size */
        size_type   size() const { return (this->_size); }

        /* max_size */
        size_type   max_size() const { return (this->_alloc.max_size()); }

        /* reserve */
        void    reserve(size_type n)
        {
            if (n > this->max_size())
                throw (std::length_error("vector"));
            if (n <= this->_capacity)
                return ;
            pointer tmp = this->_alloc.allocate(n);
            for (size_t i = 0; i != this->_size; i++)
            {
                this->_alloc.construct(tmp + i, this->_begin[i]);
                this->_alloc.destroy(this->_begin + i);
            }
            this->_alloc.deallocate(this->_begin, this->_capacity);
            this->_capacity = n;
            this->_begin = tmp;
        }

        /* capacity */
        size_type   capacity() const { return (this->_capacity); }

        /***** Modifiers *****/
        /* clear */
        void    clear()
        {
            for (size_t i = 0; i != this->_size; i++)
                this->_alloc.destroy(this->_begin + i);
            this->_size = 0;
        }

        /* insert */
        iterator insert(iterator position, const value_type& val)
        {
            size_type   i;
            
            i = position - this->begin();
            if (this->_capacity == this->_size)
				this->reserve(this->_size * 2);
			for (size_type j = this->_size; j > i; j--)
			{
				this->_alloc.construct(this->_begin + j, this->_begin[j - 1]);
				this->_alloc.destroy(this->_begin + j - 1);
			}
			this->_alloc.construct(&(*position), val);
            this->_size++;
            return (position);
        }

        void    insert(iterator position, size_type n, const value_type& val)
        {
            size_type   i;

            i = position - this->begin();
			if ((this->_size + n) > this->_capacity && n < this->_size)
                this->reserve(this->_size * 2);
			else if ((this->_size + n) > this->_capacity)
				this->reserve(this->_size + n);
			for (size_type j = n + this->_size - 1; j > i + n - 1; j--)
			{
				this->_alloc.construct(this->_begin + j, this->_begin[j - n]);
				this->_alloc.destroy(this->_begin + j - n);
			}
			for (size_type k = i; k < i + n; k++)
			{
				this->_alloc.construct(this->_begin + k, val);
				this->_size++;
			}
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type* = 0)
        {
            size_type       i;
            size_type       n;
            
            i = position - this->begin();
            n = last - first;
            if ((this->_size + n) > this->_capacity && n < this->_size)
                this->reserve(this->_size * 2);
			else if ((this->_size + n) > this->_capacity)
				this->reserve(this->_size + n);
			for (size_type j = n + this->_size - 1; j > i + n - 1; j--)
			{
				this->_alloc.construct(this->_begin + j, this->_begin[j - n]);
				this->_alloc.destroy(this->_begin + j - n);
			}
			for (size_type k = i; k < i + n; k++)
			{
				this->_alloc.construct(this->_begin + k, *first);
                ++first;
				this->_size++;
			}
        }

        /* erase */
        iterator erase (iterator position)
        {
            size_type   index;

            index = position - this->begin();
            this->_size--;
            for (size_type i = index; i < this->_size; i++)
            {
                this->_alloc.construct(this->_begin + i, this->_begin[i + 1]);
                this->_alloc.destroy(this->_begin + i + 1);
            }
            return (iterator(this->_begin + index));
        }

        iterator erase (iterator first, iterator last)
        {
            size_type   index;
            size_type   n;
            
            index = first - this->begin();
            n = last - first;
            this->_size -= n;
            for (size_type i = index; i < this->_size; i++)
            {
                this->_alloc.construct(this->_begin + i, this->_begin[i + n]);
                this->_alloc.destroy(this->_begin + i + n);
            }
            return (iterator(this->_begin + index));
        }
        
        /* push_back */
        void    push_back(const value_type& val)
        {
            if (this->_size == this->_capacity && this->_size > 0)
                this->reserve(this->_size * 2);
            else if (this->_size == this->_capacity)
                this->reserve(8);
            this->_size++;
            this->_alloc.construct(this->_begin + this->_size - 1, val);
        }

        /* pop_back */
        void    pop_back()
        {
            if (this->_size == 0)
                return ;
            this->_alloc.destroy(&this->back());
            this->_size--;
        }

        /* resize */
        void    resize(size_type n, value_type val = value_type())
        {
            if (n > this->max_size())
                throw (std::length_error("vector"));
            else if (n > this->_size)
            {
                while (this->_size < n)
                    this->push_back(val);
            }
            else if (n < this->_size)
            {
                while (this->_size > n)
                    this->pop_back();
            }
        }

        /* swap */
        void    swap(vector& x)
        {
            ft::swap(this->_alloc, x._alloc);
			ft::swap(this->_capacity, x._capacity);
			ft::swap(this->_begin, x._begin);
			ft::swap(this->_size, x._size);
        }

        /***** Utils Functions *****/
        private:
    };
    /* Non-member function overloads ******************************************** */
    /* relational operators */
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        for (size_t i = 0; i != lhs.size(); i++)
            if (lhs[i] != rhs[i])
                return (false);
        return (true);
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {
        return (!(lhs < rhs));
    }

    /* swap */
    template <class T, class Alloc>
    void swap (vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }
}

#endif