/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PUSH_BACK_H
# define FT_PUSH_BACK_H

# include "ft_build.h"
# include "ft_sort_big.h"

void	ft_push_back(t_list **stack_a, t_list **stack_b, int len_a, int len_b);
void	ft_search_pos(t_list **end_a, t_list **cur_b);
t_bool	ft_min_max(t_list **current_a, t_list **current_b, t_list **min);
void	ft_pos_ontop(t_list **stack_a, t_list **cur_b, t_list **end, int len);
t_list	*ft_finish(t_list **stack_a, t_list **end_a, t_list **min, int len_a);

#endif
