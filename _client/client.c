/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:28:14 by fnascime          #+#    #+#             */
/*   Updated: 2023/12/07 20:46:30 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*get_current_bits(char c)
{
	int		i;
	char	*bin;

	i = 0;
	bin = malloc(sizeof(char) * 8);
	while (i < 8)
	{
		if (c & (1 << i))
			bin[i] = '1';
		else
			bin[i] = '0';
		i++;
	}
	return (bin);
}

void	send_message(int pid, char *str)
{
	int		i;
	int		j;
	char	*bin;

	i = 0;
	while (str[i])
	{
		j = 7;
		bin = get_current_bits(str[i]);
		while (j >= 0)
		{
			if (bin[j] == '0')
				kill(pid, SIGUSR1);
			else if (bin[j] == '1')
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("ERRO: Número de argumentos inválido\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid < 0 || !str)
	{
		ft_printf("ERRO: argumentos inválidos\n");
		return (1);
	}
	send_message(pid, str);
	return (0);
}
