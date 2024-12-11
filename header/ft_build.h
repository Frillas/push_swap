/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:00:22 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:00:25 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILD_H
# define FT_BUILD_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_type.h"
# include "ft_list.h"
# include "ft_utils.h"
# include "ft_utils_next.h"
# include "ft_split.h"
# include "ft_sort_list.h"
# include "ft_sort_big.h"

t_list	*ft_build_list(char **result, t_list *head, t_list **end);
t_list	*ft_parsing(int argc, char **argv, t_list **end);

#endif
