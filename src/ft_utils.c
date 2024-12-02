/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:01:38 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/29 15:59:30 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_utils.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	n;
	size_t	max_size;

	max_size = (size_t)-1;
	if ((nmemb != 0) && (size > max_size / nmemb))
		return (NULL);
	n = nmemb * size;
	p = (void *) malloc(n);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, n);
	return (p);
}

t_bool	ft_atoi_valid(const char *s, long int *value)
{
	int		i;
	int		sign;
	t_bool	res;

	i = 0;
	sign = 1;
	res = FALSE;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = TRUE;
		*value = (*value * 10) + (s[i++] - '0');
	}
	if ((res == TRUE) && (s[i] == '\0'))
		return (TRUE);
	else
		return (FALSE);
}
