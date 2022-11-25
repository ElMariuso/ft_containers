/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:11:12 by mthiry            #+#    #+#             */
/*   Updated: 2022/11/25 17:55:01 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

/* Includes ***************************************************************** */

# include <memory>
# include <iostream>
# include <stdexcept>

/* Class ******************************************************************** */

namespace ft
{
    template <class T>
    class random_access_iterator
    {
        public:

        /* Member types ************************************************************* */
        typedef T*  pointer;
        typedef T&  reference;

        /* Member function ********************************************************** */
        /***** Basic *****/
        /* Constructor */
        random_access_iterator(void): _current(NULL) { }
        random_access_iterator(pointer current): _current(current) { }
        random_access_iterator(const random_access_iterator& x): _current(x._current) { }
        /* Destructor */
        virtual ~random_access_iterator() { }
        /* operator= */
        random_access_iterator& operator=(const random_access_iterator& x)
        {
            if (x == *this)
                return (*this);
            this->_current = x._current;
            return (*this);
        }

        /***** Other *****/
        /* base */
        pointer base() const { return (this->_current); }
        /* operator* */
        reference operator*(void) const { return (*(this->_current)); }
        /* operator-> */
        pointer operator->() const { return (&(this->operator*())) }
        /* operator++ */
        random_access_iterator& operator++() { this->current++; return (*this); }
        /* ++operator */
        random_access_iterator operator++(int) 
        {
            random_access_iterator ret(*this);
            ret++;
            return (ret);
        }
        /* operator-- */
        random_access_iterator& operator--() { this->current--; return (*this); }
        /* --operator */
        random_access_iterator operator++(int)
        {
            random_access_iterator ret(*this);
            ret--;
            return (ret);
        }
        /* operator+ */
        random_access_iterator operator+(difference_type n) const { return (this->_current + n); }
        /* operator+= */
        random_access_iterator& operator+=(difference_type n) { this->_current += n; return (*this); }
        /* operator- */
        random_access_iterator operator-(difference_type n) const { return (this->_current - n); }
        /* operator-= */
        random_access_iterator& operator-=(difference_type n) { this->_current -= n; return (*this); }
        /* operator[] */
        reference operator[](difference_type n) const { return (*(this->operator+(n))); }

        /* Attributes *************************************************************** */
        protected:
            pointer _current;
    };
}

/* operator== */

/* operator< */

/* operator!= */

/* operator> */

/* operator>= */

/* operator<= */

/* operator- */

/* operator+ */

#endif