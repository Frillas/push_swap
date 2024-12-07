/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_sort_big_utils.h"

void	ft_find_pos(t_list *cur_a, t_list *stack_b)
{
	t_list	*cur_b;

	cur_b = stack_b;
	while (cur_b != NULL)
	{
		if (cur_a->content < cur_b->content)
		{
			if (cur_b->next != NULL && cur_a->content > cur_b->next->content)
			{
				cur_a->pos = cur_b->next;
				break ;
			}
		}
		if (cur_b->next == NULL)
			break ;
		cur_b = cur_b->next;
	}
	if (cur_a->pos == NULL)
	{
		if (cur_a->content < cur_b->content
			&& cur_a->content > stack_b->content)
			cur_a->pos = stack_b;
		else
			cur_a->pos = ft_find_max(stack_b);
	}
}

t_list	*ft_find_max(t_list *stack_b)
{
	t_list	*current;
	t_list	*max;

	current = stack_b;
	max = current;
	while (current != NULL)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

int	ft_countmove(t_list *current)
{
	int	moves;

	moves = 0;
	if (current->dir)
	{
		while (current->prev != NULL)
		{
			moves++;
			current = current->prev;
		}
	}
	else
	{
		while (current->next != NULL)
		{
			moves++;
			current = current->next;
		}
		moves++;
	}
	return (moves);
}

int	ft_total_move(t_list *current)
{
	int	min;
	int	mouv_a;
	int	mouv_b;
	int	tot;

	mouv_a = current->tot_move;
	mouv_b = current->pos->tot_move;
	if ((current->tot_move > 0) && (current->pos->tot_move > 0))
	{
		min = ft_minimum(current->tot_move, current->pos->tot_move);
		tot = mouv_a + mouv_b + 1 - min;
	}
	else
		tot = mouv_a + mouv_b + 1;
	return (tot);
}
