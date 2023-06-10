#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <cs50.h>

int main()
{
     int candidate_count = 3;
    int preferences[3][3];
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0 ;
        }
    }
    int ranks[] = {2, 0, 1};
   
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            //preferences[ranks[i]][j]++;
            if(ranks[i]>ranks[j])
            {
                   preferences[ranks[i]][j]++;
            }
    
            
        }
    }
}
  