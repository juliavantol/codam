/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectibles.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juvan-to <juvan-to@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 14:30:21 by juvan-to      #+#    #+#                 */
/*   Updated: 2023/05/10 01:42:31 by Julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_node	*new_list(void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	if (content == NULL)
		node -> img = NULL;
	else
		node -> img = content;
	node -> found= false;
	node -> next = NULL;
	return (node);
}

void	add_collectible(t_node **collectibles, t_node *new)
{
	if (*collectibles == NULL || collectibles == NULL)
	{
		new -> next = NULL;
		*collectibles = new;
	}
	else
	{
		new -> next = *collectibles;
		*collectibles = new;		
	}
}

void	put_collectible(mlx_t *mlx, t_game *game, int x, int y)
{
	mlx_image_t		*img;
	t_node			*temp;

	img = get_picture(mlx, "textures/porb2.png");
	put_image(mlx, img, x, y);
	temp = new_list(img);
	add_collectible(game->collectibles, temp);	
}