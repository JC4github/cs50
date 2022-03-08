#include <cs50.h>
#include <stdio.h>

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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank - 1] = i return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int i = 0;
    int j = 0;
    for (int k = 0; k < candidate_count - 1; k++)
    {
        i = ranks[k];
        j = ranks[k + 1];
        preferences[i][j] += 1;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (prefereces[i][j] != 0)
            {
                if (prefereces[i][j] > prefereces[j][i])
                {
                    int exists = 0;                            // entry doest exist yet
                    for (int var = 0; var < pair_count; var++) // finding if entry already exists
                    {
                        if (i == pairs[var].winner && j == [pairs[var].loser])
                        {
                            exists = 1; // entry already exist
                        }
                    }
                    if (exists == 0)
                    {
                        pairs[k].winner = i;
                        pairs[k].loser = j;
                        k++;
                        pair_count++;
                    }
                }
                else if (prefereces[i][j] < prefereces[j][i])
                {
                    int exists = 0;                            // entry doest exist yet
                    for (int var = 0; var < pair_count; var++) // finding if entry already exists
                    {
                        if (j == pairs[var].winner && i == [pairs[var].loser])
                        {
                            exists = 1; // entry already exist
                        }
                    }
                    if (exists == 0)
                    {
                        pairs[k].winner = j;
                        pairs[k].loser = i;
                        k++;
                        pair_count++;
                    }
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int strength = 0;
    int ignore = 0;
    int index = 0;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = ignore; j < pair_count; j++) // gets highest difference loop
        {
            if (strength < (pairs[j].winner - pairs[j].loser))
            {
                strength = (pairs[j].winner - pairs[j].loser)
                index = j; //index of heightest value
            }
        }
        ignore++; //ignore values that are sorted
        int holdingWinner = pairs[i].winner;
        int holdingLoser = pairs[i].loser;

        pairs[i].winner = pairs[index].winner;
        pairs[i].loser = pairs[index].loser;

        pairs[index].winner = holdingWinner;
        pairs[index].loser = holdingLoser;
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int stillZero = candidate_count;
    int seen_j_values[pair_count];
    for (int i = 0; i < pair_count; i++) //loop through pairs array
    {
        int match = 0;
        for (int j = 0, j < pair_count; j++) //loop through seen j values
        {
            if (pairs[i].loser == seen_j_values[j])
            {
                match = 1; //seen it
            }
        }
        if (match != 1) //if not seen, add it into array
        {
            seen_j_values[i] = pairs[i].loser;
            stillZero--;
        }
        if (stillZero > 1)
        {
            locked[pairs[i].winner][pairs[i].loser] = 1;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}