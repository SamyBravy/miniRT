/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_properties_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy_bravy <samy_bravy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:57:13 by samy_bravy        #+#    #+#             */
/*   Updated: 2024/09/23 08:27:03 by samy_bravy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt_bonus.h"

static char	*get_object_name(int type)
{
	if (type == pl)
		return ("Plane");
	if (type == sp)
		return ("Sphere");
	if (type == cy)
		return ("Cylinder");
	if (type == h_p)
		return ("Hyperbolic Paraboloid");
	return ("");
}

static void	display_messages(t_data *data, int y_msg)
{
	mlx_string_put(data->mlx_struct->mlx, data->mlx_struct->mlx_win,
		7, y_msg, 0x00FFFFFF, "Press C to change properties");
	mlx_string_put(data->mlx_struct->mlx, data->mlx_struct->mlx_win,
		7, y_msg + 16, 0x00FFFFFF, "Press Q to unselect object");
}

void	display_object_properties(t_data *data, t_object *obj)
{
	int		y_msg;

	mlx_string_put(data->mlx_struct->mlx, data->mlx_struct->mlx_win,
		7, 14, 0x00FFFFFF, get_object_name(obj->type));
	if (obj->type == sp)
		display_sphere_properties(data, obj);
	else if (obj->type == pl)
		display_plane_properties(data, obj);
	else if (obj->type == cy)
		display_cylinder_properties(data, obj);
	else if (obj->type == h_p)
		display_hyperbolic_paraboloid_properties(data, obj);
	y_msg = 74;
	if (obj->type == cy)
		y_msg += 31;
	else if (obj->type == h_p)
		y_msg += 105;
	display_messages(data, y_msg);
}
