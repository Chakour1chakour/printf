#include "main.h"

/**
 * _printf - prints everything
 * @format: the first string
 * Return: length of the printed content
 */

int _printf(const char *format, ...)
{
	int i, j, num = 0, len = 0;
	va_list type;

	data spec[] = {
		{'s', _str},
		{'c', _char},
		{'%', _mod},
	};

	va_start(type, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (format[i] == '%' && format[i + 1] != '\0')
			{
				if (format[i + 1] == spec[j].s)
				{
					spec[j].f(type);
					i += 2;
					if (format[i] == 's')
					{
						len = spec[j].f(type);
					}
					num += len;
				}
			}
		}
		ch(format[i]);
	}
	va_end(type);
	return (num);
}
