#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

struct territory
{
    char * territoryName;
    char * listEthnicities; // A list of the ethnical groups who inhabit this area
    int * populationNumber;
    float * productivity; // Measured by time in hours for one indiviual. Counted by the mean of the population.
    // For example, if the productivity is 30h, it means that one worker produces the equivalent of 30 workers in the lowest
    // productivity possible. Lowest productivity possible is 1 worker = 1h
    float * income; // productivity multiplied populationNumber. Measured in gold coins.

    // Include squalor and other things in the future
};

struct faction
{
    char * nameFaction;
    char * mainEthnicity;
    int * amountArmies;
};

struct army
{
    // Include different types of units in the future
    char * commandersName;
    float * commandersPoints; // Goes from 0 to 500.
    int * numbers; // Can be 1000, 5000, 10000...
    float * training; // Goes from 1 to 5.
    int * attack; // Each successful attack removes numbers from the enemy's army
    int * defense; // Attack minus defense equals a successful attack
    int * strength; // numbers multiplied by training plus commandersPoints. An army of 1000 with 5 training and a commander with
    //500 points equals an army with 5500 men, but no training and no commandersPoints.

    // Maybe substitute strength and training by attack, defense etc? To make it easier?
};

//typedef struct army ankarasRighteous;
//typedef struct army konstaninosFaithful;
struct army ankarasRighteous;
struct army konstaninosFaithful;

int getRandValueFromRange(int * pminimumParam, int * pmaximumParam);

int main(void){
    // Testing methods..
    /*
    struct army ankarasRighteous = {
        "Mehmed II";
    };
    */

    /*
    int aNumber;
    srand(time(NULL));
    aNumber = rand() % 10;
    printf("%d\n", aNumber);
    //printf("%d\n", rand());
    //getRandValueFromRange(14, 20);
    */
    /*
    Since I think rand() % number can't include number, but maximum number - 1, then add 1 to compensate:
    https://www.codegrepper.com/code-examples/whatever/how+to+generate+random+number+between+1+and+10+in+c
    */

    // This is a test:
    int aNumber;
    srand(time(NULL));
    aNumber = rand() % 10;
    printf("%d\n", aNumber);

    int minimumAttack = 14;
    int * pminimumAttack = & minimumAttack;
    int maximumAttack = 25;
    int * pmaximumAttack = & maximumAttack;

    printf("%d\n", getRandValueFromRange(pminimumAttack, pmaximumAttack));

    return 0;
};

int getRandValueFromRange(int * pminimumParam, int * pmaximumParam)
//int getRandValueFromRange(void)
{
    int tempNumber;

    srand(time(NULL));
    //tempNumber = rand() % (maximum - minimum);
    *pmaximumParam+=1; // Adding 1 to compensate. See article above
    tempNumber = rand() % (*pmaximumParam - *pminimumParam);
    return *pminimumParam + tempNumber;
    //return tempNumber;
    //return minimum + tempNumber;

    /*
    for (i = minimum; i < maximum; i++)
    {
        printf("%d\n", rand());
    };
    */
};


// Later create a method that creates armies




