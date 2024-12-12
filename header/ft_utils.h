/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:58:41 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/12 16:53:03 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_list.h"

void	*ft_calloc(size_t nmemb, size_t size);
t_bool	ft_atoi_valid(const char *s, long int *value, t_bool res);
void	ft_free(char **result, t_list *head);
int		ft_count_list(t_list *head, t_bool *sort_numb);

#endif
