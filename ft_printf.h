/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:33:26 by ntom              #+#    #+#             */
/*   Updated: 2018/09/25 02:40:06 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

# include <stdarg.h>

# define ON 1L
# define OFF 0L

# define IC_S 0
# define IC_MS 1
# define IC_P 2
# define IC_D 3
# define IC_MD 4
# define IC_I 5
# define IC_O 6
# define IC_MO 7
# define IC_U 8
# define IC_MU 9
# define IC_X 10
# define IC_MX 11
# define IC_C 12
# define IC_MC 13

# define IF_HAS 0
# define IF_ZER 1
# define IF_MIN 2
# define IF_PLU 3
# define IF_SPA 4

# define ICA_H 0
# define ICA_L 1
# define ICA_J 2
# define ICA_Z 3
# define ICA_HH 4
# define ICA_LL 5

# define I_W 0
# define I_D 1
# define I_P 2

typedef struct		s_infos
{
	int				printed;
	unsigned char	iflag;
	unsigned char	icast;
	int				iconv;
	unsigned char	iwdp;
	int				width;
	int				prec;
	char			*str;
	int				i;
	char			*res;
	int				error;
}					t_infos;

int					ft_printf(const char *format, ...);
void				ft_stock(t_infos *infos);

#endif
