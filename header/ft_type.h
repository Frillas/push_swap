#ifndef FT_TYPE_H
# define FT_TYPE_H

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

#endif
