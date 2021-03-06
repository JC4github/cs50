import csv
import sys


def main():

    # TODO: Check for command-line usage
    while True:
        if len(sys.argv) == 3:
            break
        else:
            print("Usage: CSV file, Text file")
            break

    # TODO: Read database file into a variable
    dna = []
    keys = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            dna.append(row)

    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        for row in reader:
            keys = row
            break

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as text:
        sequence = text.read()

    # TODO: Find longest match of each STR in DNA sequence
    profile = {}
    for key in keys:
        profile[key] = 0

    for key in range(1, len(keys)):
        match = longest_match(sequence, keys[key])
        profile[keys[key]] = match

    # TODO: Check database for matching profiles
    found = 0
    for person in dna:
        count = 0
        for key in person:
            if person[key] == str(profile[key]):
                count += 1
                if count == len(keys) - 1:
                    print(person['name'])
                    found = 1

    if found == 0:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
