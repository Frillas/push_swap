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

t_list	*ft_sort_big(t_list *stack_a, t_list *end_a, int len_a)
{
	t_list	*stack_b;
	t_list	*extract;
	t_list	*end_b;
	int		len_b;

	stack_b = NULL;
	extract = NULL;
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	end_b = stack_b->next;
	len_a = len_a - 2;
	len_b = 2;
	while (len_a > 3)
	{
		extract = ft_pick_one(stack_a, stack_b, len_a, len_b);
		ft_send_node(&extract, &end_a, &end_b);
		stack_a = extract;
		stack_b = extract->pos;
		ft_pb(&stack_a, &stack_b);
		len_a--;
		len_b++;
	}
	stack_a = ft_sort_three(stack_a, end_a);
	ft_push_back(&stack_a, &stack_b, len_a, len_b);
	ft_print_list(stack_b);
	return (stack_a);
}

t_list	*ft_pick_one(t_list *stack_a, t_list *stack_b, int len_a, int len_b)
{
	t_list			*extract;
	unsigned long	least_move;
	unsigned long	move;

	least_move = (unsigned long)-1;
	while (stack_a != NULL)
	{
		ft_update_move(stack_a, stack_b, len_a, len_b);
		if (stack_a->dir && stack_a->pos->dir)
			move = ft_total_move(stack_a);
		else if (!(stack_a->dir) && !(stack_a->pos->dir))
			move = ft_total_move(stack_a);
		else
			move = stack_a->tot_move + stack_a->pos->tot_move + 1;
		if (move < least_move)
		{
			extract = stack_a;
			least_move = move;
			if (move == 1 || move == 2)
				break ;
		}
		stack_a = stack_a->next;
	}
	return (extract);
}

void	ft_update_move(t_list *current, t_list *stack_b, int len_a, int len_b)
{
	current->pos = NULL;
	ft_find_pos(current, stack_b);
	current->dir = (current->index <= (len_a / 2));
	current->pos->dir = (current->pos->index <= (len_b / 2));
	current->tot_move = ft_countmove(current);
	current->pos->tot_move = ft_countmove(current->pos);
}
