/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:11:25 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/29 12:15:40 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_c(va_arg(args, int)));
	if (format == 's')
		return (ft_print_s(va_arg(args, char *)));
	if (format == 'p')
		return (ft_print_p(va_arg(args, uintptr_t)));
	if (format == 'd' || format == 'i')
		return (ft_print_d(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_u(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_print_x(va_arg(args, unsigned int), format));
	if (format == '%')
		return (ft_print_c('%'));
	else
		return (ft_print_c('%'), ft_print_c(format), 2);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_c(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	char	c;
// 	char	*str;
// 	int		num;
// 	char	*line;
// 	int		result;
// 	int 	result2;

// 	line = "---------------------------------------------------";
// 	printf("%s\n\n", line);
// 	c = 'A';
// 	ft_printf("My ft_printf  c --> %c\n\n", c);
// 	printf("Printf        c --> %c\n", c);
// 	result = ft_printf("%c\n", c);
// 	ft_printf("Valeur de retour ft_printf : %d\n", result);
// 	result2 = printf("%c\n", c);
// 	ft_printf("Valeur de retour printf : %d\n", result2);
// 	printf("%s\n\n", line);
// 	str = "Bonjour le petit printf";
// 	ft_printf("My ft_printf  s --> %s\n\n", str);
// 	printf("Printf        s --> %s\n", str);
// 	printf("%s\n\n", line);
// 	ft_printf("My ft_printf  p --> %p\n\n", str);
// 	printf("Printf        p --> %p\n", str);
// 	printf("%s\n\n", line);
// 	num = 123456;
// 	ft_printf("My ft_printf  d --> %d\n\n", num);
// 	printf("Printf        d --> %d\n", num);
// 	printf("%s\n\n", line);
// 	ft_printf("My ft_printf  i --> %i\n\n", num);
// 	printf("Printf        i -->  %i\n", num);
// 	printf("%s\n\n", line);
// 	ft_printf("My ft_printf  u --> %u\n\n", num);
// 	printf("Printf        u --> %u\n", num);
// 	printf("%s\n\n", line);
// 	ft_printf("My ft_printf x --> %x\n\n", num);
// 	printf("Printf       x --> %x\n", num);
// 	printf("%s\n\n", line);
// 	ft_printf("My ft_printf X --> %X\n\n", num);
// 	printf("Printf       X --> %X\n", num);
// 	printf("%s\n\n", line);
// 	ft_printf("My ft_printf pourcent --> %%\n\n");
// 	printf("Printf pourcent       --> %%\n");
// }
