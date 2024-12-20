/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:16 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_BONUS_H
# define FT_CHECKER_BONUS_H
# include "../ft_build.h"
# include "get_next_line_bonus.h"
# include "ft_instru_1_bonus.h"
# include "ft_instru_2_bonus.h"
# include "ft_utils_bonus.h"

void	ft_instru(t_list **stack_a, t_list **stack_b, char *str);
t_bool	execute_instructions(t_list **stack_a, t_list **stack_b, char *inst);
t_bool	collect_instructions(char **inst);
t_bool	ft_get_stdin(t_list **stack_a, t_list **stack_b);

#endif
