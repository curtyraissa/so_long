/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raissacurty <raissacurty@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:08:01 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/19 11:35:03 by raissacurty      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Free a 2D array of strings.
void	ft_free_array(char **duplicate, size_t height)
{
	size_t	y;

	y = 0;
	if (!duplicate[0])
	{
		free(duplicate);
		return ;
	}
	while (y < height)
	{
		free(duplicate[y]);
		y++;
	}
	free(duplicate);
}

// Free the game map from memory.
void	ft_free_map(t_map *game)
{
	size_t	y;

	y = 0;
	if (!game->map[0])
	{
		free(game->map);
		return ;
	}
	while (y < game->height)
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
}

// Destroy loaded images to free memory.
// mlx_destroy_image(): Releases memory used by an image to prevent leaks.
void	destroy_images(t_map *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->coffee)
		mlx_destroy_image(game->mlx_ptr, game->coffee);
}

// Free all allocated memory in the game structure.
void	ft_free_all(t_map *game)
{
	if (!game)
		return ;
	if (game->map)
		ft_free_map(game);
	destroy_images(game);
	if (game->image.img)
		mlx_destroy_image(game->mlx_ptr, game->image.img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
	return ;
}

// Free all resources and exit the game.
int	ft_exit_game(t_map *game)
{
	ft_free_all(game);
	exit(0);
}

