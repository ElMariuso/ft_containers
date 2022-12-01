/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:52:24 by mthiry            #+#    #+#             */
/*   Updated: 2022/12/01 15:09:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Includes ***************************************************************** */

#include <iostream>
#include "ft_containers.hpp"

/* Functions **************************************************************** */

// the return type (bool) is only valid if T is an integral type
template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
    is_odd(T i) { return bool(i % 2); }

template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type
    is_even(T i) { return !bool(i % 2); }

void    testing_type_traits(void)
{
    /* enable_if ***************************************************************** */
    short int   i;
    std::string j;

    i = 1;
    j = "Hello";
    
    /* Compile because i is an integral*/
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;

    /* Don't compile because j is not an integral */
    // std::cout << "j is odd: " << is_odd(j) << std::endl;
    // std::cout << "j is even: " << is_even(j) << std::endl;
}