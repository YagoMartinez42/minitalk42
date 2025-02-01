/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:44:25 by samartin          #+#    #+#             */
/*   Updated: 2023/01/14 18:11:05 by samartin         ###   ########.fr       */
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
		usleep(500);
	}
}

static void	message_done(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Full message sent and recived\n");
		exit(0);
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
	if (serv_pid < 100 || serv_pid > 99999998)
	{
		write (1, "PID out of valid range\n", 23);
		return (-1);
	}
	str = argv[2];
	signal(SIGUSR1, message_done);
	signal(SIGUSR2, message_done);
	while (*str)
		send_binary(*str++, serv_pid);
	send_binary('\0', serv_pid);
	return (0);
}
