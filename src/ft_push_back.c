/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_back.h"

void	ft_push_back(t_list **stack_a, t_list **stack_b, int len_a, int len_b)
{
	t_list	*min;
	t_list	*max;
	t_list	*end_a;
	t_list	*current_a;
	t_list	*current_b;

	min = *stack_a;
	max = (*stack_a)->next->next;
	end_a = max;
	current_a = (*stack_a);
	current_b = (*stack_b);
	current_b->pos = NULL;
	while (len_b > 0) 
	{
		if (current_b->content < min->content)
		{
			if (!(ft_min_max(&current_a, &current_b, &min)))
			{
				ft_pos_ontop(stack_a, &current_b, &end_a, len_a);
				ft_pa(&current_b, stack_a);
				min = *stack_a;
			}
			else
			{
				*stack_a = current_a;
				*stack_b = current_b;
				min = *stack_a;
			}
		}
	
		else if (current_b->content > max->content)
		{
			if (!(ft_min_max(&current_a, &current_b, &min)))
			{
				ft_pos_ontop(stack_a, &current_b, &end_a, len_a);
				ft_pa(&current_b, stack_a);
				max = *stack_a;
			}
			else
			{
				*stack_a = current_a;
				*stack_b = current_b;
				max = *stack_a;
			}
		}
		else if ((current_b->content < current_a->content) 
			&& (current_b->content > end_a->content))
			ft_pa(&current_b, stack_a);
		else
		{	
			ft_search_pos(&end_a, &current_b);
			ft_pos_ontop(stack_a, &current_b, &end_a, len_a);
			ft_pa(&current_b, stack_a);
		}
	(*stack_b) = current_b;
	current_a = (*stack_a);
	if (current_b != NULL)
		current_b->pos = NULL;
	len_b--;
	len_a++;
	}
	*stack_a = ft_finish(stack_a, &end_a, &min, len_a);
}

void	ft_search_pos(t_list **end_a, t_list **cur_b)
{
	t_list	*search;

	search = *end_a;
	while (search != NULL)
	{
		if ((*cur_b)->content < search->content)
		{
			if (search->prev != NULL && (*cur_b)->content > search->prev->content)
			{
				(*cur_b)->pos = search;
				break;
			}
		}
		search = search->prev;
	}
}
t_bool	ft_min_max(t_list **current_a, t_list **current_b, t_list **min)
{
	t_bool	check_pa;

	check_pa = FALSE;
	if ((*min)->content == (*current_a)->content) 
	{	
		ft_pa(current_b, current_a);
		check_pa = TRUE;
	}
	else
		(*current_b)->pos = *min;
	return (check_pa);
}
void	ft_pos_ontop(t_list **stack_a, t_list **current_b, t_list **end_a, int len_a)
{
	(*current_b)->pos->dir = ((*current_b)->pos->index <= (len_a / 2));
	(*current_b)->pos->tot_move = ft_countmove((*current_b)->pos);
	if ((*current_b)->pos->dir == TRUE)
	{
		while ((*current_b)->pos->tot_move > 0)
		{	
			ft_ra(stack_a, end_a, FALSE);
			(*current_b)->pos->tot_move--;
		}
	}
	else
	{
		while ((*current_b)->pos->tot_move > 0)
		{	
			ft_rra(stack_a, end_a, FALSE);
			(*current_b)->pos->tot_move--;
		}	
	}
}

t_list	*ft_finish(t_list **stack_a, t_list **end_a, t_list **min, int len_a)
{
	t_list	*current;
	
	current = *min;
	current->dir = current->index <= (len_a / 2);
	current->tot_move = ft_countmove(current);
	if (current->dir == TRUE)
	{
		while (current->tot_move > 0)
		{
			ft_ra(stack_a, end_a, FALSE);
			current->tot_move--;
		}
	}
	else 
	{
		while (current->tot_move > 0)
		{
			ft_rra(stack_a, end_a, FALSE);
			current->tot_move--;
		}
	}
	return (*stack_a);
}
