/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:41 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/13 11:28:17 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_boarders(t_map *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (i == 0 || i == game->height - 1)
				if (game->map[i][j] != '1')
					ft_kill(4, game);
			if (j == 0 || j == game->width -1)
				if (game->map[i][j] != '1')
					ft_kill(4, game);
			j++;
		}
		i++;
	}
}

void	validate_size(t_map *game)
{
	size_t	i;

	i = -1;
	while (++i < game->height)
	{
		if (count_width(game->map[i]) != game->width)
			ft_kill(3, game);
		if (game->width + game->height < 8
			|| game->width < 5 || game->height < 3)
			ft_kill(3, game);
	}
}

void	validate_assets(t_map *game)
{
	size_t	i;
	size_t	j;
	int		player;
	int		exit;

	player = 0;
	exit = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			player += (game->map[i][j] == 'P');
			if (game->map[i][j] == 'P')
			{
				game->player_pos.x = j;
				game->player_pos.y = i;
			}
			exit += (game->map[i][j] == 'E');
		}
	}
	if (player != 1 || exit != 1)
		ft_kill(6, game);
}

void	validate_elements(t_map *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] != '1'
				&& game->map[i][j] != '0'
				&& game->map[i][j] != 'P'
				&& game->map[i][j] != 'E'
				&& game->map[i][j] != 'C')
				ft_kill(9, game);
		}
	}
}

void	validate_map(t_map *game)
{
	validate_boarders(game);
	validate_size(game);
	validate_assets(game);
	validate_elements(game);
	validate_collectibles(game);
	validate_path(game);
}
