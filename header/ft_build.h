#ifndef FT_BUILD_H
# define FT_BUILD_H
# include <stdio.h>
# include <unistd.h>
# include "ft_type.h"
# include "ft_list.h"
# include "ft_utils.h"
# include "ft_split.h"

void	std_error(void);
t_list	*ft_build_list(char **result, t_list *head);
void	ft_parsing(int argc, char **argv);

#endif
