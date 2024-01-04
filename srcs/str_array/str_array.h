/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:40:56 by albaud            #+#    #+#             */
/*   Updated: 2022/07/21 19:22:07 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_ARRAY_H
# define STR_ARRAY_H

int		ft_all_str_in_sa(char **src, char **targets);
int		ft_contain_sa(char **to_count, char *target);
int		ft_srta_ind_equal(char **arr, int ind, char *target);
int		ft_stracmp(char **a, char **b);

int		ft_count_st(char **to_count, char *target);
int		ft_strtablen(char **str);
char	**ft_imtoa(t_matrix mat);
void	ft_bubble_sort_sa(char **arr);

char	**ft_clean_enclosures_sa(char **array, char *charset);
char	**ft_clean_cs_first(char **array, char *charset, int num);
char	**ft_strsplit(char const *s, char c);
char	**ft_strange_split(char const *s, char c, char *join);

#endif