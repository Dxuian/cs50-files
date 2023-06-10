#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j]) == 0)
        {
            ranks[rank] = j;
            printf("\n %i", rank);
            rank++;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // int preferences[MAX][MAX];
    //  candidates[i]
    int array[candidate_count];
    int air[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        array[i] = i;
    }

    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (array[i] < array[j])
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    /*// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;*/
    //// preferences[i][j] is number of voters who prefer i over j
    // int preferences[MAX][MAX];
    /*typedef struct
    {
        int winner;
        int loser;
    }
    pair;*/
    int alp = 0;
    pair_count = 0;
    int addn = 0;
    bool p = 0;

    for (int j = 0; j < candidate_count; j++)
    {

        for (int i = 0; i < candidate_count; i++)
        {

            for (int a = 0; a < candidate_count; a++)
            {
                if (pairs[a].winner == i && pairs[a].loser == j)
                {
                    p = 0;
                    break;
                }
                else if (pairs[a].winner == j && pairs[a].loser == i)
                {
                    p = 0;
                    break;
                }
                else if (a == candidate_count - 1)
                {
                    p = 1;
                    break;
                }
            }
            if (preferences[i][j] > preferences[j][i] && p == 1)
            {
                pairs[alp].winner = i;
                pairs[alp].loser = j;
                pair_count++;
                alp++;
            }
            else if (preferences[i][j] < preferences[j][i] && p == 1)
            {
                pairs[alp].winner = j;
                pairs[alp].loser = i;
                pair_count++;
                alp++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    /*Complete the sort_pairs function.
The function should sort the pairs array in decreasing order of strength of victory, where strength o
f victory is defined to be the number of voters who prefer the preferred candidate. If multiple pairs have the same strength of victory, you may assume that the order does not matter.*/
    pair a[pair_count];
    for (int sa = 0; sa < pair_count; sa++)
    {
        a[sa] = pairs[sa];
    }

    for (int d = 0; d < pair_count - 1; d++)
    {
        for (int c = 0; c < pair_count - 1; c++)
        {
            if (pairs[c].winner - pairs[c].loser > pairs[c + 1].winner - pairs[c + 1].loser)
            {
                pairs[c].winner = a[c + 1].winner;
                pairs[c].loser = a[c + 1].loser;

                pairs[c + 1].winner = a[c].winner;
                pairs[c + 1].loser = a[c].loser;

                a[c].winner = pairs[c].winner;
                a[c].loser = pairs[c].loser;

                a[c + 1].winner = pairs[c + 1].winner;
                a[c + 1].loser = pairs[c + 1].loser;
            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO

    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            for (int a = 0; a < pair_count; a++)
            {
                for (int k = 0; k < candidate_count; k++)
                {
                    if (locked[i][j] == true && locked[j][k] == true && locked[k][i] == true)
                    {
                        locked[i][j] = false;
                        break;
                    }

                    if (i == pairs[a].winner && j == pairs[a].loser)
                    {
                        locked[i][j] = true;
                    }
                    else if (j == pairs[a].winner && i == pairs[a].loser)
                    {
                        locked[j][i] = true;
                    }
                    else if (a == pair_count - 1)
                    {
                        for (int kd = 0; kd < candidate_count; kd++)
                        {
                            if (locked[i][j] == true && locked[j][kd] == true && locked[kd][i] == true)
                            {
                                locked[i][j] = false;
                                break;
                            }

                            if (i == pairs[a].winner && j == pairs[a].loser)
                            {
                                locked[i][j] = true;
                            }
                            else if (j == pairs[a].winner && i == pairs[a].loser)
                            {
                                locked[j][i] = true;
                            }
                        }
                    }
                }

                if (a == pair_count)
                {
                    for (int k = 0; k < candidate_count; k++)
                    {
                        if (locked[i][j] == true && locked[j][k] == true && locked[k][i] == true)
                        {
                            locked[i][j] = false;
                        }
                    }
                }
            }
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int array[candidate_count];
    for (int a = 0; a < candidate_count; a++)
    {
        array[a] = 0;
    }
    /* for (int i = 0; i < candidate_count; i++)
     {
         for (int j = 0; j < candidate_count; j++)
         {
             if (locked[i][j] == true)
             {
                 array[j]++;
             }
         }
     }*/
    for (int v = 0; v < candidate_count; v++)
    {
        for (int h = 0; h < candidate_count; h++)
        {
            if (locked[v][h] == true)
            {
                array[v]++;
            }
        }
    }
    int winner;
    for (int b = 0; b < candidate_count; b++)
    {
        for (int a = 0; a < candidate_count; a++)
        {
            if (array[b] > array[a])
            {
                winner = b;
            }
            else if (array[b] < array[a])
            {
                winner = a;
            }
            else if (array[b] == array[a] && b != a)
            {
                winner = b;
            }
        }
    }

    printf("%s\n", candidates[winner]);
    for (int c = 0; c < candidate_count; c++)
    {
        if (array[c] == array[winner] && c != winner)
        {
            printf("%s\n", candidates[c]);
        }
    }
    return;
}
