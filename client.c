/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:52:16 by samartin          #+#    #+#             */
/*   Updated: 2022/12/16 15:45:49 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

static void	send_binary(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i++))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(120);
	}
}

int	main(int argc, char **argv)
{
	pid_t	serv_pid;
	char	*str;

	if (argc < 3)
	{
		write (1, "PID and message arguments needed\n", 33);
		return (-1);
	}
	serv_pid = ft_atoi(argv[1]);
	if (serv_pid < 100 || serv_pid > 99998)
	{
		write (1, "PID out of valid range\n", 23);
		return (-1);
	}
	str = argv[2];
	while (*str)
		send_binary(*str++, serv_pid);
	return (0);
}
