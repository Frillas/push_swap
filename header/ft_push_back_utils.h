/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_BACK_UTILS_H
# define FT_PUSH_BACK_UTILS_H

# include "ft_build.h"
# include "ft_sort_big.h"

t_bool	is_outside_range(int content, int min, int max);
t_bool	between(int content, int stack_a_content, int end_a_content);
void	ft_search_pos(t_list **end_a, t_list **cur_b);
void	ft_pos_ontop(t_list **stack_a, t_list **cur_b, t_list **end, int len);
t_bool	ft_is_min_top(t_list **current_a, t_list **current_b, t_list **min);

#endif
