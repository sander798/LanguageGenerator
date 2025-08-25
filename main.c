#include <inttypes.h>
#include <stdio.h>

/*
 This program generates a requested number of names using a pattern of vowels, consonants, prefixes, and suffixes to simulate a fantasy language naming scheme.
 */

int main(int argc, char* argv[]){

    int nameCount = 10; //Default to 10 names

    //Get the number of desired names to be generated
    if (argc > 1) {
        nameCount = strtoimax(argv[1], NULL, 10);

        //Bounds checking
        nameCount < 0 ? nameCount = 0 : 0;
        nameCount > 128 ? nameCount = 128 : 0;
    }

    printf("%d", nameCount);

    return 0;
}
