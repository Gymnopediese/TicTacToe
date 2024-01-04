/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:24:06 by albaud            #+#    #+#             */
/*   Updated: 2022/07/24 16:07:23 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_mouvements_inputs_x(int key, t_vector *temp, t_game game)
{
	if (key == KEYCODE_UP_ARROW)
		temp->x += cos(ft_deg_to_rad(game.player.rotation)) * game.player.speed;
	if (key == KEYCODE_DOWN_ARROW)
		temp->x -= cos(ft_deg_to_rad(game.player.rotation)) * game.player.speed;
	if (key == KEYCODE_A)
		temp->x += cos(ft_deg_to_rad(game.player.rotation) - PI / 2)
			* game.player.speed;
	if (key == KEYCODE_D)
		temp->x -= cos(ft_deg_to_rad(game.player.rotation) - PI / 2)
			* game.player.speed;
}

void	ft_mouvements_inputs_y(int key, t_vector *temp, t_game game)
{
	if (key == KEYCODE_UP_ARROW)
		temp->y += sin(ft_deg_to_rad(game.player.rotation)) * game.player.speed;
	if (key == KEYCODE_DOWN_ARROW)
		temp->y -= sin(ft_deg_to_rad(game.player.rotation)) * game.player.speed;
	if (key == KEYCODE_A)
		temp->y += sin(ft_deg_to_rad(game.player.rotation) - PI / 2)
			* game.player.speed;
	if (key == KEYCODE_D)
		temp->y -= sin(ft_deg_to_rad(game.player.rotation) - PI / 2)
			* game.player.speed;
}

int	ft_player_movements(int key, t_game game)
{
	t_vector	tempy;
	t_vector	tempx;

	if (key == KEYCODE_LEFT_ARROW)
		game.player.rotation -= game.player.rotspeed;
	if (key == KEYCODE_RIGHT_ARROW)
		game.player.rotation += game.player.rotspeed;
	if (game.player.rotation > 360)
		game.player.rotation -= 360;
	if (game.player.rotation < 0)
		game.player.rotation += 360;
	tempx = game.player.position;
	ft_mouvements_inputs_x(key, &tempx, game);
	if (!ft_touches_wall(game.map.map, tempx, game.player.sprite.x))
		game.player.position = tempx;
	tempy = game.player.position;
	ft_mouvements_inputs_y(key, &tempy, game);
	if (!ft_touches_wall(game.map.map, tempy, game.player.sprite.x))
		game.player.position = tempy;
	//ft_raycast_ground(game);
	//ft_clean_canvas(game.map.cvs3d);
	ft_raycast_walls(game);
	mlx_put_image_to_window(game.w.mlx, game.w.win, game.w.cvs.img, -1, 0);
	// ft_resize_cvs(game.w.mlx, game.map.cvs3d, 0.5).img
	mlx_put_image_to_window(game.w.mlx, game.w.win, ft_resize_cvs(game.w.mlx, game.map.cvs3d, 0.15).img, 0, BIT);
	mlx_put_image_to_window(game.w.mlx, game.w.win, game.map.sprites[4].img, game.player.position.y * 0.15, game.player.position.x * 0.15 + BIT);
	//mlx_put_image_to_window(game.w.mlx, game.w.win, game.map.cvs3d.img, 0, BIT);
	return (0);
}
