/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 02:47:31 by samy_bravy        #+#    #+#             */
/*   Updated: 2024/10/24 12:59:23 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static int	cleanup_and_exit(t_data *data, t_minilibx *mlx)
{
	if (data)
	{
		if (data->objects)
			free(data->objects);
		if (data->lights)
			free(data->lights);
	}
	if (mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_elem		*elem;
	t_minilibx	mlx_struct;
	t_data		data;
	int			save_mode;

	save_mode = 0;
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
		save_mode = 1;
	elem = NULL;
	parsing(&elem, argv[1], argc - save_mode);
	mlx_struct.name = argv[1];
	minilibx_init(&mlx_struct, elem);
	data = build_data(elem, &mlx_struct);
	free(elem);
	build_image(&data);
	if (save_mode)
	{
		save_bmp(&data, argv[1]);
		return (cleanup_and_exit(&data, &mlx_struct));
	}
	setup_hooks(&mlx_struct, &data);
	return (0);
}
