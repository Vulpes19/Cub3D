/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummyMain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:20:09 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 19:24:47 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/parser.h"

int main(int argc, char **argv)
{
	t_parse	*data;

	if (argc == 2)
	{
		data = malloc(sizeof(t_parse));
		data->file = open(argv[1], O_RDONLY);
		if (data->file > 0)
			ft_readMap(data);
		else
			ft_file_error();
		free(data);
	}
	else
		ft_arguments_error();
	return (0);
}