/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:41:42 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/05/19 18:58:34 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

int	free_displays(t_cub *cub)
{
	mlx_loop_end((*cub).mlx_ptr);
	mlx_destroy_window((*cub).mlx_ptr, (*cub).win_ptr);
	mlx_destroy_display((*cub).mlx_ptr);
	free((*cub).mlx_ptr);
	ft_printf("Closing Application!");
	exit(1);
	return (0);
}
