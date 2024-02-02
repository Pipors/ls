/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:34:11 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 01:16:58 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*new_value(char *str, int i, int start)
{
	char	*tmp;
	char	*new;

	tmp = ft_substr(str, start, i - start);
	if (!tmp[0])
	{
		free(tmp);
		return (NULL);
	}
	else
		new = expand_dollar(tmp, g_data.env);
	free(tmp);
	return (new);
}

char	*parse_dollar(char *str, int *i, int quote)
{
	int		start;
	char	*new;

	start = *i + 1;
	g_data.dollar = 1;
	if (str[start] == '?')
	{
		new = ft_itoa(g_data.exit_status);
		(*i)++;
	}
	else if ((str[start] == '"' || str[start] == '\'') && !quote)
		return (NULL);
	else if (is_separator(str[start]) || !is_acceptable(str[start]))
		new = ft_strdup("$");
	else
	{
		while (str[*i] && is_acceptable(str[++(*i)]))
			;
		new = new_value(str, *i, start);
		(*i)--;
	}
	return (new);
}

char	*parse_dquote(char *str, int *i)
{
	char	*new;
	char	*tmp;

	new = ft_calloc(1, sizeof(char));
	while (str[++(*i)] && str[*i] != '"')
	{
		if (str[*i] == '$')
			tmp = parse_dollar(str, i, 1);
		else
			tmp = ft_substr(str, *i, 1);
		new = advanced_join(new, tmp);
		free(tmp);
	}
	g_data.dollar = 0;
	return (new);
}

char	*parse_squote(char *str, int *i)
{
	int		start;
	char	*new;

	start = *i + 1;
	while (str[++(*i)] && str[*i] != '\'')
		;
	new = ft_substr(str, start, *i - start);
	return (new);
}

char	*parse_args(char *str)
{
	int		i;
	char	*new;
	char	*tmp;

	i = -1;
	new = ft_calloc(1, sizeof(char));
	while (str[++i])
	{
		if (str[i] == '"')
			tmp = parse_dquote(str, &i);
		else if (str[i] == '\'')
			tmp = parse_squote(str, &i);
		else if (str[i] == '$')
		{
			tmp = parse_dollar(str, &i, 0);
			if (ft_strchr(tmp, ' '))
				tmp = handle_spaces(tmp, &new);
		}
		else
			tmp = ft_substr(str, i, 1);
		new = advanced_join(new, tmp);
		free(tmp);
	}
	return (new);
}
