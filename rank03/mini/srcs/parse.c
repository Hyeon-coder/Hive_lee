/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh3900 <ljh3900@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:14:33 by ljh3900           #+#    #+#             */
/*   Updated: 2025/05/29 10:13:11 by ljh3900          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    **tokenize(char *line)
{
    size_t  cap;
    size_t  cnt;
    char    **tokens;

    (void)cnt;
    cap = INITIAL_CAP;
    cnt = 0;
    if (!line || !*line || line[0] == '\0')
        return NULL;
    tokens = (char **)malloc(cap * sizeof(char *));
    if (!tokens)
        return NULL;
    while (line[0])
    {
        
    }
    return NULL;
}

