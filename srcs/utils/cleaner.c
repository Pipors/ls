/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:34:36 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 01:15:44 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_token(t_token *token)
{
	free(token->value);
	free(token);
}

void	free_loop(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

void	free_cmd(void *cmd)
{
	free(((t_cmd *)cmd)->cmd);
	free(((t_cmd *)cmd)->infile);
	free(((t_cmd *)cmd)->append);
	free_loop(((t_cmd *)cmd)->args);
	free_loop(((t_cmd *)cmd)->outfiles);
	free((t_cmd *)cmd);
}

void	clean(void)
{
	t_list	*tmp;

	if (g_data.cmds)
	{
		while (g_data.cmds)
		{
			tmp = g_data.cmds;
			g_data.cmds = g_data.cmds->next;
			ft_lstdelone(tmp, &free_cmd);
		}
	}
	else
		free_cmd(g_data.cmd);
}

void	cleaning(void)
{
	ft_putstr_fd("exit\n", 1);
	free_loop(g_data.env);
	free_loop(g_data.export);
	exit (g_data.exit_status);
}
