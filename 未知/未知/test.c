#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
int main() {
    char a[50][50] = { "######",
                    "#& # ",
                    "# ## #",
                    "#  # #",
                    "##   #",
                    "######",
    };
    int i, x, y, p, q;
    char ch;
    x = 1, y = 1, p = 1, q = 5;
    for (i = 0; i <= 5; i++) {
        puts(a[i]);
    }
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 's')
        {

            a[x][y] = ' ';
            x++;
            a[x][y] = '&';
        }
        if (ch == 'w')
        {

            if (a[x - 1][y] != '#') {
                a[x][y] = ' ';
                x--;
                a[x][y] = '&';
            }
        }
    }
    return 0;
}