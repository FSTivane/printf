#include "main.h"

/****####################### PRINT UNSIGNED NUMBER ##################*****/
/**
 * print_unsigned - prints unsigned number
 * @types: list of argumets
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision
 * @size: size specification
 * Return: quantity of chars
 */
int print_unsigned(va_list types, char buffer[], int flags,
		int width, precision, int size)
{
	int i = BUF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;

	}

	i++;

	return (write_undsgnd(0, i, buffer, flags, width, precision, size));
}

/***################### PRINT UNSIGNED NUMBER IN OCTAL ################***/
/**
 * print_octal - prints unsigned number in octal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: specification of precision
 * @size: size
 * Return:Number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags, int width,
			int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}

/***############# PRINT UNSIGNED NUMBER IN HEXADECIMAL ###############***/
/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * @types: lista of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: specification of size
 * @size: size specifier
 * Return:Number of chars printed
*/
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
				int precision, int size));
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
					width, precision, size));
}

/***###########PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ###########***/
/**
 * print_hexa_upper - prints unsigned number in upper hexadecimal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags: claculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
				int precision, size));
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
				'X', width, precision, size));
}

/***################ PRINT HEXX NUM IN LOWER OR UPPER ###################***/
/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @types: list of arguments
 * @map_to: arrayof values to map the number to
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @flag_ch: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specification
 * Return: quant of chars
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
