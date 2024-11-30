#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include "ft_build.h"

t_list	*ft_create_list(t_list *head, int value);
t_list	*ft_add_to_list(t_list *head, int value, char **result);
t_bool	ft_check_value(t_list *head, int value);
void	ft_print_list(t_list *head);
void	ft_free(char **result, t_list *head);

#endif
