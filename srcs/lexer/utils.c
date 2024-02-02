/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:33:56 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 01:16:30 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_charachter(char c)
{
	if (c == '\0' || c == '|' || c == '<'
		|| c == '\t' || c == ' ' || c == '>' || c == '&')
		return (0);
	return (1);
}

int	is_quote(char c, char q)
{
	if (c == '\0' || c == q)
		return (0);
	return (1);
}

int	is_unexpected_token(char c)
{
	if (c == '\0' || c == ';' || c == '|'
		|| c == '&' || c == '<' || c == '>'
		|| c == '(' || c == ')' || c == '\n')
		return (1);
	return (0);
}

t_token	*unexpected_token(t_lexer *lexer)
{
	char	*value;
	t_token	*token;

	lexer_advance(lexer);
	value = ft_substr(lexer->line, lexer->i, 1);
	token = token_init(value, TOKEN_ERROR);
	free(value);
	return (token);
}

void	quote_inside(t_lexer *lexer, int *i)
{
	char	q;

	q = lexer->c;
	lexer_advance(lexer);
	(*i)++;
	while (is_quote(lexer->c, q))
	{
		lexer_advance(lexer);
		(*i)++;
	}
}
