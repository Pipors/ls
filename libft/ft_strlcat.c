/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:33:24 by aamardou          #+#    #+#             */
/*   Updated: 2024/02/02 02:31:13 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lnth;
	size_t	i;
	size_t	len;

	lnth = ft_strlen(dst);
	len = ft_strlen(src);
	if (dstsize <= lnth)
		len += dstsize;
	else
		len += lnth;
	i = 0;
	while (src[i] != '\0' && lnth + 1 < dstsize)
	{
		dst[lnth] = src[i];
		lnth++;
		i++;
	}
	dst[lnth] = '\0';
	return (len);
}
