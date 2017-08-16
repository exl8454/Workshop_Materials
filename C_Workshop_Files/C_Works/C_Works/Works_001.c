/*
*	Electronics Workshop
 *	Works_001.c
*	Intro to C Programming (2)
 *	Conditional Statements
*	C has similar conditional statement like python, but has different syntax.
 */
#include <stdio.h>

int main(void)
{
	int a, b;
	
	/*
	*	In C, there is no variable type for boolean. Zero(0) is always false, while
	 *	everything other than zero is true.
	*/
	a = 0; /* Setting variable a as false by assigning value to zero. */

	/*
	*	Usually, conditional statements requires brackets({}) inbetween, but if it
	 *	is a single line execution, brackets can be omitted.
	*/
	if (a == 0)
		printf("a is false\n");

	if (!a) /* In python we used not() to negate the statement. In C, we use ! */
		printf("a is false\n");

	b = 1;
	/*
	*	!= is similar to not(b == 0) in python.
	*/
	if (b != 0)
		printf("b is true\n");


	getchar();
	return 0;
}
