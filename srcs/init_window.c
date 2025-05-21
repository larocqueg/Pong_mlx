/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:26:08 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/05/14 17:52:13 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_window(t_cub *cub)
{
	(*cub).mlx_ptr = mlx_init();
	(*cub).win_ptr = mlx_new_window((*cub).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "cub3d");

}
