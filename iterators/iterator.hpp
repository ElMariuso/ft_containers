/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:56:02 by mthiry            #+#    #+#             */
/*   Updated: 2022/11/29 17:03:49 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    /* Types ******************************************************************** */

    struct output_iterator_tag {};
    struct input_iterator_tag {};
    struct forward_iterator_tag         : public input_iterator_tag {};
    struct bidirectional_iterator_tag   : public forward_iterator_tag {};
    struct random_acces_iterator_tag    : public bidirectional_iterator_tag {};

    /* Class ******************************************************************** */
}

#endif