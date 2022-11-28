/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:17:09 by moduwole          #+#    #+#             */
/*   Updated: 2022/11/21 13:17:09 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_frame
{
	int		i;
	int		infile;
	int		outfile;
	int		pid;
	int		pid2;
	int		fd[2];
	char	**cmd;
	char	**prenv;
	char	**env;
	char	*path;
	char	*tmp;
}	t_frame;

int		arrlen(char **arr);
void	ft_clear(char **str);
void	add_path(t_frame *ppx);
int		get_path(t_frame *ppx);
void	init_null(t_frame *ppx);
void	process_1(t_frame *ppx, char **envp);
void	process_2(t_frame *ppx, char **envp);
void	ft_clarr(t_frame *ppx, int f);
t_frame	*init_ppx(int argc, char **argv);
char	**ft_stradd(char **src, char *str);
int		get_args(t_frame *ppx, char **argv, char **envp, int process);

#endif