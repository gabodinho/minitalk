/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:36:19 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/08/28 22:11:24 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"

static int	g_signo;

static void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		g_signo = 1;
	else if (signo == SIGUSR2)
		g_signo = 0;
}

int	main(void)
{
	int					i;
	int					res;
//	struct sigaction	new_handler;

	ft_printf("%d\n", getpid());
	struct sigaction new_handler = {.sa_handler = signal_handler,};
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	while (1)
	{
		i = 0;
		res = 0;
		while (i < 8)
		{
			pause();
			res |= (g_signo << i);
			i++;
		}
		write(1, &res, 1);
	}
	return (0);
}
