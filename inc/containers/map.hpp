/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:46 by root              #+#    #+#             */
/*   Updated: 2022/12/13 19:01:37 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

/* Includes ***************************************************************** */

# include <memory>
# include <stdexcept>
# include <iostream>

/* Includes.h *************************************************************** */

# include "../utils/algorithm.hpp"
# include "../utils/iterator.hpp"
# include "../utils/type_traits.hpp"
# include "../utils/utility.hpp"

/* Class ******************************************************************** */

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T>> >
    class map
    {
        /* Member types ************************************************************* */
        public:

        /* Attributes *************************************************************** */
        private:

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */

        /* Destructor */

        /* operator= */

        /* get_allocator */

        /***** Element access *****/
        /* at */

        /* operator[] */

        /***** Iterators *****/
        /* begin */

        /* end */

        /* rbegin */

        /* rend */

        /***** Capacity *****/
        /* empty */
        
        /* size */

        /* max_size */

        /***** Modifiers *****/
        /* clear */

        /* insert */

        /* erase */

        /* swap */

        /***** Lookup *****/
        /* count */

        /* find */

        /* equal_range */

        /* lower_bound */

        /* upper_bound */

        /***** Observers *****/
        /* key_comp */

        /* value_comp */

        /***** Utils Functions *****/
        private:
    };
    /* Non-member function overloads ******************************************** */
    /* relational operators */
}

#endif