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

#include "../header/ft_build.h"

void	std_error(void)
{
	write(2, "Error\n", 6);
}

t_list	*ft_build_list(char **result, t_list *head)
{
	int		i;
	int		value;

	i = 0;
	while (result[i] != NULL)
	{
		if (!ft_isdigit(result[i]))
		{
			std_error();
			ft_free(result, head);
			return (NULL);
		}
		value = ft_atoi(result[i]);
		head = ft_add_to_list(head, value, result);
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
		head = ft_build_list(result, head);
		if (head == NULL)
			return ;
		i++;
	}
	ft_print_list(head);
}
