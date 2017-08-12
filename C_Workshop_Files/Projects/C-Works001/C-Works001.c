/*
 * C-Works001.c
 *
 *  Created on: Jul 7, 2017
 *      Author: CShin
 *
 *  Starting with first code
 *  Complies with C89 standard
 */

/* Unlike Python, you import(include) all dependencies before code blocks.
 * stdio.h is Standard Input/Output header file. It has basic functions such as printf()
 */
#include <stdio.h>

int main(void)
{
	/* C89 standard speicifes you must declare all variables first before using any.*/
	char a = 'A';
	int b = 10;
	float c = 20.3;
	double d = 30.3;

	/* printf means formatted print to the screen.
	 * To print a value from a variable, you will have to include specifiers, followed by
	 * variables.
	 * printf function does not include newline delimieter, so you must provide one at the end*/
	printf("Hello World!\n");

	/* For char, use %c specifier to print char on screen */
	printf("A char is %c\n", a);

	/* For int, use %d specifier to print integer(decimal) on screen */
	printf("A char is %c, an int is %d\n", a, b);

	/* For float, use %f specifier to print float on screen */
	printf("A char is %c, and int is %d, a float is %f\n", a, b, c);

	/* For double, use %f specifier to print double on screen */
	printf("A char is %c, and int is %d, a float is %f, a double is %f\n", a, b, c, d);

	/* Long story short on float vs double, double can store more bits compare to float, hence float comes out as 20.2999 */

	/* Think of 1/3. When we do it by hand, we know it is 0.3 and recursive. However, since computers cannot store recursive
	 * values, it will end at some point. Think of 0.3. In binary, 3 is 0011, which means 3 is 0011. 30 is 0001 1110,
	 * so and forth. since float can only store up to 32 bits, it will eventually end after 32 bits. in IEEE floating point,
	 * 00111110100110011001100110011010 represents 0.3 But since recursive cannot be represented by computer bits, this will
	 * output 0.300000011920928955078125 as a result, which leads to floating point error. This occures on double as well, but
	 * since double can allocate more bits compare to float, error due to conversion will be much less.
	 */

	return 0;
}
