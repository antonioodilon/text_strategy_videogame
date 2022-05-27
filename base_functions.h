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
