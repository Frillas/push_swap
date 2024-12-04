/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/03 11:41:50 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_sort_list.h"

t_list	*ft_sort_three(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	if (current == end)
	{
		ft_switch_two(&head, &end);
		return (end);
	}
	if (head->content > head->next->content)
	{
		if ((end->content < head->content) && (end->content > current->content))
			ft_ra(&head, &end);
		else
			ft_sa(&head, &end);
	}
	if (head->next->content > end->content)
	{
		ft_rra(&head, &end);
		if (head->content > head->next->content)
			ft_sa(&head, &end);
	}
	return (head);
}

t_list	*ft_sort_five(t_list *stack_a, t_list *end)
{
	t_list	*stack_b;
	int		min;
	int		max;

	max = stack_a->content;
	min = stack_a->content;
	stack_b = NULL;
	ft_min_max(&stack_a, &stack_b, &min, &max);
	end = stack_a;
	while (end->next != NULL)
		end = end->next;
	stack_a = ft_sort_three(stack_a, end);
	while (end->next != NULL)
		end = end->next;
	while (stack_b != NULL)
	{
		if (stack_b->content < stack_a->content)
			ft_pb(&stack_b, &stack_a);
		else
		{
			ft_pb(&stack_b, &stack_a);
			ft_ra(&stack_a, &end);
		}
	}
	return (stack_a);
}

void	ft_min_max(t_list **stack_a, t_list **stack_b, int *min, int *max)
{
	t_list	*current;
	t_list	*end;
	int		i;

	end = (*stack_a);
	current = (*stack_a)->next;
	i = 0;
	while (end->next != NULL)
		end = end->next;
	while (current != NULL)
	{
		if (current->content > *max)
			*max = current->content;
		else if (current->content < *min)
			*min = current->content;
		current = current->next;
	}
	while (i < 2)
	{
		if ((*stack_a)->content == *max)
		{
			ft_pa(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->content == *min)
		{
			ft_pa(stack_a, stack_b);
			i++;
		}
		else
			ft_ra(stack_a, &end);
	}
}
