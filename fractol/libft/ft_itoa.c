/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urabex <urabex@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:07:04 by hurabe            #+#    #+#             */
/*   Updated: 2024/10/05 17:48:32 by urabex           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	ft_numlength(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	void	ft_string(char	*s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = '0' + (number % 10);
		number /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		numlength;
	unsigned int	num;

	numlength = ft_numlength(n);
	s = (char *)malloc(sizeof(char) * (numlength + 1));
	if (!s)
		return (NULL);
	s[numlength] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (n < 0)
	{
		num = (unsigned int)(-((long int)n));
		s[0] = '-';
	}
	else
		num = (unsigned int)n;
	ft_string(s, num, numlength - 1);
	return (s);
}
