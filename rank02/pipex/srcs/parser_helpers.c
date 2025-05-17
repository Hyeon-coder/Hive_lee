/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:00:00 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/18 10:00:00 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	to_copy;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		if (old_size < new_size)
			to_copy = old_size;
		else
			to_copy = new_size;
		memcpy(new_ptr, ptr, to_copy);
		free(ptr);
	}
	return (new_ptr);
}

// int	buf_add(char **buf, size_t *cap, size_t *len, char c)
// {
// 	size_t	nc;
// 	char	*nb;

// 	if (*len + 1 >= *cap)
// 	{
// 		nc = *cap * 2;
// 		nb = ft_realloc(*buf, *cap, nc);
// 		if (!nb)
// 			return (0);
// 		*buf = nb;
// 		*cap = nc;
// 	}
// 	(*buf)[(*len)++] = c;
// 	return (1);
// }

// int	parse_escape(const char **p, char **buf, size_t *cap, size_t *len)
// {
// 	(*p)++;
// 	if (!buf_add(buf, cap, len, *(*p)++))
// 		return (0);
// 	return (1);
// }

// int	parse_quoted(const char **p, char **buf, size_t *cap, size_t *len)
// {
// 	char	quote;

// 	quote = *(*p)++;
// 	while (**p && **p != quote)
// 	{
// 		if (!buf_add(buf, cap, len, *(*p)++))
// 			return (0);
// 	}
// 	if (**p == quote)
// 		(*p)++;
// 	return (1);
// }
