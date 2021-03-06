#include "push_swap.h"

static void	print_stack(t_lst2 *stack, char name)
{
	t_lst2	*first;
	t_data	*data;

	ft_printf("stack %c: ", name);
	if (!stack)
	{
		ft_printf("\n");
		return ;
	}
	first = stack;
	while (stack->next != first)
	{
		data = stack->data;
		ft_printf("%01i (%01i), ", data->nbr, data->pos);
		stack = stack->next;
	}
	data = stack->data;
	ft_printf("%01i (%01i), ", data->nbr, data->pos);
	data = stack->next->data;
	ft_printf("[%01i]\n", data->nbr);
}

static void	testing_p(t_stacks *stack)
{
	print_stack(stack->a, 'a');
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack->a) ? "yes" : "no");
	ft_printf("\n--> action_pb 3x\n");
	run_action(PB, stack);
	run_action(PB, stack);
	run_action(PB, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack->a) ? "yes" : "no");
	ft_printf("\n--> action_pa 3x\n");
	run_action(PA, stack);
	run_action(PA, stack);
	run_action(PA, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("is_lst_ordered? %s\n", is_lst_ordered(stack->a) ? "yes" : "no");
}

static void	testing_s(t_stacks *stack)
{
	ft_printf("\n--> action_ss\n");
	run_action(SS, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("\n--> action_pb\n");
	run_action(PB, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
}

static void	testing_r(t_stacks *stack)
{
	ft_printf("\n--> action_rr\n");
	run_action(RR, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("\n--> action_pb\n");
	run_action(PB, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
}

static void	testing_rr(t_stacks *stack)
{
	ft_printf("\n--> action_rrr\n");
	run_action(RRR, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
	ft_printf("\n--> action_pb\n");
	run_action(PB, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');
}

static void	reset(t_stacks *stack)
{
	ft_printf("\n--> action_pa 3x\n");
	run_action(PA, stack);
	run_action(PA, stack);
	run_action(PA, stack);
	print_stack(stack->a, 'a');
	print_stack(stack->b, 'b');

}

void	testing(t_stacks *stack)
{
	// testing_p(stack);

	// testing_s(stack);
	// testing_s(stack);
	// testing_s(stack);
	// reset(stack);

	// testing_r(stack);
	// testing_r(stack);
	// testing_r(stack);
	// reset(stack);

	// testing_rr(stack);
	// testing_rr(stack);
	// testing_rr(stack);
	// reset(stack);

	print_stack(stack->a, 'a');
	print_stack(stack->order, 'o');
}
