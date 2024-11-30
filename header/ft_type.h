#ifndef FT_TYPE_H
# define FT_TYPE_H

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_list
{
	int				content;
	struct s_list	*pred;
	struct s_list	*next;
}	t_list;

#endif
