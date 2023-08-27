/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:36:57 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/08/27 22:04:26 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

static void	send_char(pid_t pid, int arg)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((arg >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	char	*str;

	if (argc < 3)
		return (0);
	str = argv[2];
	while (*str)
	{
		send_char(atoi(argv[1]), *str);
		str++;
	}
	return (0);
}

