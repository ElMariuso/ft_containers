/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:16 by root              #+#    #+#             */
/*   Updated: 2022/11/30 17:25:27 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

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
        bool operator()(const T2 &x, const T1 &y) const { return (x == y); }
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
        typedef typename iterator_traits<InputIt1>::value_type  v1;
        typedef typename iterator_traits<InputIt2>::value_type  v2;
        return (equal(first1, last1, first1, equal_to<v1, v2>()))
    }
}

#endif