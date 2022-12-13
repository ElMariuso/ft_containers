/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:46 by root              #+#    #+#             */
/*   Updated: 2022/12/13 13:47:24 by mthiry           ###   ########.fr       */
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
}

#endif