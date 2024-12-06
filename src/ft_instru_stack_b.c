/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instru_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:38:50 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:10:23 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_instru_stack_b.h"

void	ft_pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*current_b;

	current_b = (*stack_b)->next;
	if (current_b != NULL)
	{
		(*stack_b)->next = *stack_a;
		(*stack_a)->prev = *stack_b;
		current_b->prev = NULL;
		*stack_a = *stack_b;
		*stack_b = current_b;
		update_index(*stack_a);
		update_index(*stack_b);
	}
	else if (current_b == NULL)
	{
		(*stack_b)->next = *stack_a;
		(*stack_a)->prev = *stack_b;
		*stack_a = *stack_b;
		*stack_b = NULL;
		update_index(*stack_a);
	}
	write(1, "pa\n", 3);
}
