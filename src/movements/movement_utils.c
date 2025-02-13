/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:09:16 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/13 11:24:28 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_map *game)
{
	if (game->collectibles == 0)
	{
		game->movement++;
		ft_printf("Number of movements: %d\n", game->movement);
		ft_printf("Now you are ready to code!\n");
		ft_free_all(game);
		exit(1);
	}
}

void	validate_move_up_down(int key, t_map *game)
{
	if (key == XK_w || key == XK_Up)
	{
		if (game->map[game->player_pos.y - 1][game->player_pos.x] == '1')
			return ;
		else if (game->map[game->player_pos.y - 1][game->player_pos.x] == 'E'
				&& game->collectibles != 0)
			return ;
		else
			move_up(game);
		game->movement++;
		ft_printf("Number of movements: %d\n", game->movement);
	}
	else if (key == XK_s || key == XK_Down)
	{
		if (game->map[game->player_pos.y + 1][game->player_pos.x] == '1')
			return ;
		else if (game->map[game->player_pos.y + 1][game->player_pos.x] == 'E'
				&& game->collectibles != 0)
			return ;
		else
			move_down(game);
		game->movement++;
		ft_printf("Number of movements: %d\n", game->movement);
	}
}

void	validate_move_left_right(int key, t_map *game)
{
	if (key == XK_a || key == XK_Left)
	{
		if (game->map[game->player_pos.y][game->player_pos.x - 1] == '1')
			return ;
		else if (game->map[game->player_pos.y][game->player_pos.x - 1] == 'E'
				&& game->collectibles != 0)
			return ;
		else
			move_left(game);
		game->movement++;
		ft_printf("Number of movements: %d\n", game->movement);
	}
	if (key == XK_d || key == XK_Right)
	{
		if (game->map[game->player_pos.y][game->player_pos.x + 1] == '1')
			return ;
		else if (game->map[game->player_pos.y][game->player_pos.x + 1] == 'E'
				&& game->collectibles != 0)
			return ;
		else
			move_right(game);
		game->movement++;
		ft_printf("Number of movements: %d\n", game->movement);
	}
}

int	key_press(int key, t_map *game)
{
	if (key == XK_Escape)
	{
		ft_free_all(game);
		exit(1);
	}
	if ((key == XK_w || key == XK_Up) || (key == XK_s || key == XK_Down))
		validate_move_up_down(key, game);
	if ((key == XK_a || key == XK_Left) || (key == XK_d || key == XK_Right))
		validate_move_left_right(key, game);
	return (0);
}
