/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instru_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:16 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/ft_instru_2_bonus.h"

void	reverse(t_list **head)
{
	t_list	*end;

	if (!head || !*head || !(*head)->next)
		return ;
	end = *head;
	while (end->next != NULL)
		end = end->next;
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = *head;
	(*head)->prev = end;
	*head = end;
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rrr(t_list **stack_a, t_list**stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}
