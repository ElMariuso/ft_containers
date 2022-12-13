/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:16 by root              #+#    #+#             */
/*   Updated: 2022/12/13 21:40:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

/* Includes.h *************************************************************** */

# include "iterator.hpp"

/* Namespace **************************************************************** */
namespace ft
{
    /* equal_to ***************************************************************** */
    template <class T1, class T2 = T1>
    struct equal_to
    {
        bool operator()(const T1 &x, const T1 &y) const { return (x == y); }
        bool operator()(const T1 &x, const T2 &y) const { return (x == y); }
        bool operator()(const T2 &x, const T1 &y) const { return (x == y); }
        bool operator()(const T2 &x, const T2 &y) const { return (x == y); }
    };
    
    template <class T>
    struct equal_to<T, T>
    {
        bool operator()(const T &x, const T &y) const { return (x == y); }
    };

    template <class T>
    struct equal_to<const T, T>
    {
        bool operator()(const T &x, const T &y) const { return (x == y); }
    };

    template <class T>
    struct equal_to<T, const T>
    {
        bool operator()(const T &x, const T &y) const { return (x == y); }
    };
    /* less ********************************************************************* */
    template <class T1, class T2 = T1>
    struct less
    {
        bool operator()(const T1 &x, const T1 &y) const { return (x < y); }
        bool operator()(const T1 &x, const T2 &y) const { return (x < y); }
        bool operator()(const T2 &x, const T1 &y) const { return (x < y); }
        bool operator()(const T2 &x, const T2 &y) const { return (x < y); }   
    };

    template <class T>
    struct less<T, T>
    {
        bool operator()(const T &x, const T &y) const { return (x < y); }
    };

    template <class T>
    struct less<const T, T>
    {
        bool operator()(const T &x, const T &y) const { return (x < y); }
    };

    template <class T>
    struct less<T, const T>
    {
        bool operator()(const T &x, const T &y) const { return (x < y); }
    };
    /* equal ******************************************************************** */
    template <class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
    {
        for (; first1 != last1; ++first1, (void) ++first2)
            if (!p(*first1, *first2))
                return (false);
        return (true);
    }
    
    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        typedef typename ft::iterator_traits<InputIt1>::value_type  v1;
        typedef typename ft::iterator_traits<InputIt2>::value_type  v2;
        return (equal(first1, last1, first2, ft::equal_to<v1, v2>()));
    }
    /* lexicographical_compare ************************************************** */
    template <class InputIt1, class InputIt2, class Compare>
    bool _lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
    {
        for (; first2 != last2; ++first1, (void) ++first2)
        {
            if (first1 == last1 || comp(*first1, *first2))
                return (true);
            if (comp(*first2, *first1))
                return (false);
        }
        return (false);
    }

    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        return (ft::_lexicographical_compare(first1, last1, first2, last2, ft::less<typename ft::iterator_traits<InputIt1>::value_type,
            typename ft::iterator_traits<InputIt2>::value_type>()));
    }
}

#endif