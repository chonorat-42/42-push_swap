/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:59:55 by chonorat          #+#    #+#             */
/*   Updated: 2023/08/29 14:58:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b, int argc)
{
	argc++;
	if (argc <= 6)
		small_sort(a, b, argc);
	else if (argc > 6)
		radix_sort(a, b);
}

static char	**remove_ws(char **argv)
{
	int	index;

	index = 0;
	while (argv[1][index] >= 9 || argv[1][index] >= 13)
	{
		if (argv[1][index] == '\t')
			argv[1][index] = ' ';
		index++;
	}
	return (argv);
}

static int	unique_arg(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arg_value;

	stack_a = NULL;
	stack_b = NULL;
	arg_value = NULL;
	arg_value = remove_ws(argv);
	arg_value = ft_split(argv[1], ' ');
	if (!arg_value)
		return (0);
	argc = arg_counter(arg_value);
	if (argc == -1)
		return (free_argvalue(arg_value), 0);
	else if (argc == 1)
		return (free_argvalue(arg_value), 1);
	if (!arg_checker(argc, arg_value, 0))
		return (free_argvalue(arg_value), 0);
	stack_a = convert_stack(argc, arg_value, 0);
	if (is_sorted(stack_a))
		return (free_elements(&stack_a, &stack_b, arg_value), 1);
	sort_stack(&stack_a, &stack_b, argc);
	return (free_elements(&stack_a, &stack_b, arg_value), 1);
}

static int	multiple_arg(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!arg_checker(argc, argv, 1))
		return (0);
	stack_a = convert_stack(argc, argv, 1);
	if (is_sorted(stack_a))
		return (free_elements(&stack_a, &stack_b, NULL), 1);
	if (argc <= 6)
		small_sort(&stack_a, &stack_b, argc);
	if (argc > 6)
		radix_sort(&stack_a, &stack_b);
	free_elements(&stack_a, &stack_b, NULL);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && ft_memcmp(argv[1], "", 1) != 0)
	{
		if (!unique_arg(argc, argv))
			return (ft_putstr_fd("Error\n", 1), EXIT_FAILURE);
	}
	if (argc >= 3)
	{
		if (!multiple_arg(argc, argv))
			return (ft_putstr_fd("Error\n", 1), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
