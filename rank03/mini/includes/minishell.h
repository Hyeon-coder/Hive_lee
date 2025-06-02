/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:18:18 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/01 23:51:58 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define INITIAL_CAP 16

/* 사용자 구현 부분 */
char	**tokenize(char *line);
void	execute(char *line, char ***env);
void	free_tokens(char **args);

void	setup_signals(void);

/* built-in command */
int		ft_cd(char **argv);
int		ft_echo(char **argv);
int		ft_env(char **argv, char ***env);
int		ft_export(char **argv, char ***env);
int		ft_pwd(char **argv);
int		ft_unset(char **argv, char ***env);

void	ft_free_2d_array(char **arr);

#endif
