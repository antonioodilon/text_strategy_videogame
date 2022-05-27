#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

//struct army ankarasRighteous;
//struct army konstaninosFaithful;

// Structs:
struct territory
{
    char * pterritoryName;
    char * plistEthnicities; // A list of the ethnical groups who inhabit this area
    //int * ppopulationNumber;
    int populationNumber;
    float productivity;
    int income;
    int coinInCoffers; // The money is all stored in the capital for better protection. This is why it's not in the faction struct
    // A little workaround I came up with hahaha
    int costRecruitSoldiers; // 1 soldier = 2 gold coins
    //float * pproductivity; // Measured by time in hours for one indiviual. Counted by the mean of the population.
    // For example, if the productivity is 30h, it means that one worker produces the equivalent of 30 workers in the lowest
    // productivity possible. Lowest productivity possible is 1 worker = 1h
    //float * pincome; // productivity multiplied populationNumber. Measured in gold coins.

    // Include squalor, money in the bank (to be looted by the invading army) and other things in the future?
};

struct battleOverStruct
{
    //_Bool * battleOver;
    //_Bool * battleWon;
    //_Bool battleOver;
    //_Bool battleWon;
    int battleOver;
    int battleWon;
};

struct faction
{
    char * pnameFaction;
    char * pmainEthnicity;
    int * pamountArmies;
    char * listTerrories; // A list of the territories the faction controls
};

struct army
{
    // Include different types of units in the future
    char * pcommandersName;
    int commandersPoints; // Goes from 0 to 500.
    int numbers; // Can be 1000, 5000, 10000...
    int extraPoints; // Can later be allocated to get more commandersPoints or numbers
    float experience; // Goes from 1 to 10. Every 1 point in experience is 1 more point in maxattack, minattack, mindefense and maxdefense
    int minAttack; // Each successful attack removes numbers from the enemy's army
    int maxAttack;
    int minDefense; // Attack minus defense equals a successful attack
    int maxDefense;
    float strength; // Strength is calculated as such:
    int baggageTrain;
};
