/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instru_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:38:50 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:10:15 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_instru_stack_a.h"

void	ft_switch_two(t_list **head, t_list **end)
{
	(*head)->prev = *end;
	(*head)->next = NULL;
	(*end)->prev = NULL;
	(*end)->next = *head;
	write(1, "sa\n", 3);
}

void	ft_sa(t_list **head, t_list **end)
{
	t_list	*current;

	current = (*head)->next;
	(*head)->prev = current;
	(*head)->next = *end;
	current->prev = NULL;
	current->next = *head;
	(*end)->prev = *head;
	(*head) = current;
	(*head)->index = 0;
	(*head)->next->index = 1;
	write(1, "sa\n", 3);
}

void	ft_ra(t_list **head, t_list **end, t_bool check)
{
	t_list	*current;

	current = (*head)->next;
	(*head)->prev = *end;
	(*head)->next = NULL;
	current->prev = NULL;
	(*end)->next = *head;
	*end = *head;
	*head = current;
	update_index(*head);
	if (check == FALSE)
		write(1, "ra\n", 3);
}

void	ft_rra(t_list **head, t_list **end, t_bool check)
{
	t_list	*current;

	current = *head;
	(*end)->next = *head;
	(*end) = (*end)->prev;
	(*head) = (*end)->next;
	(*end)->next = NULL;
	current->prev = *head;
	(*head)->prev = NULL;
	(*head)->next = current;
	update_index(*head);
	if (check == FALSE)
		write(1, "rra\n", 4);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = *stack_a;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
		current_a->prev = NULL;
	}
	else
	{
		current_b = *stack_b;
		*stack_b = *stack_a;
		(*stack_b)->next = current_b;
		(*stack_b)->prev = NULL;
		current_b->prev = *stack_b;
		current_a->prev = NULL;
	}
	*stack_a = current_a;
	update_index(*stack_a);
	update_index(*stack_b);
	write(1, "pb\n", 3);
}
