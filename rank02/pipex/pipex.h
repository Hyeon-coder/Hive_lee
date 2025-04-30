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

# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

void	perror_exit(char *opt, int exit_code, int *fd);
void	execute(char *cmd, char **envp, int *fd);
void	close_fds(int *fd, int infile, int outfile);
void	dup_child_1(char **av, int *fd);
void	dup_child_2(char **av, int *fd);
pid_t	child_process_1(char **av, char **envp, int *fd);
pid_t	child_process_2(char **av, char **envp, int *fd);
void	ft_free(char **str);
char	**get_env_path(char **envp);
char	*get_cmd(char **path, char *cmd);

#endif
