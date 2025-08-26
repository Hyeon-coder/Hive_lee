/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:18:10 by trietpham         #+#    #+#             */
/*   Updated: 2025/05/09 17:19:50 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if ((ac != 5 && ac !=6) || !arg_check(ac, av))
	{
		printf("Invalid Arguments\n");
		exit (1);
	}
	if (ft_init(ac, av, &data) == 0)
	{
		destroy(&data);
		exit (1);
	}
	if (ft_simu(&data) == 0)
	{
		destroy(&data);
		exit (1);
	}
	destroy(&data);
	return (0);
}