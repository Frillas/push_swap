/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_sort_big.h"

t_list	*ft_sort_big(t_list *stack_a, int len_a)
{
	t_list	*stack_b;
	t_list	*extract;
	int		len_b;

	stack_b = NULL;
	extract = NULL;
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	len_a = len_a - 2;
	len_b = 2;
	extract = ft_pick_one(stack_a, stack_b, len_a, len_b);
	printf("%d\n", extract->content);
	return (stack_a);
}

t_list	*ft_pick_one(t_list *stack_a, t_list *stack_b, int len_a, int len_b)
{
	t_list			*current;
	t_list			*extract;
	unsigned long	least_move;
	unsigned long	move;

	current = stack_a;
	extract = NULL;
	least_move = (unsigned long)-1;
	while (current != NULL)
	{
		ft_update_move(current, stack_b, len_a, len_b);
		if (current->dir && current->pos->dir)
			move = ft_total_move(current);
		else
			move = current->tot_move + current->pos->tot_move + 1;
		if (move < least_move)
		{
			extract = current;
			least_move = move;
			if (move == 1)
				break ;
		}
		current = current->next;
	}
	return (extract);
}

void	ft_update_move(t_list *current, t_list *stack_b, int len_a, int len_b)
{
	ft_find_pos(current, stack_b);
	current->dir = (current->index <= (len_a / 2));
	current->pos->dir = (current->pos->index <= (len_b / 2));
	current->tot_move = ft_countmove(current);
	current->pos->tot_move = ft_countmove(current->pos);
}
