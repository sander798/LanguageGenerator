#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 This program generates a requested number of names using a pattern of vowels, consonants, prefixes, and suffixes to simulate a fantasy language naming scheme.
 */

char vowels[][3] = {{"a"}, {"e"}, {"i"}, {"o"}, {"u"}, {"y"}, {"aa"}, {"ee"}, {"ii"},
                    {"oo"}, {"uu"}, {"yy"}, {"ae"}, {"ui"}, {"ie"}, {"ei"}, {"oi"}, {"io"},
                    {"eo"}, {"oe"}, {"ey"}, {"ye"}, {"ou"}, {"uo"}, {"ue"}, {"eu"}};

const int TOTAL_VOWELS = sizeof(vowels) / sizeof(vowels[0]);

char consonants[][3] = {{"q"}, {"w"}, {"r"}, {"t"}, {"y"}, {"p"}, {"s"}, {"d"}, {"f"},
                        {"g"}, {"h"}, {"j"}, {"k"}, {"l"}, {"z"}, {"x"}, {"c"}, {"v"},
                        {"b"}, {"n"}, {"m"}, {"qu"}, {"ll"}};

const int TOTAL_CONSONANTS = sizeof(consonants) / sizeof(consonants[0]);

char prefixes[6][11] = {{""}};
const int TOTAL_PREFIXES = sizeof(prefixes) / sizeof(prefixes[0]);

char suffixes[6][11] = {{""}};
const int TOTAL_SUFFIXES = sizeof(suffixes) / sizeof(suffixes[0]);

const int CONSONANT_RATIO = 4;

int main(int argc, char* argv[]){

    int nameCount = 10; //Default to 10 names

    //Get the number of desired names to be generated
    if (argc > 1) {
        nameCount = (int)strtoimax(argv[1], NULL, 10);

        //Bounds checking
        nameCount < 0 ? nameCount = 0 : 0;
        nameCount > 128 ? nameCount = 128 : 0;
    }

    long seed = time(NULL);

    //Get the random seed if provided
    if (argc > 2) {
        seed = strtoimax(argv[2], NULL, 10);
    }

    srand(seed);

    //Choose vowels
    int vowelCount = 4 + (rand() % (TOTAL_VOWELS - 3));
    char *pChosenVowels[vowelCount];

    //printf("Vowels:\n");

    for (int i = 0; i < vowelCount; i += 1) {
        pChosenVowels[i] = vowels[rand() % TOTAL_VOWELS];
        //printf("%s\n", pChosenVowels[i]);
    }

    //Choose consonants
    int consonantCount = 10 + (rand() % (TOTAL_CONSONANTS - 9));
    char *pChosenConsonants[consonantCount];

    //printf("Consonants:\n");

    for (int i = 0; i < consonantCount; i += 1) {
        pChosenConsonants[i] = consonants[rand() % TOTAL_CONSONANTS];
        //printf("%s\n", pChosenConsonants[i]);
    }

    //Create prefixes
    int size = 0;

    for (int i = 0; i < TOTAL_PREFIXES; i += 1) {
        //Get a random prefix size of at least 1
        size = 1 + (rand() % (sizeof(prefixes[0]) / 2));

        //Get an element from either vowels or consonants for each prefix element
        for (int c = 0; c < size; c += 1) {
            if (rand() % CONSONANT_RATIO){
                strcat(prefixes[i], pChosenConsonants[rand() % consonantCount]);
                continue;
            }

            strcat(prefixes[i], pChosenVowels[rand() % vowelCount]);
        }

        //printf("%s\n", prefixes[i]);
    }

    //Create suffixes
    for (int i = 0; i < TOTAL_SUFFIXES; i += 1) {
        //Get a random suffix size of at least 1
        size = 1 + (rand() % (sizeof(suffixes[0]) / 2));

        //Get an element from either vowels or consonants for each suffix element
        for (int c = 0; c < size; c += 1) {
            if (rand() % CONSONANT_RATIO){
                strcat(suffixes[i], pChosenConsonants[rand() % consonantCount]);
                continue;
            }

            strcat(suffixes[i], pChosenVowels[rand() % vowelCount]);
        }

        //printf("%s\n", suffixes[i]);
    }

    //Output names
    for (int i = 0; i < nameCount; i += 1) {
        char name[32] = "";

        //Add a prefix
        if (rand() % 2) {
            strcat(name, prefixes[rand() % TOTAL_PREFIXES]);
        }

        //Add elements
        size = 1 + (rand() % 5);

        for (int c = 0; c < size; c += 1) {
            if (rand() % CONSONANT_RATIO){
                strcat(name, pChosenConsonants[rand() % consonantCount]);
                continue;
            }

            strcat(name, pChosenVowels[rand() % vowelCount]);
        }

        //Add a suffix
        if (rand() % 2) {
            strcat(name, suffixes[rand() % TOTAL_SUFFIXES]);
        }

        printf("%s\n", name);
    }

    return 0;
}
