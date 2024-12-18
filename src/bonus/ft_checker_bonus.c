/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/12 13:48:00 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/bonus/ft_checker_bonus.h"

void	ft_instru(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		swap(stack_a);
	else if (!ft_strncmp(str, "sb", 3))
		swap(stack_b);
	else if (!ft_strncmp(str, "ss", 3))
		swap_ss(stack_a, stack_b);
	else if (!ft_strncmp(str, "pa", 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb", 3))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp(str, "ra", 3))
		rotate(stack_a);
	else if (!ft_strncmp(str, "rb", 3))
		rotate(stack_b);
	else if (!ft_strncmp(str, "rr", 3))
		rotate_rr(stack_a, stack_b);
	else if (!ft_strncmp(str, "rra", 4))
		reverse(stack_a);
	else if (!ft_strncmp(str, "rrb", 4))
		reverse(stack_b);
	else if (!ft_strncmp(str, "rrr", 4))
		reverse_rrr(stack_a, stack_b);
}

t_bool	execute_instructions(t_list **stack_a, t_list **stack_b, char *inst)
{
	char	**ptr_inst;
	int		i;

	i = 0;
	if (inst == NULL)
		return (TRUE);
	ptr_inst = ft_split(inst, '\n');
	free(inst);
	if (ptr_inst == NULL)
		return (FALSE);
	while (ptr_inst[i])
	{
		ft_instru(stack_a, stack_b, ptr_inst[i]);
		free(ptr_inst[i]);
		i++;
	}
	free(ptr_inst);
	return (TRUE);
}

t_bool	collect_instructions(char **inst)
{
	char	*str;

	*inst = NULL;
	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (!ft_check_str(str) || (str[0] == '\n'))
		{
			free(*inst);
			free(str);
			write (2, "Error\n", 6);
			return (FALSE);
		}
		*inst = ft_strjoin(*inst, str, ft_strlen(*inst), ft_strlen(str));
		free(str);
		if (*inst == NULL)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_get_stdin(t_list **stack_a, t_list **stack_b)
{
	char	*inst;

	if (!collect_instructions(&inst))
		return (FALSE);
	if (!execute_instructions(stack_a, stack_b, inst))
		return (FALSE);
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
			if (ft_get_stdin(&stack_a, &stack_b))
			{
				if (!ft_check_sort(stack_a) && (stack_b == NULL))
					write(1, "OK\n", 3);
				else
					write(1, "KO\n", 3);
			}
		}
	}
	ft_free(NULL, stack_a);
	ft_free(NULL, stack_b);
}
