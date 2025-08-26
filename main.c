#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 This program generates a requested number of names using a pattern of vowels, consonants, prefixes, and suffixes to simulate a fantasy language naming scheme.
 */

char vowels[][2] = {{"a"}, {"e"}, {"i"}, {"o"}, {"u"}, {"y"}, {"aa"}, {"ee"}, {"ii"},
                    {"oo"}, {"uu"}, {"yy"}, {"ae"}, {"ui"}, {"ie"}, {"ei"}, {"oi"}, {"io"},
                    {"eo"}, {"oe"}, {"ey"}, {"ye"}};

char consonants[][2] = {{"q"}, {"w"}, {"r"}, {"t"}, {"y"}, {"p"}, {"s"}, {"d"}, {"f"},
                        {"g"}, {"h"}, {"j"}, {"k"}, {"l"}, {"z"}, {"x"}, {"c"}, {"v"},
                        {"b"}, {"n"}, {"m"}, {"qu"}, {"ll"}};

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

    printf("%d\n", nameCount);

    long seed = time(NULL);

    //Get the random seed if provided
    if (argc > 2) {
        seed = strtoimax(argv[2], NULL, 10);
    }

    srand(seed);

    //printf("%ld\n", seed);

    return 0;
}
