/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ambient_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy_bravy <samy_bravy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:44:00 by samy_bravy        #+#    #+#             */
/*   Updated: 2024/10/24 13:04:49 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt_bonus.h"

void	display_ambient_properties(t_data *data)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	while (++i < data->num_of_lights)
	{
		str = ft_itoa(i);
		tmp = ft_strjoin("Light ", str);
		free(str);
		str = ft_strjoin(tmp, " position:");
		free(tmp);
		display_axes(data, data->lights[i].pos, str, 14 + 16 * i);
		free(str);
	}
	i--;
	display_axes(data, data->camera.pos, "Camera position:", 33 + 16 * i);
	display_axes(data, data->camera.orientation,
		"Camera orientation:", 49 + 16 * i);
	mlx_string_put(data->mlx_struct->mlx, data->mlx_struct->mlx_win,
		7, 73 + 16 * i, 0x00FFFFFF, "Press C to change properties");
}
