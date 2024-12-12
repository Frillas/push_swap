/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:01:38 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/12 16:53:07 by aroullea         ###   ########.fr       */
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

t_bool	ft_atoi_valid(const char *s, long int *value, t_bool res)
{
	int		i;
	int		sign;

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
		if (*value < 0)
			return (FALSE);
	}
	*value = *value * sign;
	if ((res == TRUE) && (s[i] == '\0'))
		return (TRUE);
	return (FALSE);
}

void	ft_free(char **result, t_list *head)
{
	int		i;
	t_list	*current;

	i = 0;
	current = head;
	while (current != NULL)
	{
		head = head->next;
		free(current);
		current = head;
	}
	if (result != NULL)
	{
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
}

int	ft_count_list(t_list *head, t_bool *sort_numb)
{
	int		len;
	t_list	*current;

	len = 0;
	current = head->next;
	while (head != NULL)
	{
		if ((*sort_numb == TRUE) && (current != NULL))
		{
			if (head->content < current->content)
				*sort_numb = TRUE;
			else
				*sort_numb = FALSE;
		}
		len++;
		if (current == NULL)
			break ;
		head = head->next;
		current = current->next;
	}
	return (len);
}
