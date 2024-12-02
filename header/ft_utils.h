#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_list.h"

void	*ft_calloc(size_t nmemb, size_t size);
t_bool	ft_atoi_valid(const char *s, long int *value);
void	ft_free(char **result, t_list *head);

#endif
