/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/05/19 18:46:27 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_abs(int num)
{
	if (num <= -2147483648)
		return (2147483647);
	if (num < 0)
		return (num * -1);
	return (num);
}


void	drawline_low(t_cub *cub, t_point start, t_point dest)
{
	t_drawline	line;

	line.dx = dest.x - start.x;
	line.dy = dest.y - start.y;
	line.yi = 1;
	if (line.dy < 0)
	{
		line.yi = -1;
		line.dy = -line.dy;
	}
	line.d = (2 * line.dy) - line.dx;
	while (start.x <= dest.x)
	{
		ft_pixelput(&cub->image, start.x++, start.y, LINE_COLOR);
		if (line.d > 0)
		{
			start.y = start.y + line.yi;
			line.d = line.d + (2 * (line.dy - line.dx));
		}
		else
			line.d = line.d + 2 * line.dy;
	}
}

void	drawline_high(t_cub *cub, t_point start, t_point dest)
{
	t_drawline	line;

	line.dx = dest.x - start.x;
	line.dy = dest.y - start.y;
	line.xi = 1;
	if (line.dx < 0)
	{
		line.xi = -1;
		line.dx = -line.dx;
	}
	line.d = (2 * line.dx) - line.dy;
	while (start.y <= dest.y)
	{
		ft_pixelput(&cub->image, start.x, start.y++, LINE_COLOR);
		if (line.d > 0)
		{
			start.x = start.x + line.xi;
			line.d = line.d + (2 * (line.dx - line.dy));
		}
		else
			line.d = line.d + 2 * line.dx;
	}
}

void	drawline(t_cub *cub, t_point start, t_point dest)
{
	if (ft_abs(dest.y - start.y) < ft_abs(dest.x - start.x))
	{
		if (start.x > dest.x)
			drawline_low(cub, dest, start);
		else
			drawline_low(cub, start, dest);
	}
	else
	{
		if (start.y > dest.y)
			drawline_high(cub, dest, start);
		else
			drawline_high(cub, start, dest);
	}
}
