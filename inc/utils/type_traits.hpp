/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:34:54 by mthiry            #+#    #+#             */
/*   Updated: 2022/12/12 16:12:21 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

/* Includes.h *************************************************************** */

/* C types
    # include <uchar.h>
*/

/* Namespace **************************************************************** */
namespace ft
{
    /* enable_if ***************************************************************** */
    template <bool B, class T = void>   struct enable_if {};
    template <class T>                  struct enable_if<true, T> { typedef T type; };
    /* integral_constant ********************************************************* */
    template <class T, T v>
    struct integral_constant
    {
        typedef T       value_type;
        static const T  value = v;
        operator value_type() { return (value); }
    };
    /* false_type **************************************************************** */
    typedef integral_constant<bool, false>  false_type;
    typedef integral_constant<bool, true>   true_type;
    /* is_integral *************************************************************** */
    template <class T>  struct is_integral                          : public false_type {};
    template <>         struct is_integral<bool>                    : public true_type {};
    template <>         struct is_integral<char>                    : public true_type {};
    /* C types
        template <>         struct is_integral<char16_t>                : public true_type {};
        template <>         struct is_integral<char32_t>                : public true_type {};
    */
    template <>         struct is_integral<wchar_t>                 : public true_type {};
    template <>         struct is_integral<signed char>             : public true_type {};
    template <>         struct is_integral<short int>               : public true_type {};
    template <>         struct is_integral<int>                     : public true_type {};
    template <>         struct is_integral<long int>                : public true_type {};
    template <>         struct is_integral<long long int>           : public true_type {};
    template <>         struct is_integral<unsigned char>           : public true_type {};
    template <>         struct is_integral<unsigned short int>      : public true_type {};
    template <>         struct is_integral<unsigned int>            : public true_type {};
    template <>         struct is_integral<unsigned long int>       : public true_type {};
    template <>         struct is_integral<unsigned long long int>  : public true_type {};
}

#endif