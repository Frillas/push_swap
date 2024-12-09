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
	t_list	*current;

	min = *stack_a;
	max = (*stack_a)->next->next;
	end_a = max;
	current = (*stack_b);
	while (len_b > 0)
	{
		if (is_outside_range(current->content, min->content, max->content))
		{
			end_a = handle_ext(stack_a, stack_b, &min, &max);
			current = *stack_b;
		}
		else if (between(current->content, (*stack_a)->content, end_a->content))
			ft_pa(&current, stack_a);
		else
			default_case(stack_a, &current, &end_a, len_a);
		(*stack_b) = current;
		len_b--;
		len_a++;
	}
	*stack_a = ft_finish(stack_a, &end_a, &min, len_a);
}

t_list	*handle_ext(t_list **sta_a, t_list **sta_b, t_list **min, t_list **max)
{
	t_list	*end_a;
	int		len_a;

	len_a = 1;
	end_a = *sta_a;
	while (end_a->next != NULL)
	{
		end_a = end_a->next;
		len_a++;
	}
	if (!(ft_is_min_top(sta_a, sta_b, min)))
	{
		ft_pos_ontop(sta_a, sta_b, &end_a, len_a);
		ft_pa(sta_b, sta_a);
	}
	if ((*sta_a)->content < (*min)->content)
		*min = *sta_a;
	else if ((*sta_a)->content > (*max)->content)
		*max = *sta_a;
	return (end_a);
}

void	default_case(t_list **sta_a, t_list **sta_b, t_list **end_a, int len_a)
{
	ft_search_pos(end_a, sta_b);
	ft_pos_ontop(sta_a, sta_b, end_a, len_a);
	ft_pa(sta_b, sta_a);
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
