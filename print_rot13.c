#include "holberton.h"
#include <stdio.h>
/**
  * print_rot13 - encodes a string into rot13.
  * @r: string to convert
  * Return: s econdes
  */
int print_rot13(va_list R)
{
	int j, i, count = 0;
	char *r;

	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	r = va_arg(R, char *);
	for (j = 0; r[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (r[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}