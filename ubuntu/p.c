#include <cs50.h>
#include <stdio.h>

int getposint(string randomnumberdaala);
int main (void)
{
    int number = getposint("Height: "); 
   
    for (int height = 0; height < number; height++) 
    {
        for (int dots = number - height - 2; dots >= 0; dots--)
        {
            printf(" "); 
        }
        for (int row = 0; row <= height; row++)
        {
            printf("#");
        }
        printf("\n");
    }
}


int pluswalano(string randomnumberdaala) 
{
    int number; 
    //cuz ek baar krna hai 
    do 
    {
        number = get_int("%s", randomnumberdaala);
    }
    while (number < 1 || number > 8);  
    return number; 
}
