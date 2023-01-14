/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:46:24 by samartin          #+#    #+#             */
/*   Updated: 2023/01/14 18:09:13 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	compose_char(int sig, siginfo_t *info, void *context)
{
	static int	bytelen = 0;
	static int	char2print = 0;

	context = NULL;
	if (sig == SIGUSR1)
		char2print |= (1 << bytelen);
	bytelen++;
	if (bytelen >= 8)
	{
		if (char2print == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		else
			write(1, &char2print, 1);
		char2print = 0;
		bytelen = 0;
	}
}

int	main(void)
{
	pid_t				selfid;
	struct sigaction	act1;
	struct sigaction	act2;

	selfid = getpid();
	ft_printf("PID: %i\n", selfid);
	act1.sa_flags = SA_SIGINFO;
	act1.sa_sigaction = compose_char;
	sigaction(SIGUSR1, &act1, NULL);
	act2.sa_flags = SA_SIGINFO;
	act2.sa_sigaction = compose_char;
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		pause();
	return (0);
}
