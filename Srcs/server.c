/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:29:44 by mmarie            #+#    #+#             */
/*   Updated: 2023/05/17 00:22:38 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Minitalk.h"

void	bit_handler(int signal, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static unsigned char	c = 0;
	static char		*line = NULL;

	(void)context;
	if (signal == SIGUSR2)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		line = ft_strjoin_char(line, c);
		if (c == 0 && line)
		{
			ft_printf("%s\n", line);
			free(line);
			line = NULL;
		}
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main()
{
	int	pid;
	struct sigaction	sa;


	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sa.sa_sigaction = (void *) bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		//signal(SIGUSR1, bit_handler);
		//signal(SIGUSR2, bit_handler);
	}
	return(0);
}
