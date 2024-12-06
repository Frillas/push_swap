/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:47 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 10:58:03 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_BIG_UTILS_H
# define FT_SORT_BIG_UTILS_H

# include "ft_build.h"
# include "ft_sort_big.h"

void	ft_find_pos(t_list *current_a, t_list *stack_b);
t_list	*ft_find_max(t_list *stack_b);
int		ft_countmove(t_list *current);
int		ft_total_move(t_list *current);

#endif
