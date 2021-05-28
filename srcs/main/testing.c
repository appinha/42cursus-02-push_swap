#include "push_swap.h"

static void	print_stack(t_lst2 *stack, char name)
{
	t_lst2	*first;
	int len;

	ft_printf("stack %c: ", name);
	if (!stack)
	{
		ft_printf("\n");
		return ;
	}
	first = stack;
	len = 1;
	while (stack->next != first)
	{
		stack = stack->next;
		len++;
	}
	stack = first;
	while (len--)
	{
		ft_printf("%i ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("(%i)\n", stack->nbr);
}

static void	testing_p(t_stacks *stack)
{
	print_stack(stack->a, 'a');
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack->a) ? "yes" : "no");
	ft_printf("\n--> action_pb 3x\n");
	action_pb(stack);
	action_pb(stack);
	action_pb(stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack->a) ? "yes" : "no");
	ft_printf("\n--> action_pa 3x\n");
	action_pa(stack);
	action_pa(stack);
	action_pa(stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack->a) ? "yes" : "no");
}

static void	testing_s(t_stacks *stack)
{
	ft_printf("\n--> action_ss\n");
	action_ss(stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("\n--> action_pb\n");
	action_pb(stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
}

void	testing(t_stacks *stack)
{
	testing_p(stack);
	testing_s(stack);
	testing_s(stack);
	testing_s(stack);
}