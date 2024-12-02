/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:56:35 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/29 17:35:30 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_list.h"

t_list	*ft_create_list(t_list *head, int value)
{
	t_list	*ls_new;
	t_list	*current;

	ls_new = NULL;
	ls_new = (t_list *) malloc (sizeof(t_list));
	if (ls_new == NULL)
	{
		current = head;
		while (current != NULL)
		{
			head = head->next;
			free(current);
			current = head;
		}
		return (NULL);
	}
	ls_new->content = value;
	ls_new->pred = NULL;
	ls_new->next = NULL;
	return (ls_new);
}

t_list	*ft_add_to_list(t_list *head, int value, char **result)
{
	t_list	*new;
	t_list	*current;

	if (!ft_check_value(head, value))
	{
		std_error();
		ft_free(result, head);
		return (NULL);
	}
	else
	{
		new = ft_create_list(head, value);
		if (new == NULL)
			return (0);
		else if (head == NULL)
			return (new);
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->pred = current;
		return (head);
	}
}

t_bool	ft_check_value(t_list *head, int value)
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
	return (res);
}

void	ft_print_list(t_list *head)
{
	t_list	*current;

	current = head;
	if (current->next == NULL)
		return ;
	while (current != NULL)
	{
		head = head->next;
		printf("%d\n", current->content);
		free (current);
		current = head;
	}
}

void	ft_free(char **result, t_list *head)
{
	int		i;
	t_list	*current;

	i = 0;
	current = head;
	while (current != NULL)
	{
		head = head->next;
		free(current);
		current = head;
	}
	while (result[i] == NULL)
		i++;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}
