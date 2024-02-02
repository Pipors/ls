/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:34:24 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 01:16:58 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	unclosed_quotes(char *line)
{
	int	i;
	int	sign;

	i = -1;
	sign = 0;
	while (line[++i])
	{
		if (line[i] == '\'')
			if (sign != 2)
				sign = (((sign == 0) * 1) + ((sign == 1) * 0));
		if (line[i] == '"')
			if (sign != 1)
				sign = (((sign == 0) * 2) + ((sign == 2) * 0));
	}
	return (sign);
}

int	parsing(char *line)
{
	t_lexer	*lexer;

	data_init();
	if (line[0] == '\0')
		return (1);
	if (unclosed_quotes(line))
	{
		g_data.exit_status = 258;
		ft_putstr_fd("minishell: syntax error: unclosed quotes\n", 2);
		return (1);
	}
	lexer = lexer_init(line);
	if (tokens_handler(lexer))
	{
		free(lexer);
		return (1);
	}
	free(lexer);
	return (0);
}
