/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelicio <rfelicio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:04:37 by rfelicio          #+#    #+#             */
/*   Updated: 2022/08/16 10:14:08 by rfelicio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

static void	*ft_memset(void *b, int c, size_t len);

/*
** DESCRIPTION: fill a byte string with a byte value
**
** BEHAVIOUR: Writes len bytes of value c (converted to an unsigned char) 
** to the string b.
**
** RETURN VALUES: (void) b
*/

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, 0, n);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	if (!s1)
		return (NULL);
	while (s1[len] != '\0')
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}