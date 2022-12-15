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

int main (int argc, char **argv)
{
	pid_t	serv_pid;
	char	*str;

	if (argc < 3)
		return (-1);
	serv_pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
		send_binary(*str++, serv_pid);
	
	return (0);
}