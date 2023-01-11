/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummyMain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:20:09 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 17:50:32 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/parser.h"

int main(int argc, char **argv)
{
	int     file;
	char    *buff;
	char	*tmp;
	char    **map;
	char	*leaks;

	file = open(argv[1], O_RDONLY);
	if (file > 0)
	{
		tmp = ft_strdup("");
		buff = get_next_line(file);
		while (buff)
		{
			leaks = tmp;
			free(leaks);
			tmp = ft_strjoin(leaks, buff);
			free(buff);
			buff = get_next_line(file);
			
		}
		// system("leaks a.out");
		printf("%s\n", tmp);
		map = ft_split(tmp, '\n');
		free(tmp);
	}
	else
		ft_file_error();
	return (0);
}