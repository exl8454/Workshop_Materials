/*
*	Electronics Workshop
 *	Works_002.c
*	Intro to C Programming (3)
 *	Loop Statements
*/
#include <stdio.h>

int main(void)
{
	int i;

	/* 
	*	To create a for statement...
	 *	for(initial condition; terminate condition; increment)
	*	{}
	 *	C does not restrict what type of for loop you create; that is, you can use anything other than
	*	integer. For simplicity and example purpose, we will use integer as condition.
	 */
	for (i = 0; i < 10; i++)
	{
		printf("i is %5d\n", i);
	}
	printf("i is %5d\n", i);
	printf("\n");

	/*
	*	To create a while loop...
	 *	while(condition)
	*	{}
	 *	while loop will continue to evaluate as long as condition is true
	*/
	while (i > 0)
	{
		printf("i is %5d\n", i);
		i--;
	}
	printf("i is %5d\n", i);
	printf("\n");

	/*
	*	To create a do-while loop...
	 *	do
	*	{}
	 *	while(condition);
	*	difference between while loop and do-while loop is that do-while loop will evaluate the code at least
	 *	once, while while loop will skip the code if condition is not met.
	*/
	do
	{
		printf("i is %5d\n", i);
		i++;
	} while (i < 9);
	printf("i is %5d\n", i);

	/*
	*	There are various ways to create infinite loop, with either for loop or while loop
	 */
	/* Don't run this code however
	for (;;)
	{
	}

	while(1)
	{
	}

	do
	{
	}
	while(1);
	*/


	getchar();
	return 0;
}