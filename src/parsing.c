/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:04:54 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/29 17:37:20 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	std_error(void)
{
	write(2, "Error\n", 6);
}

t_list	*ft_sort_list(char **result, t_list *head)
{
	int		i;
	int		value;
	t_list	*current;

	i = 0;
	while (result[i] != NULL)
	{
		if (!ft_isdigit(result[i]))
		{
			std_error();
			current = head;
			while (current != NULL)
			{
				head = head->next;
				free(current);
				current = head;
			}
			while ((i >= 0) && (result[i]))
			{
				free(result[i]);
				i--;
			}
			free(result);
			return (NULL);
		}
		value = ft_atoi(result[i]);
		head = ft_append_list(head, value);
		if (head == NULL)
			return (NULL);
		free (result[i]);
		i++;
	}
	free(result);
	return (head);
}

void	ft_parsing(int argc, char **argv)
{
	int		i;
	char	**result;
	t_list	*head;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		result = ft_split(argv[i], ' ');
		if (result == NULL)
			return ;
		head = ft_sort_list(result, head);
		if (head == NULL)
			return ;
		i++;
	}
	ft_print_list(head);
}
