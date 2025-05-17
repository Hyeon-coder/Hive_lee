/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_quoted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/18 12:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

size_t ft_count_words_quoted(const char *s)
{
    size_t count = 0;
    int    in_w  = 0;
    char   q;

    while (*s)
    {
        if (!ft_isspace((unsigned char)*s) && !in_w)
        {
            in_w = 1;
            count++;
        }
        if (in_w)
        {
            if (*s == '\\' && s[1])
                s += 2;
            else if (*s == '"' || *s == '\'')
            {
                q = *s++;
                while (*s && *s != q)
                    s++;
            }
            else if (ft_isspace((unsigned char)*s))
                in_w = 0;
            if (*s)
                s++;
        }
        else
            s++;
    }
    return (count);
}
