// This is a code to manage electrical appliances in a house a calculate the bill

#include <stdio.h>

int main () {
    int lightbulb;
    int on_num;
    int fan;
    int television;
    int ac;
    int appliances;
    char on_ac;
    char ensure;
    printf("The bill Buzzer\n");
    printf("How many light bulbs / tubelights are present in the living room?\n");
    scanf("%d", &lightbulb);
    printf("How many fans are present in the living room?\n");
    scanf("%d", &fan);
    printf("Do you have a TV in the living room? (answer in 0 or 1)\n");
    scanf("%d", &television);
    printf("Do you have an AC in the living room? (answer in 0 or 1)\n");
    scanf("%d", &ac);
    printf("How many appliances including fans and lights were on today?\n");
    scanf("%d", &on_num);
    if (ac == 1) {
        printf("Was the ac on? (answer in y or n)\n");
    scanf("%s", &on_ac);
    }
    

    
    appliances = fan + lightbulb + television + ac;
    if (on_num <= appliances && appliances != 0) {
        if (on_num == appliances && on_num > 3 && appliances != 0) {
        printf("You should control your electricity consumption as it wastes energy and increases bill!\n");
    }
    else if (on_num >= appliances/2 && on_num > 2 && on_num != appliances) {
        printf("Ok, but you could further reduce you consumption.\n");
    }
    else {
        printf("Good your electric consumption is as it should be, keep it up!\n");
    }
    }
    else if (appliances == 0) {
        printf("Are you sure you have no appliances in your living room? (ans y or n)\n");
        scanf("%s", &ensure);
        if (ensure == 'y') {
            printf("Hey stone age man!\n");
        } 
        else if (ensure == 'n') {
            printf("Ok then don't lie next time!\n");
        }
        else {
            printf("Invalid input!\n");
        }
    }
    else {
        printf("Invalid input\n");
    }
    if (on_ac == 'y') {
        printf("Also ensure minimal usage of your air conditioner!");
    }
    else if (on_ac != 'n' && on_ac != 'y') {
        printf("Invalid input");
    }
    return 0;
}