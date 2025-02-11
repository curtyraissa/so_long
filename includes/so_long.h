/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:05:58 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/11 15:59:06 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

/*=============================================================================#
#                               DEFINES                                        #
#=============================================================================*/

# define EXTENSION_ERROR "map extension is wrong. correct map extension is .ber"
# define MAP_ERROR "couldn't open map"
# define SIZE_ERROR "size of the map is wrong"
# define BOARDER_ERROR "map is not surrounded by walls"
# define MALLOC_ERROR "memory allocation failed"
# define PLAYER_ERROR "Map has to be one player and one exit only"
# define ASSETS_ERROR "The assets in the map are wrong"
# define COLLECTIBLES_ERROR "map has no collectibles"
# define PATH_ERROR "map has no valid path"
# define MLX_ERROR "Error on the MLX"

# define SIZE 85

/*=============================================================================#
#                               STRUCTS                                        #
#=============================================================================*/

typedef struct s_point
{
	int	x; // width
	int	y; // height
}	t_point;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_image;

typedef struct s_map
{
	size_t		width;
	size_t		height;
	size_t		collectibles;
	size_t		gathered;
	char		**map;
	int			exit_check;
	int			movement;
	void		*player;
	t_point		player_pos;
	void		*exit;
	t_point		exit_pos;
	void		*floor;
	void		*coffee;
	void		*wall;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
}				t_map;

/*=============================================================================#
#                               GENERAL                                        #
#=============================================================================*/

t_map	*init(void);
void	init_game(t_map *game);
void	init_image(t_map *game);
void	read_map(char *argv, t_map *game);
size_t	count_width(const char *str);
size_t	count_lines(char *file);
void	copy_map(int fd, t_map *game);
void	ft_free_array(char **duplicate, size_t height);
void	ft_kill(int number, t_map *game);
void	ft_free_all(t_map *game);
void	ft_free_map(t_map *game);
int		ft_exit_game(t_map *game);

/*=============================================================================#
#                               CHECKERS                                       #
#=============================================================================*/

void	check_extension(char *file);
void	validate_map(t_map *game);
void	validate_boarders(t_map *game);
void	validate_size(t_map *game);
void	validate_assets(t_map *game);
void	validate_elements(t_map *game);
void	validate_collectibles(t_map *game);
void	validate_path(t_map *game);
void	ft_flood_fill(char **duplicate, t_map *game, size_t x, size_t y);

/*=============================================================================#
#                               RENDER                                         #
#=============================================================================*/

void	render(t_map *game);
void	open_window(t_map *game);
void	create_sprites(t_map *game);
void	render_map(t_map *game);
void	render_image(t_map *game, char c, size_t x, size_t y);

/*=============================================================================#
#                               MOVEMENTS                                      #
#=============================================================================*/

int		key_press(int key, t_map *game);
void	validate_move_up_down(int key, t_map *game);
void	validate_move_left_right(int key, t_map *game);
void	move_up(t_map *game);
void	move_down(t_map *game);
void	move_left(t_map *game);
void	move_right(t_map *game);
void	check_win(t_map *game);

#endif