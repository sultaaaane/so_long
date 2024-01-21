/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:38:28 by mbentahi          #+#    #+#             */
/*   Updated: 2023/12/05 19:06:34 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlong(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb >= 10)
	{
		counter += ft_putlong(nb / 10);
		counter += ft_putlong(nb % 10);
	}
	else
		counter += ft_putchar(nb + 48);
	return (counter);
}
