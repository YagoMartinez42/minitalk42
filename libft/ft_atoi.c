/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:17:16 by samartin          #+#    #+#             */
/*   Updated: 2022/10/01 13:01:12 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	get_mltp(const char *str)
{
	int		i;
	long	mltp;

	i = 0;
	mltp = -1;
	while (str[i] == '0')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (mltp > __INT_MAX__)
			return (-1);
		if (mltp == -1)
			mltp = 1;
		else
			mltp = mltp * 10;
		i++;
	}
	if (i == 0)
		return (i);
	else
		return (mltp);
}

static int	get_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] != '-' && str[i] != '+')
	{
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		else if (!(str[i] >= '\t' && str[i] <= '\r') && str[i] != ' ')
			return (-1);
		i++;
	}
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		*sign = 1;
		i++;
	}
	else
		*sign = 1;
	return (i);
}

static long	parse_nb(const char *str, long long mltp, int i)
{
	long	nb;

	nb = 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb += (str[i] - 48) * mltp;
		mltp = mltp / 10;
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nb;
	long	mltp;

	sign = 0;
	i = get_sign(str, &sign);
	if (i == -1)
		return (0);
	mltp = get_mltp(&str[i]);
	if (mltp == 0 || (mltp == -1 && sign == -1))
		return (0);
	else if (mltp == -1 && sign == 1)
		return (-1);
	nb = parse_nb(str, mltp, i) * sign;
	if (nb > __INT_MAX__)
		return (-1);
	else if (nb < (-(__INT_MAX__) - 1))
		return (0);
	else
		return ((int)nb);
}
