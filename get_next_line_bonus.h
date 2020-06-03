/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaptain <mcaptain@msk-school21.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:28:30 by mcaptain          #+#    #+#             */
/*   Updated: 2020/05/18 12:43:19 by mcaptain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_BONUS_H
# define FT_GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			content;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
char			*ft_strnjoin(char *s1, char *s2, int n);
char			*ft_strchr(const char *str, int ch);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
int				push(char **buf, char **line);

#endif
