/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:56:16 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/11 06:54:36 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/ft_utils_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

t_bool	ft_check_sort(t_list *head)
{
	if (head == NULL)
		return (1);
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
			return (1);
		head = head->next;
	}
	return (0);
}

t_list	*find_end(t_list *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}
