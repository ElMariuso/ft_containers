/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:46 by root              #+#    #+#             */
/*   Updated: 2022/12/13 21:48:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

/* Namespace **************************************************************** */
namespace ft
{
    /* swap ********************************************************************** */
    template <typename T>
    void swap(T &first, T &second)
    {
        T   tmp;
        
        tmp = first;
        first = second;
        second = tmp;
    }
    /* pair ********************************************************************** */
    template <class T1, class T2>
    struct pair
    {
        /* Member types */
        typedef T1  first_type;
        typedef T2  second_type;

        /* Member objects */
        first_type  first;
        second_type second;

        /* Constructor */
        pair(): first(), second() {}
        pair(const T1 &x, const T2 &y): first(x), second(y) {}
        template <class U1, class U2>
        pair(const pair<U1, U2> &p): first(p.first), second(p.second) {}
        pair(const pair &p): first(p.first), second(p.second) {}

        /* operator= */
        pair& operator=(const pair &x)
        {
            if (*this == x)
                return (*this);
            first = x.first;
            second = x.second;
            return (*this);
        }
    };
    /* Non-member function overloads ******************************************** */
    /* make_pair */
    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 t, T2 u) { return (ft::pair<T1, T2>(t, u)); }

    /* relational operators */
    template <class T1, class T2>
    bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return ((lhs.first == rhs.second) && (lhs.second == rhs.second));
    }

    template <class T1, class T2>
    bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return (!(lhs < rhs));
    }
}

#endif