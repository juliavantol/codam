/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:46:09 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/07 00:21:59 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(char	**map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		printf("%s\n", map[row]);
		row++;
	}
}

mlx_image_t	*get_picture(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	// Load texture
	texture = mlx_load_png(path);
	if (!texture)
        ft_error("Texture error\n");
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
        ft_error("Image error\n");
	return (img);
}

t_imgs	set_images(mlx_t *mlx)
{
	t_imgs	pics;

	pics.floor = get_picture(mlx, "textures/tile_32/00.png");
	pics.wall = get_picture(mlx, "textures/ice_32/113.png");
	pics.player_front = get_picture(mlx, "textures/ghosts/front.png");
	pics.player_back = get_picture(mlx, "textures/ghosts/back.png");
	pics.player_left = get_picture(mlx, "textures/ghosts/left.png");
	pics.player_right = get_picture(mlx, "textures/ghosts/right.png");
	return (pics);
}

void	fill_background(mlx_t *mlx, t_imgs pics, char **map)
{
	int x;
	int y;
	int	height;
	int width;

	height = 0;
	x = 0;
	while (map[height])
	{
		width = 0;
		y = 0;
		while (map[height][width])
		{
			if (map[height][width] == '0')
			{
				if (mlx_image_to_window(mlx, pics.floor, y, x) < 0)
       				ft_error("Image error\n");
			}
			else if (map[height][width] == '1')
			{
				if (mlx_image_to_window(mlx, pics.wall, y, x) < 0)
       				ft_error("Image error\n");
			}
			else if (map[height][width] == 'P')
			{
				if (mlx_image_to_window(mlx, pics.floor, y, x) < 0)
       				ft_error("Image error\n");
				if (mlx_image_to_window(mlx, pics.player_front, y, x) < 0)
       				ft_error("Image error\n");
			}
			width++;
			y += PIXELS;
		}
		x += PIXELS;
		height++;
	}
}

int	close_window(void)
{
	exit(1);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == 256 && keydata.action == MLX_RELEASE)
		exit(1);
	param++;
	param--;
}

void	open_window(t_map map_data)
{
	mlx_t			*mlx;
	t_imgs			pics;
	int				height;
	
	height = 0;
	while (map_data.map[height])
		height++;
	mlx = mlx_init((ft_strlen(*(map_data.map)) * PIXELS), (height * PIXELS), "so_long", false);
	if (mlx == NULL)
		ft_error("MLX error\n");
	pics = set_images(mlx);
	mlx_key_hook(mlx, &key_hooks, NULL);
	fill_background(mlx, pics, map_data.map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
