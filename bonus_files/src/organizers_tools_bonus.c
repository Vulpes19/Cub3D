/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizers_tools_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:31:45 by mbaioumy          #+#    #+#             */
/*   Updated: 2023/01/31 20:52:08 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "parser_bonus.h"

int	ft_wordsize(char *word)
{
	int	count;

	count = 0;
	while (word[count] && word[count] != ' ')
		count++;
	return (count);
}

int	ft_secondword_size(char *word)
{
	int	count;

	count = 0;
	while (word[count])
		count++;
	return (count);
}

char	**ft_split_textures_colors(char *line)
{
	char	**split;
	int		i;
	int		j;
	int		k;
	int		len;

	split = ft_calloc(3, sizeof(char *));
	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && j == 0)
			len = ft_wordsize(line + i);
		else if (line[i])
			len = ft_secondword_size(line + i);
		split[j] = ft_calloc(len + 1, sizeof(char));
		k = 0;
		while (k < len)
			split[j][k++] = line[i++];
		j++;
	}
	return (split);
}

t_status	ft_check_digit(char *digit)
{
	char	**tmp;

	tmp = ft_split(digit, ' ');
	if (tmp[1])
	{
		freethis1(tmp);
		return (ERROR);
	}
	freethis1(tmp);
	return (GOOD);
}

t_status	ft_check_commas(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (GOOD);
	return (ERROR);
}
