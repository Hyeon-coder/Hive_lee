/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JuHyeon <juhyeonl@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:59:43 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/04/30 20:54:05 by JuHyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	int		status1;
	int		status2;
}	t_pipex;

/* utils.c */
void	ft_free(char **str);
void	init_pipex(t_pipex *pipex);
void	clean_pipex(t_pipex *pipex);
void	error_exit(char *msg, int exit_code);
char	*find_path(char *cmd, char **envp);
void	execute(t_pipex *pipex, char **envp, int cmd_num);

/* pipex.c */
void	child_process1(t_pipex *pipex, char **av, char **envp);
void	child_process2(t_pipex *pipex, char **av, char **envp);

#endif
