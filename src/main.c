/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:56:35 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/29 11:46:39 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	std_error(void)
{
	write(2, "Error\n", 6);
}

t_list	*ft_create_list(int value)
{
	t_list	*ls_new;

	ls_new = NULL;
	ls_new = (t_list *) malloc (sizeof(t_list));
	if (ls_new == NULL)
		exit(EXIT_FAILURE);
	ls_new->content = value;
	ls_new->pred = NULL;
	ls_new->next = NULL;
	return (ls_new);
}

t_list	*ft_append_list(t_list *head, int value)
{
	t_list	*new;
	t_list	*current;

	new = ft_create_list(value);
	if (head == NULL)
		return (new);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->pred = current;
	return (head);
}

void	ft_print_list(t_list *head)
{
	t_list	*current;

	current = head;
	if (current->next == NULL)
		return ;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		value;
	char	**result;
	t_list	*head;

	i = 0;
	j = 0;
	head = NULL;
	if (argc < 2)
	{
		std_error();
		return (0);
	}
	else if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			result = ft_split(argv[i], ' ');
			while (result[j] != NULL)
			{
				if (!ft_isdigit(result[j]))
				{
					std_error();
					return (0);
				}
				value = ft_atoi(result[j]);
				head = ft_append_node(head, value);
				free (result[j]);
				j++;
			}
			free (result);
			j = 0;
			i++;
		}
	}
	ft_print_list(head);
}
