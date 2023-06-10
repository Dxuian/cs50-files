#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
   string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1>score2)
    {
        printf("Player 1 wins! ");
    }
    else if (score1==score2)
    {
        printf("tie");
    }
    else  
    {
        printf("Player 2 wins!");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    char alpha = 'A';
    int changer = (int)alpha ;
    int x  = 0 ;
    int score = 0 ;
    int small = changer + 32 ;
    int i = strlen(word);
    while ( x < i)
    {
        if( (int)word[x]< 90 && (int)word[x]>=65)
        {
            while ( (int)word[x] != changer)
            {
                changer++;
            }
            int y = changer - 65 ;
            score += POINTS[y] ;
            changer = 65;
            y = 0;
            x++;
            
        }
        else if ( (int)word[x] < 65 || (int)word[x] > 122 || (90<(int)word[x] &&  (int)word[x]<97 ) )
        {
            x++ ; 
            score += 0 ;
        }
        else if  ( (int)word[x] >= 97 && (int)word[x] <= 122)
        {
            while ( (int)word[x] != small)
            {
                small++;
            }
            int k = small - 97;
            score += POINTS[k];
            small  = 97 ;
            k = 0 ;
            x++ ;
        }
        
    }
     return score ;
}