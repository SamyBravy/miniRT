/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_h_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy_bravy <samy_bravy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:50:42 by samy_bravy        #+#    #+#             */
/*   Updated: 2024/09/28 12:39:35 by samy_bravy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt_bonus.h"

void	change_hyperbolic_paraboloid_properties(t_object *h_paraboloid)
{
	prompt_and_set("Enter h_p coeff A", &h_paraboloid->h_p_abcdefg[pA]);
	prompt_and_set("Enter h_p coeff B", &h_paraboloid->h_p_abcdefg[pB]);
	prompt_and_set("Enter h_p coeff C", &h_paraboloid->h_p_abcdefg[pC]);
	prompt_and_set("Enter h_p coeff D", &h_paraboloid->h_p_abcdefg[pD]);
	prompt_and_set("Enter h_p coeff E", &h_paraboloid->h_p_abcdefg[pE]);
	prompt_and_set("Enter h_p coeff F", &h_paraboloid->h_p_abcdefg[pF]);
	prompt_and_set("Enter h_p coeff G", &h_paraboloid->h_p_abcdefg[pG]);
	prompt_and_set("Enter h_p size", &h_paraboloid->diameter);
}
