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
	int			i;
	long int	value;
	t_bool		res;

	i = 0;
	while (result[i] != NULL)
	{
		value = 0;
		res = ft_atoi_valid(result[i], &value);
		if (!res || ((value > 2147483647) || (value < -2147483647)))
		{
			std_error();
			ft_free(result, head);
			return (NULL);
		}
		head = ft_add_to_list(head, value, result);
		if (head == NULL)
			return (NULL);
		free (result[i]);
		result[i] = NULL;
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
