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

t_list	*ft_sort_list(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	if (head->content > end->content)
	{
		if (head->content > current->content)
		{
			if (current->content < end->content)
				head = ft_ra(head, end);
			else
			{
				head = ft_sa(head, end);
				head = ft_rra(head, end);
			}
		}
		else
			head = ft_rra(head, end);
	}
	if (head->content < end->content)
	{
		if (current->content < head->content)
			head = ft_sa(head, end);
		else if (current->content > end->content)
		{
			head = ft_sa(head, end);
			head = ft_ra(head, end);
		}
	}
	return (head);
}
