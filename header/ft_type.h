/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:58:26 by aroullea          #+#    #+#             */
/*   Updated: 2024/12/06 11:08:21 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_list
{
	int				content;
	int				index;
	int				dir;
	int				tot_move;
	struct s_list	*pos;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

#endif
