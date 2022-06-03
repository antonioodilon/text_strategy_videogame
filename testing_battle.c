#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

#include "base_functions.h"

// Making our program aware of the functions:
struct battleOverStruct battle(struct army * pplayersArmy, struct army * penemyArmy);

// Creating our variables of type struct:
struct army enemyArmy;
struct army createdPlayerArmy;

struct army * penemyArmy = &enemyArmy;
struct army * pcreatedPlayerArmy = &createdPlayerArmy;

struct territory enemyTerritory;
struct territory playerTerritory;

struct territory * penemyTerritory = &enemyTerritory;
struct territory * pplayerTerritory = &playerTerritory;

struct battleOverStruct battleOverMainProgram;
struct battleOverStruct * pbattleOverMainProgram = &battleOverMainProgram;

struct battleOverStruct aftermathBattleStruct;
struct battleOverStruct * paftermathBattleStruct = &aftermathBattleStruct;

// The main() function:
int main(void){
    // Testing the battle() function:
    enemyTerritory.coinInCoffers = 2000;
    enemyTerritory.costRecruitSoldiers = 2;

    char enemyCommandersName[] = "Enemy Commander";
    enemyArmy.pcommandersName = enemyCommandersName;
    int initEnNumbers = 2700;
    enemyArmy.numbers = initEnNumbers;
    enemyArmy.commandersPoints = 200;
    enemyArmy.experience = 5;
    enemyArmy.strength = (enemyArmy.numbers * (enemyArmy.experience/2)) + enemyArmy.commandersPoints;
    enemyArmy.baggageTrain = 1000;

    int enMinAttack = 20;
    int enMaxAttack = 25;
    int enMinDefense = 10;
    int enMaxDefense = 15;

    enemyArmy.minAttack = enMinAttack;
    enemyArmy.maxAttack = enMaxAttack;
    enemyArmy.minDefense = enMinDefense;
    enemyArmy.maxDefense = enMaxDefense;

    playerTerritory.coinInCoffers = 2000;
    playerTerritory.costRecruitSoldiers = 2;

    char playersCommandersName[] = "Player Commander";
    createdPlayerArmy.pcommandersName = playersCommandersName;
    int initPlayNumbers = 2500;
    createdPlayerArmy.numbers = initPlayNumbers;
    createdPlayerArmy.commandersPoints = 400;
    createdPlayerArmy.experience = 3;
    createdPlayerArmy.strength = (createdPlayerArmy.numbers * (createdPlayerArmy.experience/2)) + createdPlayerArmy.commandersPoints;
    createdPlayerArmy.baggageTrain = 1400;

    int playMinAttack = 22;
    int playMaxAttack = 27;
    int playMinDefense = 13;
    int playMaxDefense = 18;

    createdPlayerArmy.minAttack= playMinAttack;
    createdPlayerArmy.maxAttack = playMaxAttack;
    createdPlayerArmy.minDefense = playMinDefense;
    createdPlayerArmy.maxDefense = playMaxDefense;

    printf("The player's army has %d soldiers\n", pcreatedPlayerArmy->numbers);
    printf("The player's army has %.2f experience\n", pcreatedPlayerArmy->experience);
    printf("The player's commander has %d commander's points\n", pcreatedPlayerArmy->commandersPoints);
    printf("The strength of the player's army is %.2f\n", pcreatedPlayerArmy->strength);

    printf("\n=======================\n");

    printf("\nThe enemy's army has %d soldiers\n", penemyArmy->numbers);
    printf("The enemy's army has %.2f experience\n", penemyArmy->experience);
    printf("The enemy's commander has %d commander's points\n", penemyArmy->commandersPoints);
    printf("The strength of the enemy's army is %.2f\n", penemyArmy->strength);
    printf("\n=======================\n");

    battleOverMainProgram = battle(pcreatedPlayerArmy, penemyArmy);

    printf("\n\nThe player's army has %d soldiers\n", pcreatedPlayerArmy->numbers);
    printf("The player's army has %.2f experience\n", pcreatedPlayerArmy->experience);
    printf("The player's commander has %d commander's points\n", pcreatedPlayerArmy->commandersPoints);
    printf("The strength of the player's army is %.2f\n", pcreatedPlayerArmy->strength);

    printf("\n=======================\n");

    printf("\nThe enemy's army has %d soldiers\n", penemyArmy->numbers);
    printf("The enemy's army has %.2f experience\n", penemyArmy->experience);
    printf("The enemy's commander has %d commander's points\n", penemyArmy->commandersPoints);
    printf("The strength of the enemy's army is %.2f\n", penemyArmy->strength);
    printf("\n=======================\n");

    return 0;
};
