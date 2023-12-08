/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:24:22 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/07 20:57:51 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handler(int signum)
{
	static int i = 0;
	static char c = 0;

	if (signum == SIGUSR1) // 0
	{
		c = c | (1 << i);
		if (++i == 8)
		{
			ft_printf("%c", c);
			i = 0;
			c = 0;
		}
	}
	else if (signum == SIGUSR2) // 1
	{
		c = c | (0 << i);
		if (++i == 8)
		{
			ft_printf("%c", c);
			i = 0;
			c = 0;
		}
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	*sa;

	sa = malloc(sizeof(struct sigaction));
	sa->sa_handler = handler;
	pid = getpid();
	if (pid < 0)
	{
		ft_printf("ERRO: Não foi possível obter o PID\n");
		return (1);
	}
	ft_printf("%d\n", pid);
	while (1)
	{
		if (sigaction(SIGUSR1, sa, NULL) < 0)
			ft_printf("ERRO: Não foi possível obter o PID\n");
		else if (sigaction(SIGUSR2, sa, NULL) < 0)
			ft_printf("ERRO: Não foi possível obter o PID\n");
		pause();
	}
	return (0);
}
