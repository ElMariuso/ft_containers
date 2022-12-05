/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:52 by root              #+#    #+#             */
/*   Updated: 2022/12/05 14:24:04 by mthiry           ###   ########.fr       */
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
                this->_alloc.construct(this->begin + i, *first);
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

        /* operator= */
        vector& operator=(const vector& x)
        {
            this->_alloc = x._alloc;
            this->_begin = x._begin;
            this->_size = x._size;
            this->_capacity = x._capacity;
            for (size_t i = 0; i != this->_size; i++)
                this->_alloc.construct(this->_begin + i, x[i]);
        }

        /* assign */
        template <class InputIterator> 
        void assign (InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type* = NULL)
        {
            difference_type n;

            n = ft::distance(first, last);
            if (n > this->_capacity)
            {
                this->reserve(n);
                this->_capacity = n;
            }
            this->clear();
            for (size_t i = 0; i != n; i++)
                this->_alloc.construct(this->_begin + i, first + i);
            this->_size = n;
        }
        void    assign(size_type n, const value_type& val)
        {
            if (n > this->_capacity)
            {
                this->reserve(n);
                this->_capacity = n;
            }
            this->clear();
            for (size_t i = 0; i != n; i++)
                this->_alloc.construct(this->_begin + i, val);
            this->_size = n;
        }

        /* get_allocator */
        allocator_type get_allocator() const { return (this->_alloc); }

        /***** Element access *****/
        /* at */
        reference at (size_type n)
        {
            if (n > this->_size)
                throw (std::out_of_range("[ERROR]: OutOfRangeException"));
            return (this->_start + n);
        }
        const_reference at (size_type n) const
        {
            if (n > this->_size)
                throw (std::out_of_range("[ERROR]: OutOfRangeException"));
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

        /* reserve */
        void    reserve(size_type n)
        {
            if (n > this->capacity())
                throw (std::length_error("[ERROR]: LengthErrorException"));
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

        // /* insert */
        // iterator insert (iterator position, const value_type& val)
        // {
            
        // }

        // void    insert (iterator position, size_type n, const value_type& val)
        // {
            
        // }

        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last,
        //     typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type* = NULL)
        // {
            
        // }

        /* erase */
        iterator erase (iterator position)
        {
            difference_type n;

            n = ft::distance(this->_begin, position);
            if (n >= this->_size)
                return (NULL);
            else if (n == this->_size)
            {
                this->pop_back();
                return (this->back());
            }
            for (size_t i = n; i != this->_size; i++)
            {
                this->_alloc.construct(this->begin + i, this->_begin + i + 1);
                this->_alloc.destroy(this->_begin + i + 1);
            }
            this->_size--;
            return (iterator(this->_begin + n));
        }

        iterator erase (iterator first, iterator last)
        {
            difference_type start;
            difference_type end;
            difference_type diff;

            start = ft::distance(this->_begin, first);
            end = ft::distance(this->_begin, last);
            diff = ft::distance(first, end);
            if (start >= this->_size || end >= this->_size)
                return (NULL);
            for (size_t j = 0; j != diff; j++)
            {
                for (size_t i = start; i != this->_size; i++)
                {
                    this->_alloc.construct(this->_begin + i, this->_begin + i + 1);
                    this->_alloc.destroy(this->_begin + i + 1);
                }
                this->_size--;
            }
            return (iterator(this->_begin + start));
        }

        /* push_back */
        void    push_back(const value_type& val)
        {
            if (this->_size == this->_capacity)
                this->reserve(this->_size + 1);
            this->_size++;
            this->back() = val;
        }

        /* pop_back */
        void    pop_back()
        {
            if (this->_size == 0)
                return ;
            this->_alloc.destroy(this->back());
            this->_size--;
        }

        /* resize */
        void    resize(size_type n, value_type val = value_type())
        {
            if (n < this->_size)
            {
                for (size_t i = n; i != this->_size; i--)
                    this->pop_back();
                this->_size = n;
            }
            else if (n > this->_size)
            {
                if (n > this->_capacity)
                {
                    this->reserve(n);
                    this->_capacity = n;
                }
                for (size_t i = this->_size; i != n; i++)
                    this->push_back(val);
                this->_size = n;
            }
        }

        /* swap */
        void    swap(vector& x)
        {
            swap(this->_alloc, x._alloc);
            swap(this->_begin, x._begin);
            swap(this->_size, x._size);
            swap(this->_capacity, x._capacity);
        }

        /***** Utils Functions *****/
        private:
        /* swap_utils */
        template <class F>
        void swap(F &a, F &b)
        {
            F   tmp;

            tmp = a;
            a = b;
            b = tmp;
        }
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
    void    swap (vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }
}

#endif