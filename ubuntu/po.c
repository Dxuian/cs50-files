#include<stdio.h>
int main()
{
    FILE* f = fopen("t.txt", "r");
    FILE* f1 = fopen("out.txt" , "w");
    char d ; 
    for(int i = 0 ; i < 10; i++)
    {
        fread(&d, 1,1, f);
        fwrite(&d ,1,1 , f1);
        
    }

    while( fread(&d, 1,1, f))
    {
        
        fwrite(&d ,1,1 , f1);
        
    }
}