/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:06:28 by moduwole          #+#    #+#             */
/*   Updated: 2022/11/21 13:06:28 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_frame	*ppx;

	ppx = init_ppx(argc, argv);
	if (ppx == NULL)
		return (1);
	if (!get_args(ppx, argv, envp, 1))
		return (2);
	ppx->pid = fork();
	if (ppx->pid == -1)
		return (ft_printf("Error: could not make child process\n"), 3);
	process_1(ppx, envp);
	ft_clarr(ppx, 1);
	if (!get_args(ppx, argv, envp, 2))
		return (5);
	ppx->pid2 = fork();
	if (ppx->pid2 == -1)
		return (ft_printf("Error: could not make child process\n"), 6);
	process_2(ppx, envp);
	ft_clarr(ppx, 2);
	return (0);
}
