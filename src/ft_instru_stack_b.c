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

void	ft_rr(t_list **s_a, t_list **s_b, t_list **end_a, t_list **end_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = (*s_a);
	while (current_a->prev != NULL)
		current_a = current_a->prev;
	current_b = (*s_b);
	while (current_b->prev != NULL)
		current_b = current_b->prev;
	ft_ra(&current_a, end_a, TRUE);
	ft_ra(&current_b, end_b, TRUE);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_list **s_a, t_list **s_b, t_list **end_a, t_list **end_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = (*s_a);
	while (current_a->prev != NULL)
		current_a = current_a->prev;
	current_b = (*s_b);
	while (current_b->prev != NULL)
		current_b = current_b->prev;
	ft_rra(&current_a, end_a, TRUE);
	ft_rra(&current_b, end_b, TRUE);
	write(1, "rrr\n", 4);
}

void	ft_rb(t_list **head, t_list **end)
{
	t_list	*current;

	current = (*head);
	while (current->prev != NULL)
		current = current->prev;
	ft_ra(&current, end, TRUE);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_list **head, t_list **end)
{
	t_list	*current;

	current = (*head);
	while (current->prev != NULL)
		current = current->prev;
	ft_rra(&current, end, TRUE);
	write(1, "rrb\n", 4);
}
