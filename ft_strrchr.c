/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:16:46 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 10:21:37 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int index;
	char *final;

	index = (int)ft_strlen(s);
	final = (char *)s;
	if (!c)
		return (NULL);
	while (index >= 0)
	{
		if (s[index] == (unsigned char)c)
			return (final + index);
		index--;
	}
	return (NULL);
}