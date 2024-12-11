/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:16 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/ft_checker_bonus.h"

void	ft_instru(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 4))
		swap(stack_a);
	else if (!ft_strncmp(str, "sb\n", 4))
		swap(stack_b);
	else if (!ft_strncmp(str, "ss\n", 4))
		swap_ss(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa\n", 4))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb\n", 4))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra\n", 4))
		rotate(stack_a);
	else if (!ft_strncmp(str, "rb\n", 4))
		rotate(stack_b);
	else if (!ft_strncmp(str, "rr\n", 4))
		rotate_rr(stack_a, stack_b);
	else if (!ft_strncmp(str, "rra\n", 5))
		reverse(stack_a);
	else if (!ft_strncmp(str, "rrb\n", 5))
		reverse(stack_b);
	else if (!ft_strncmp(str, "rrr\n", 5))
		reverse_rrr(stack_a, stack_b);
}

int	ft_check_str(char *str)
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

t_bool	ft_get_stdin(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if ((str == NULL))
		{
			free(str);
			return (TRUE);
		}
		if (!ft_check_str(str) || (str[0] == '\n'))
		{
			free(str);
			write (2, "Error\n", 6);
			return (FALSE);
		}
		ft_instru(stack_a, stack_b, str);
		free(str);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*end;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		stack_a = ft_parsing(argc, argv, &end);
		if (stack_a != NULL)
		{
			ft_get_stdin(&stack_a, &stack_b);
			if (!ft_check_sort(stack_a) && (stack_b == NULL))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
	}
	ft_free(NULL, stack_a);
	ft_free(NULL, stack_b);
}
