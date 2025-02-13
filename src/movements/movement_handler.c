/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:05 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/13 11:24:22 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *game)
{
	if (game->map[game->player_pos.y - 1][game->player_pos.x] == 'C')
	{
		game->map[game->player_pos.y - 1][game->player_pos.x] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.y--;
		game->collectibles--;
	}
	else if (game->map[game->player_pos.y - 1][game->player_pos.x] == 'E')
		check_win(game);
	else
	{
		game->map[game->player_pos.y - 1][game->player_pos.x] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.y--;
	}
	render_map(game);
}

void	move_down(t_map *game)
{
	if (game->map[game->player_pos.y + 1][game->player_pos.x] == 'C')
	{
		game->map[game->player_pos.y + 1][game->player_pos.x] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.y++;
		game->collectibles--;
	}
	else if (game->map[game->player_pos.y + 1][game->player_pos.x] == 'E')
		check_win(game);
	else
	{
		game->map[game->player_pos.y + 1][game->player_pos.x] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.y++;
	}
	render_map(game);
}

void	move_left(t_map *game)
{
	if (game->map[game->player_pos.y][game->player_pos.x - 1] == 'C')
	{
		game->map[game->player_pos.y][game->player_pos.x - 1] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.x--;
		game->collectibles--;
	}
	else if (game->map[game->player_pos.y][game->player_pos.x - 1] == 'E')
		check_win(game);
	else
	{
		game->map[game->player_pos.y][game->player_pos.x - 1] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.x--;
	}
	render_map(game);
}

void	move_right(t_map *game)
{
	if (game->map[game->player_pos.y][game->player_pos.x + 1] == 'C')
	{
		game->map[game->player_pos.y][game->player_pos.x + 1] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.x++;
		game->collectibles--;
	}
	else if (game->map[game->player_pos.y][game->player_pos.x + 1] == 'E')
		check_win(game);
	else
	{
		game->map[game->player_pos.y][game->player_pos.x + 1] = 'P';
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		game->player_pos.x++;
	}
	render_map(game);
}
