/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:33:43 by ntom              #+#    #+#             */
/*   Updated: 2018/09/24 02:47:31 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_precwidth(char c, t_infos *infos)
{
	if (ft_isdigit(c) || c == '.')
	{
		while (infos->str[infos->i] && ft_isdigit(infos->str[infos->i]))
		{
			infos->iwdp |= ON << I_W;
			infos->width = ((infos->width * 10) + (infos->str[infos->i] - '0'));
			infos->i++;
		}
		if (infos->str[infos->i] && infos->str[infos->i] == '.')
		{
			infos->iwdp |= ON << I_D;
			infos->i++;
			while (infos->str[infos->i] && ft_isdigit(infos->str[infos->i]))
			{
				infos->iwdp |= ON << I_P;
				infos->prec = ((infos->prec * 10)
						+ (infos->str[infos->i] - '0'));
				infos->i++;
			}
		}
		if ((infos->iwdp & ON << I_W) && (infos->width <= infos->prec))
			infos->iwdp &= ~(ON << I_W);
		return (1);
	}
	return (0);
}

/*
** Recuperer la precision et la width
** Et allumer les bit correspondant
*/

static int	ft_cast(char c, t_infos *infos)
{
	static char		*cast = "hljz\0";
	int				i;

	i = 0;
	while (cast[i])
	{
		if (c == cast[i])
		{
			if ((infos->icast & ON << ICA_L) && c == 'l')
				infos->icast |= ON << ICA_LL;
			else if ((infos->icast & ON << ICA_H) && c == 'h')
				infos->icast |= ON << ICA_HH;
			else
			{
				infos->icast |= ON << i;
			}
			infos->i++;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Allume le bit de cast
** Et essai de gerer les cas speciaux
** il faudra lire a partir de H et remonter jusqu'au plus haut
*/

static int	ft_flags(char c, t_infos *infos)
{
	static char		*flag = "#0-+ \0";
	int				i;

	i = 0;
	while (flag[i])
	{
		if (c == flag[i])
		{
			infos->iflag |= ON << i;
			infos->i++;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Allume le bit de flag
*/

static int	ft_conv(char c, t_infos *infos)
{
	static char		*conv = "sSpdDioOuUxXcC\0";
	int				i;

	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
		{
			infos->iconv |= ON << i;
			infos->i++;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Allume le bit de conversion
*/

void		ft_stock(t_infos *infos)
{
	while (infos->str[infos->i])
	{
		if (ft_flags(infos->str[infos->i], infos)
		|| ft_cast(infos->str[infos->i], infos)
		|| ft_precwidth(infos->str[infos->i], infos))
			;
		else if (ft_conv(infos->str[infos->i], infos))
		{
			break ;
		}
		else
			break ;
	}
	return ;
}
