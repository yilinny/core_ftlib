/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi0ltan <yi-ltan@student.42sinfapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:48:25 by yi-ltan           #+#    #+#             */
/*   Updated: 2025/11/24 09:48:44 by yi0ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	index;
	int	length;

	length = ft_strlen(s);
	index = 0;
	while (index < length)
	{
		f(index, s + index);
		index ++;
	}
}
