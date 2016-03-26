#include <stdio.h>
#include <string.h>
int generate_s(char* buffer_st, char* buffer_ptr, char* set_ptr, int s_len);
int giun_num = 0;
int uncount_len;

int main(void)
{
	//make a place holder
	printf("input the length of array\n");
	int strlen;
	scanf("%d", &strlen);
	char buffer[strlen+1];
	char set[] = "01";
	
	printf("input uncount paddle\n");
	scanf("%d", &uncount_len);
	
	printf("here come the motherfucking combination:\n");
	generate_s(buffer, buffer, set, strlen);
	printf("%d\n", giun_num);
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
		printf("%s", buffer_st);
		s_len = strlen(buffer_st);
		for(int i = 0; i < s_len; i++)
		{
			if(buffer_st[i] == '0')
			{
				
					int flag = 0;
					for(int j = 0; j < uncount_len; j++)
					{
						if( i + uncount_len > s_len)
						{
							flag = 1;
							break;
						}
						if(buffer_st[i+j] == '1')
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						printf("*\n");
						return 0;
					}
					else if (flag == 1)
					{
						continue;
					}
			}
		}
		giun_num++;
		printf("\n");
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
