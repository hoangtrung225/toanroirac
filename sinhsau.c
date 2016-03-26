#include <stdio.h>
#include <string.h>
int generate_s(char* buffer_st, char* buffer_ptr, char* set_ptr, int s_len);
int checker = 0;
char input_string[100];

int main(void)
{
	//make a place holder
	printf("input the length of array\n");
	int strlen;
	scanf("%d", &strlen);
	char buffer[strlen+1];
	
	//get input set
	char set[100];
	printf("input a predefine set\n");
	scanf("%s",set);
	
	//get input string
	printf("input predefine string for comparition");
	scanf("%s", input_string);
	
	//print out string
	printf("here come the motherfucking combination:\n");
	generate_s(buffer, buffer, set, strlen);
	return 0;
}
	
	 
int generate_s(char* buffer_st, char* buffer_ptr, char* set_ptr, int s_len)
{
	if(set_ptr == NULL || buffer_ptr == NULL)
	{
		return -1;
	}
	 
	if( s_len == 0 )
	{
		buffer_ptr[0] = '\0';
		printf("%s\n", buffer_st);
		if (checker == 1)
		{
			printf("____________________\n");
			checker = 0;
		}
		if (strcmp(buffer_st, input_string) == 0) checker = 1;
		return 0;
	}
	else 
	{
		int set_len = strlen(set_ptr);
		for(int i = 0; i < set_len; i++)
		{
			buffer_ptr[0] = set_ptr[i];
			generate_s(buffer_st, buffer_ptr+1, set_ptr, s_len-1);
		}
	}
}
