#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("elbitsystems.elbit", "rb");
    unsigned char byte, x, y, print_code;
    while (fread(&byte, 1, 1, fp) != 0)
    {
        switch (byte)
        {
        case 0x3F:
            fread(&x, 1, 1, fp);
            break;
        case 0x40:
            fread(&y, 1, 1, fp);
            break;
        case 0x24:
            fread(&print_code, 1, 1, fp);
            if (print_code == 1)
            {
                gotoxy(x, y);
                printf(",");
            }
            if (print_code == 2)
            {
                gotoxy(x, y);
                printf("%%");
            }
            if (print_code == 4)
            {
                gotoxy(x, y);
                printf(",,");
            }
            if (print_code == 16)
            {
                gotoxy(x, y);
                printf("#");
            }
            if (print_code == 32)
            {
                gotoxy(x, y);
                printf("(");
            }
            if (print_code == 64)
            {
                gotoxy(x, y);
                printf("/");
            }
            if (print_code == 128)
            {
                gotoxy(x, y);
                printf("*");
            }
            break;
        default:
            break;
        }
    }
    fclose(fp);
    printf("\n");
    return 0;
}