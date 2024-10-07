/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:40:05 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/07 18:22:19 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_set(t_vars *vars)
{
	if (vars->command1[0] == '2')
	{
		vars->set.num_a = -0.6701;
		vars->set.num_b = 0.4539;
	}
	else if (vars->command1[0] == '3')
	{
		vars->set.num_a = 0.3;
		vars->set.num_b = 0.5;
	}
	else if (vars->command1[0] == '4')
	{
		vars->set.num_a = -0.8;
		vars->set.num_b = 0.15;
	}
	else if (vars->command1[0] == '5')
	{
		vars->set.num_a = -0.439165;
		vars->set.num_b = 0.574507;
	}
	else if (vars->command1[0] == '6')
	{
		vars->set.num_a = 0.27334;
		vars->set.num_b = 0.00742;
	}
}

unsigned int	color(char *command, int count)
{
	if (command[2] == 'a')
		return (0x00000000U + count * 1000);
	if (command[2] == 'b')
		return (0x00FF00FFU - count * 10000);
	if (command[2] == 'c')
		return (0x00FF0000U + count * 10000);
	if (command[2] == 'd')
		return (0x004b0082U + count * 10000);
	return (-1);
}
