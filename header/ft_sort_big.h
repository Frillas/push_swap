/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:47 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 10:58:03 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_BIG_H
# define FT_SORT_BIG_H
# include "ft_build.h"
# include "ft_type.h"
# include "ft_instru_stack_a.h"
# include "ft_instru_stack_b.h"
# include "ft_sort_big_utils.h"
# include "ft_send_node.h"

t_list	*ft_sort_big(t_list *stack_a, t_list *end, int len_a);
t_list	*ft_pick_one(t_list *stack_a, t_list *stack_b, int len_a, int len_b);
void	ft_update_move(t_list *current, t_list *stack_b, int len_a, int len_b);

#endif
