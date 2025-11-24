/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:44:11 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:32:34 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimmed_length(char const *s1, char const *set)
{
	int	final;
	int	i;

	final = 0;
	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, (int)s1[i]) == NULL)
			final ++;
		i ++;
	}
	return (final);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	j = 0;
	final = (char *)malloc(trimmed_length(s1, set) + 1);
	while (s1[i])
	{
		if (ft_strchr(set, (int)s1[i]) == NULL)
		{
			final[j] = s1[i];
			j++;
		}
		i++;
	}
	final[j] = '\0';
	return (final);
}
