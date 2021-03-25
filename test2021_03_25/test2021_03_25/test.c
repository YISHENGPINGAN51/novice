#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//
//
//int func(char* s, char a, int n)
//{
//	int j;
//	*s = a; j = n;
//	while (*s < s[j]) j--;
//	return j;
//}
//int main()
//{
//	char c[6];
//	int i;
//	for (i = 1; i <= 5; i++) *(c + 1) = 'A' + i + 1;
//	printf("%d\n", func(c, 'E', 5));
//	return 0;
//}

//int fun(char* s)
//{
//	char* p = s;
//	while (*p) p++;
//	return (p - s);
//}
//int main()
//{
//	char* a = "abcdef";
//	printf("%d\n", fun(a));
//	return 0;
//}

//int sub(char* a, int t1, int t2)
//{
//    char ch;
//    while (t1 < t2) {
//        ch = *(a + t1); *(a + t1) = *(a + t2); *(a + t2) = ch;
//        t1++; t2--;
//    }
//}
//int main()
//{
//    char s[12];
//    int i;
//    for (i = 0; i < 12; i++) s[i] = 'A' + i + 32;
//    sub(s, 7, 11);
//    for (i = 0; i < 12; i++) printf("%c", s[i]);
//    printf("\n");
//    return 0;
//}

int sub(char* a, char b)
{
    while (*(a++) != '\0');
    while (*(a - 1) < b)
        *(a--) = *(a - 1);
    *(a--) = b;
}
int main()
{
    char s[] = "97531", c;
    c = getchar();
    sub(s, c); puts(s);
    return 0;
}