/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:18:18 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/07 18:39:48 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
#include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define INITIAL_CAP 16
# define TRUE 1
# define FALSE 0


enum	Types
{
	WORD,
	CAT,
	PIPE,
	CD,
	EXPORT,
	ENV,
	ECHO,
	UNSET,
	EXIT,
    	N,
	PWD,
	EV,
	RD_O,
	RD_O_APPEND,
	RD_I,
	READ_I,
};

typedef struct	t_token 
{
	size_t	id;
	enum	Types type;
	char	*str;
	int	int_val;
}   t_token ;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

extern volatile sig_atomic_t g_signal;

// t_token    **tokenize(char *line);
void    free_tokens(t_token **args);

void    setup_signals(void);

void	execute(char *line, t_env *env_list);

/* built-in command */
int		ft_cd(char **argv, t_env *env_list);
int		ft_echo(char **argv);
int		ft_env(char **argv, t_env *env_list);
int		ft_export(char **argv, t_env *env_list);
int		ft_pwd(char **argv);
int		ft_unset(char **argv, t_env *env_list);
void	ft_exit(char **argv);
int		ft_str_isalpha(char *str);

/* utils */
void	ft_free_2d_array(char **arr);

/* env_utils */
void	env_clear(t_env **lst);
t_env	*env_init(char **envp);

#endif
