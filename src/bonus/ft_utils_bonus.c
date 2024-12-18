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
		return (TRUE);
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
			return (TRUE);
		head = head->next;
	}
	return (FALSE);
}

t_list	*find_end(t_list *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_bool	ft_check_str(char *str)
{
	if (!ft_strncmp(str, "sa\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "sb\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "ss\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "pa\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "pb\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "ra\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "rb\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "rr\n", 4))
		return (TRUE);
	else if (!ft_strncmp(str, "rra\n", 5))
		return (TRUE);
	else if (!ft_strncmp(str, "rrb\n", 5))
		return (TRUE);
	else if (!ft_strncmp(str, "rrr\n", 5))
		return (TRUE);
	return (FALSE);
}
