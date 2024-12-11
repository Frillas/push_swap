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
# include <stdio.h>
# include "../ft_build.h"
# include "get_next_line.h"
# include "ft_instru_1_bonus.h"
# include "ft_instru_2_bonus.h"
# include "ft_utils_bonus.h"

void	ft_instru(t_list **stack_a, t_list **stack_b, char *str);
int		ft_check_str(char *str);
void	ft_get_stdin(t_list **stack_a, t_list **stack_b);

#endif
