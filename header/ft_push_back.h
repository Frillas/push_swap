/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:40:52 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PUSH_BACK_H
# define FT_PUSH_BACK_H

# include "ft_build.h"
# include "ft_sort_big.h"
# include "ft_push_back_utils.h"

void	ft_push_back(t_list **stack_a, t_list **stack_b, int len_a, int len_b);
t_list	*handle_ext(t_list **sta_a, t_list **sta_b, t_list **min, t_list **max);
void	default_case(t_list **sta_a, t_list **sta_b, t_list **end_a, int len_a);
t_list	*ft_finish(t_list **stack_a, t_list **end_a, t_list **min, int len_a);

#endif
