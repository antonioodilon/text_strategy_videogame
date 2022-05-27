#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

#include "base_functions.h"

int main(void){
    struct army aTestArmy;
    aTestArmy = createsPlayerArmy();
    printf("\n=============\n");

    printf("Your commander's name is %s\n", aTestArmy.pcommandersName);
    printf("Your commander has %d points\n", aTestArmy.commandersPoints);
    printf("You have %d soldiers in your army\n", aTestArmy.numbers);
    printf("Minimum attack: %d **** Maximum attack: %d\n", aTestArmy.minAttack, aTestArmy.maxAttack);
    printf("Minimum defense: %d **** Maximum defense: %d\n", aTestArmy.minDefense, aTestArmy.maxDefense);
    printf("Your army has %.2f points of experience\n", aTestArmy.experience);
    printf("The strength of your army is %.2f\n", aTestArmy.strength);

    return 0;
};
