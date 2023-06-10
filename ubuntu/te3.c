#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main()
{
	int a = get_int("enter the number ");
	if (a % 2 != 0)
	{
		int m;
		m = pow(a + 1, 0.5);
		float x  =  pow(a-1,0.5) ; 
		if( x   - floor(x) > 0 )
		{
		    print("no")
		}
		if (pow(m, 2) + 1 != a)
		{
			m = pow(a + 1, 0.5);
			printf("%i \n %f", 2 * m, pow(m, 2) + 1);
		}
		else 
		{
			m = pow(a - 1, 0.5);
			printf("%i \n %f", 2 * m, pow(m, 2) - 1);
		}
	}
	else
	{
		int m;
		m = a / 2;
		printf("%f \n %f", pow(m, 2) - 1, pow(m, 2) + 1);
	}
}
