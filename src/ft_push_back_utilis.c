/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_back_utils.h"

t_bool	is_outside_range(int content, int min, int max)
{
	if ((content < min) || (content > max))
		return (TRUE);
	else
		return (FALSE);
}

t_bool	between(int content, int stack_a_content, int end_a_content)
{
	if ((content < stack_a_content) && (content > end_a_content))
		return (TRUE);
	else
		return (FALSE);
}

void	ft_search_pos(t_list **end_a, t_list **cur_b)
{
	t_list	*search;

	search = *end_a;
	while (search != NULL)
	{
		if ((*cur_b)->content < search->content)
		{
			if (search->prev != NULL
				&& (*cur_b)->content > search->prev->content)
			{
				(*cur_b)->pos = search;
				break ;
			}
		}
		search = search->prev;
	}
}

void	ft_pos_ontop(t_list **stack_a, t_list **cur_b, t_list **end, int len)
{
	(*cur_b)->pos->dir = ((*cur_b)->pos->index <= (len / 2));
	(*cur_b)->pos->tot_move = ft_countmove((*cur_b)->pos);
	if ((*cur_b)->pos->dir == TRUE)
	{
		while ((*cur_b)->pos->tot_move > 0)
		{
			ft_ra(stack_a, end, FALSE);
			(*cur_b)->pos->tot_move--;
		}
	}
	else
	{
		while ((*cur_b)->pos->tot_move > 0)
		{
			ft_rra(stack_a, end, FALSE);
			(*cur_b)->pos->tot_move--;
		}
	}
}

t_bool	ft_is_min_top(t_list **stack_a, t_list **current_b, t_list **min)
{
	t_bool	check_pa;

	check_pa = FALSE;
	if ((*min)->content == (*stack_a)->content)
	{
		ft_pa(current_b, stack_a);
		check_pa = TRUE;
	}
	else
		(*current_b)->pos = *min;
	return (check_pa);
}
