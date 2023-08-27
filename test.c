/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:36:19 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/08/27 21:56:22 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void my_handler(int signum)
{
    if (signum == SIGUSR1)
    {
		write(1, "Received SIGUSR1!\n", 18);
	}
}

int main(void)
{	
	pid_t pid = getpid();
	printf("%d", pid);
	fflush(stdout);
	while (1);
		signal(SIGUSR1, my_handler);
	return (0);
}
*/
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int	glsigno;

static void signal_handler(int signo)
{
	if (signo == SIGUSR1)
		glsigno = 1;
	else if (signo == SIGUSR2)
		glsigno = 0;
}

int main(void)
{
		pid_t pid = getpid();
		printf("%d\n", pid);
		fflush(stdout);
	int	signo;
	int	i;
	int res;

//	signal(SIGUSR1, signal_handler);
//	signal(SIGUSR2, signal_handler);
	struct sigaction new_handler = {.sa_handler = signal_handler,};
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
 	while(1)
	{
		i = 0;
		res = 0;
		while (i < 8)
		{	
//			printf("yep\n");
			pause();
//			printf("still yep\n");
			res |= (glsigno << i);
			i++;
		}
		write(1, &res, 1);
//		printf("res%c", res);
	}


/*
		struct sigaction new_handler = {.sa_handler = signal_handler,};

        if (sigaction(SIGUSR1, &new_handler, NULL) < 0) {
                perror("sigaction");
        }

        pause();
*/
        return 0;
}

