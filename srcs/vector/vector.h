/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:54:38 by albaud            #+#    #+#             */
/*   Updated: 2024/01/04 02:49:38 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "../sources.h"

int			ft_vector_eql(t_vector a, t_vector b);

t_vector	ft_add_to_vector(t_vector vect, double x, double y, double z);
t_vector	ft_add_vector(t_vector vect, t_vector toadd);
t_vector	ft_vect(double x, double y, double z);
t_vector	ft_vector_int(t_vector vect);
t_vector	*ft_mal_vector(double x, double y, double z);
t_vector	*ft_dup_vector(t_vector toclone);
double		ft_distance(t_vector a, t_vector b);

#endif