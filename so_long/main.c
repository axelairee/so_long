/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:21:33 by abolea            #+#    #+#             */
/*   Updated: 2024/01/19 17:00:44 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_game	val;

	if (argc != 2)
		return (0);
	if (return_error(argv[1], &val) == 1)
		init_window(&val);
	else
	{
		ft_printf("Error\nErreur de map");
		return (0);
	}
	free_map(&val);
	return (0);
}
