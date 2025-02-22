/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissacurty <raissacurty@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:06:51 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/15 13:48:03 by raissacurty      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialize the game structure by setting all values to zero.
void	init_game(t_map *game)
{
	ft_memset(game, 0, sizeof(t_map));
	ft_memset(&game->player, 0, sizeof(t_point));
	ft_memset(&game->exit, 0, sizeof(t_point));
	ft_memset(&game->image, 0, sizeof(t_image));
}

// Allocate memory for the game structure, initialize its values (init_game),
// and start the MiniLibX library with mlx_init().
t_map	*init(void)
{
	t_map	*game;

	game = malloc(sizeof(t_map));
	if (!game)
		ft_kill(5, game);
	init_game(game);
	game->mlx_ptr = mlx_init();
	return (game);
}
