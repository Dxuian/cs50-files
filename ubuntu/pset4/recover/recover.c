#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
int faltu(FILE* c);
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover filename");
        return 1;
    }
    else
    {

        FILE *s = fopen(argv[1], "r");
        if (s == NULL)
        {
            printf("the file couldnt be opened/file wasnt found");
            return 1;
        }
        typedef uint8_t byte;
        byte d[512];
        int a = 0;
        char buf[10];
        bool file = false;
        bool cond =  false ;
        FILE* c = NULL;
        while (fread(&d, 512, 1, s))
        {
           if(   (d[0] == 0xff && d[1] == 0xd8 && d[2] == 0xff) &&   ((d[3]& 0xf0) == 0xe0 ) )
           {
               cond= true ;
                goto place;
           }
           else
           {
               cond= false;
               goto place ;
           }
           place:
           if( cond==true && file==false )
           {
                sprintf(buf, "%.3i.jpg", a);
                c = fopen(buf, "a+");
                file = true;
                fwrite(&d, 512, 1, c);
           }
           else if(cond==false && file==true)
           {
               fwrite(&d, 512, 1, c);
           }
           else if(cond==true && file==true     )
           {
                fclose(c);
                a++;
                sprintf(buf, "%.3i.jpg", a);
                c = fopen(buf, "a+");
                file = true;
                fwrite(&d, 512, 1, c);
           }
        }
        fclose(s);
    }
}

