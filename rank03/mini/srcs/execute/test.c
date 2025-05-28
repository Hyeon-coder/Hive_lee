/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyeonl <juhyeonl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:43:06 by juhyeonl          #+#    #+#             */
/*   Updated: 2025/05/28 16:47:40 by juhyeonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int main(void)
{
	char *s1 = "echo Hello";
	int i = 0;

	while (s1[i] != ' ')
		i++;
	printf("i >>> %d\n", i);
	if (ft_strncmp(s1, "echo", i + 1))
		printf("in\n");
	return (0);
}
