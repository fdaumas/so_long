/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaumas <fdaumas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:03:28 by fdaumas           #+#    #+#             */
/*   Updated: 2022/04/07 19:21:12 by fdaumas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	split(int n)
{
	char	c;

	if (n > 9)
		split(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static void	inverse(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	split(n);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
		inverse(n);
	write(1, "\n", 1);
}
