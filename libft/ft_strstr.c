/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 22:57:36 by ntom              #+#    #+#             */
/*   Updated: 2018/06/21 23:46:06 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *dest;
	const char *src;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		dest = haystack;
		src = needle;
		while (*src != '\0' && *src == *dest)
		{
			dest++;
			src++;
			if (*src == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
