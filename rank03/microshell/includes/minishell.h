/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:18:18 by ljh3900           #+#    #+#             */
/*   Updated: 2025/06/06 14:07:56 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
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

typedef struct	t_env
{
	char	*name;
	char	*value;
}	t_env;

extern volatile sig_atomic_t g_signal;

// t_token    **tokenize(char *line);
void    free_tokens(t_token **args);

void    setup_signals(void);

void	execute(char *line, char ***env);

/* built-in command */
int		ft_cd(char **argv, char ***env);
int		ft_echo(char **argv);
int		ft_env(char **argv, char ***env);
int		ft_export(char **argv, char ***env);
int		ft_pwd(char **argv);
int		ft_unset(char **argv, char ***env);
int     ft_exit(char **argv);
int		ft_str_isalpha(char *str);

/* utils */
void	ft_free_2d_array(char **arr);

#endif
