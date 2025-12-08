/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_shapes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy_bravy <samy_bravy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:51:24 by samy_bravy        #+#    #+#             */
/*   Updated: 2024/10/24 13:04:49 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt_bonus.h"

void	display_sphere_properties(t_data *data, t_object *obj)
{
	display_axes(data, obj->pos, "Center:", 35);
	display_value(data, obj->diameter, "Diameter:", 50);
}

void	display_plane_properties(t_data *data, t_object *obj)
{
	display_axes(data, obj->pos, "Point:", 35);
	display_axes(data, obj->orientation, "Normal:", 50);
}

void	display_cylinder_properties(t_data *data, t_object *obj)
{
	display_axes(data, obj->pos, "Center:", 35);
	display_axes(data, obj->orientation, "Axis:", 50);
	display_value(data, obj->diameter, "Diameter:", 65);
	display_value(data, obj->height, "Height:", 80);
}
