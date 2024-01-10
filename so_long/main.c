/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:21:33 by abolea            #+#    #+#             */
/*   Updated: 2024/01/10 16:25:44 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main()
{
	game val;
	int	i;
	
	i = 0;
	if (return_error("map.ber", &val) == 1)
	{
		while (i < val.height)
		{
			printf("%s", val.map[i]);
			i++;
		}
	}
	else
	{
		printf("erreur de map");
		return (0);
	}
	free_map(&val);
	return (0);
}
