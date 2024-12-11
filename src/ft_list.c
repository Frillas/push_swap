/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:56:35 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:10:31 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_list.h"

t_list	*ft_create_list(t_list *head, int value, char **result)
{
	t_list		*ls_new;
	static int	i;

	ls_new = NULL;
	ls_new = (t_list *) malloc (sizeof(t_list));
	if (ls_new == NULL)
	{
		ft_free(result, head);
		return (NULL);
	}
	ls_new->index = i;
	ls_new->content = value;
	ls_new->tot_move = 0;
	ls_new->dir = -1;
	ls_new->pos = NULL;
	ls_new->prev = NULL;
	ls_new->next = NULL;
	i++;
	return (ls_new);
}

t_list	*ft_add_to_list(t_list **head, t_list **end, int value, char **result)
{
	t_list			*new;

	if (!ft_check_value(*head, value, result))
		return (NULL);
	else
	{
		new = ft_create_list(*head, value, result);
		if (new == NULL)
			return (NULL);
		else if (*head == NULL)
		{
			*head = new;
			*end = new;
			return (*head);
		}
		(*end)->next = new;
		new->prev = (*end);
		(*end) = new;
		return (*head);
	}
}

t_bool	ft_check_value(t_list *head, int value, char **result)
{
	t_list	*current;
	t_bool	res;

	current = head;
	res = TRUE;
	while ((current != NULL) && (res == TRUE))
	{
		if (current->content == value)
			res = FALSE;
		current = current->next;
	}
	if (res == FALSE)
		std_error(result, head);
	return (res);
}
