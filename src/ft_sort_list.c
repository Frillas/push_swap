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

t_list	*ft_sort_five(t_list *stack_a, t_list *end, int len)
{
	t_list	*stack_b;

	stack_b = NULL;
	putmin_ontop(&stack_a, &stack_b, &end, len);
	stack_a = ft_sort_three(stack_a, end);
	while (stack_b != NULL)
		ft_pa(&stack_b, &stack_a);
	return (stack_a);
}

int	ft_check_min(t_list *stack_a)
{
	t_list	*current;
	int		min_pos;
	int		pos;
	int		min;

	current = stack_a;
	pos = 0;
	min_pos = 0;
	min = current->content;
	while (current != NULL)
	{
		if (current->content < min)
		{
			min = current->content;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	putmin_ontop(t_list **stack_a, t_list **stack_b, t_list **end, int len)
{
	int	i;
	int	size;
	int	min_pos;

	i = 0;
	size = len - 3;
	min_pos = ft_check_min(*stack_a);
	while (i < size)
	{
		if (min_pos <= (len / 2))
		{
			while ((min_pos--) > 0)
				ft_ra(stack_a, end);
		}
		else
		{
			while ((min_pos++) < len)
				ft_rra(stack_a, end);
		}
		ft_pb(stack_a, stack_b);
		min_pos = ft_check_min(*stack_a);
		i++;
		len--;
	}
}
