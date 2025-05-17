/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quoted_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/18 10:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char *read_word(const char **p)
{
    size_t buf_cap = 64, len = 0;
    char   *buf = malloc(buf_cap);
    char    quote;

    if (!buf)
        return (NULL);
    while (**p && !ft_isspace((unsigned char)**p))
    {
        if (**p == '\\' && *(*p + 1))
        {
            (*p)++;
            if (len + 1 >= buf_cap)
            {
                buf_cap *= 2;
                buf = realloc(buf, buf_cap);
                if (!buf)
                    return (NULL);
            }
            buf[len++] = *(*p)++;
            continue;
        }
        if (**p == '"' || **p == '\'')
        {
            quote = *(*p)++;
            while (**p && **p != quote)
            {
                if (len + 1 >= buf_cap)
                {
                    buf_cap *= 2;
                    buf = realloc(buf, buf_cap);
                    if (!buf)
                        return (NULL);
                }
                buf[len++] = *(*p)++;
            }
            if (**p == quote)
                (*p)++;
        }
        else
        {
            if (len + 1 >= buf_cap)
            {
                buf_cap *= 2;
                buf = realloc(buf, buf_cap);
                if (!buf)
                    return (NULL);
            }
            buf[len++] = *(*p)++;
        }
    }
    buf[len] = '\0';
    return (buf);
}

char **ft_split_quoted(const char *s)
{
    char      **result;
    size_t      wcount;
    size_t      i = 0;
    const char *p = s;

    wcount = ft_count_words_quoted(s);
    result = malloc((wcount + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    while (i < wcount)
    {
        while (*p && ft_isspace((unsigned char)*p))
            p++;
        result[i++] = read_word(&p);
        while (*p && ft_isspace((unsigned char)*p))
            p++;
    }
    result[i] = NULL;
    return (result);
}
