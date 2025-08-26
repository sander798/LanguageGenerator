#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 This program generates a requested number of names using a pattern of vowels, consonants, prefixes, and suffixes to simulate a fantasy language naming scheme.
 */

char vowels[][3] = {{"a"}, {"e"}, {"i"}, {"o"}, {"u"}, {"y"}, {"aa"}, {"ee"}, {"ii"},
                    {"oo"}, {"uu"}, {"yy"}, {"ae"}, {"ui"}, {"ie"}, {"ei"}, {"oi"}, {"io"},
                    {"eo"}, {"oe"}, {"ey"}, {"ye"}};

int VOWEL_NUM = sizeof(vowels) / sizeof(vowels[0]);

char consonants[][3] = {{"q"}, {"w"}, {"r"}, {"t"}, {"y"}, {"p"}, {"s"}, {"d"}, {"f"},
                        {"g"}, {"h"}, {"j"}, {"k"}, {"l"}, {"z"}, {"x"}, {"c"}, {"v"},
                        {"b"}, {"n"}, {"m"}, {"qu"}, {"ll"}};

int CONSONANT_NUM = sizeof(consonants) / sizeof(consonants[0]);

char prefixes[6][6] = {{""}};
char suffixes[6][6] = {{""}};

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
    int vowelCount = 4 + rand() % 6;
    char *pChosenVowels[vowelCount];

    printf("Vowels:\n");

    for (int i = 0; i < vowelCount; i += 1) {
        pChosenVowels[i] = vowels[rand() % VOWEL_NUM];
        printf("%s\n", pChosenVowels[i]);
    }

    //Choose consonants
    int consonantCount = 10 + rand() % 10;
    char *pChosenConsonants[consonantCount];

    printf("Consonants:\n");

    for (int i = 0; i < consonantCount; i += 1) {
        pChosenConsonants[i] = consonants[rand() % CONSONANT_NUM];
        printf("%s\n", pChosenConsonants[i]);
    }

    //Create prefixes


    //Create suffixes


    //Output

    return 0;
}
