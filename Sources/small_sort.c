/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:46:51 by chonorat          #+#    #+#             */
/*   Updated: 2023/04/18 15:56:44 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->index == 2)
		do_swap(stack_a, NULL, "sa");
}

static void	sort_three(t_stack **stack_a)
{
	t_stack	*top;
	t_stack	*middle;
	t_stack	*bottom;

	top = *stack_a;
	middle = top->next;
	bottom = middle->next;
	if (bottom->content > top->content && top->content > middle->content)
		do_swap(stack_a, NULL, "sa");
	if (top->content > middle->content && middle->content > bottom->content)
	{
		do_swap(stack_a, NULL, "sa");
		do_rev_rotate(stack_a, NULL, "rra");
	}
	if (middle->content > bottom->content && bottom->content > top->content)
	{
		do_swap(stack_a, NULL, "sa");
		do_rotate(stack_a, NULL, "ra");
	}
	if (middle->content > top->content && top->content > bottom->content)
		do_rev_rotate(stack_a, NULL, "rra");
	if (top->content > bottom->content && bottom->content > middle->content)
		do_rotate(stack_a, NULL, "ra");
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	while (!(*stack_b))
	{
		if ((*stack_a)->index == 1)
			do_push(stack_a, stack_b, "pb");
		else
			do_rotate(stack_a, NULL, "ra");
	}
	sort_three(stack_a);
	do_push(stack_a, stack_b, "pa");
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	push;

	push = 0;
	while (push != 2)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
		{
			do_push(stack_a, stack_b, "pb");
			push++;
		}
		else
			do_rotate(stack_a, NULL, "ra");
	}
	sort_three(stack_a);
	if ((*stack_b)->index != 2)
		do_swap(NULL, stack_b, "sb");
	while (*stack_b)
		do_push(stack_a, stack_b, "pa");
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
		sort_two(stack_a);
	if (argc == 4)
		sort_three(stack_a);
	if (argc == 5)
		sort_four(stack_a, stack_b);
	if (argc == 6)
		sort_five(stack_a, stack_b);
}
