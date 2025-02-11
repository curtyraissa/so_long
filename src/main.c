/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:07:09 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/11 16:30:32 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*game;

	if (argc == 2)
	{
		check_extension(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			ft_kill(2, NULL);
		game = init();
		read_map(argv[1], game);
		validate_map(game);
		render(game);
	}
	return (0);
}
