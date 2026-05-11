#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

// candidate structure
typedef struct
{
    string name;
    int votes;
}
candidate;

// array of candidates
candidate candidates[MAX];

// number of candidates
int candidate_count;

// prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // check command-line arguments
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }

    // candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // set candidate names and votes
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // number of voters
    int voter_count = get_int("Number of voters: ");

    // voting
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // check vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // print winner
    print_winner();
}

// update vote totals
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// print winner of election
void print_winner(void)
{
    int max = 0;

    // find highest votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }

    // print winner(s)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}