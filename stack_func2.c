/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeynepsasmaz <zeynepsasmaz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:44:12 by zeynepsasma       #+#    #+#             */
/*   Updated: 2022/12/26 22:44:12 by zeynepsasma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *data)
{
	int	tmp;
	int	i;

	i = 0;
	if (data->a_len >= 2)
	{
		tmp = data->a_s[i];
		data->a_s[i] = data->a_s[i + 1];
		data->a_s[i + 1] = tmp;
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	swap_b(t_stack *data)
{
	int	tmp;
	int	i;

	i = 0;
	if (data->b_len >= 2)
	{
		tmp = data->b_s[i];
		data->b_s[i] = data->b_s[i + 1];
		data->b_s[i + 1] = tmp;
		write(1, "sb\n", 3);
	}
	else
		return ;
}

void	rotate_a(t_stack *data)
{
	int	i;
	int	d;

	i = 1;
	d = data->a_s[0];
	while (i < data->a_len)
	{
		data->a_s[i - 1] = data->a_s[i];
		i++;
	}
	data->a_s[data->a_len - 1] = d;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *data)
{
	int	tmp;
	int	i;
	int	d;

	i = 1;
	d = data->b_s[0];
	while (i < data->b_len)
	{
		tmp = data->b_s[i];
		data->b_s[i] = data->b_s[i - 1];
		data->b_s[i - 1] = tmp;
		i++;
	}
	data->b_s[data->b_len - 1] = d;
	write(1, "rb\n", 3);
}

void	rev_rotate_a(t_stack *data)
{
	int	tmp;
	int	i;
	int	d;

	i = data->a_len - 1;
	d = data->a_s[i];
	while (i > 0)
	{
		tmp = data->a_s[i - 1];
		data->a_s[i] = data->a_s[i - 1];
		data->a_s[i] = tmp;
		i--;
	}
	data->a_s[0] = d;
	write(1, "rra\n", 4);
}
