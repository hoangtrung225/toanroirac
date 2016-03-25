#include <stdio.h>
#include <math.h>

int main(void)
{
	//khai bao va nhan
	int inputval;
	scanf("%d", &inputval);
	
	//tinh can bac hai
	int rootsquare = (int) sqrt(inputval);
	
	//loop
	for(int i = 2; i < rootsquare; i++)
	{
		if( (inputval % i) == 0)
		{
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	return 0;
}
