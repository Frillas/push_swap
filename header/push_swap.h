#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_list
{
	int				content;
	struct s_list	*pred;
	struct s_list	*next;
}	t_list;

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);
t_bool	ft_isdigit(char *s);
void	std_error(void);
t_list	*ft_build_list(char **result, t_list *head);
void	ft_parsing(int argc, char **argv);
void	ft_print_list(t_list *head);
t_list	*ft_add_to_list(t_list *head, int value, char **result);
t_list	*ft_create_list(t_list *head, int value);
t_bool	ft_check_value(t_list *head, int value);
void	ft_free(char **result, t_list *head);

#endif
