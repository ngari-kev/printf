#include "main.h"
/**
  *_printf - produces output according to a format.
  *@format: array of specifiers
  *Return: Number of characters printed to stdout
  */
int _printf(const char *format, ...)
{
	int xters = 0, i = 0;/*xters is the number of characters*/
	char c, *str;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			xters++;
		}
		else if (*format == '%')
		{
			format++;/*if *format == %, we move to the next item*/
			if (*format == '%')/*the case of double %*/
			{
				write(1, format, 1);
				xters++;
			}
			else if (*format == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, 1);
				xters++;
			}
			else if (*format == 's')
			{
				str = va_arg(ap, char*);
				i = strlen(str);
				write(1, str, i);
				xters += i;
			}
		}
		format++;
	}
	return (xters);
}
