/*
*	Electronics Workshop
 *	Works_000.c
*	Intro to C Programming (1)
 *	First step into C Programming
*	C programming has no built-in function for printing to screen
 *	hence why the stdio.h is included. stdio stands for standard
*	input/output.
 */
#include <stdio.h>

int main_0(void)
{
	/*
	*	To comply with C89 standard, all variables must be declared at the
	*	beginning of the code. Assining value to variables can come after.
	*	C has 7 different data types;
	*	char, short, int, long, float, double, and long double
	*/
	char c = 'c'; /* char is the smallest size among 7 types. */
	short s = 32767; /* short has size of 2 bytes. */
	int i = 2147483647; /* int has size of 4 bytes, but it starts from 2 bytes. */
	long l = 2147483647; /* long has size of 4 bytes. */
	float f = 0.123456f; /* float has size of 4 bytes, and has precision up to 6 decimal places. */
	double d = 3.14; /* double has size of 8 bytes, and has precision up to 15 decimal places. */
	long double ld = 6.28; /* long double has size of 10 bytes, and has precision up to 19 decimal places. */

	/*
	*	printf(const char* format, ...); allows us to print a
	*	string to screen, with given format. C does not have default
	*	option for changing line, so we must include newline delimeter
	*	\n at the end to change line.
	*/
	printf("Hello World!"); /* This will not change line */
	printf(" This is C!\n"); /* This will change line */
	printf("\n");

	/*
	*	To print a value, use format delimiter, then specify the variable to print
	*/
	printf("For char, use %%c: %c\n", c);
	printf("For short, use %%d: %d\n", s);
	printf("For int, use %%d: %d\n", i);
	printf("For long, use %%d: %d\n", l);
	printf("For float, use %%f: %f\n", f);
	printf("For double, use %%f: %f\n", d);
	printf("For long double, use %%f: %f\n", ld);
	printf("\n");

	/*
	*	To format a value, use %[flags][width][.precision][length]specifier
	*	width and .precision comes handy when it comes to organzing numbers
	*/
	printf("Width of 20, %20d\n", i);
	printf("Width of 20, %20f\n", f);
	printf("To left justify, %-20d<-\n", i);
	printf("To left justify, %-20f<-\n", f);
	printf("Left pad with zeros, %020d<-\n", i);
	printf("Left pad with zeros, %020f<-\n", f);

	/*
	*	When running an application, a console will popup and will close
	*	instantly, because it returns 0 at the end immediately. To prevent
	*	console from closing immediately, we add getchar(); function at the
	*	end. This will prevent window from closing until we type enter.
	*/
	getchar();
	return 0;
}
