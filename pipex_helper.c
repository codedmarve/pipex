/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:40:11 by moduwole          #+#    #+#             */
/*   Updated: 2022/11/23 23:40:11 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_1(t_frame *ppx, char **envp)
{
	if (ppx->pid == 0)
	{
		close(ppx->fd[0]);
		dup2(ppx->infile, STDIN_FILENO);
		dup2(ppx->fd[1], STDOUT_FILENO);
		close(ppx->fd[1]);
		if (execve(ppx->cmd[0], ppx->cmd, envp) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
}

void	process_2(t_frame *ppx, char **envp)
{
	if (ppx->pid2 == 0)
	{
		dup2(ppx->fd[0], STDIN_FILENO);
		close(ppx->fd[1]);
		dup2(ppx->outfile, STDOUT_FILENO);
		close(ppx->fd[0]);
		if (execve(ppx->cmd[0], ppx->cmd, envp) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
}

void	add_path(t_frame *ppx)
{
	int		i;
	char	**dst;

	dst = ft_calloc(arrlen(ppx->cmd) + 2, sizeof(char *));
	dst[0] = ft_strdup(ppx->path);
	i = 1;
	while (ppx->cmd[i])
	{
		dst[i] = ft_strdup(ppx->cmd[i]);
		i++;
	}
	ft_clear(ppx->cmd);
	ppx->cmd = dst;
}

int	get_path(t_frame *ppx)
{
	ppx->env = ft_calloc(arrlen(ppx->prenv) + 1, sizeof(char *));
	ppx->i = 0;
	while (ppx->i < arrlen(ppx->prenv))
	{
		if (ppx->prenv[ppx->i][ft_strlen(ppx->prenv[ppx->i]) - 1] != '/')
		{
			ppx->env[ppx->i] = ft_strjoin(ppx->prenv[ppx->i],
					ppx->tmp = ft_strjoin("/", ppx->cmd[0]));
			free(ppx->tmp);
		}
		else
			ppx->env[ppx->i] = ft_strjoin(ppx->prenv[ppx->i], ppx->cmd[0]);
		if (access(ppx->env[ppx->i], X_OK) == 0)
		{
			ppx->path = ppx->env[ppx->i];
			break ;
		}
		ppx->i++;
	}
	if (ppx->path)
		return (add_path(ppx), 1);
	return (ft_printf("Error: %s command not found\n", ppx->cmd[0]),
		ft_clarr(ppx, 2), 0);
}

int	get_args(t_frame *ppx, char **argv, char **envp, int process)
{
	if (ppx->pid == 0)
		return (0);
	ppx->i = 0;
	if (process == 1)
	{
		ppx->cmd = ft_split(argv[2], ' ');
		if (access(ppx->cmd[0], X_OK) == 0)
			return (1);
	}
	else if (process == 2)
	{
		ppx->cmd = ft_split(argv[3], ' ');
		if (access(ppx->cmd[0], X_OK) == 0)
			return (1);
	}
	while (envp[ppx->i])
	{
		if (ft_strncmp(envp[ppx->i], "PATH=", 5) == 0)
		{
			ppx->prenv = ft_split(&envp[ppx->i][5], ':');
			break ;
		}
		ppx->i++;
	}
	return (get_path(ppx));
}
