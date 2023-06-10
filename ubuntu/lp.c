#include<stdio.h>
int main ()
{
    FILE *f = fopen("cs50.txt","r+");
    char* c ="heres to making the world a better place \0" ;
    fwrite(&c , 1 ,43 , f);
    fprintf(f, "here  to making the world a better place ");
    fseek(f , 15 , SEEK_SET);
    fprintf(f , "not");
    char* s  = "hallalueja\0";
    fwrite(&c ,1,10 , f );
    fclose(f);
}