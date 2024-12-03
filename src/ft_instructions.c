#include"../header/ft_instructions.h"

t_list	*ft_ra(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	head->prev = end;
	head->next = NULL;
	current->prev = NULL;
	end->next = head;
	head = current;
	write(1, "ra\n", 3);
	return (head);
}

t_list *ft_sa(t_list *head, t_list *end)
{
	t_list	*current;
	
	current = head->next;
	head->prev = current;
	head->next = end;
	current->prev = NULL;
	current->next = head;
	end->prev = head;
	head = current;
	write(1, "sa\n", 3);
	return (head);
}

t_list	*ft_rra(t_list *head, t_list *end)
{
	t_list	*current;

	current = head->next;
	head->prev = end;
	head->next = current;
	current->next = NULL;
	end->prev = NULL;
	end->next = head;
	head = end;
	write(1, "rra\n", 4);
	return (head);
}
