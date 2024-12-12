/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:04:54 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/12 16:51:50 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_build.h"

t_list	*ft_build_list(char **result, t_list *head, t_list **end)
{
	int			i;
	long int	value;
	t_bool		res;

	i = 0;
	res = FALSE;
	while (result[i] != NULL)
	{
		value = 0;
		res = ft_atoi_valid(result[i], &value, res);
		if (!res || ((value > 2147483647) || (value < -2147483648)))
		{
			std_error(result, head);
			return (NULL);
		}
		head = ft_add_to_list(&head, end, value, result);
		if (head == NULL)
			return (NULL);
		i++;
	}
	ft_free(result, NULL);
	return (head);
}

t_list	*ft_parsing(int argc, char **argv, t_list **end)
{
	int		i;
	char	**result;
	t_list	*head;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		if (is_empty(argv[i]))
		{
			std_error(NULL, head);
			return (NULL);
		}
		result = ft_split(argv[i], ' ');
		if (result == NULL)
			return (NULL);
		else
		{
			head = ft_build_list(result, head, end);
			if (head == NULL)
				return (NULL);
		}
		i++;
	}
	return (head);
}
