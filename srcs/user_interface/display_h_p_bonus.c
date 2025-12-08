/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_h_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy_bravy <samy_bravy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:41:39 by samy_bravy        #+#    #+#             */
/*   Updated: 2024/10/24 13:04:49 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt_bonus.h"

void	display_hyperbolic_paraboloid_properties(t_data *data, t_object *obj)
{
	int		i;
	char	*labels[7];

	labels[0] = "A:";
	labels[1] = "B:";
	labels[2] = "C:";
	labels[3] = "D:";
	labels[4] = "E:";
	labels[5] = "F:";
	labels[6] = "G:";
	display_axes(data, get_h_p_vertex(obj->h_p_abcdefg), "Vertex:", 35);
	display_value(data, obj->diameter, "Size:", 50);
	i = -1;
	while (++i < 7)
		display_value(data, obj->h_p_abcdefg[i], labels[i], 65 + (i * 15));
}
