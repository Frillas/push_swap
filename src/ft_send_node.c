/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_send_node.h"

void	ft_send_node(t_list **extract, t_list **end_a, t_list **end_b)
{
	if (((*extract)->dir == TRUE) && ((*extract)->pos->dir == TRUE))
		ft_dir_true(extract, end_a, end_b);
	else if (((*extract)->dir == FALSE) && ((*extract)->pos->dir == FALSE))
		ft_dir_false(extract, end_a, end_b);
	else if ((*extract)->dir != (*extract)->pos->dir)
	{
		ft_opposite_a(extract, end_a);
		ft_opposite_b(&((*extract)->pos), end_b);
	}
}

void	ft_dir_true(t_list **extract, t_list **end_a, t_list **end_b)
{
	while (((*extract)->tot_move > 0) && ((*extract)->pos->tot_move > 0))
	{
		ft_rr(extract, &((*extract)->pos), end_a, end_b);
		(*extract)->tot_move--;
		(*extract)->pos->tot_move--;
	}
	while ((*extract)->tot_move > 0)
	{
		ft_ra(extract, end_a, FALSE);
		(*extract)->tot_move--;
	}
	while ((*extract)->pos->tot_move > 0)
	{
		ft_rb(&((*extract)->pos), end_b);
		(*extract)->pos->tot_move--;
	}
}

void	ft_dir_false(t_list **extract, t_list **end_a, t_list **end_b)
{
	while (((*extract)->tot_move > 0) && ((*extract)->pos->tot_move > 0))
	{
		ft_rrr(extract, &((*extract)->pos), end_a, end_b);
		(*extract)->tot_move--;
		(*extract)->pos->tot_move--;
	}
	while ((*extract)->tot_move > 0)
	{
		ft_rra(extract, end_a, FALSE);
		(*extract)->tot_move--;
	}
	while ((*extract)->pos->tot_move > 0)
	{
		ft_rrb(&((*extract)->pos), end_b);
		(*extract)->pos->tot_move--;
	}
}

void	ft_opposite_a(t_list **head, t_list **end)
{
	if ((*head)->dir == TRUE)
	{
		while ((*head)->tot_move > 0)
		{
			ft_ra(head, end, FALSE);
			(*head)->tot_move--;
		}
	}
	else
	{
		while ((*head)->tot_move > 0)
		{
			ft_rra(head, end, FALSE);
			(*head)->tot_move--;
		}
	}
}

void	ft_opposite_b(t_list **head, t_list **end)
{
	if ((*head)->dir == TRUE)
	{
		while ((*head)->tot_move > 0)
		{
			ft_rb(head, end);
			(*head)->tot_move--;
		}
	}
	else
	{
		while ((*head)->tot_move > 0)
		{
			ft_rrb(head, end);
			(*head)->tot_move--;
		}
	}
}
