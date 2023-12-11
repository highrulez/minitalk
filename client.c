/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aawgku-o <aawgku-o@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:27:12 by aawgku-o          #+#    #+#             */
/*   Updated: 2023/12/11 15:48:07 by aawgku-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(88);
			i--;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		printf("\n");
		printf("\033[31m███████╗██████╗ ██████╗  ██████╗ ██████╗ ██╗\n");
		printf("██╔════╝██╔══██╗██╔══██╗██╔═══██╗██╔══██╗██║\n");
		printf("█████╗  ██████╔╝██████╔╝██║   ██║██████╔╝██║\n");
		printf("██╔══╝  ██╔══██╗██╔══██╗██║   ██║██╔══██╗╚═╝\n");
		printf("███████╗██║  ██║██║  ██║╚██████╔╝██║  ██║██╗\n");
		printf("╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝\n");
		printf("\033[31mIf you did'nt know what you doing, ASK!\n\n");
		printf("\033[34mTry: ./client [PID] [MESSAGE]\n\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_signal(pid, argv[2]);
	ft_signal(pid, "\n\n");
}
