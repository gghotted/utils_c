/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_subprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gypark <gypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:16:32 by gypark            #+#    #+#             */
/*   Updated: 2021/02/15 18:53:36 by gypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int		on_subprocess(void (*fnc)(), void *param)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		fnc(param);
		exit(0);
	}
	wait(&status);
	return (WEXITSTATUS(status));
}
