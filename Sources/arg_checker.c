/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:01:49 by chonorat          #+#    #+#             */
/*   Updated: 2023/03/28 17:15:46 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static int	check_negative(char arg, int loc)
{
	if (loc == 0 && arg == '-')
		return (1);
	return (0);
}

static int	check_character(int argc, char *argv[], int index)
{
	int	index_j;

	index_j = 0;
	while (index < argc)
	{
		while (argv[index][index_j])
		{
			if (!ft_isdigit(argv[index][index_j]))
			{
				if (!check_negative(argv[index][index_j], index_j))
					return (0);
			}
			index_j++;
		}
		index_j = 0;
		index++;
	}
	return (1);
}

static int	check_size(int argc, char *argv[], int index)
{
	int	arg_len;

	while (index < argc)
	{
		arg_len = ft_strlen(argv[index]);
		if (arg_len > 11)
			return (0);
		else if (arg_len == 11)
		{
			if (ft_strncmp(argv[index], MIN_INT, 11) > 0)
				return (0);
		}
		else if (arg_len == 10)
		{
			if (ft_strncmp(argv[index], MAX_INT, 10) > 0)
				return (0);
		}
		index++;
	}
	return (1);
}

static int	check_duplicate(int argc, char *argv[], int index)
{
	int	index_j;

	index_j = 1;
	while ((index + 1) < argc)
	{
		while ((index + index_j) < argc)
		{
			if (ft_strncmp(argv[index], argv[index + index_j], 11) == 0)
				return (0);
			index_j++;
		}
		index_j = 1;
		index++;
	}
	return (1);
}

int	arg_checker(int argc, char *argv[], int index)
{
	if (!check_character(argc, argv, index))
		return (0);
	if (!check_size(argc, argv, index))
		return (0);
	if (!check_duplicate(argc, argv, index))
		return (0);
	return (1);
}
