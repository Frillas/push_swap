#ifndef FT_SORT_LIST_H
# define FT_SORT_LIST_H
#include "ft_build.h"
#include "ft_type.h"
#include "ft_instru_stack_a.h"
#include "ft_instru_stack_b.h"

t_list	*ft_sort_three(t_list *head, t_list *end);
t_list	*ft_sort_five(t_list *stack_a, t_list *end, int len);
int		ft_check_min(t_list *stack_a);
void	putmin_ontop(t_list **stack_a, t_list **stack_b, t_list **end, int len);

#endif
