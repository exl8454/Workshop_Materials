/*
 * C-Works002.c
 *
 *  Created on: Jul 7, 2017
 *      Author: CShin
 *
 *  More about printf()
 *  Complies with C89 standard
 */

#include <stdio.h>

int main(void)
{
	float a = 1.234;
	int b = 10;

	/* printf is powerful function when it comes to printing to screen in C */
	printf("Hello World!\n");

	/* Format specifiers can have different formats. You can limit floating point display, indentation, etc...*/
	printf("A float is %.1f\n", a); /* This will only print 1 decimal point */

	/* Format specifier works as
	 * %[flags][width][.precision][length]specifier
	 * [flags] defines left justify, right justify, paddings, etc.
	 * [width] defines number of padding to do on format.
	 * [.precision] is the number of decimal points to be printed on screen
	 * [length] is used to define output type, such as int or long
	 */

	/* Here, we will pad zero(0) on float, with minimum width of 5 and decimal point of 1 */
	printf("A float is %05.1f\n", a);

	/* You can also pad integer */
	printf("A int is %010d\n", b);

	/* If you skip flag specifier, it will automatically indent */
	printf("A int is %10d\n", b);

	/* You can also justify to left */
	printf("A int is %-10d\n", b);

	return 0;
}
