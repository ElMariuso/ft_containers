/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:56:02 by mthiry            #+#    #+#             */
/*   Updated: 2022/11/30 16:01:27 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/* Includes ***************************************************************** */

# include <cstddef>

/* Includes.h *************************************************************** */

# include "type_traits.hpp"

/* Namespace **************************************************************** */

namespace ft
{
    /* Types ******************************************************************** */
    struct output_iterator_tag {};
    struct input_iterator_tag {};
    struct forward_iterator_tag         : public input_iterator_tag {};
    struct bidirectional_iterator_tag   : public forward_iterator_tag {};
    struct random_acces_iterator_tag    : public bidirectional_iterator_tag {};
    /* iterator_traits ********************************************************** */
    template <class Iter>
    struct iterator_traits
    {
        typedef typename Iter::difference_type      difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;
    };
    template <class T>
    struct iterator_traits<T*>
    {
        typedef typename std::ptrdiff_t             difference_type;
        typedef typename T                          value_type;
        typedef typename T*                         pointer;
        typedef typename T&                         reference;
        typedef typename random_access_iterator_tag iterator_category;
    };
    /* has_iterator ***************************************************************/
    
    /* iterator ***************************************************************** */
    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef typename Category   iterator_category;
        typedef typename T          value_type;
        typedef typename Distance   difference_type;
        typedef typename Pointer    pointer;
        typedef typename Reference  reference;
    };
    /* advance ****************************************************************** */
    template <class InputIt>
    void    advance(InputIt &i, typename iterator_traits<InputIt>::difference_type n, input_iterator_tag)
    {
        for (; n > 0; --n)
            ++i;
    }

    template <class BiDirIt>
    void    advance(BiDirIt &i, typename iterator_traits<BiDirIt>::difference_type n, bidirectional_iterator_tag)
    {
        if (n >= 0)
            for (; n > 0; --n)
                ++i;
        else
            for (; n < 0; ++n)
                --i;
    }

    template <class RandIt>
    void    advance(RandIt &i, typename iterator_traits<RandIt>::difference_type n, random_acces_iterator_tag)
    {
        i += n;
    }

    /* distance ***************************************************************** */
    template <class InputIt>
    typename iterator_traits<InputIt>::difference_type  distance(InputIt first, InputIt last, input_iterator_tag)
    {
        typename iterator_traits<InputIt>::difference_type  r;
        for (; first != last; ++first)
            ++r;
        return (r);
    }

    template <class RandIt>
    typename iterator_traits<RandIt>::difference_type  distance(RandIt first, RandIt last, random_acces_iterator_tag)
    {
        return (last - first);
    }

    /* reverse_iterator ********************************************************* */
    template <class Iter>
    class reverse_iterator
    {
        private:
            Iter    t;
            
        protected:
            Iter    current;

        public:
            /* Member types ************************************************************* */
            typedef Iter                                                iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iter>::value_type          value_type;
            typedef typename iterator_traits<Iter>::difference_type     difference_type;
            typedef typename iterator_traits<Iter>::pointer             pointer;
            typedef typename iterator_traits<Iter>::reference           reference

            /* Member function ********************************************************** */
            /***** Basic *****/
            /* Constructor */
            reverse_iterator() : t(), current() {}
            
            explicit reverse_iterator(Iter x) : t(x), current(x) {}

            template <class U>
            reverse_iterator(const reverse_iterator<U> &other) : t(other.base()), current(other.base()) {}

            /* Destructor */

            /* operator= */
            template <class U>
            reverse_iterator& operator=(const reverse_iterator<U>& other) { this->t = this->current = other.base(); return (*this); }

            /* base */
            Iter base() const { return (this->current); }

            /* operator* */

            /* operator-> */

            /* operator[] */

            /* operator++ */

            /* ++operator (operator++(int)) */

            /* operator+= */

            /* operator+ */

            /* operator-- */

            /* --operator (operator--(int)) */

            /* operator-= */

            /* operator- */
    };
    /* Non-Member function ****************************************************** */
    /* operator== */
    
    /* operator!= */

    /* operator< */

    /* operator<= */

    /* operator> */

    /* operator>= */

    /* operator+ */
    
    /* operator- */
}

#endif