#include<stdio.h>
#include<string.h>

#define PRINTF_ARRAY(array, length)									\
do {																\
		int	__i;													\
		printf("[%s,%d]: %s = {", __FUNCTION__, __LINE__, #array);	\
		for(__i = 0; __i < (length); __i++) {						\
			printf("%c", (array)[__i]);								\
		}															\
		printf("}\n");												\
} while(0)

#define PRINTF_AND_GET_LENGTH(array, length)	\
do {											\
		int __length;							\
		__length = strlen(array);				\
		(length) = __length - 1;				\
} while(0)

#define PRINTF_RESULT(fmt, args...)			\
do {										\
		printf(fmt, ##args);				\
		printf("\n");						\
} while(0)

char input[100];

int main()
{
	int length;
	int result[4]={0,0,0,0};
	
	fgets(input, 100, stdin);
	//PRINTF_ARRAY(input, 100);
	PRINTF_AND_GET_LENGTH(input, length);

	while(length > 0) {
		if('A' <= input[length - 1] && input[length - 1] <= 'Z') {
			result[0] ++;
		} else if ('a' <= input[length - 1] && input[length - 1] <= 'z') {
			result[1] ++;
		} else if ('0' <= input[length - 1] && input[length - 1] <= '9') {
			result[2] ++;
		} else if (' ' == input[length - 1]) {
			result[3] ++;
		}

		length--;
	}
	PRINTF_RESULT("%d %d %d %d",result[0],result[1], result[2], result[3]);
	return 0;
}
