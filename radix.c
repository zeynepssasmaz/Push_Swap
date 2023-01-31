/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeynepsasmaz <zeynepsasmaz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:43:48 by zeynepsasma       #+#    #+#             */
/*   Updated: 2022/12/26 22:43:48 by zeynepsasma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_maxbit(t_stack *data)
{
	int	max;

	data->max_bit = 0;
	max = data->a_len - 1;
	while (max > 0)
	{
		data->max_bit++;
		max /= 2;
	}
}

int	find_index(t_stack *data, int nbr)
{
	int	i;

	i = 0;
	while (i < data->len)
	{
		if (data->sorted[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

void	radix(t_stack *data)
{
	int	i;
	int	x;
	int	alen;

	i = 0;
	alen = data->a_len;
	while (i < data->max_bit)
	{
		x = 0;
		while (x < alen)
		{
			if ((find_index(data, data->a_s[0]) >> i & 1))
				rotate_a(data);
			else
				push_b(data);
			x++;
		}
		while (data->b_len)
			push_a(data);
		i++;
	}
}
