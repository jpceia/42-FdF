/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:15:13 by jceia             #+#    #+#             */
/*   Updated: 2021/08/31 22:03:46 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <string.h>

typedef struct s_grid
{
	double	**data;
	size_t	width;
	size_t	height;
}	t_grid;

void	grid_init(t_grid *grid);
double	*grid_parse_line(char *line);
void	grid_append_line(t_grid *grid, char *line);
void	grid_clear(t_grid *grid);
void	grid_parse_file(t_grid *grid, char *fname);
void	grid_print(t_grid	*grid);

#endif
