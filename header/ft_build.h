#ifndef FT_BUILD_H
# define FT_BUILD_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_type.h"
# include "ft_list.h"
# include "ft_utils.h"
# include "ft_utils_next.h"
# include "ft_split.h"
# include "ft_sort_list.h"

void	std_error(void);
t_list	*ft_build_list(char **result, t_list *head, t_list **end);
t_list	*ft_parsing(int argc, char **argv, t_list **end);

#endif
