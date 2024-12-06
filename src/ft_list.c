/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:56:35 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/02 11:47:21 by aroullea         ###   ########.fr       */
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
		std_error();
		ft_free(result, head);
		return (NULL);
	}
	ls_new->index = i;
	ls_new->content = value;
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
	{
		std_error();
		ft_free(result, head);
	}
	return (res);
}

void	ft_print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		head = head->next;
		printf("Value: %d, Index: %d\n", current->content, current->index);
		current = head;
	}
	printf("\n");
}
