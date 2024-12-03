/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:38:50 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/03 11:40:14 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_instructions.h"

t_list	*ft_sa(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	head->prev = current;
	head->next = end;
	current->prev = NULL;
	current->next = head;
	end->prev = head;
	head = current;
	write(1, "sa\n", 3);
	return (head);
}

t_list	*ft_ra(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	head->prev = end;
	head->next = NULL;
	current->prev = NULL;
	end->next = head;
	head = current;
	write(1, "ra\n", 3);
	return (head);
}

t_list	*ft_rra(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	head->prev = end;
	head->next = current;
	current->next = NULL;
	end->prev = NULL;
	end->next = head;
	head = end;
	write(1, "rra\n", 4);
	return (head);
}

t_list	*ft_pa(t_list *head_a, t_list *head_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = head_a->next;
	if (head_b == NULL)
	{
		head_b = head_a;
		head_b->next = NULL;
		head_b->prev = NULL;
		current_a->prev = NULL;
	}
	else
	{
		current_b = head_b;
		head_b = head_a;
		head_b->next = current_b;
		head_b->prev = NULL;
		current_b->prev = head_b;
		current_a->prev = NULL;
	}
	return (head_b);
}
