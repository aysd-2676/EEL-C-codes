#include <stdio.h>

int main () 
{
    int math;
    int eng;
    int phy;
    int chem;
    int cs;
    int avg;
    int student_num = 1;
    char guidance;
    char counselling;
    
    
    label:
    printf("KYG: Know your grade!\n");
    while (student_num < 141) {
    printf("\n");
    printf("Enter marks for roll no. %d\n", student_num);
    printf("At first you need to let us know your marks you have attained per subject\n");
    printf("English:");
    scanf("%d", &eng);
    printf("Maths:");
    scanf("%d", &math);
    printf("Physics:");
    scanf("%d", &phy);
    printf("Chemistry:");
    scanf("%d", &chem);
    printf("Computer Science:");
    scanf("%d", &cs);

    avg = (math + eng + phy + chem + cs)/5;

    printf("\n");

    if ( eng <= 100 && eng >= 0 && math <= 100 && math >= 0 && phy <= 100 && phy >= 0 && chem <= 100 && chem >= 0 && cs <= 100 && cs >= 0) {
        printf("Your average marks are %d",avg);
        printf(" and:\n");
        if (eng <= 100 && eng >= 40 && math <= 100 && math >= 40 && phy <= 100 && phy >= 40 && chem <= 100 && chem >= 40 && cs <= 100 && cs >= 40) {
            if ( avg >= 75 ) {
            printf("Congratulations! You have passed with Distinction!\n");
            printf("Keep it up!\n");
        } else if ( avg >= 60 ) {
            printf("Nice! you have passed with 1st Division. Strive harder for distinction\n");
            printf("Do you want personal guidance to ensure higher grade?");
            scanf("%s", &guidance);
            if (guidance == 'n' || guidance == 'N') {
                printf("Alright, \n");
            } else if (guidance != 'y' && guidance == 'Y' && guidance == 'n' && guidance == 'N') {
                printf("INVALID INPUT!!!");
            }
            if (guidance == 'y' || guidance == 'Y') {
                printf("Alright, at first make a timetable for your studies.\n");
                printf("In that timetable, make sure you give enough time for studies, healthy food, proper exercise and sleep.\n");
                printf("After a particular curricular day in college, ensure that you revise whatever is taught in the lectures.\n");
                printf("Make proper notes for the concepts and regularly ask your doubts to the teachers.\n");
                printf("If you follow these steps you can make it to distinction.\n");
                guidance++;
                } 
        } else if ( avg >= 50) {
            printf("You have achieved 2nd Division! You have to study harder for better grades\n");
            printf("Do you want personal guidance to ensure higher grade?\n");
            scanf("%s", &guidance);
            if (guidance == 'n' || guidance == 'N') {
                printf("Alright, \n");
            } else if (guidance != 'y' && guidance == 'Y' && guidance == 'n' && guidance == 'N') {
                printf("INVALID INPUT!!!");
            }
            if (guidance == 'y' || guidance == 'Y') {
                printf("Alright, at first make a timetable for your studies.\n");
                printf("In that timetable, make sure you give enough time for studies, healthy food, proper exercise and sleep.\n");
                printf("After a particular curricular day in college, ensure that you revise whatever is taught in the lectures.\n");
                printf("Make proper notes for the concepts and regularly ask your doubts to the teachers. Incase if you feel shy talk to your class representatives.\n");
                printf("If you follow these steps you can make it to higher grades. also,\n");
                printf("Do you want personal counselling?\n");
                scanf("%s", &counselling);
                do {
                    printf("Alright, the college's counsellor would be informed of your necessity.\n");
                    printf("Your meet with the college counsellor will be arranged soon.\n");
                    counselling++;
                } 
                while (counselling == 'y' || counselling == 'Y');
                guidance++;
                } 
        } else if ( avg >= 40 ) {
            printf("You have achieved 3rd Division!\n");
            printf("Do you want personal guidance to ensure higher grade?\n");
            scanf("%s", &guidance);
            if (guidance == 'n' || guidance == 'N') {
                printf("Alright, \n");
            } else if (guidance != 'y' && guidance == 'Y' && guidance == 'n' && guidance == 'N') {
                printf("INVALID INPUT!!!");
            }
            if (guidance == 'y' || guidance == 'Y') {
                printf("Alright, at first make a timetable for your studies.\n");
                printf("In that timetable, make sure you give enough time for studies, healthy food, proper exercise and sleep.\n");
                printf("After a particular curricular day in college, ensure that you revise whatever is taught in the lectures.\n");
                printf("Make proper notes for the concepts and regularly ask your doubts to the teachers. Incase if you feel shy talk to your class representatives\n");
                printf("If you follow these steps you can make it to better grades. Always remember, your college helps everyone in need! Also, \n");
                printf("Do you want personal counselling?\n");
                scanf("%s", &counselling);
                
                while (counselling == 'y' || counselling == 'Y');
                do {
                    printf("Alright, the college's counsellor would be informed of your necessity.\n");
                    printf("Your meet with the college counsellor will be arranged soon.\n");
                    counselling++;
                } while (counselling == 'y' || counselling == 'Y');
            } 
            }} else {
            printf("You have failed in the semester exams! You have to repeat your classes\n");
            printf("Do you want personal counselling?\n");
            scanf("%s", &counselling);
            if (counselling == 'n' || counselling == 'N') {
                printf("Alright, \n");
            } else if (counselling != 'y' && counselling == 'Y' && counselling == 'n' && counselling == 'N') {
                printf("INVALID INPUT!!!");
            }
            if (counselling == 'y' || counselling == 'Y') {
                printf("Alright, the college's counsellor would be informed of your necessity.\n");
                printf("Your meet with the college counsellor will be arranged soon.\n");
                counselling++;
            }         
            }
    } else {
        printf("INVALID INPUT!!! Please enter valid marks!\n");
        goto label;
    }
    printf("Thank you!\n");
    printf("\n");
    student_num++;
    }
    return 0;
}
