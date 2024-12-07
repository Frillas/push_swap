/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instru_stack_a.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:56:18 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 10:57:05 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRU_STACK_A_H
# define FT_INSTRU_STACK_A_H
# include "ft_sort_list.h"

void	ft_switch_two(t_list **head, t_list **end);
void	ft_sa(t_list **head, t_list **end);
void	ft_ra(t_list **head, t_list **end, t_bool check);
void	ft_rra(t_list **head, t_list **end, t_bool check);
void	ft_pb(t_list **stack_a, t_list **stack_b);

#endif
