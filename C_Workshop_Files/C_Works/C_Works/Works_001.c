/*
*	Electronics Workshop
 *	Works_001.c
*	Intro to C Programming (2)
 *	Conditional Statements
*	C has similar conditional statement like python, but has different syntax.
 */
#include <stdio.h>

int main_1(void)
{
	int a, b, c;
	
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
	if (b)
		printf("b is true \n");

	/*
	*	!= is similar to not(b == 0) in python.
	*/
	if (b != 0)
		printf("b is true\n");

	/*
	*	if-else statement is similar to python.
	 */
	if (a == b)
		printf("a is equal to b\n");
	else
		printf("a and b is different\n");

	/*
	*	For if-else if-else statement, unlike python where it was if-elif-else, we
	 *	fully state if-else if-else.
	*/
	if (a == b)
		printf("a is equal to b\n");
	else if (a < b)
		printf("a is less than b\n");
	else
		printf(" a is bigger than b\n");

	/*
	*	For nested if statement, be sure to indent properly!
	 *	Also, for nested loop, be sure to separate with bracket!
	*/
	if (a)
	{
		if (a > 0) /* If if statement is lowest level and is single statement, bracket can be omitted. */
			printf("a is positive\n");
		else if (a == 0)
			printf("a is zero\n");
		else if (a < 0)
			printf("a is negative\n");
	}
	else if (b)
	{
		if (b > 0)
			printf("b is positive\n");
		else if (b == 0)
			printf("b is zero\n");
		else if (b < 0)
			printf("b is negative\n");
	}

	/*
	*	Another type of conditional statement, the switch-case.
	 */
	switch (a) /* Expression inside switch must be integer or enumerated type. */
	{
		case 0:
			printf("a is 0\n");
			break;
		case 1:
			printf("a is 1\n");
			break;
		case 2:
			printf("a is 2\n"); /* If break keyword is omitted, switch will move to next case. */
		case 3:
			printf("a is 3\n");
			break;
		
		default:
			printf("a is not a number\n");
			break; /* If default is at the bottom, break is unecessary. */
	}

	/*
	*	C supports conditional operator, ? and :
	 *	exp1 ? exp2 : exp3;
	*	exp1 is evaluated, such as b == 2
	 *	exp2 is evaluated if exp1 returns true
	*	exp3 is evaluated if exp1 returns false
	 */
	c = 10;
	printf("Before expression: %d\n", c);
	a == b ? c++ : c--;
	printf("After expression: %d\n", c);

	getchar();
	return 0;
}
