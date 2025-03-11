/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:05:23 by JuHyeon           #+#    #+#             */
/*   Updated: 2025/03/11 15:29:03 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

/*
	Prints an error message. (에러 메시지 출력)
*/
void	ft_error(char *msg, char **tgt_arr)
{
	ft_free(tgt_arr);
	ft_putendl_fd(msg, 1);
	exit(0);
}
