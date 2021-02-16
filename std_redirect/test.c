/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gypark <gypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:03:16 by gypark            #+#    #+#             */
/*   Updated: 2021/02/16 20:25:58 by gypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		stdin_redirect(int fd);
int		stdin_restore();
int		stdout_redirect(int fd);
int		stdout_restore();

void	test_inout()
{
	char	buf[1024];
	int		readed;

	readed = read(STDIN_FILENO, buf, 1023);
	buf[readed] = '\0';
	write(STDOUT_FILENO, buf, readed);
}

int		main(void)
{
	int	fd_in, fd_out;

	fd_in = open("input.txt", O_RDONLY);
	fd_out = open("output.txt", O_WRONLY | O_CREAT, 0644);

	stdin_redirect(fd_in);
	stdout_redirect(fd_out);
	test_inout();
	stdout_restore();
	stdin_restore();

	test_inout();

	return (0);
}
