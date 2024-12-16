/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instru_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/16 17:44:48 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/ft_instru_1_bonus.h"

void	swap(t_list **head)
{
	t_list	*current;
	t_list	*end;

	if (!head || !*head || (*head)->next == NULL)
		return ;
	end = find_end(*head);
	current = (*head)->next;
	if (current != end)
	{
		(*head)->prev = current;
		(*head)->next = current->next;
		current->prev = NULL;
		current->next->prev = *head;
		current->next = *head;
		(*head) = current;
	}
	else
	{
		(*head)->prev = end;
		(*head)->next = NULL;
		end->prev = NULL;
		end->next = *head;
		(*head) = end;
	}
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_b;

	if (!stack_b || !*stack_b)
		return ;
	current_b = (*stack_b)->next;
	if (current_b != NULL)
	{
		(*stack_b)->next = *stack_a;
		if (*stack_a)
			(*stack_a)->prev = *stack_b;
		current_b->prev = NULL;
		*stack_a = *stack_b;
		*stack_b = current_b;
	}
	else if (current_b == NULL)
	{
		(*stack_b)->next = *stack_a;
		if (*stack_a)
			(*stack_a)->prev = *stack_b;
		*stack_a = *stack_b;
		*stack_b = NULL;
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	if (!stack_a || !*stack_a)
		return ;
	current_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = *stack_a;
		(*stack_b)->next = NULL;
		(*stack_b)->prev = NULL;
		if (current_a)
			current_a->prev = NULL;
	}
	else
	{
		current_b = *stack_b;
		*stack_b = *stack_a;
		(*stack_b)->next = current_b;
		(*stack_b)->prev = NULL;
		current_b->prev = *stack_b;
		if (current_a)
			current_a->prev = NULL;
	}
	*stack_a = current_a;
}

void	rotate(t_list **head)
{
	t_list	*end;
	t_list	*current;

	if (!head || !*head || !(*head)->next)
		return ;
	end = find_end(*head);
	current = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	end->next = current;
	current->prev = end;
	current->next = NULL;
}
