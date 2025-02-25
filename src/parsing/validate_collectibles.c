/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_collectibles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:11:16 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/25 13:52:49 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Count the number of collectibles in the map.
// If there are no collectibles, terminate the game with an error.
void	validate_collectibles(t_map *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				game->collectibles++;
		}
	}
	if (game->collectibles < 1)
		ft_kill(7, game);
}

// Marks visited positions to ensure all collectibles and exit
// are reachable from the player's starting position.
void	ft_flood_fill(char **duplicate, t_map *game, size_t x, size_t y)
{
	if (x >= game->width || y >= game->height)
		return ;
	else if (duplicate[y][x] == 'C')
	{
		game->gathered++;
		duplicate[y][x] = 'F';
	}
	else if (duplicate[y][x] == '1' || duplicate[y][x] == 'F')
		return ;
	else if (duplicate[y][x] == 'E')
	{
		game->exit_check = 1;
		return ;
	}
	else
		duplicate[y][x] = 'F';
	ft_flood_fill(duplicate, game, x + 1, y);
	ft_flood_fill(duplicate, game, x, y + 1);
	ft_flood_fill(duplicate, game, x - 1, y);
	ft_flood_fill(duplicate, game, x, y - 1);
}

// Validate that all collectibles and exit are reachable from the player.
void	validate_path(t_map *game)
{
	char		**duplicate;
	size_t		i;

	duplicate = calloc(game->height + 1, sizeof(char *));
	if (!duplicate)
		ft_kill(5, game);
	i = -1;
	while (++i < game->height)
		duplicate[i] = ft_strdup(game->map[i]);
	ft_flood_fill(duplicate, game, game->player_pos.x, game->player_pos.y);
	if (game->collectibles != game->gathered || game->exit_check != 1)
	{
		ft_free_array(duplicate, game->height);
		ft_kill(8, game);
	}
	ft_free_array(duplicate, game->height);
}
