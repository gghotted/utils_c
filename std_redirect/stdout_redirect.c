/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gypark <gypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:51:57 by gypark            #+#    #+#             */
/*   Updated: 2021/02/16 20:24:01 by gypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	*saved_stdout()
{
	static int	stdout;

	return (&stdout);
}

int		stdout_restore()
{
	int	ret;

	ret = dup2(*saved_stdout(), STDOUT_FILENO);
	close(*saved_stdout());
	return (ret);
}

int		stdout_redirect(int fd)
{
	int	saved_fd;
	int	newfd;

	saved_fd = dup(STDOUT_FILENO);
	if (saved_fd == -1)
		return (-1);
	newfd = dup2(fd, STDOUT_FILENO);
	if (newfd == -1)
	{
		close(saved_fd);
		return (-1);
	}
	close(fd);
	*saved_stdout() = saved_fd;
	return (1);
}
