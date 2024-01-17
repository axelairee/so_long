/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:21:33 by abolea            #+#    #+#             */
/*   Updated: 2024/01/17 10:48:46 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char	**argv)
{
	t_game val;
	int	i;
	
	if (argc > 2)
		return (0);
	i = 0;
	if (return_error(argv[1], &val) == 1)
		init_window(&val);
	else
	{
		printf("erreur de map");
		return (0);
	}
	free_map(&val);
	return (0);
}
