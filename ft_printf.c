/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:33:42 by ntom              #+#    #+#             */
/*   Updated: 2018/09/25 02:40:03 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_reset(t_infos *infos)
{
	infos->icast = 0;
	infos->prec = 0;
	infos->width = 0;
	infos->iflag = 0;
	infos->iconv = 0;
	infos->iwdp = 0;
}

/*
** initialise a 0 ou reset, les flags et autres
*/

static void	ft_ignoredf(t_infos *infos)
{
	if (((infos->iflag & ON << IF_ZER) && (infos->iwdp & ON << I_P))
	|| ((infos->iflag & ON << IF_ZER ) && (infos->iflag & ON << IF_MIN)))
		infos->iflag &= ~(ON << IF_ZER);
	if (infos->iflag & (ON << IF_HAS)
	&& infos->iconv & ~(ON << IC_X) && infos->iconv & ~(ON << IC_MX))
		infos->iflag &= ~(ON << IF_HAS);
//	if (infos->iflag & (ON << IF_SPA)
//	&& infos->iconv & ~(ON << IC_I) && infos->iconv & ~(ON << IC_D))
//		infos->iflag &= ~(ON << IF_SPA);
	if ((infos->iflag & ON << IF_SPA) && (infos->iflag & ON << IF_PLU))
		infos->iflag &= ~(ON << IF_SPA);
}

int			ft_printf(const char *format, ...)
{
	t_infos	infos;
	va_list	ap;

	infos.error = 0;
	infos.i = 0;
	infos.printed = 0;
	if (!(infos.str = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	ft_reset(&infos);
	while (infos.str[infos.i])
	{
		if (infos.str[infos.i] == '%')
		{
			infos.i++;
			ft_reset(&infos);
			ft_stock(&infos);
			ft_ignoredf(&infos);
			ft_putbits_int(infos.iconv);
			ft_put_what(ap, &infos);
		}
		else
		{
			ft_putchar(infos.str[infos.i++]);
			infos.printed++;
		}
	}
	//
	//ft_putbits_int(infos.iflag);
	//ft_putbits_int(infos.iconv);
	//ft_putbits_int(infos.icast);
	//ft_putbits_int(infos.iwdp);
	//printf("width %d\n", infos.width);
	//printf("prec %d\n", infos.prec);
	//
	free(infos.str);
	if (infos.error == -1)
		return (-1);
	return (infos.printed);
}

int			main(void)
{
	int		ret = 16;
	char	a = 'a';
	ft_printf("%C\n");
	//	ft_printf("%0s\n");
	return (0);
}

/*
** # + o = un 0 d'office en premier
** # + x = 0x en premier 
*/
