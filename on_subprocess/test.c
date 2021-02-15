/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gypark <gypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:43:09 by gypark            #+#    #+#             */
/*   Updated: 2021/02/15 19:01:04 by gypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		on_subprocess(void (*fnc)(), void *param);

int		x = 42;

void	inner_fnc(void *param)
{
	x += 30;
	*(int*)param *= 5;
	printf("inner_fnc on_subprocess x = %d, param = %d\n", x, *(int*)param);
	exit(0);
}

void	inner_fnc2(void *param)
{
	x += 30;
	*(int*)param *= 5;
	printf("inner_fnc2 on_subprocess x = %d, param = %d\n", x, *(int*)param);
	exit(42);
}

void	inner_fnc3(void *param)
{
	x += 30;
	*(int*)param *= 5;
}

int		main(void)
{
	int	param = -1;
	int	status;

	status = on_subprocess(inner_fnc, &param);
	printf("origin process : x = %d, param = %d, status = %d\n", x, param, status);

	status = on_subprocess(inner_fnc2, &param);
	printf("origin process : x = %d, param = %d, status = %d\n", x, param, status);

	inner_fnc3(&param);
	printf("origin process : x = %d, param = %d, status = %d\n", x, param, status);
	return (0);
}

/*
inner_fnc on_subprocess x = 72, param = -5
origin process : x = 42, param = -1, status = 0
inner_fnc2 on_subprocess x = 72, param = -5
origin process : x = 42, param = -1, status = 42
origin process : x = 72, param = -5, status = 42
*/
