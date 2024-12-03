#include "../header/ft_sort_list.h"

t_list	*ft_sort_list(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	if (head->content > current->content)
	{
		if (head->content > end->content)
		{
			if (current->content < end->content)
				head = ft_ra(head, end);
			else
			{
				head = ft_sa(head, end);
				head = ft_rra(head, end);
			}
		}
		else if (head->content < end->content) 
			head = ft_sa(head, end);
		
	}
	return (head);
}
