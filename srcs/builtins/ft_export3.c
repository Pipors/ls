/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:33:14 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 01:16:58 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	big_len(int s1, int s2)
{
	if (s1 > s2)
		return (s1);
	return (s2);
}

int	get_index(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (i);
}

char	*get_name(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = malloc(sizeof(char) * get_index(str, '=') + 1);
	if (!tmp)
		return (NULL);
	while (++i < get_index(str, '='))
		tmp[i] = str[i];
	tmp[i] = 0;
	return (tmp);
}
