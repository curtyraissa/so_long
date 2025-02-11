/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:07:01 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/11 16:30:29 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_kill(int number, t_map *game)
{
	ft_printf("Error\n");
	if (number == 1)
		ft_printf("%s\n", EXTENSION_ERROR);
	if (number == 2)
		ft_printf("%s\n", MAP_ERROR);
	if (number == 3)
		ft_printf("%s\n", SIZE_ERROR);
	if (number == 4)
		ft_printf("%s\n", BOARDER_ERROR);
	if (number == 5)
		ft_printf("%s\n", MALLOC_ERROR);
	if (number == 6)
		ft_printf("%s\n", PLAYER_ERROR);
	if (number == 7)
		ft_printf("%s\n", COLLECTIBLES_ERROR);
	if (number == 8)
		ft_printf("%s\n", PATH_ERROR);
	if (number == 9)
		ft_printf("%s\n", ASSETS_ERROR);
	if (number == 10)
		ft_printf("%s\n", MLX_ERROR);
	if (number > 2)
		ft_free_all(game);
	exit(1);
}
