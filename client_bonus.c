/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:14 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/09 12:50:05 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(int pid, char c)
{
	int		i;
	int		bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(600);
		i++;
	}
}

void	mhandler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Mensagem recebida com sucesso!\n");
}

void	send_message(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Uso: ./client [PID] [mensagem]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid < 0 || !str)
	{
		ft_printf("ERRO: argumentos inválidos\n");
		return (1);
	}
	signal(SIGUSR1, &mhandler);
	send_message(pid, str);
	return (0);
}
