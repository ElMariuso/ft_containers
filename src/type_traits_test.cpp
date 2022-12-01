/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:52:24 by mthiry            #+#    #+#             */
/*   Updated: 2022/12/01 14:49:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Includes ***************************************************************** */

#include <iostream>
#include "ft_containers.hpp"

/* Functions **************************************************************** */

//
template <class  T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
    is_odd(T i) { return bool(i % 2); }

//
template <class  T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
    is_even(T i) { return !bool(i % 2); }

void    testing_type_traits(void)
{
    /* enable_if ***************************************************************** */
    short int i;

    i = 1;

    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "is is even: " << is_even(i) << std::endl;
}