#include "main.h"
#include <stdarg.h>
/**
 * _printf - produces output according to a format.
 * @format: array of specifiers
 * Return: Number of characters printed to stdout
 */
int _printf(const char *format, ...)
{
	int xters = 0;      /* Number of characters printed */
	va_list ap;         /* Initialize the va_list for variable arguments */
	int len = 0;        /* Move var declaration to the top */

        if (format == NULL)
                return (-1);

	if (format == NULL)
		return (-1);
	va_start(ap, format);   /* Initialize the va_list with variable arguments */

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			xters++;
		}
		else if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, format, 1);
				xters++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(ap, int);  /* Correctly retrieve char */
				write(1, &c, 1);
				xters++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(ap, char *);
				if (str == NULL)
					return (-1);
				while (str[len] != '\0')
					len++;
				write(1, str, len);
				xters += len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, int);  /* Correctly retrieve int */
				char buffer[20];  /* Create a buffer to hold the number as a string */
				int len = 0;

				if (num < 0)
				{
					write(1, "-", 1);  /* Print a minus sign for negative numbers */
					num = -num;  /* Make num positive for conversion */
					len++;
				}
				do
				{
					buffer[len++] = num % 10 + '0';  /* Convert digits to characters */
					num /= 10;
				}
				while (num > 0);
        while (*format)
        {
                if (*format != '%')
        {
                write(1, format, 1);
                xters++;
        }
                else if (*format == '%')
                {
                        format++;
                        if (*format == '%')
                        {
                                write(1, format, 1);
                                xters++;
                        }
                        else if (*format == 'c')
                        {
                                c = va_arg(ap, int);  /* Correctly retrieve char */
                                write(1, &c, 1);
                                xters++;
                        }
                        else if (*format == 's')
                        {
                                *str = va_arg(ap, char *);
                                if (str == NULL)
                                        return (-1);
                                /* int len = 0;*/
                                while (str[len] != '\0')
                                        len++;
                                write(1, str, len);
                                xters += len;
                        }
                        else if (*format == 'd' || *format == 'i')
                        {
                                int num = va_arg(ap, int);  /* Correctly retrieve int */
                                char buffer[20];  /* Create a buffer to hold the number as a string */
                                int len = 0;
                                if (num < 0)
                                {
                                        write(1, "-", 1);  /* Print a minus sign for negative numbers */
                                        num = -num;  /* Make num positive for conversion */
                                        len++;
                                }
                                do
                                {
                                        buffer[len++] = num % 10 + '0';  /* Convert digits to characters */
                                        num /= 10;
                                }
                                while (num > 0);
                                /* Reverse the buffer to get the correct number */
                                for (len = len - 1; len >= 0; len--)
                                        write(1, &buffer[len], 1);
                                xters += len;
                        }
                }
                format++;
        }
        va_end(ap);  /* Clean up the va_list */
        return (xters);
}
