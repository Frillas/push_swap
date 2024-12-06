/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/03 11:41:50 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_sort_big.h"

t_list	ft_sort_big(t_list *stack_a, t_list *end, int len_a)
{
	t_list	*stack_b;
	t_list	*current;
	t_list	*pos;
	int		move;
	int		min_move;
	int		size;
	int		len_b;
	
	stack_b = NULL;
	pos = NULL;
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	len_a = len_a - 2;
	size = len_a - 3;
	len_b = 2;
	current = stack_a;
	while (i < len_a)
	{
		pos = ft_find_pos(current, stack_b);
	}
}

t_list	ft_find_pos(t_list *current_a, t_list *stack_b)
{
	t_list	*current_b;

	current_b = stack_b;	
	while (current_b != NULL)
	{
		if (current_a->content < current_b->content)
		{
			if (current_a->content > current_b->next->content)
				pos = current_b->next;
		}
		current_b = current_b->next;
	}
	if (pos == NULL)
		pos = ft_find_max(*stack_b);
	return (pos);
}

t_list	ft_find_max(t_list *stack_b)
{
	t_list	*current;
	t_list	pos;
	int		max;

	current = stack_b;
	max = current->content;
	while (current != NULL)
	{
		if (current->content > max)
		{
			max = current->content;
			pos = current;
		}
		current = current->next;
	}
	return (pos);
}
