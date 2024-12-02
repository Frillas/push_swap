/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 07:56:35 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/02 12:03:11 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_build.h"

int	main(int argc, char **argv)
{
	t_list	*head;

	if (argc >= 2)
	{
		head = ft_parsing(argc, argv);
		if (head != NULL)
	}
	return (0);
}
