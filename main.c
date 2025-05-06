//Mumba Ilunga
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll_a_dice();
int play_computer();
int play_user();
int score_sheet_player(int);
int score_sheet_computer(int);
int main(){
    int no_of_rounds, player_dice, com_dice, p_score, c_score, sum_com,sum_player;
    srand(time(NULL));
    printf("Welcome to Crag game.\n");
    printf("Let's get started!\n");
    printf("How many rounds would you like to play? \n");
    scanf("%d", &no_of_rounds);
    fflush(stdin);
    com_dice = roll_a_dice();//Both the computer and player roll a die to see who starts the game
    player_dice = roll_a_dice();
    printf("I have rolled the dice got %d!\n", com_dice);
    printf("I have rolled the dice and you got %d!\n", player_dice);
    sum_com= 0;//initializing both computer sum and player sum to zero, so I can be able to calculate the total in the loop with each iteration of the loop
    sum_player = 0;
    for(int count_rounds = 1; count_rounds <= no_of_rounds; count_rounds +=1){
        if(com_dice > player_dice){
            printf("Round %d ", count_rounds);
            c_score= play_computer();
            printf("Round %d ", count_rounds);
            p_score= play_user();
        }
        else{
            printf("Round %d ", count_rounds);
            p_score= play_user();
            printf("Round %d ", count_rounds);
            c_score= play_computer();
        }
        sum_player = sum_player + p_score;
        sum_com = sum_com + c_score;
    }
    printf("My score \t Your score \n");
    printf("%d \t\t    %d\n",sum_com, sum_player);
    if(sum_player>sum_com)
        printf("YOU ARE THE WINNER!!!\n");
    else if(sum_com>sum_player)
        printf("I AM THE WINNER!!!\n");
    else
        printf("IT IS A DRAW!!!");
    return 0;
}
int play_user(){
    int dice_1, dice_2, dice_3, num1, num2, score, indicator_2,indicator;
    char ans;
    dice_1 = roll_a_dice();
    dice_2 = roll_a_dice();
    dice_3 = roll_a_dice();
    printf(" -- Your turn:\n");
    printf("You got >> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n", dice_1, dice_2, dice_3);
    indicator = 0;//the variables "Indicator" and "Indicator_2" are used to keep the loop going if the user enters incorrect data.
    while(indicator == 0) {
        printf("Shall i roll for you (Y/N)? ");
        scanf("%c", &ans);
        fflush(stdin);
        indicator_2 = 0;
        if (ans == 'Y') {
            indicator = 1;
            while (indicator_2 == 0) {
                printf("\nWhich ones do you want to keep? ");
                scanf("%d %d", &num1, &num2);//the user can only enter 2 numbers
                fflush(stdin);
                if (num1 == 1 && num2 == 2) {
                    dice_3 = roll_a_dice();
                    printf("\nYou got >> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n", dice_1, dice_2, dice_3);
                    indicator_2 = 1;
                } else if (num1 == 1 && num2 == 3) {
                    dice_2 = roll_a_dice();
                    printf("\nYou got >> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n", dice_1, dice_2, dice_3);
                    indicator_2 = 1;
                } else if (num1 == 2 && num2 == 3) {
                    dice_1 = roll_a_dice();
                    printf("\nYou got >> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n", dice_1, dice_2, dice_3);
                    indicator_2 = 1;
                } else {
                    printf(" \nSorry, wrong input!");
                    indicator_2 = 0;
                }
            }
        }else if(ans == 'N')
            indicator = 1;
        else{
            indicator = 0;
        printf("Sorry, wrong input. Enter Y for yes and N for no.\n");
        }
    }
    if((dice_1 == dice_2 || dice_1 == dice_3 || dice_2 == dice_3) && (dice_3 + dice_2 + dice_1 == 13))
        score = 50;
    else if((dice_1 + dice_2 + dice_3) == 13)
        score = 26;
    else if(dice_3 == dice_2 == dice_1)
        score = 25;
    else if((dice_1 == 1 && dice_2 == 2 && dice_3 == 3) || (dice_1 == 4 && dice_2 == 5 && dice_3 == 6) || (dice_1 == 1 && dice_2 == 3 && dice_3 == 5) ||(dice_1 == 2 && dice_2 == 4 && dice_3 == 6))
        score = 20;
    else
        score = dice_3 + dice_2 + dice_1;
    score_sheet_player(score);
    return score;
}
int play_computer(){
    int dice_1, dice_2, dice_3, score;
    dice_1 = roll_a_dice();
    dice_2 = roll_a_dice();
    dice_3 = roll_a_dice();
    printf(" -- My turn: \n");
    printf("I rolled them and i got >> \n[Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n", dice_1, dice_2, dice_3);
    if(dice_1 == 4 && dice_2 == 5 && dice_3 !=6){
        printf("Rolled dice 3! \n");
        dice_3 = roll_a_dice();
        printf(">> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n",dice_1, dice_2,dice_3);
    }
    else if(dice_1 != 4 && dice_2 == 5 && dice_3 ==6){
        printf("Rolled dice 1! \n");
        dice_1 = roll_a_dice();
        printf(">> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n",dice_1, dice_2,dice_3);
    }
    else if(dice_1 == 4 && dice_2 != 5 && dice_3 ==6){
        printf("Rolled dice 2! \n");
        dice_2 = roll_a_dice();
        printf(">> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d \n",dice_1, dice_2,dice_3);
    }
    if((dice_1 == dice_2 || dice_1 == dice_3 || dice_2 == dice_3) && (dice_3 + dice_2 + dice_1 == 13))
        score = 50;
    else if((dice_1 + dice_2 + dice_3) == 13)
        score = 26;
    else if(dice_3 == dice_2 == dice_1)
        score = 25;
    else if((dice_1 == 1 && dice_2 == 2 && dice_3 == 3) || (dice_1 == 4 && dice_2 == 5 && dice_3 == 6) || (dice_1 == 1 && dice_2 == 3 && dice_3 == 5) ||(dice_1 == 2 && dice_2 == 4 && dice_3 == 6))
        score = 20;
    else
        score = dice_3 + dice_2 + dice_1;
    score_sheet_computer(score);
    return score;
}
int score_sheet_computer(int score){
    printf("My score: %d \n", score);
    return 0;
}
int score_sheet_player(int score){
    printf("Your score: %d \n", score);
    return 0;
}
int roll_a_dice(){
    int dice;
    dice = 1 + (int) rand() % 6;
    return dice;
}
