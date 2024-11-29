#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define true 1
# define false 0
typedef int bool;

typedef struct s_list
{
	int				content;
	struct s_list	*pred;
	struct s_list	*next;
}   t_list;

char    **ft_split(char const *s, char c);
void    *ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);
bool	ft_isdigit(char *s);

#endif
