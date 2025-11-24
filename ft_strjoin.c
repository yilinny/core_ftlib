/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:41:49 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 11:30:20 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*final;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = (char *)malloc(length);
	if (final == NULL)
		return (NULL);
	i = 0;
	ft_strlcpy(final, s1, length);
	ft_strlcat(final, s2, length);
	return (final);
}
