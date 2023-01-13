/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:18:48 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/12 21:36:07 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>

char			*ft_strdup(char *src);
int				checknl(char *str);
char			*get_next_line(int fd);
void			freethis(void *ptr);
void			freethis1(char **str);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char *src);
size_t			ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char const *s, char c);
void			ft_file_error(void);
void			ft_putstr(char *str);
void			ft_arguments_error(void);

#endif