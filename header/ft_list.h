/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:55:57 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 10:56:00 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "ft_build.h"

t_list	*ft_create_list(t_list *head, int value, char **result);
t_list	*ft_add_to_list(t_list **head, t_list **end, int value, char **result);
t_bool	ft_check_value(t_list *head, int value, char **result);
void	ft_print_list(t_list *head);

#endif
