/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:56:02 by mthiry            #+#    #+#             */
/*   Updated: 2022/11/30 12:39:07 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/* Includes ***************************************************************** */

# include <cstddef>

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
    void    advance (InputIt &i, typename iterator_traits<InputIt>::difference_type n, input_iterator_tag)
    {
        for (; n > 0; n--)
            ++i;
    }

    template <class BiDirIt>
    void    advance (BiDirIt &i, typename iterator_traits<BiDirIt>::difference_type n, bidirectional_iterator_tag)
    {
        
    }
}

#endif