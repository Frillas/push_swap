/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:01:38 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/19 15:10:10 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/push_swap.h"

static void    ft_bzero(void *s, size_t n)
{
    size_t  i;
    char    *str;

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

	n = nmemb * size;
	p = (void *) malloc(n);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, n);
	return (p);
}
