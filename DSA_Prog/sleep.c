#include <stdio.h>
#include <windows.h>

int main()
{
    int s, m, h, d = 1000;
    printf("\nRESET TIME : ");
    scanf("%d%d%d", &h, &m, &s);
    printf("\n");

    while (1)
    {
        s++;
        if (s > 59)
        {
            m++;
            s = 0;
        }
        else if (m > 59)
        {
            h++;
            m = 0;
        }
        else if (h > 12)
        {
            h = 1;
        }

        printf("%d:%d:%d", h, m, s);
        Sleep(d);
        system("cls");
    }

    return 0;
}
