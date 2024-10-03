#include <stdio.h>

int main () 
{
    int math;
    int eng;
    int phy;
    int chem;
    int cs;
    int avg;
    int student_num;
    
    label:
    printf("KYG: Know your grade!\n");
    printf("Enter your roll number:");
    scanf("%d", &student_num);
    while (student_num < 141) {
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
            printf("Congratulations! You have passed with Distinction!");
        } else if ( avg >= 60 ) {
            printf("Nice! you have passed with 1st Division. Strive harder for distinction");
        } else if ( avg >= 50) {
            printf("You have achieved 2nd Division! You have to study harder for better grades");
        } else if ( avg >= 40 ) {
            printf("You have achieved 3rd Division! Please go study!");
        }
        } else {
            printf("You have failed in the semester exams! You have to repeat your classes");
        }
    } else {
        printf("INVALID INPUT!!! Please enter valid marks!\n");
        goto label;
    }
    printf("Thank you!");
    student_num++;
    }
    return 0;
}