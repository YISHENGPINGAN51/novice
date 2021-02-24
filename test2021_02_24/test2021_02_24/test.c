#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>

int main()
{
	int* p1 = NULL;
	int* p2 = NULL;
	int* p = NULL;
	int a = 0;
	int b = 0;
	printf("integer numbers : ");
	scanf("%d%d", &a, &b);
	p1 = &a;    
	p2 = &b;
	if (a < b)
	{
		p = p1; 
		p1 = p2; 
		p2 = p;
	}
	printf("a = %d, b = %d\n", a, b);
	printf("%d, %d\n", *p1, *p2);
	return 0;
}

//#include <stdio.h>
//
//int main()
//{
//    int a = 100;
//    int b = 10;
//    int* pointer_1 = NULL;
//    int* pointer_2 = NULL;
//    pointer_1 = &a;
//    pointer_2 = &b;
//    printf("a = % d, b = % d\n", a, b);
//    printf(" * pointer_1 = % d, *pointer_2 =% d\n", *pointer_1, *pointer_2);
//    return 0;
//}

