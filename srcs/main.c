/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:24:34 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/20 20:18:11 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_cub	cub;
t_player player;
t_player player2;
t_player ball;
t_point padsize = {20, 100};
int		ball_max = 64;
int		ball_min = 16;
t_point ballsize = {48, 48};
int		pad1_color = 0x0573ad;
int		pad2_color = 0x990e24;
char	score_1[] = "0";
char	score_2[] = "0";
bool	hit_left = true;
bool	hit_right = true;
float	ball_speed = 400;
float	start_speed = 400;
float	boost = 0.03;
float	ball_accel = 500;
bool	started = false;
float	speed = 500;
float delta = 0;
float accel = 1000;
float friction = 1000;
float offset = 40;
long long last_frame_time = 0;


int	game_loop(t_cub *cub);
void init_players();

t_point	normalize(t_point point)
{
	float len = sqrtf(point.x * point.x + point.y * point.y);
	len = sqrtf(len);

	if (len == 0)
		return ((t_point){0, 0});
	else
	{
		point.x /= len;
		point.y /= len;
		return (point);
	}
}

void	drawrect(t_image *image, t_point pos, t_point size, int color)
{
	int	x = 0;
	int y = 0;

	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			ft_pixelput(image, pos.x + x, pos.y + y++, color);
		}
		x++;
	}
}

float clamp(float value, float min, float max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

void	get_random()
{
	ball.direction.x = (float)rand() / (float)RAND_MAX * 2.0f - 1.0f;
	ball.direction.y = (float)rand() / (float)RAND_MAX * 1.4f - 0.7f;
	if (ball.direction.x > 0)
		ball.direction.x = 1;
	else
		ball.direction.x = -1;
	ball.direction = normalize(ball.direction);
}

int	key_press(int keysym, t_cub *cub)
{
	(void)cub;
	if (keysym == XK_space && !started)
	{
		get_random();
		ball_speed = start_speed;
		started = true;
	}
	if (keysym == XK_Escape)
	{
		free_displays(cub);
	}
	if (keysym == XK_W || keysym == XK_w)
	{
		player.direction.y += -1;
		player.direction.y = clamp(player.direction.y, -1, 1);

	}
	if (keysym == XK_S || keysym == XK_s)
	{
		player.direction.y += 1;
		player.direction.y = clamp(player.direction.y, -1, 1);
	}
	if (keysym ==  XK_Up)
	{
		player2.direction.y += -1;
		player2.direction.y = clamp(player2.direction.y, -1, 1);

	}
	if (keysym == XK_Down)
	{
		player2.direction.y += 1;
		player2.direction.y = clamp(player2.direction.y, -1, 1);
	}
	return (0);
}


int	key_release(int keysym, t_cub *cub)
{
	(void)cub;
	if (keysym == XK_Escape)
	{
		free_displays(cub);
	}
	if (keysym == XK_W || keysym == XK_w)
	{
		player.direction.y += 1;
		player.direction.y = clamp(player.direction.y, -1, 1);

	}
	if (keysym == XK_S || keysym == XK_s)
	{
		player.direction.y += -1;
		player.direction.y = clamp(player.direction.y, -1, 1);

	}

	if (keysym == XK_Up)
	{
		player2.direction.y += 1;
		player2.direction.y = clamp(player2.direction.y, -1, 1);

	}
	if (keysym == XK_Down)
	{
		player2.direction.y += -1;
		player2.direction.y = clamp(player2.direction.y, -1, 1);

	}
	return (0);
}

void	calculate_Delta(void)
{
	delta = (get_time() - last_frame_time) / 1000.0f;
	last_frame_time = get_time();
}
int update(t_cub *cub);


void init_players()
{
	hit_right = true;
	hit_left = true;
	ball.pos = (t_point){SCREEN_SIZE_X / 2 - (ballsize.x / 2), SCREEN_SIZE_Y / 2 - (ballsize.y / 2)};
}
int	main(int ac, char **av)
{
	(void)av; (void) ac;
	srand(time(NULL));
	init_window(&cub);

	player.pos = (t_point){ offset, SCREEN_SIZE_Y / 2 };
	player2.pos = (t_point){SCREEN_SIZE_X - (offset + padsize.x), SCREEN_SIZE_Y / 2};
	player.direction = (t_point){0, 0};
	player2.direction = (t_point){0, 0};
	init_players();
	mlx_loop_hook(cub.mlx_ptr, &game_loop, &cub);
	mlx_hook(cub.win_ptr, 2, 1L << 0, &key_press, &cub);
	mlx_hook(cub.win_ptr, 3, 1L << 1, &key_release, &cub);
	mlx_loop(cub.mlx_ptr);
}

void	move()
{
	if (player.direction.y != 0)
	{
		player.velocity.y += player.direction.y * accel * delta;
		player.velocity.y = clamp(player.velocity.y, -speed, speed);
	}
	if (player.direction.y == 0)
	{
		if (player.velocity.y > 0)
			player.velocity.y -= friction * delta;
		else if (player.velocity.y < 0)
			player.velocity.y += friction * delta;
		else
			player.velocity.y = 0;
	}
	player.pos.y += player.velocity.y * delta;
	if (player.pos.y < 0)
	{
		player.velocity.y = 0;
		player.pos.y = 0;
	}
	if (player.pos.y > SCREEN_SIZE_Y - padsize.y)
	{
		player.velocity.y = 0;
		player.pos.y = SCREEN_SIZE_Y - padsize.y;
	}

	if (player2.direction.y != 0)
	{
		player2.velocity.y += player2.direction.y * accel * delta;
		player2.velocity.y = clamp(player2.velocity.y, -speed, speed);
	}
	if (player2.direction.y == 0)
	{
		if (player2.velocity.y > 0)
			player2.velocity.y -= friction * delta;
		else if (player2.velocity.y < 0)
			player2.velocity.y += friction * delta;
		else
			player2.velocity.y = 0;
	}
	player2.pos.y += player2.velocity.y * delta;
	if (player2.pos.y < 0)
	{
		player2.velocity.y = 0;
		player2.pos.y = 0;
	}
	if (player2.pos.y > SCREEN_SIZE_Y - padsize.y)
	{
		player2.pos.y = SCREEN_SIZE_Y - padsize.y;
		player2.velocity.y = 0;
	}

}

void	print_score()
{
	mlx_string_put(cub.mlx_ptr, cub.win_ptr, SCREEN_SIZE_X / 2 - offset, offset, 0xFFFFFF, score_1);
	mlx_string_put(cub.mlx_ptr, cub.win_ptr, SCREEN_SIZE_X / 2 + offset, offset, 0xFFFFFF, score_2);
	if (!started)
		mlx_string_put(cub.mlx_ptr, cub.win_ptr, SCREEN_SIZE_X / 2 - offset * 2, SCREEN_SIZE_Y / 2 - 100, 0xFFFFFF, "PRESS SPACE TO START THE GAME!");
	if (score_2[0] == '5')
	{
		mlx_string_put(cub.mlx_ptr, cub.win_ptr, SCREEN_SIZE_X / 2 - offset, SCREEN_SIZE_Y / 2 - 100, 0xFFFFFF, "Player 2 won!");
		score_2[0] = '0';
		score_1[0] = '0';
		ball_speed = start_speed;
		return ;
	}
	if (score_1[0] == '5')
	{
		mlx_string_put(cub.mlx_ptr, cub.win_ptr, SCREEN_SIZE_X / 2 - offset, SCREEN_SIZE_Y / 2 - 100, 0xFFFFFF, "Player 1 won!");
		score_2[0] = '0';
		score_1[0] = '0';
		ball_speed = start_speed;
		return ;
	}
}

int renderer(t_cub *cub)
{
	cub->image.img = mlx_new_image(cub->mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	cub->image.addr = mlx_get_data_addr(cub->image.img, &cub->image.bits_per_pixel,
			&cub->image.line_length, &cub->image.endian);

	drawrect(&cub->image, (t_point){0, 0}, (t_point){SCREEN_SIZE_X, SCREEN_SIZE_Y}, 0x2E8B47);
	drawline(cub, (t_point){SCREEN_SIZE_X / 2, 0}, (t_point){SCREEN_SIZE_X / 2, SCREEN_SIZE_Y});
	drawrect(&cub->image, player.pos, padsize, pad1_color);
	drawrect(&cub->image, player2.pos, padsize, pad2_color);
	drawrect(&cub->image, ball.pos, ballsize, 0xFFFFFF);


	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->image.img, 0, 0);
	print_score();
	mlx_destroy_image(cub->mlx_ptr, cub->image.img);
	return (0);
}

void	hit_player()
{
	if (hit_left && ball.pos.x > offset && ball.pos.x <= offset + padsize.x)
	{
		if (ball.pos.y + ballsize.x >= player.pos.y - 5 && ball.pos.y <= player.pos.y + 2 + padsize.y)
		{
			hit_left = false;
			hit_right = true;
			ball.direction.y = (float)rand() / (float)RAND_MAX * 1.4f - 0.7f;
			ball.direction.x = -ball.direction.x;
			ball_speed += ball_speed * boost;
			ball.direction = (t_point)normalize(ball.direction);
		}
	}
	else if (hit_right && ball.pos.x + ballsize.x <= SCREEN_SIZE_X - offset && ball.pos.x + ballsize.x >= SCREEN_SIZE_X - offset - padsize.x)
	{
		if (ball.pos.y + ballsize.x  >= player2.pos.y - 2 && ball.pos.y <= player2.pos.y + 2 + padsize.y)
		{
			hit_left = true;
			hit_right = false;
			ball.direction.y = (float)rand() / (float)RAND_MAX * 1.4f - 0.7f;
			ball.direction.x = -ball.direction.x;
			ball_speed += ball_speed * boost;
			ball.direction = (t_point)normalize(ball.direction);
		}
	}
}

void	move_ball()
{
	hit_player();
	if (ball.pos.x < 0)
	{
		started = false;
		//ball.pos = (t_point){SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2};
		score_2[0] += 1;
		init_players();
		ball.direction.x = -ball.direction.x;
	}
	else if (ball.pos.x > SCREEN_SIZE_X - ballsize.x)
	{
		started = false;
		ball.pos = (t_point){SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2};
		score_1[0] += 1;
		init_players();
		ball.direction.x = -ball.direction.x;
	}
	else if (ball.pos.y < 0)
	{
		ball.direction.y = -ball.direction.y;
	}
	else if (ball.pos.y > SCREEN_SIZE_Y - ballsize.y)
	{
		ball.direction.y = -ball.direction.y;
		ball.pos.y = SCREEN_SIZE_Y - ballsize.y;
	}
	ball.pos.x += ball.direction.x * ball_speed *  delta;
	ball.pos.y += ball.direction.y * ball_speed * delta;

}

int update(t_cub *cub)
{
	(void)cub;
	calculate_Delta();
	move();
	if (started)
	{
		if (ball.pos.x < SCREEN_SIZE_X / 2)
		{
			if (ball.pos.x > SCREEN_SIZE_X / 4)
			{
				ballsize.x = ball.pos.x / 10 - 16;
				ballsize.x = clamp(ballsize.x, ball_min, ball_max);
				ballsize.y = ballsize.x;
			}
			else
			{
				ballsize.x = (SCREEN_SIZE_X / 4 - ball.pos.x) / 20 + 16;
				ballsize.x = clamp(ballsize.x, ball_min, ball_max);
				ballsize.y = ballsize.x;
			}
		}
		else if (ball.pos.x >= SCREEN_SIZE_X / 2)
		{
			if (ball.pos.x + ballsize.x < SCREEN_SIZE_X - SCREEN_SIZE_X / 4)
			{
				ballsize.x = (SCREEN_SIZE_X - ball.pos.x + ballsize.x) / 10 - 16;
				ballsize.x = clamp(ballsize.x, ball_min, ball_max);
				ballsize.y = ballsize.x;
			}
			else
			{
				ballsize.x = (ball.pos.x + ballsize.x - (SCREEN_SIZE_X - SCREEN_SIZE_X / 4)) / 20 + 16;
				ballsize.x = clamp(ballsize.x, ball_min, ball_max);
				ballsize.y = ballsize.x;
			}
		}
		move_ball();
	}
	return (0);
}
int	game_loop(t_cub *cub)
{
	update(cub);
	renderer(cub);
	return (0);
}
