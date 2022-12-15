#include <signal.h>
#include "libft/libft.h"

static void	compose_char(int sig)
{
	static int	bytelen = 0;
	static int	char2print = 0;

	if (sig == SIGUSR1)
		char2print |= (1 << bytelen);
	bytelen++;
	if (bytelen >= 8)
	{
		write(1, &char2print, 1);
		char2print = 0;
		bytelen = 0;
	}
}

int main (void)
{
	pid_t	selfid;

	selfid = getpid();
	ft_printf("PID: %i\n", selfid);
	signal(SIGUSR1, compose_char);
	signal(SIGUSR2, compose_char);
	while (1)
		pause();
	return (0);
}