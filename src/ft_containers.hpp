/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:54:24 by root              #+#    #+#             */
/*   Updated: 2022/12/15 14:01:39 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

/* Containers *************************************************************** */

# include "../inc/containers/vector.hpp"
# include "../inc/containers/stack.hpp"
# include "../inc/containers/map.hpp"

/* Utils ******************************************************************** */

# include "../inc/utils/utility.hpp"
# include "../inc/utils/type_traits.hpp"
# include "../inc/utils/iterator.hpp"
# include "../inc/utils/algorithm.hpp"
# include "../inc/utils/functional.hpp"

/* Tests ******************************************************************** */

void    testing_type_traits(void);

#endif