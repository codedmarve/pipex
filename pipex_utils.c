/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:24:21 by moduwole          #+#    #+#             */
/*   Updated: 2022/11/21 14:24:21 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_frame	*init_ppx(int argc, char **argv)
{
	t_frame	*ppx;

	if (argc != 5)
		return (ft_printf("Error: arguments must be 5\n"), NULL);
	ppx = (t_frame *)malloc(1 * sizeof(t_frame));
	if (ppx == NULL)
		return (ft_printf("Error: failed to init"), NULL);
	ppx->infile = open(argv[1], O_RDONLY);
	ppx->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ppx->infile == -1 || ppx->outfile == -1)
	{
		free(ppx);
		return (perror("Error"), NULL);
	}
	if (pipe(ppx->fd) == -1)
	{
		free(ppx);
		return (ft_printf("Error: pipe failed"), NULL);
	}
	init_null(ppx);
	return (ppx);
}

void	init_null(t_frame *ppx)
{
	ppx->path = NULL;
	ppx->cmd = NULL;
	ppx->env = NULL;
	ppx->prenv = NULL;
	ppx->pid = -5;
	ppx->pid2 = -5;
}

void	ft_clear(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	arrlen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_clarr(t_frame *ppx, int f)
{
	if (ppx->pid == 0 || ppx->pid2 == 0)
		return ;
	if (f == 1)
	{
		wait(NULL);
		ft_clear(ppx->cmd);
		ft_clear(ppx->prenv);
		ft_clear(ppx->env);
		ppx->path = NULL;
	}
	else
	{
		close(ppx->fd[0]);
		close(ppx->fd[1]);
		wait(NULL);
		close(ppx->infile);
		close(ppx->outfile);
		ft_clear(ppx->cmd);
		ft_clear(ppx->prenv);
		ft_clear(ppx->env);
		free(ppx);
	}
}
