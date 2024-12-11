/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:01:38 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:06:08 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_utils_next.h"

void	std_error(char **result, t_list *head)
{
	write(2, "Error\n", 6);
	ft_free(result, head);
}

void	update_index(t_list *head)
{
	int		index;
	t_list	*current;

	current = head;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

int	ft_minimum(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	else if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

t_bool	is_empty(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (FALSE);
		str++;
	}
	return (TRUE);
}
