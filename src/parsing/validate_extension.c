/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:10:26 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/02/25 13:45:44 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Verify if the file has the correct ".ber" extension.
void	check_extension(char *file)
{
	if (ft_strcmp((file + (ft_strlen(file) - 4)), ".ber") != 0)
		ft_kill (1, NULL);
}
