/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:46 by samartin          #+#    #+#             */
/*   Updated: 2022/12/12 15:30:28 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_int_pos_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		base *= base;
		exp >>= 1;
	}
	return (result);
}

int	ft_int_sqrt(int n)
{
	int	sqrtn;
	int	low_ap;
	int	high_ap;

	if (n <= 0)
		return (0);
	else if (n == 1)
		return (1);
	else
	{
		low_ap = 1;
		high_ap = n / 2;
		while (low_ap <= high_ap)
		{
			sqrtn = (low_ap + high_ap) / 2;
			if (sqrtn * sqrtn <= n && (sqrtn + 1) * (sqrtn + 1) > n)
				return (sqrtn);
			else if (sqrtn * sqrtn < n)
				low_ap = sqrtn + 1;
			else
				high_ap = sqrtn - 1;
		}
	}
	return (-1);
}

int	ft_is_prime(int n)
{
	unsigned int	i;
	unsigned int	sq_n;

	if (n <= 1)
		return (0);
	i = 1;
	sq_n = (unsigned int)ft_int_sqrt(n);
	while (++i <= sq_n)
	{
		if ((n % i) == 0)
			return (0);
	}
	return (1);
}
