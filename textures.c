/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:02:39 by albaud            #+#    #+#             */
/*   Updated: 2022/08/02 17:35:51 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	init_buttons(t_board *game)
{
	game->butons[0] = ft_init_image(game->w.mlx, "sprites/but/PVSB/PVSB.xpm");
	game->butons[1] = ft_init_image(game->w.mlx, "sprites/but/BVSP/BVSP.xpm");
	game->butons[2] = ft_init_image(game->w.mlx, "sprites/but/PVSR/PVSR.xpm");
	game->butons[3] = ft_init_image(game->w.mlx, "sprites/but/RVSP/RVSP.xpm");
	game->butons[4] = ft_init_image(game->w.mlx, "sprites/but/BVSR/BVSR.xpm");
	game->butons[5] = ft_init_image(game->w.mlx, "sprites/but/RVSB/RVSB.xpm");
	game->butons[6] = ft_init_image(game->w.mlx, "sprites/but/BVSB/BVSB.xpm");
	game->butons[7] = ft_init_image(game->w.mlx, "sprites/but/RVSR/RVSR.xpm");
	game->butons[8] = ft_init_image(game->w.mlx, "sprites/but/PVSP/PVSP.xpm");
	game->butons[9] = ft_init_image(game->w.mlx, "sprites/but/PVSB/PVSBD.xpm");
	game->butons[10] = ft_init_image(game->w.mlx, "sprites/but/BVSP/BVSPD.xpm");
	game->butons[11] = ft_init_image(game->w.mlx, "sprites/but/PVSR/PVSRD.xpm");
	game->butons[12] = ft_init_image(game->w.mlx, "sprites/but/RVSP/RVSPD.xpm");
	game->butons[13] = ft_init_image(game->w.mlx, "sprites/but/BVSR/BVSRD.xpm");
	game->butons[14] = ft_init_image(game->w.mlx, "sprites/but/RVSB/RVSBD.xpm");
	game->butons[15] = ft_init_image(game->w.mlx, "sprites/but/BVSB/BVSBD.xpm");
	game->butons[16] = ft_init_image(game->w.mlx, "sprites/but/RVSR/RVSRD.xpm");
	game->butons[17] = ft_init_image(game->w.mlx, "sprites/but/PVSP/PVSPD.xpm");
	game->butons[18] = ft_init_image(game->w.mlx, "sprites/but/X.xpm");
	game->butons[19] = ft_init_image(game->w.mlx, "sprites/but/O.xpm");
}

void	init_screens(t_board *game)
{
	game->screens[0] = ft_init_image(game->w.mlx, "sprites/screens/XWON.xpm");
	game->screens[1] = ft_init_image(game->w.mlx, "sprites/screens/OWON.xpm");
	game->screens[2] = ft_init_image(game->w.mlx, "sprites/screens/TIE.xpm");
	game->screens[3] = ft_init_image(game->w.mlx,
			"sprites/screens/OTOPLAY.xpm");
	game->screens[4] = ft_init_image(game->w.mlx,
			"sprites/screens/XTOPLAY.xpm");
}
