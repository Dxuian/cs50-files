#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    int k = 0;
    while (k < candidate_count)
    {
        if (strcmp(name, candidates[k].name) == 0)
        {
            candidates[k].votes++;
            return true;
        }
        k++;
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int array[candidate_count];
    int parry[candidate_count];
    int p = 0;
    int po = 1;
    int dq = 0;
    int k = 0;
    while (k < candidate_count)
    {
        array[k] = candidates[k].votes;
        parry[k] = candidates[k].votes;
        k++;
    }
    // correct this is

    while (p < candidate_count)
    {
        while (po < candidate_count)
        {
            if (array[p] > array[po])
            {
                array[p] = parry[po];
                array[po] = parry[p];
                parry[p] = array[p];
                parry[po] = array[po];
                po++;
            }
            else if (array[p] == array[po])
            {
                po++;
            }
            else
            {
                po++;
            }
        }
        p++;
        po = p + 1;
    }

    int b = 0;
    while (b < candidate_count)
    {
        if (candidates[b].votes == array[(sizeof(array) / sizeof(array[0])) - 1])
        {
            printf("%s\n", candidates[b].name);
        }

        b++;
    }
    return;
}
