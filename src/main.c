/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:56:35 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/03 10:37:28 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_build.h"

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*end;
	int		len;
	t_bool	sort_numb;

	sort_numb = TRUE;
	head = NULL;
	if (argc >= 2)
	{
		head = ft_parsing(argc, argv, &end);
		if (head != NULL)
		{
			len = ft_count_list(head, &sort_numb);
			if ((!sort_numb) && (len <= 3))
				head = ft_sort_three(head, end);
			else if ((!sort_numb) && (len <= 5))
				head = ft_sort_five(head, end);
			ft_print_list(head);
		}
	}
	ft_free(NULL, head);
	return (0);
}
