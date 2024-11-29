/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:06:58 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/29 16:00:09 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_bool	ft_isdigit(char *s)
{
	int		i;
	t_bool	res;

	i = 0;
	res = FALSE;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = TRUE;
		i++;
	}
	if ((res) && (s[i] == '\0'))
		return (TRUE);
	else
		return (FALSE);
}
