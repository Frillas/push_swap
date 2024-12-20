/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_next.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:59:20 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:00:05 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_NEXT_H
# define FT_UTILS_NEXT_H

# include "ft_list.h"

void	std_error(char **result, t_list *head);
void	update_index(t_list *head);
int		ft_minimum(int nb1, int nb2);
t_bool	is_empty(char *str);

#endif
