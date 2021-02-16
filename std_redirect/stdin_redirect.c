/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gypark <gypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:51:57 by gypark            #+#    #+#             */
/*   Updated: 2021/02/16 20:20:51 by gypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	*saved_stdin()
{
	static int	stdin;

	return (&stdin);
}

int		stdin_restore()
{
	int	ret;

	ret = dup2(*saved_stdin(), STDIN_FILENO);
	close(*saved_stdin());
	return (ret);
}

int		stdin_redirect(int fd)
{
	int	saved_fd;
	int	newfd;

	saved_fd = dup(STDIN_FILENO);
	if (saved_fd == -1)
		return (-1);
	newfd = dup2(fd, STDIN_FILENO);
	if (newfd == -1)
	{
		close(saved_fd);
		return (-1);
	}
	close(fd);
	*saved_stdin() = saved_fd;
	return (1);
}
