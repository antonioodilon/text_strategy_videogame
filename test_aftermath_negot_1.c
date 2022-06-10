#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

#include "base_functions.h"

// Creating our variables of type struct:
struct army enemyArmy;
struct army createdPlayerArmy;

struct army * penemyArmy = &enemyArmy;
struct army * pcreatedPlayerArmy = &createdPlayerArmy;

struct territory enemyTerritory;
struct territory playerTerritory;

struct territory * penemyTerritory = &enemyTerritory;
struct territory * pplayerTerritory = &playerTerritory;

struct battleOverStruct aftermathBattleStruct;
struct battleOverStruct * paftermathBattleStruct = &aftermathBattleStruct;

// The main() function:
int main(void){

    enemyTerritory.coinInCoffers = 2000;
    enemyTerritory.costRecruitSoldiers = 2;

    char enemyCommandersName[] = "Enemy Commander";
    enemyArmy.pcommandersName = enemyCommandersName;
    int initEnNumbers = 2700;
    enemyArmy.numbers = 1500;
    enemyArmy.commandersPoints = 200;
    enemyArmy.experience = 5;
    enemyArmy.strength = (enemyArmy.numbers * (enemyArmy.experience/2)) + enemyArmy.commandersPoints;
    enemyArmy.baggageTrain = 1000;

    playerTerritory.coinInCoffers = 2000;
    playerTerritory.costRecruitSoldiers = 2;

    char playersCommandersName[] = "Player Commander";
    createdPlayerArmy.pcommandersName = playersCommandersName;
    int initPlayNumbers = 2500;
    createdPlayerArmy.numbers = 2000;
    createdPlayerArmy.commandersPoints = 400;
    createdPlayerArmy.experience = 3;
    createdPlayerArmy.strength = (createdPlayerArmy.numbers * (createdPlayerArmy.experience/2)) + createdPlayerArmy.commandersPoints;
    createdPlayerArmy.baggageTrain = 1400;

    printf("The player's army has %d soldiers\n", pcreatedPlayerArmy->numbers);
    printf("The player's army has %.2f experience\n", pcreatedPlayerArmy->experience);
    printf("The player's commander has %d commander's points\n", pcreatedPlayerArmy->commandersPoints);
    printf("The strength of the player's army is %.2f\n", pcreatedPlayerArmy->strength);
    printf("The amount of gold coins in your capital's coffers are %d\n", pplayerTerritory->coinInCoffers);

    printf("\n=======================\n");

    printf("\nThe enemy's army has %d soldiers\n", penemyArmy->numbers);
    printf("The enemy's army has %.2f experience\n", penemyArmy->experience);
    printf("The enemy's commander has %d commander's points\n", penemyArmy->commandersPoints);
    printf("The strength of the enemy's army is %.2f\n", penemyArmy->strength);
    printf("\n=======================\n");

    paftermathBattleStruct->battleOver = 1;
    paftermathBattleStruct->battleWon = 1;

    aftermathBattle(paftermathBattleStruct, pcreatedPlayerArmy, penemyArmy, pplayerTerritory, penemyTerritory, initPlayNumbers, initEnNumbers);

    printf("\n\nThe player's army has %d soldiers\n", pcreatedPlayerArmy->numbers);
    printf("The player's army has %.2f experience\n", pcreatedPlayerArmy->experience);
    printf("The player's commander has %d commander's points\n", pcreatedPlayerArmy->commandersPoints);
    printf("The strength of the player's army is %.2f\n", pcreatedPlayerArmy->strength);
    printf("The amount of gold coins in your capital's coffers are %d\n", pplayerTerritory->coinInCoffers);

    printf("\n=======================\n");

    printf("\nThe enemy's army has %d soldiers\n", penemyArmy->numbers);
    printf("The enemy's army has %.2f experience\n", penemyArmy->experience);
    printf("The enemy's commander has %d commander's points\n", penemyArmy->commandersPoints);
    printf("The strength of the enemy's army is %.2f\n", penemyArmy->strength);
    printf("\n=======================\n");

    return 0;
};
