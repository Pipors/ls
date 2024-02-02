/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:32:43 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 01:16:58 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(void)
{
	int	i;

	i = 0;
	if (((t_cmd *)(g_data.cmds->content))->args[1] == NULL)
	{
		while (g_data.env[i] != NULL)
		{
			ft_putstr_fd(g_data.env[i], 1);
			ft_putchar_fd('\n', 1);
			i++;
		}
		return ;
	}
	else
	{
		g_data.exit_status = 127;
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(((t_cmd *)(g_data.cmds->content))->args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}
