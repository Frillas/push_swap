/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*     ft_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/15 16:17:16 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H
# include "ft_checker_bonus.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_bool	ft_check_sort(t_list *head);
t_list	*find_end(t_list *head);

#endif
