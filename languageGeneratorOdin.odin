package langGen

import "core:fmt"
import "core:os"
import "core:strconv"
import "core:math/rand"
import "base:runtime"

@rodata
vowels := []string{
    "a", "e", "i", "o", "u", "y", "aa", "ee", "ii", "oo", "uu",
    "yy", "ae", "ui", "ie", "ei", "oi", "io", "eo", "oe", "ey",
    "ye", "ou", "uo", "ue", "eu"
}

@rodata
consonants := []string {
    "q", "w", "r", "t", "y", "p", "s", "d", "f", "g", "h", "j",
    "k", "l", "z", "x", "c", "v", "b", "n", "m", "qu", "ll"
}

Word :: struct {
    word: [5]^string,
    size: int,
}

consonantRatio :: 4

main :: proc() {

    nameCount: int = 10 //Default to 10 names

    //Get the number of desired names if specified
    if len(os.args) > 1 {
        nameCount = strconv.atoi(os.args[1])

        if nameCount < 0 do nameCount = 0
        if nameCount > 128 do nameCount = 128
    }

    //Seed the random number generator if given a seed
    if len(os.args) > 2 {
        rand.reset(u64(strconv.atoi(os.args[2])))
    }

    //Choose vowels
    chosenVowels: [50]^string
    vowelCount := 4 + rand.int_max(len(vowels) - 3)

    for i in 0..<vowelCount {
        chosenVowels[i] = &vowels[rand.int_max(len(vowels))]
    }

    //Choose consonants
    chosenConsonants: [50]^string
    consonantCount := 10 + rand.int_max(len(consonants) - 9)

    for i in 0..<consonantCount {
        chosenConsonants[i] = &consonants[rand.int_max(len(consonants))]
    }

    //Create prefixes
    prefixes := [6]Word{}

    size := 0

    for i in 0..<6 {
        size = 1 + rand.int_max(5)
        prefixes[i].size = size

        //Get an element from either vowels or consonants for each prefix element
        for c in 0..<size {
            if rand.int_max(consonantRatio) > 0 {
                prefixes[i].word[c] = &consonants[rand.int_max(len(consonants))]
                continue
            }

            prefixes[i].word[c] = &vowels[rand.int_max(len(vowels))]
        }
    }

    //Create suffixes
    suffixes := [6]Word{}

    for i in 0..<6 {
        size = 1 + rand.int_max(5)
        suffixes[i].size = size

        //Get an element from either vowels or consonants for each suffix element
        for c in 0..<size {
            if rand.int_max(consonantRatio) > 0 {
                suffixes[i].word[c] = &consonants[rand.int_max(len(consonants))]
                continue
            }

            suffixes[i].word[c] = &vowels[rand.int_max(len(vowels))]
        }
    }

    randomNum: int

    //Output names
    for i in 0..<nameCount {

        //Add a prefix
        if rand.int_max(2) == 1 {
            randomNum = rand.int_max(len(prefixes))

            for c in 0..<prefixes[randomNum].size do fmt.print(prefixes[randomNum].word[c]^)
        }

        //Add elements
        size = 1 + rand.int_max(5)

        for c in 0..<size {
            if rand.int_max(consonantRatio) > 0 {
                fmt.print(consonants[rand.int_max(len(consonants))])
                continue
            }

            fmt.print(vowels[rand.int_max(len(vowels))])
        }

        //Add a suffix
        if rand.int_max(2) == 1 {
            randomNum = rand.int_max(len(suffixes))

            for c in 0..<suffixes[randomNum].size do fmt.print(suffixes[randomNum].word[c]^)
        }

        fmt.println();
    }
}
