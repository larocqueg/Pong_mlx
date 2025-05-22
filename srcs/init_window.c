/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:47:06 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/22 20:50:05 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_window(t_cub *cub)
{
	(*cub).mlx_ptr = mlx_init();
	(*cub).win_ptr = mlx_new_window((*cub).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "cub3d");
	cub->image.img = mlx_new_image(cub->mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	cub->image.addr = mlx_get_data_addr(cub->image.img, &cub->image.bits_per_pixel,
			&cub->image.line_length, &cub->image.endian);
}
