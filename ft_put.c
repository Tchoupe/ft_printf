/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 22:58:41 by ntom              #+#    #+#             */
/*   Updated: 2018/09/25 02:40:01 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_int(va_list ap, t_infos *infos, char c)
{
	if ((c == 'd' || c == 'i') && !(infos->res = ft_itoa(va_arg(ap, intmax_t))))
			infos->error = -1;
	else if (c == 'o' && !(infos->res = ft_itoa_base(va_arg(ap, uintmax_t), 8)))
			infos->error = -1;
	else if ((c == 'x' || c == 'X')
			&& !(infos->res = ft_itoa_base(va_arg(ap, uintmax_t), 16)))
			infos->error = -1;
	else if (c == 'u' && !(infos->res = ft_itoa(va_arg(ap, uintmax_t))))
			infos->error = -1;
	else if (c == 'p' && !(infos->res = ft_itoa_base(va_arg(ap, uintmax_t), 16)))
			infos->error = -1;
	else if (c == 'b' && !(infos->res = ft_itoa_base(va_arg(ap, uintmax_t), 2)))
			infos->error = -1;
	else
		return (0);
	return (1);
}

/*
** To put an int, doesnt work with unsigned int
*/

static int	ft_put_c(va_list ap, t_infos *infos, char c)
{
	if (c == 'c')
	{
		if (!(infos->res = malloc(sizeof(intmax_t) * 1)))
			infos->error = -1;
		infos->res[1] = '\0';
		if (!(infos->res[0] = va_arg(ap, intmax_t)))
			infos->error = -1;
	}
	else if (c == 'C')
	{
		if (!(infos->res = malloc(sizeof(intmax_t) * 1)))
			infos->error = -1;
		infos->res[1] = '\0';
		if (!(infos->res[0] = va_arg(ap, intmax_t)))
			infos->error = -1;
	}
	else
		return (0);
	return (1);
}

/*
** to put a char, doesnt work with wchar_t
** gerer tout le reste
** ecrire un put wchart (si simple char 1 << 8, double char 1 << 8 , 7, etc) 
*/

static int	ft_put_s(va_list ap, t_infos *infos, char c)
{
	if (c == 's' && !(infos->res = ft_strdup(va_arg(ap, void*))))
			infos->error = -1;
	else if (c == 'S' && !(infos->res = va_arg(ap, void*)))
			infos->error = -1;
	else
		return (0);
	return (1);
}

void		ft_put_what(va_list	ap, t_infos *infos)
{
	if ((infos->str[infos->i] == '%' || infos->iconv == 0) && infos->error == 0)
		;
	else if (ft_put_int(ap, infos, infos->str[infos->i]) && infos->error == 0)
		;
	else if (ft_put_c(ap, infos, infos->str[infos->i]) && infos->error == 0)
		;
	else if (ft_put_s(ap, infos, infos->str[infos->i]) && infos->error == 0)
		;
}

/*
** Juste str_join tout pour finir
*/
