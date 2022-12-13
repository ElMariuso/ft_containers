/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:46 by root              #+#    #+#             */
/*   Updated: 2022/12/13 21:03:50 by root             ###   ########.fr       */
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
    template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T>> >
    class map
    {
        /* Member types ************************************************************* */
        public:
        typedef Key                                     key_type;
        typedef T                                       mapped_type;
        typedef typename ft::pair<const Key, T>         value_type;
        typedef std::size_t                             size_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef Compare                                 key_compare;
        typedef Allocator                               allocator_type;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef typename allocator_type::pointer        pointer;
        typedef typename allocator_type::const_pointer  const_pointer;
        // Need to make iterators
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

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