#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

#include "base_structs.h"

#define MAXCHARS 50
#define MAXTOTALPOINTS 1500
#define MAXCOMMPOINTS 500
#define MINCOMMPOINTS 0

// Functions:
int getRandValueFromRange(int * pminimumParam, int * pmaximumParam)
{
    int tempNumber;

    if (*pminimumParam >= *pmaximumParam)
    {
        *pminimumParam = *pmaximumParam - 2;
    };

    srand(time(NULL));
    tempNumber = rand() % (*pmaximumParam - *pminimumParam);
    return *pminimumParam + tempNumber; // This is the random value generated
};

float calculatesArmyStrength(int inputArmyNumbers, float inputArmyXp, int inputArmyCommPts)
{
    return (inputArmyNumbers * (inputArmyXp/2)) + inputArmyCommPts;
};

struct army createsPlayerArmy(void)
{
    struct army inputPlayersArmy;
    int continueNumber;
    char inputCommandersName[MAXCHARS];
    int totalPoints = MAXTOTALPOINTS;
    int inputMaxAttack = 20;
    int inputMinAttack = 15;
    int inputMaxDefense = 20;
    int inputMinDefense = 15;
    inputPlayersArmy.experience = 1.0;

    printf("Now that you have chosen your faction, it is time for you to create your army!\n");
    printf("Choose a name for your commander: ");
    scanf(" ");
    gets(inputCommandersName);
    inputPlayersArmy.pcommandersName = (char*)calloc(strlen(inputCommandersName), sizeof(char));
    strcpy(inputPlayersArmy.pcommandersName, inputCommandersName);

    printf("\n=====================\n");

    printf("Now it's time to allocate points for your army. You have a total of %d points to distribute across your your"
    " commander's points and the amount of troops you have.\n", totalPoints);
    printf("\n=====================\n");
    printf("Your commander can have up to 500 points, while there is no limit to the amount of troops you can have.\n");

    printf("Press any number to continue...");
    scanf("%d", &continueNumber);

    _Bool acceptCommPoints = false;
    while (acceptCommPoints == false)
    {
        printf("How many points will your commander have? ");
        scanf("%d", &inputPlayersArmy.commandersPoints);
        if (inputPlayersArmy.commandersPoints > MAXCOMMPOINTS || inputPlayersArmy.commandersPoints < MINCOMMPOINTS)
        {
            printf("Your commander can only have a maximum of %d points, and cannot have less than %d.\n",
            MAXCOMMPOINTS, MINCOMMPOINTS);
        } else
        {
            while (true)
            {
                int doubleCheckComm;
                printf("Do you accept the value of %d points that your commander will have?\nType 1 for 'Yes' and"
                " 0 for 'No': ", inputPlayersArmy.commandersPoints);
                scanf("%d", &doubleCheckComm);

                if (doubleCheckComm == 1)
                {
                    acceptCommPoints = true;
                    break;
                } else if (doubleCheckComm == 0)
                {
                    printf("Then feel free to type in another value.\n");
                    break;
                } else
                {
                    printf("Please type in a valid answer.\n");
                };
            };
        };

    };

    totalPoints -= inputPlayersArmy.commandersPoints;

    printf("Your commander has %d points, and now you have %d points left to recruit soldiers. Remember: 1 point = 1 soldier.\n",
    inputPlayersArmy.commandersPoints, totalPoints);

    printf("Press any number to continue...");
    scanf("%d", &continueNumber);

    printf("\n=====================\n");

    _Bool acceptNumSoldiers = false;
    while (acceptNumSoldiers == false)
    {
        printf("How many soldiers would you like to recruit? ");
        scanf("%d", &inputPlayersArmy.numbers);
        if (inputPlayersArmy.numbers > totalPoints || inputPlayersArmy.numbers < 0)
        {
            printf("You cannot recruit more than %d or less than 0 soldiers. Please insert a valid number\n", totalPoints);
            printf("\n=====================\n");
            continue;
        } else if (inputPlayersArmy.numbers < totalPoints)
        {
            printf("Are you sure you would like to recruit less soldiers than the amount of remaining points you have?\n");
            printf("If so, then you will end up with %d soldiers, and the rest of the points will be allocated to your extra"
            " points that you can later distribute.\n",
            inputPlayersArmy.numbers);
            printf("\n=====================\n");

            while (true)
            {
                int doubleCheck = 1;
                printf("Press 1 to agree or 0 to make a new choice: ");
                scanf("%d", &doubleCheck);
                if (doubleCheck == 1)
                {
                    printf("You have thus recruited %d soldiers\n", inputPlayersArmy.numbers);
                    acceptNumSoldiers = true;
                    break;
                } else if (doubleCheck == 0)
                {
                    break;
                } else
                {
                    printf("Please insert a valid answer.\n");
                };
            };
        } else
        {
            while (true)
            {
                int doubleCheck2;
                printf("Are you sure you would like to recruit %d soldiers? Press 1 for 'Yes' and 0 for 'No': ",
                inputPlayersArmy.numbers);
                scanf("%d", &doubleCheck2);
                if (doubleCheck2 == 1)
                {
                    printf("You have thus recruited %d soldiers\n", inputPlayersArmy.numbers);
                    acceptNumSoldiers = true;
                    break;
                } else if (doubleCheck2 == 0)
                {
                    break;
                    //goto VALIDANSWER;
                } else
                {
                    printf("Please press a valid answer.\n");
                };
            };
        };
    };

    printf("\n=====================\n");

    inputPlayersArmy.extraPoints = totalPoints - inputPlayersArmy.numbers;

    printf("Now it's time to calculate your army's attack and defense.\n");

    printf("Press any number to continue...");
    scanf("%d", &continueNumber);
    printf("\n=====================\n");

    printf("The way the game works is thus: you have to roll a dice in order to get the value of "
    "your army's maximum attack and the value of its maximum defense.\n");
    printf("The maximum possible value you can get when rolling the dice for the maximum attack and "
    "the maximum defense is 20, while the minimum possible value is 15.\n");

    printf("Press any number to continue...");
    scanf("%d", &continueNumber);
    printf("\n=====================\n");

    printf("The minimum attack and defense, on the other hand, are always 5 less than their "
    "respective maximum counterparts.\n");

    printf("Press any number to continue...");
    scanf("%d", &continueNumber);
    printf("\n=====================\n");

    printf("For example: if you got the values 20 and 18 for maximum attack and maximum defense "
    "respectively, then your minimum attack and minimum defense will be 15 and 13, respectively.\n");
    printf("So during a battle, when you roll the dice to attack an enemy, the maximum value for your "
    "attack can be 20, while the minimum can be 15.\nAnd when defending, the maximum will be 18, and the"
    " minimum 13.\n");

    printf("Press any number to continue...");
    scanf("%d", &continueNumber);
    printf("\n=====================\n");


    printf("After each successful battle, your soldiers are awarded 1 point in experience, which in turn"
    " increases your army's defense and attack.\n");
    printf("Press any number to continue...");
    scanf("%d", &continueNumber);
    printf("\n=====================\n");

    printf("Now let's roll a dice for your attack and another one for your defense. You have a maximum "
    "of 4 attempts.\n");

    printf("Press any number to continue...");
    scanf("%d", &continueNumber);
    printf("\n=====================\n");

    printf("Press any number to roll a dice for your maximum attack value: ");
    scanf("%d", &continueNumber);

    _Bool playerAcceptsAttack = false;
    for (int i = 1; i < 5; i++)
    {
        if (playerAcceptsAttack == true)
        {
           break;
        };

        printf("Attempt number %d!\n", i);

        if (i == 4)
        {
            printf("Warning! This is your last attempt!\nPress any number to continue: ");
            scanf("%d", &continueNumber);
        };

        int accept;
        inputPlayersArmy.maxAttack = getRandValueFromRange(&inputMinAttack, &inputMaxAttack);
        printf("You've rolled a dice and got the value of %d for the attack\n",
         inputPlayersArmy.maxAttack);

        if (i == 4)
        {
            printf("Since this is your last attempt, you can't change this value anymore.\n");
            printf("Press any number to exit: ");
            scanf("%d", &continueNumber);
            continue;
        };

        while (true)
        {
            printf("Do you accept this value? Press 1 for 'Yes' and 0 for 'No': ");
            scanf("%d", &accept);
            if (accept == 1)
            {
                printf("Your army's maximum attack is then set to %d\n", inputPlayersArmy.maxAttack);
                playerAcceptsAttack = true;
                break;
            } else if (accept == 0)
            {
                printf("Ok, let's try again\n");
                printf("\n=====================\n");
                break;
            } else
            {
                printf("Please type in a valid answer.\n");
            };
        };
    };
    printf("\n=====================\n");

    inputPlayersArmy.minAttack = inputPlayersArmy.maxAttack - 5;
    printf("Since your minimum attack is 5 less than your maximum attack, then the minimum attack "
    "value is set to %d\n", inputPlayersArmy.minAttack);

    printf("\n=====================\n");

    printf("Now you are going to roll a dice for your maximum defense.\n");
    printf("Press any number to roll a dice for your maximum defense value: ");
    scanf("%d", &continueNumber);

    _Bool playerAcceptsDef = false;
    for (int i = 1; i < 5; i++)
    {
        if (playerAcceptsDef == true)
        {
            break;
        };

        printf("Attempt number %d!\n", i);

        if (i == 4)
        {
            printf("Warning! This is your last attempt!\nPress any number to continue: ");
            scanf("%d", &continueNumber);
        };

        int accept;
        inputPlayersArmy.maxDefense = getRandValueFromRange(&inputMinDefense, &inputMaxDefense);
        printf("You've rolled a dice and got the value of %d for the defense\n",
         inputPlayersArmy.maxDefense);

        if (i == 4)
        {
            printf("Since this is your last attempt, you can't change this value anymore.\n");
            printf("Press any number to exit: ");
            scanf("%d", &continueNumber);
            continue;
        };

        while (true)
        {
            printf("Do you accept this value? Press 1 for 'Yes' and 0 for 'No': ");
            scanf("%d", &accept);

            if (accept == 1)
            {
                printf("Your army's maximum defense is then set to %d\n", inputPlayersArmy.maxDefense);
                playerAcceptsDef = true;
                break;
            } else if (accept == 0)
            {
                printf("Ok, let's try again\n");
                printf("\n=====================\n");
                break;
            } else
            {
                printf("Please type in a valid answer.\n");
            };
        };
    };

    printf("\n=====================\n");

    inputPlayersArmy.minDefense = inputPlayersArmy.maxDefense - 5;
    printf("Since your minimum defense is 5 less than your maximum defense, then the minimum defense "
    "value is set to %d\n", inputPlayersArmy.minDefense);

    inputPlayersArmy.strength = calculatesArmyStrength(inputPlayersArmy.numbers, inputPlayersArmy.experience,
    inputPlayersArmy.commandersPoints);
    printf("\n=====================\n");

    printf("Your army is ready! Here are the details:\n");
    printf("\n\tYour commander's name is %s\n", inputPlayersArmy.pcommandersName);
    printf("\n\tYour points have been distributed as such:\n\t-> %d Commander's Points\n\t-> %d Soldiers\n\t-> %d Extra points\n",
    inputPlayersArmy.commandersPoints, inputPlayersArmy.numbers, inputPlayersArmy.extraPoints);
    printf("\n\tAttack range: %d - %d\n\tDefense range: %d - %d\n",
    inputPlayersArmy.minAttack, inputPlayersArmy.maxAttack, inputPlayersArmy.minDefense, inputPlayersArmy.maxDefense);
    printf("\n\tSince your army has no combat experience yet, its experience points have been set to %.2f\n", inputPlayersArmy.experience);
    printf("\n\tThe stregth of your army determines its advantage during battles, and it is key to winning them. ");
    printf("Your army's strength is %.2f", inputPlayersArmy.strength);

    return inputPlayersArmy;
};


int resultingDamage(int attack, int defense)
{
    if ((attack - defense) > 0)
    {
        //printf("The resulting damage is %d\n", attack - defense);
        return attack - defense;
    //} else if ((attack - defense) < 0 || attack == defense)
    } else
    {
        //printf("The soldiers' armor have fully blocked the attack! ");
        //printf("The resulting damage is %d\n", 0);
        return 0;
    };
};


//struct battleOverStruct checkBattleOver(int currPlayersNum, int initPlayersNum, int currEnemyNums, int initEnemyNums)
struct battleOverStruct checkBattleOver(int currPlayersNum, int currEnemyNums,
int currPlayersStrength, int initPlayersStrength, int currEnemysStrength, int initEnemysStrength)
{
    //if (currPlayersNum <= initPlayersNum || currEnemyNums <= initEnemyNums)
    //{
    struct battleOverStruct isBattleOver;
    //isBattleOver.battleOver = NULL;
    //isBattleOver.battleWon = NULL;
    int minimumBattleStrength;

    if (initPlayersStrength <= initEnemysStrength)
    {
        minimumBattleStrength = initPlayersStrength/2;
    } else {
        minimumBattleStrength = initEnemysStrength/2;
    };

    // Substitute numbers for strength? Or remove strength? Maybe strength AND numbers play a role?
    //if (currPlayersNum <= 0 || currPlayersStrength <= (initPlayersStrength/2))
    if (currPlayersNum <= 0 || currPlayersStrength <= minimumBattleStrength)
    {
        printf("The battle is over!\n");
        if (currPlayersNum <= 0)
        {
            currPlayersNum = 0;
            printf("However, our soldiers have bravely fought to the last man! True heroes indeed!\n");
        } else
        {
            printf("You have been beaten and your soldiers are routing! ");
            printf("Shameful display!\n");
        };
        isBattleOver.battleOver = 1;
        isBattleOver.battleWon = 0;
        //isBattleOver.battleOver = true;
        //isBattleOver.battleWon = false;
        return isBattleOver;

    } else if (currEnemyNums <= 0 || currEnemysStrength <= minimumBattleStrength)
    {
        printf("The battle is over!\n");
        if (currEnemyNums <= 0)
        {
            currEnemyNums = 0;
            printf("But the enemy isn't as weak as we had initially thought: their soldiers fought"
            " to the last man! Admirable foes indeed!\n");
        } else
        {
            printf("Victory! The enemy runs like the worthless rabid dog it is!\n");
        };
        isBattleOver.battleOver = 1;
        isBattleOver.battleWon = 1;
        //isBattleOver.battleOver = true;
        //isBattleOver.battleWon = true;
        return isBattleOver;

    } else {
        isBattleOver.battleOver = 0;
        isBattleOver.battleWon = 0;
        //isBattleOver.battleOver = false;
        //isBattleOver.battleWon = false;
        return isBattleOver;
    };
    //};
};


// THIS FUNCTION IS JUST A TEST!! DELETE IT AFTERWARDS!
struct battleOverStruct checkBattleOverAlt(int currPlayersNum, int currEnemyNums,
int currPlayersStrength, int initPlayersStrength, int currEnemysStrength, int initEnemysStrength)
{
    //if (currPlayersNum <= initPlayersNum || currEnemyNums <= initEnemyNums)
    //{
    struct battleOverStruct isBattleOver;
    //isBattleOver.battleOver = NULL;
    //isBattleOver.battleWon = NULL;
    int minimumBattleStrength;

    if (initPlayersStrength <= initEnemysStrength)
    {
        minimumBattleStrength = initPlayersStrength*4/5;
    } else {
        minimumBattleStrength = initEnemysStrength*4/5;
    };

    // Substitute numbers for strength? Or remove strength? Maybe strength AND numbers play a role?
    //if (currPlayersNum <= 0 || currPlayersStrength <= (initPlayersStrength/2))
    if (currPlayersNum <= 0 || currPlayersStrength <= minimumBattleStrength)
    {
        printf("The battle is over!\n");
        if (currPlayersNum <= 0)
        {
            currPlayersNum = 0;
            printf("However, our soldiers have bravely fought to the last man! True heroes indeed!\n");
        } else
        {
            printf("You have been beaten and your soldiers are routing! ");
            printf("Shameful display!\n");
        };
        isBattleOver.battleOver = 1;
        isBattleOver.battleWon = 0;
        //isBattleOver.battleOver = true;
        //isBattleOver.battleWon = false;
        return isBattleOver;

    } else if (currEnemyNums <= 0 || currEnemysStrength <= minimumBattleStrength)
    {
        printf("The battle is over!\n");
        if (currEnemyNums <= 0)
        {
            currEnemyNums = 0;
            printf("But the enemy isn't as weak as we had initially thought: their soldiers fought"
            " to the last man! Admirable foes indeed!\n");
        } else
        {
            printf("Victory! The enemy runs like the worthless rabid dog it is!\n");
        };
        isBattleOver.battleOver = 1;
        isBattleOver.battleWon = 1;
        //isBattleOver.battleOver = true;
        //isBattleOver.battleWon = true;
        return isBattleOver;

    } else {
        isBattleOver.battleOver = 0;
        isBattleOver.battleWon = 0;
        //isBattleOver.battleOver = false;
        //isBattleOver.battleWon = false;
        return isBattleOver;
    };
    //};
};

//void battle(struct army * pplayersArmy, struct army * penemyArmy)
//void battle(void)
//_Bool battle(struct army * pplayersArmy, struct army * penemyArmy)
struct battleOverStruct battle(struct army * pplayersArmy, struct army * penemyArmy)
{
    // Every turn the player and the enemy roll a dice to see if part of the army routs based on the
    // commander's points and the experience?
    int continueNumber;
    int startBattle;
    int turnNumber;
    int initialPlayersNumbers = pplayersArmy->numbers;
    int initialEnemysNumbers = penemyArmy->numbers;

    //pplayersArmy->strength = (pplayersArmy->numbers * pplayersArmy->experience) + pplayersArmy->commandersPoints;
    //penemyArmy->strength = (penemyArmy->numbers * penemyArmy->experience) + penemyArmy->commandersPoints;

    float initialPlayersStrength =  pplayersArmy->strength;
    float initialEnemysStrength = penemyArmy->strength;
    //float enemyStrengthLost;
    //float playerStrengthLost;
    struct battleOverStruct battleIsOver;

    printf("A battle is about to start! You have %d soldiers against the enemy's %d soldiers!\n", initialPlayersNumbers, initialEnemysNumbers);
    printf("Your army's strength is %.2f!\nYour enemy's strength is %.2f!\n", initialPlayersStrength, initialEnemysStrength);
    printf("Press any integer number to start the combat: ");
    scanf("%d", &startBattle);

    turnNumber = 0;
    while (true)
    {
        // Use commandersPoints here too eventually?
        int playerValAttack;
        int playerValDefense;
        int enemyValAttack;
        int enemyValDefense;
        //int playerSoldiersRemain;
        //int enemySoldiersRemain;
        int damageAgainstEnemy;
        int damageAgainstPlayer;
        int damAgainstEnComm;
        int damAgainstPlayComm;

        ++turnNumber;
        printf("\n============\n");
        printf("\nStarting turn number %d\n", turnNumber);
        printf("\n============\n");

        printf("Press an integer number to roll the dice for an attack against the enemy: "); // Say that the number is just to continue
        scanf("%d", &continueNumber);
        playerValAttack = getRandValueFromRange(&pplayersArmy->minAttack, &pplayersArmy->maxAttack);
        printf("You roll the dice and your attack is %d!\n", playerValAttack);

        printf("Press any number to continue...");
        scanf("%d", &continueNumber);

        printf("The enemy rolls a dice to defend! ");
        enemyValDefense = getRandValueFromRange(&penemyArmy->minDefense, &penemyArmy->maxDefense);
        printf("Its defense is %d!\n", enemyValDefense);

        printf("Press any number to continue...");
        scanf("%d", &continueNumber);

        //damageAgainstEnemy = resultingDamage(playerValAttack, enemyValDefense)*100;
        damageAgainstEnemy = resultingDamage(playerValAttack, enemyValDefense)*50;
        damAgainstEnComm = resultingDamage(playerValAttack, enemyValDefense);
        if (damageAgainstEnemy > 0)
        {
            /*
            if (damageAgainstEnemy >= penemyArmy->numbers)
            {
                damageAgainstEnemy = penemyArmy->numbers;
                penemyArmy->numbers = 0;
            } else
            {
                (penemyArmy->numbers) -= damageAgainstEnemy;
            };*/
        printf("The resulting damage against the worthless enemy is %d!\n", damageAgainstEnemy);
            //(penemyArmy->numbers) -= damageAgainstEnemy;
            // OVERHAUL THIS!! STRE
        (penemyArmy->numbers) -= damageAgainstEnemy;
        (penemyArmy->commandersPoints) -= damAgainstEnComm;
            //enemyStrengthLost = damageAgainstEnemy/penemyArmy->experience - damAgainstEnComm;
        (penemyArmy->strength) = (penemyArmy->numbers * (penemyArmy->experience/2)) + penemyArmy->commandersPoints;
        //(penemyArmy->strength) -= enemyStrengthLost;
            //(penemyArmy->strength) = (penemyArmy->numbers * penemyArmy->experience) + penemyArmy->commandersPoints;
        } else
        {
            printf("Curses! The enemy soldiers' armor have fully blocked the attack! ");
            printf("The resulting damage is %d\n", damageAgainstEnemy);
        };

        if (penemyArmy->numbers <= 0)
        {
            penemyArmy->numbers = 0;
        };

        printf("With this attack the enemy has lost %d soldiers\n", damageAgainstEnemy);
        printf("The enemy now has %d soldiers left\n", (penemyArmy->numbers));
        printf("The damage against the commander has been %d\n", damAgainstEnComm);
        printf("The enemy now has %d commander's points\n", penemyArmy->commandersPoints);
        printf("The enemy's strength is now %.2f\n", penemyArmy->strength);

        battleIsOver = checkBattleOver(pplayersArmy->numbers, penemyArmy->numbers,
        pplayersArmy->strength, initialPlayersStrength, penemyArmy->strength, initialEnemysStrength);

        // THIS IS JUST A TEST! The real battleIsOver is above!!!
        // battleIsOver = checkBattleOverAlt(pplayersArmy->numbers, penemyArmy->numbers,
        // pplayersArmy->strength, initialPlayersStrength, penemyArmy->strength, initialEnemysStrength);
        if (battleIsOver.battleOver == 1)
        {
            return battleIsOver;
        };

        printf("Press any number to continue...");
        scanf("%d", &continueNumber);

        enemyValAttack = getRandValueFromRange(&penemyArmy->minAttack, &penemyArmy->maxAttack);
        printf("The enemy attacks you with %d attack points!\n", enemyValAttack);

        printf("Press any number to continue...");
        scanf("%d", &continueNumber);

        printf("Press an integer number to roll a dice and defend yourself! ");
        scanf("%d", &continueNumber);
        playerValDefense = getRandValueFromRange(&pplayersArmy->minDefense, &pplayersArmy->maxDefense);
        printf("You've rolled a dice and you defend with %d points!\n", playerValDefense);

        printf("Press any number to continue...");
        scanf("%d", &continueNumber);

        //damageAgainstPlayer = resultingDamage(enemyValAttack, playerValDefense)*100;
        damageAgainstPlayer = resultingDamage(enemyValAttack, playerValDefense)*50;
        damAgainstPlayComm = resultingDamage(enemyValAttack, playerValDefense);
        if (damageAgainstPlayer > 0)
        {
            printf("Damnation! The despicable enemy has caused a damage of %d to our soldiers!!\n",
             damageAgainstPlayer);
            (pplayersArmy->numbers) -= damageAgainstPlayer;
            (pplayersArmy->commandersPoints) -= damAgainstPlayComm;
            (pplayersArmy->strength) = (pplayersArmy->numbers * (pplayersArmy->experience/2)) + pplayersArmy->commandersPoints;
        } else
        {
            printf("Praise our blacksmiths! Our soldiers' strong armor have fully blocked the attack! ");
            printf("The resulting damage against us is %d\n", damageAgainstPlayer);
        };

        if (pplayersArmy->numbers <= 0)
        {
            pplayersArmy->numbers = 0;
        };

        printf("With this attack we have lost %d soldiers\n", damageAgainstPlayer);
        printf("We now have %d soldiers left\n", (pplayersArmy->numbers));
        printf("The damage against our commander has been %d\n", damAgainstPlayComm);
        printf("Our commander now has %d commander's points\n", pplayersArmy->commandersPoints);
        printf("The strength of our army is now %.2f\n", pplayersArmy->strength);

        battleIsOver = checkBattleOver(pplayersArmy->numbers, penemyArmy->numbers,
        pplayersArmy->strength, initialPlayersStrength, penemyArmy->strength, initialEnemysStrength);
        if (battleIsOver.battleOver == 1)
        {
            return battleIsOver;
        };
    };
};


int recruitDefeatSold(struct army * pplayerArmy, float * pamountExtStrenParam, int * penemySoldLeftParam)
{
    printf("*penemySoldLeftParam: %d\n", *penemySoldLeftParam);

    printf("Initial player numbers: %d *** Initial player strength: %.2f\n",
    pplayerArmy->numbers, pplayerArmy->strength);
    pplayerArmy->numbers += *penemySoldLeftParam;
    printf("amountExtraStrength: %.2f\n", *pamountExtStrenParam);
    pplayerArmy->strength -= *pamountExtStrenParam;
    printf("Player numbers after: %d *** Player strength after: %.2f\n",
    pplayerArmy->numbers, pplayerArmy->strength);

    *penemySoldLeftParam = 0;

    printf("*penemySoldLeftParam: %d\n", *penemySoldLeftParam);

    return *penemySoldLeftParam;
};


int killDefeatSold(struct army * pplayerArmy, float * pamountExtStrenParam)
{
    int enemySoldLeft;
    printf("You have thus decided to butcher them all! They can't be trusted to join your army, after all. Besides, you"
    " feel more like providing your foes the cold touch of death than to feel your pockets a little heavier!\n");
    printf("Strength before: %.2f\n", pplayerArmy->strength);

    pplayerArmy->strength += *pamountExtStrenParam;
    enemySoldLeft = 0;

    printf("As a result of this action, you haven't gained any extra soldiers, but your army has gained %.2f"
    " extra points of strength!\n The stench of the enemy's blood smells like a damsel's perfume to your men!\n",
     *pamountExtStrenParam);
    printf("Strength after: %.2f\n", pplayerArmy->strength);

    return enemySoldLeft;
};


int negotiation1(struct army * penemyArmy, struct territory * penemyTerritory, int * penemySoldLeftParam,
 struct army * pplayerArmy, float * pamountExtStrenParam)
{
    // CHECK FOR NEGATIVE NUMBERS!!!!!

    int continueNumber;
    int enemySuggestion;

    printf("My liege, the enemy obviously lost soldiers, but they consider this loss to be manageable."
    " You should be careful when negotiating with them, for they don't seem to care that much about"
    " the soldier's we've captured from them!\n");

    printf("You have thus decided to ransom the soldiers. Maybe the enemy would be"
    " be willing to pay good coin for the lives of those weaklings?\n");
    printf("Press any number to continue: ");
    scanf("%d", &continueNumber);

    if (penemyTerritory->coinInCoffers > 0)
    {
        int ransomMoneyAsk;
        // This is the maximum amount of money the enemy will be willing to give. Namely,
        // the cost to recruit a soldier divided by 2 multiplied by the amount of soldiers
        // left. The enemy believes that these soldiers are worth less.
        int ransomMoneyMaxGive = (penemyTerritory->costRecruitSoldiers * *penemySoldLeftParam)/2;
        if (ransomMoneyMaxGive > penemyTerritory->coinInCoffers)
        {
            // Because the enemy wouldn't be willing to give all their money for their soldiers,
            // and want to have some money in their coffers to make investments.
            ransomMoneyMaxGive = (penemyTerritory->coinInCoffers)*2/3;
        };

        int count = 0;
        //int ransomMoneyAskNext;
        _Bool negotiationTerminated = false;

        //for (count = 0, negotiationTerminated = false; count < 6, negotiationTerminated == false; count++)
        for (count = 0; count < 6; count++)
        {
            if (negotiationTerminated == true)
            {
                break;
            };

            //int initialPlayerValue;
            int minEnemySuggestion;

            printf("\n===count: %d===\n", count);
            printf("\n===count: %d===\n", count);

            //INSERTVALUEAGAIN:
            while (true)
            {
                printf("How much money would you like to ask? ");
                scanf("%d", &ransomMoneyAsk);
                if (count >= 1 && ransomMoneyAsk >= enemySuggestion)
                {
                    printf("The enemy says we are now asking for a value that is greater than or equal to the previous one."
                    " So we should suggest a smaller value for the negotiation to continue.\n");
                        //printf("Value is greater than or equal to the previous one.");
                } else if (count >= 0 && ransomMoneyAsk > ransomMoneyMaxGive)
                {
                    //printf("Please insert another value.\n");
                    printf("According to our negotiators, the maximum value the enemy is willing "
                    "to negotiate with is %d.\nSo since, according to them, we seem so intent on making such "
                    "absurd offers, they have demanded that we make another offer.\n",
                    ransomMoneyMaxGive);
                } else
                {
                    printf("The enemy says this is a reasonable offer. Let's see if they accept...\n");
                    break;
                };
            };
            /*
            if (count == 0 && ransomMoneyAsk <= ransomMoneyMaxGive)
            {
                initialPlayerValue = ransomMoneyAsk;
            } else if (count >= 1 && ransomMoneyAsk <= ransomMoneyMaxGive)
            {
                if (ransomMoneyAsk >= enemySuggestion)
                {
                    printf("The enemy says we are now asking for a value that is greater than or equal to the previous one."
                    " So we should suggest a smaller value for the negotiation to continue.\n");
                    //printf("Value is greater than or equal to the previous one.");
                    goto INSERTVALUEAGAIN;
                };
            } else
            {
                //printf("Please insert another value.\n");
                printf("According to our negotiators, the maximum value the enemy is willing "
                "to negotiate with is %d.\nSo since, according to them, we seem so intent on making such "
                "absurd offers, they have demanded that we make another offer.\n",
                ransomMoneyMaxGive);
                goto INSERTVALUEAGAIN;
            };
            */

            float tempFloat = ransomMoneyAsk/3;
            minEnemySuggestion = (int)tempFloat;

            enemySuggestion = getRandValueFromRange(&minEnemySuggestion, &ransomMoneyAsk);

            while (true)
            {
                //int minEnemySuggestion;
                int playerNegotChoice;

                printf("\n=============\n");

                if (ransomMoneyAsk > ransomMoneyMaxGive)
                {
                    printf("The enemy would only be willing to give at maximum %d gold coins.\n",
                    ransomMoneyMaxGive);
                    break;
                } else
                {
                    INVALIDANSNEGOTIATION:
                    if (enemySuggestion > 0)
                    {
                        printf("\t-> The enemy suggests the value of %d. Do you accept? \n", enemySuggestion);
                        printf("Press 1 for 'Yes' and 0 for 'No': ");
                        scanf("%d", &playerNegotChoice);
                    } else
                    {
                        printf("The enemy doesn't wish to discuss anymore. They say that we should do whatever pleases us with"
                        " their soldiers.\n");
                        // At this point, the player should be prompted again about what to do (Option to kill, to recruit,
                        // or a new option: to release them)
                        enemySuggestion = 0;
                        negotiationTerminated = true;
                        break;
                    };

                    if (playerNegotChoice == 1)
                    {
                        printf("We have accepted the enemy's counter-offer. Our foes are glad that we have come to an agreement!\n");
                        printf("The player has accepted.\n");
                        penemyTerritory->coinInCoffers -= enemySuggestion;
                        negotiationTerminated = true;
                        break; // Break out of the while(true) loop
                    } else if (playerNegotChoice == 0)
                    {
                        if (count >= 5)
                        {
                            printf("The enemy doesn't wish to discuss anymore. They say that we should do whatever pleases us with"
                            " their soldiers.\n");
                            // At this point, the player should be prompted again about what to do (Option to kill, to recruit,
                            // or a new option: to release them)
                            enemySuggestion = 0;
                            negotiationTerminated = true;
                            break;
                        } else
                        {
                            printf("Ok, then let's continue with the negotiation.\n");
                            break;
                        };
                        //printf("Didn't accept!");
                    } else
                    {
                        printf("Invalid answer.");
                        goto INVALIDANSNEGOTIATION;
                    };
                        printf("\n\t====Pass====\n");
                };
            };
        };
    } else
    {
        printf("My lord, our negotiators say that the enemy doesn't even want to start negotiations for their"
        " captured soldiers. Maybe their coffers are empty...?\n");
        enemySuggestion = 0;
    };

    if (enemySuggestion > 0)
    {
        printf("The negotiation was sucessful, and you have agreed to ransom the enemy's %d soldiers for"
        " %d gold coins.\n", *penemySoldLeftParam, enemySuggestion);

        printf("Before the enemy's numbers were %d\n", penemyArmy->numbers);

        penemyArmy->numbers += *penemySoldLeftParam;

        printf("Now the enemy has %d soldiers.\n", penemyArmy->numbers);

    } else
    {
        while (true)
        {
            int finalChoiceEnSoldiers;
            printf("Apparently you haven't come to an agreement. What will you then do with the enemy's soldiers?\n");
            printf("My lord, as before, you are presented with the same options of either killing them all or recruiting them."
            " What are you going to do?\nPress 1 to recruit them and 0 to kill them: ");
            scanf("%d", &finalChoiceEnSoldiers);

            if (finalChoiceEnSoldiers == 0)
            {
                killDefeatSold(pplayerArmy, pamountExtStrenParam);
                break;
            } else if (finalChoiceEnSoldiers == 1)
            {
                recruitDefeatSold(pplayerArmy, pamountExtStrenParam, penemySoldLeftParam);
                break;
            } else
            {
                printf("Please insert a valid answer.\n");
            };
        };
    };
    return enemySuggestion;
};


int negotiation2(struct army * penemyArmy, struct army * pplayersArmy, struct territory * penemyTerritory,
struct territory * pplayersTerritory, int * penemySoldLeftParam, float * pamountExtStrenParam)
{
    // CHECK FOR NEGATIVE NUMBERS!!!!!

    int continueNumber;
    int enemySuggestion;
    _Bool enemyCoffersEmpty = false;

    printf("My lord, keep in mind that the enemy took a good beating by our forces after the battle, but not so"
    " much that it would make them desperate to get their soldiers back.\n");

    printf("You have thus decided to ransom the soldiers. Maybe the enemy would be"
    " be willing to pay good coin for the lives of those weaklings?\n");
    printf("Press any number to continue: ");
    scanf("%d", &continueNumber);

    if (penemyTerritory->coinInCoffers > 0)
    {
        int ransomMoneyAsk;
        // This is the maximum amount of money the enemy will be willing to give. Namely,
        // the cost to recruit a soldier divided by 2 multiplied by the amount of soldiers
        // left. The enemy believes that these soldiers are worth less.
        int ransomMoneyMaxGive = (penemyTerritory->costRecruitSoldiers * *penemySoldLeftParam)/2;
        if (ransomMoneyMaxGive > penemyTerritory->coinInCoffers)
        {
            // Because the enemy wouldn't be willing to give all their money for their soldiers,
            // and want to have some money in their coffers to make investments.
            ransomMoneyMaxGive = (penemyTerritory->coinInCoffers)*2/3;
        };

        int count;
        //int ransomMoneyAskNext;
        //_Bool negotiationTerminated = false;

        for (count = 0; count < 6; count++)
        {
            //int initialPlayerValue;
            int minEnemySuggestion;

            float tempFloat;

            int newMinEnSuggestion = 2;
            int newMaxEnSuggestion = 5;
            int * pnewMinEnSuggestion = &newMinEnSuggestion;
            int * pnewMaxEnSuggestion = &newMaxEnSuggestion;

            int randomValue;
            int difference;

            int playersAnswer;

            printf("How much money would you like to ask? ");
            scanf("%d", &ransomMoneyAsk);

            if (ransomMoneyAsk >= ransomMoneyMaxGive)
            {
                ransomMoneyAsk = ransomMoneyMaxGive;
                printf("According to our negotiators, the maximum value the enemy is willing "
                "to negotiate with is %d.\nSo since, according to them, we seem so intent on making such "
                "absurd offers, they will consider this maximum value to be our current offer.\n",
                ransomMoneyAsk);
            };

            printf("You have offered %d gold coins for the prisoners.\n", ransomMoneyAsk);
            randomValue = getRandValueFromRange(pnewMinEnSuggestion, pnewMaxEnSuggestion);
            printf("Random value: %d\n", randomValue);

            if (count == 0)
            {
                tempFloat = ransomMoneyAsk/randomValue;
                minEnemySuggestion = (int)tempFloat;
                printf("Count = %d || minEnemySuggestion: %d\n", count, minEnemySuggestion);
            } else
            {
                minEnemySuggestion = enemySuggestion;
                printf("Count = %d || minEnemySuggestion: %d\n", count, minEnemySuggestion);
            };

            difference = ransomMoneyAsk - minEnemySuggestion;
            printf("Difference: %d\n", difference);
            enemySuggestion = getRandValueFromRange(&minEnemySuggestion, &ransomMoneyAsk);

            _Bool validAnswer = false;
            //while (true)
            while (validAnswer == false)
            {
                int playersAnswer2;
                printf("My liege, the enemy's current offer is %d\nDo you accept? Press 1 for 'Yes' and"
                " 0 for 'No' ", enemySuggestion);
                scanf("%d", &playersAnswer);

                if (playersAnswer == 1)
                {
                    printf("The enemy is glad we have reached an agreement!\n");
                    printf("The enemy gave you %d gold coins\n", enemySuggestion);
                    printf("Before the negotiation you had %d gold coins\n", pplayersTerritory->coinInCoffers);
                    penemyTerritory->coinInCoffers -= enemySuggestion;
                    printf("Now they have %d gold.\n", penemyTerritory->coinInCoffers);

                    printf("Before the enemy's numbers were %d\n", penemyArmy->numbers);
                    penemyArmy->numbers += *penemySoldLeftParam;
                    printf("Now the enemy has %d soldiers.\n", penemyArmy->numbers);

                    //printf("\nBefore the enemy's coffers had %d gold\n", penemyTerritory->coinInCoffers);
                    //penemyTerritory->coinInCoffers -= enemySuggestion;
                    //printf("Now they have %d gold.\n", penemyTerritory->coinInCoffers);

                    return enemySuggestion;
                } else if (playersAnswer == 0)
                {
                    while (true)
                    {
                            //if (count < 5)
                            //{
                        printf("Would you like to try to make a new offer? Press 1 for 'Yes' and 0 for 'No' ");
                        scanf("%d", &playersAnswer2);
                        //if (playersAnswer2 == 1 && count <= 5)
                        if (playersAnswer2 == 1)
                        {
                            printf("Then let's try to make a new offer.\n");
                            validAnswer = true;
                            break;
                        } else if (playersAnswer2 == 0)
                        {
                            printf("Then there is nothing else to discuss, and the negotiation has been terminated.\n");
                            enemySuggestion = 0;
                            count = 5;
                            validAnswer = true;
                            break;
                                //float amountExtraStrength = *penemySoldLeftParam/2.0;
                        } else
                        {
                            printf("Please type in a valid answer.\n");
                        };
                    };
                } else
                {
                    printf("Please type in a valid answer.\n");
                };
            };
        };
    } else
    {
        printf("My lord, our negotiators say that the enemy doesn't even want to start negotiations for their"
        " captured soldiers. Maybe their coffers are empty...?\n");
        enemySuggestion = 0;
        enemyCoffersEmpty = true;
        //return enemySuggestion;
    };

    if (enemyCoffersEmpty == false)
    {
        printf("My lord, the enemy said it won't try to reason with us anymore, and have thus decided to drop"
        " any attempts of continuing this conversation.\n");
    };

    while (true)
    {
        int finalChoice;
        printf("Since you and the enemy haven't been able to reach and agreement, you now "
        "have to decide what to do with the prisoners. Are you going to kill them all, or are you"
        " going to recruit them? \nPress 0 if you want to kill them and 1 if you want to recruit "
        "them: ");
        scanf("%d", &finalChoice);
        if (finalChoice == 0)
        {
            killDefeatSold(pplayersArmy, pamountExtStrenParam);
            break;
        } else if (finalChoice == 1)
        {
            recruitDefeatSold(pplayersArmy, pamountExtStrenParam, penemySoldLeftParam);
            break;
        } else
        {
            printf("Please type in a valid answer.\n");
        };
    };
};


int negotiation3(struct army * penemyArmy, struct army * pplayersArmy, struct territory * penemyTerritory,
struct territory * pplayersTerritory, int * penemySoldLeftParam, float * pamountExtStrenParam)
{
    int continueNumber;
    int enemySuggestion = 0;

    printf("My lord, we have observed that the enemy's numbers have been so depleted after the battle, that they"
    " seem desperate to get at least some of their soldiers back with this negotiation. Be sure to use this to your"
    " advantage!\n");

    printf("You have thus decided to ransom the soldiers. Maybe the enemy would be be willing to pay good coin for "
    "the lives of those weaklings?\n");
    printf("Press any number to continue: ");
    scanf("%d", &continueNumber);

    if (penemyTerritory->coinInCoffers > 0)
    {
        int ransomMoneyAsk;
        // This is the maximum amount of money the enemy will be willing to give. Namely,
        // the cost to recruit a soldier divided by 2 multiplied by the amount of soldiers
        // left. The enemy believes that these soldiers are worth less.
        int ransomMoneyMaxGive = (penemyTerritory->costRecruitSoldiers * *penemySoldLeftParam)/2;
        if (ransomMoneyMaxGive > penemyTerritory->coinInCoffers)
        {
            // Because the enemy wouldn't be willing to give all their money for their soldiers,
            // and want to have some money in their coffers to make investments.
            ransomMoneyMaxGive = (penemyTerritory->coinInCoffers)*2/3;
        };

        while (true)
        {
            printf("My lord, how much money would you like to ask for those %d captured enemy soldiers? ",
            *penemySoldLeftParam);
            scanf("%d", &ransomMoneyAsk);

            if (ransomMoneyAsk > ransomMoneyMaxGive)
            {
                printf("Your majesty, the enemy would only be willing to give us at maximum %d gold coins"
                " for those %d soldiers.\nChoose another value.\n", ransomMoneyMaxGive, *penemySoldLeftParam);
            } else
            {
                printf("The desperate enemy has agreed with our demands!\n");
                printf("Enemy's suggestion before: %d\n", enemySuggestion);
                printf("Enemy's coffers before: %d\n", penemyTerritory->coinInCoffers);
                printf("Enemy's numbers before: %d\n", penemyArmy->numbers);
                enemySuggestion = ransomMoneyAsk;
                penemyTerritory->coinInCoffers -= enemySuggestion;
                penemyArmy->numbers += *penemySoldLeftParam;
                printf("Enemy's suggestion AFTER: %d\n", enemySuggestion);
                printf("Enemy's coffers AFTER: %d\n", penemyTerritory->coinInCoffers);
                printf("Enemy's numbers AFTER: %d\n", penemyArmy->numbers);
                return enemySuggestion;
            };
        };
    } else {
        printf("My lord, our negotiators say that the enemy doesn't even want to start negotiations for their"
        " captured soldiers. Maybe their coffers are empty...?\n");
        enemySuggestion = 0;
    };

    while (true)
    {
        int finalChoice;
        printf("Since you and the enemy haven't been able to reach and agreement, you now have to decide what to"
        " do with the prisoners. Are you going to kill them all, or are you going to recruit them? \nPress 0 if you"
        " want to kill them and 1 if you want to recruit them: ");
        scanf("%d", &finalChoice);
        if (finalChoice == 0)
        {
            killDefeatSold(pplayersArmy, pamountExtStrenParam);
            break;
        } else if (finalChoice == 1)
        {
            recruitDefeatSold(pplayersArmy, pamountExtStrenParam, penemySoldLeftParam);
            break;
        } else
        {
            printf("Please type in a valid answer.\n");
        };
    };

    return enemySuggestion;
};


// int befBattlePlayNums, int befBattleEnNums should be stored in variables before the battle
void aftermathBattle (struct battleOverStruct * paftermathBattleStructParam, struct army * pplayerStruct,
struct army * penemyStruct, struct territory * pplayerTerritory, struct territory * penemyTerritory,
int befBattlePlayNums, int befBattleEnNums)
// Add struct territory * penemyTerritory as parameter later!!
{
    // NO NEED FOR THIS, AS THE COMMANDER ALREADY LOSES POINTS IN THE BATTLE!
    /*
    float proportionSoldLostPl = pplayerStruct->numbers / befBattlePlayNums;
    float proportionSoldLostEn = penemyStruct->numbers / befBattleEnNums;
    pplayerStruct->commandersPoints = pplayerStruct->commandersPoints * proportionSoldLostPl;
    penemyStruct->commandersPoints = penemyStruct->commandersPoints * proportionSoldLostEn;
    */

    int enemySoldLeft = penemyStruct->numbers / 3;
    penemyStruct->numbers -= enemySoldLeft;
    int tempGoldInPossession;
    int ransomMoney;

    int continueNumber;

    if (paftermathBattleStructParam->battleWon == 1)
    {
        printf("The battle has been won! The enemy is utterly beaten, and you have conquered their "
        "territory! \n");
        // Print the stats of the soldiers, commander etc
        if (penemyStruct->baggageTrain > 0)
        {
            printf("After looting the enemy's camp, you have found their baggage train, and have added"
            " its gold to your own!\nThe enemy had %d gold coins, and before the battle you had %d\n",
            penemyStruct->baggageTrain, pplayerStruct->baggageTrain);

            tempGoldInPossession = penemyStruct->baggageTrain;
            //pplayerStruct->baggageTrain += penemyStruct->baggageTrain;

            printf("Now the amount of gold in your possession is %d!\n", tempGoldInPossession);
            //printf("Now the amount of gold in your possession is %d!\n", pplayerStruct->baggageTrain);
        } else if (penemyStruct->baggageTrain <= 0)
        {
            penemyStruct->baggageTrain = 0;
            printf("Ha! It seems that besides being weaklings, the enemies were also bankrupt!\n"
            "After searching their camp, you have found nothing of value, as their baggage train had"
            " no coins.\n");
        };

        printf("Press any number to continue: ");
        scanf("%d", &continueNumber);
        if (enemySoldLeft > 0)
        {
            int choice;
            float amountExtraStrength = enemySoldLeft/2.0;

            printf("After the battle %d enemy soldiers fled the field, and in their camp there were"
            " %d enemy soldiers left\n", penemyStruct->numbers, enemySoldLeft);
            while (true)
            {
                printf("What are you going to do with them? If you decide to recruit them, you will gain more "
                "soldiers, but due to your own soldiers suspicions about their former enemies, your army will "
                "lose strength. Alternatively, you can also ransom them to the enemy for coin, or you can "
                "decide to kill them all!\n");
                printf("Press 1 to recruit them, 2 to ransom them or 0 to butcher them! ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                    enemySoldLeft = recruitDefeatSold(pplayerStruct, &amountExtraStrength, &enemySoldLeft);
                    printf("enemySoldLeft out of the function: %d\n", enemySoldLeft);
                    break;
                } else if (choice == 0)
                {
                    // Insert here the function to kill the soldiers.
                    enemySoldLeft = killDefeatSold(pplayerStruct, &amountExtraStrength);
                    printf("\nEnemy Soldiers left: %d\n", enemySoldLeft);
                    break;
                } else if (choice == 2) // INSERT THE NEGOTIATION FUNCTION HERE!
                {
                    float totalEnemAftBatt = enemySoldLeft + penemyStruct->numbers;

                    printf("totalEnemAftBatt = %.2f\n", totalEnemAftBatt);
                    printf("befBattleEnNums (enemy numbers before the battle) = %d\n", befBattleEnNums);
                    printf("befBattleEnNums / totalEnemAftBatt  = %.2f\n", (float)totalEnemAftBatt/(float)befBattleEnNums );
                    printf("totalEnemAftBatt / 3 = %.2f\n", (float)totalEnemAftBatt / 3);

                    //if ((float)totalEnemAftBatt >= (befBattleEnNums / 3))
                    if ((float)totalEnemAftBatt >= (befBattleEnNums / 2))
                    {
                        printf("\nThis is negotiation 1\n");
                        ransomMoney = negotiation1(penemyStruct, penemyTerritory, &enemySoldLeft, pplayerStruct, &amountExtraStrength);
                        break;
                        // Call negotiation1
                    } else if (befBattleEnNums / 2 > (float)totalEnemAftBatt && (float)totalEnemAftBatt  >= (befBattleEnNums / 3))
                    {
                        printf("\nThis is negotiation 2\n");
                        ransomMoney = negotiation2(penemyStruct, pplayerStruct, penemyTerritory, pplayerTerritory, &enemySoldLeft, &amountExtraStrength);
                        break;
                        // Call negotiation2
                    } else
                    {
                        printf("\nThis is negotiation 3\n");
                        ransomMoney = negotiation3(penemyStruct, pplayerStruct, penemyTerritory, pplayerTerritory, &enemySoldLeft, &amountExtraStrength);
                        break;
                        // Call negotiation3
                    };
                }else
                {
                    printf("Please type in a valid answer.\n");
                    // There is a bug here that needs to be addressed. If the user types a letter
                    // instead of an integer number, the program keeps looping infinitely
                };
            };
        } else {
            enemySoldLeft = 0;
            printf("The enemy soldiers who were left behind by the enemy have been"
            " slaughtered to the last man, and now your army can celebrate its victory!\n");
            // Player gets the same amount of strength as it would get if it slaughtered the prisoners
        };

        printf("Temporary gold in possession BEFORE: %d\n", tempGoldInPossession);
        tempGoldInPossession += ransomMoney;
        printf("Temporary gold in possession AFTER: %d\n", tempGoldInPossession);

        if (tempGoldInPossession > 0)
        {
            int choiceExtraGold;
            int moneyToBaggTrain;
            //int moneyToCoffers;

            printf("Press any number to continue: ");
            scanf("%d", &continueNumber);
            printf("My lord, now you need to decide what to do with the extra money you've taken"
            " from the enemy, both in their camp and as ransom money.\n");
            printf("\t-> Your baggage train's money is %d\n\t-> The money in your capital's coffers is %d\n"
            "\t-> And the money taken from the enemy is %d\n", pplayerStruct->baggageTrain,
            pplayerTerritory->coinInCoffers, tempGoldInPossession);

            while(true)
            {
                printf("What are you going to do with all the extra money?\n\t-> Press 1 to add all of it to"
                " your baggage train (remember that an army without money can't buy food!)\n\t"
                "-> Press 2 to add all of it to your capital's coffers\n\t"
                "-> Press 3 to add part of it to your capital's coffers and part of it to your baggage train.\n");
                scanf("%d", &choiceExtraGold);

                if (choiceExtraGold == 1)
                {
                    pplayerStruct->baggageTrain += tempGoldInPossession;
                    printf("My lord, now your baggage train has %d gold coins.\n", pplayerStruct->baggageTrain);
                    break;
                } else if (choiceExtraGold == 2)
                {
                    pplayerTerritory->coinInCoffers += tempGoldInPossession;
                    printf("My liege, now your glorious capital's coffers have %d gold coins.\n", pplayerTerritory->coinInCoffers);
                    break;
                } else if (choiceExtraGold == 3)
                {
                    while (true)
                    {
                        printf("The money you took from the enemy amounts to %d gold coins.\n", tempGoldInPossession);
                        printf("How much money would you like to add to your baggage train? ");
                        scanf("%d", &moneyToBaggTrain);

                        if (moneyToBaggTrain > tempGoldInPossession || moneyToBaggTrain < 0)
                        {
                            printf("The amount of money you've entered is either more than you have in possession, "
                            "or less than zero. Please type in a valid number. \n");
                        } else
                        {
                            printf("Your baggage train had %d gold coins before.\n", pplayerStruct->baggageTrain);
                            printf("%d gold coins have been added to your baggage train.\n", moneyToBaggTrain);
                            pplayerStruct->baggageTrain += moneyToBaggTrain;
                            printf("Your baggage train now has %d gold coins.\n", pplayerStruct->baggageTrain);
                            tempGoldInPossession -= moneyToBaggTrain;
                            printf("Now the money you took from the enemy amounts to %d gold coins.\n", tempGoldInPossession);
                            break;
                        };
                    };

                    if (tempGoldInPossession <= 0)
                    {
                        printf("Before your coffers had %d gold coins.\n", pplayerTerritory->coinInCoffers);
                        tempGoldInPossession = 0;
                        printf("My lord, the money you took from the enemy now amounts to %d gold coins, and so there"
                        " is nothing left to be added to your coffers.\n", tempGoldInPossession);
                        printf("The gold in your coffers amounts to %d gold coins.\n", pplayerTerritory->coinInCoffers);
                        break;
                    } else
                    {
                        printf("Before your coffers had %d gold coins.\n", pplayerTerritory->coinInCoffers);
                        printf("My lord, since the remainder of the money you took from the enemy now amounts to %d"
                        " gold coins, this value has been added to your coffers.\n", tempGoldInPossession);
                        pplayerTerritory->coinInCoffers += tempGoldInPossession;
                        printf("The gold in your coffers now amounts to %d gold coins.\n", pplayerTerritory->coinInCoffers);
                        break;
                    };
                } else
                {
                    printf("Please type in a valid answer.\n");
                };
            };
            // HERE! Ask the player what he wants to do with the money he gained. Does he want to put it
            // in his coffers, or in his cart?
            // Variables:
            // tempGoldInPossession
            //pplayerTerritory->coinInCoffers; // The faction's coffers
            //pplayerStruct->baggaeTrain; // The baggage train
        } else
        {
            printf("My lord, since the enemy's army had no money at all in their possession, there are no"
            " issues that need addressing at this moment.\n");
        };

        printf("My lord, now it is time to return to our capital and rejoice for this glorious victory!\n");
    // IMPORTANT!!! Create a loop here. For every battle won, award 1 experience to the player and increase
    // the defense and attack by 1.
    } else if (paftermathBattleStructParam->battleWon == 0)
    {
        printf("The battle has been lost! You have been utterly defeated\n");
    };
};

void mainCampaign(void)
{
    printf("Main campaign function");
    // Player can perform a limited number of actions per turn (for example, 3 actions)
    // Options: 1) Allocate extra points to commander or soldiers; 2) Take an economic action (there are other subactions inside this one)
    // 3) Take a military action; 4) etc
};

// A FUNCTION TO AUTOMATICALLY CREATE AN ARMY FOR THE AI!!!!

// Create an aftermathBattle function. Commanderspoints will be reduced based on the amount of soldiers.
// If the player won, he will get X amount of points to distribute across commanderspoints, numbers or extrapoints.
// He will also gain 2/3 of the money in the baggage train.
// The player will be prompted:
// 1) to recruit 1/3 of the soldiers who fled the battlefield, since they were captured by the player.
// If 3000 soldiers fled, the player can then recruit up to 1000, but recruiting 1 soldier costs 2 extraPoints.
// So in order to recruit 1000 soldiers, the player needs 2000 extrPoints.
// 2)
// If the player loses, he gets no points, and from the soldiers who left he only gets 2/3 of them.

// Create an occupyTerritory function:
// If the player wins, he occupies the territory and is prompted as to what he is going to do with it.

// About the baggage train in the army:
// Without a baggage train, the army will lose strength at every turn because they won't have money to buy food!
// At every turn in the main campaign the army will lose a little baggage train money in order to sustain itself.
