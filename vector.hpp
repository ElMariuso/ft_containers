/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:47:52 by root              #+#    #+#             */
/*   Updated: 2022/11/13 00:18:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* Includes ***************************************************************** */

# include <memory>

/* Class ******************************************************************** */

namespace ft
{
    template <class T, class Alloc = std::allocator<T>>
    class vector
    {
        public:

        /* The first template parameter (T) */
        typedef T                                           value_type;

        /* The second template parameter (Alloc) */
        typedef Alloc                                       allocator_type;

        /* allocator_type::reference */
        typedef typename allocator_type::reference          reference;

        /* allocator_type::const_reference */
        typedef typename allocator_type::const_reference    const_reference;

        /* allocator_type::pointer */
        typedef typename allocator_type::pointer            pointer;

        /* allocator_type::const_pointer */
        typedef typename allocator_type::const_pointer      const_pointer;

        private:
    };
}

#endif