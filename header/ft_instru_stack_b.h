/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instru_stack_b.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:56:31 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 10:58:55 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRU_STACK_B_H
# define FT_INSTRU_STACK_B_H

# include "ft_sort_list.h"

void	ft_pa(t_list **stack_b, t_list **stack_a);
void	ft_rr(t_list **s_a, t_list **s_b, t_list **end_a, t_list **end_b);
void	ft_rrr(t_list **s_a, t_list **s_b, t_list **end_a, t_list **end_b);
void	ft_rb(t_list **head, t_list **end);
void	ft_rrb(t_list **head, t_list **end);

#endif
