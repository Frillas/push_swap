/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_node.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:59:20 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:00:05 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEND_NODE_H
# define FT_SEND_NODE_H

# include "ft_build.h"
# include "ft_sort_big.h"

void	ft_send_node(t_list **extract, t_list **end_a, t_list **end_b);
void	ft_dir_true(t_list **extract, t_list **end_a, t_list **end_b);
void	ft_dir_false(t_list **extract, t_list **end_a, t_list **end_b);
void	ft_opposite_a(t_list **head, t_list **end);
void	ft_opposite_b(t_list **head, t_list **end);

#endif
