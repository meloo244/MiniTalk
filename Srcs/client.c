/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:29:42 by mmarie            #+#    #+#             */
/*   Updated: 2023/05/17 10:32:34 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Minitalk.h"

int g_pause = 1;

void count_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while(bit < 8)
	{
		g_pause = 1;
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		while(g_pause)
			usleep(10);
	}
}

void	handler(int	signal)
{
	g_pause = 0;
	(void)signal;
}

int main(int argc, char **argv)
{
	int	pid;
	int	i;
	char *mess;

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	(void) argc;
	pid = ft_atoi(argv[1]);
	mess = argv[2];
	i = 0;
	while(mess[i])
	{
		count_bit(pid, mess[i]);
		i++;
	}
	ft_printf("Message received!");
	count_bit(pid, 0);
	return(0);
}

int check_error(int argc, char **argv)
	{
		int	i;

		(void) argc;
		if (argv[1][0] < '1' || argv[1][0] > '9')
		{
			ft_printf("Erreur : Le PID doit être un nombre entre 1 et 9.\n");
			return(0);
		}

		if (argv[2] = 0)
		{
			printf("rentre un message ");
			return(0);
		}

		if (argv[3])
		{
			printf("Erreur : N'oublie les guillemets.\n"); // ex : ./test 1823 emzqm eqmzm
			return(0);
		}
	}
