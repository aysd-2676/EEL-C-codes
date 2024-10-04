// The Grade Helper

// Stage 1: Empathize, Research: 
// External links:- National Institute Of Health(https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3708204/)  Science Direct
// (https://www.sciencedirect.com/science/article/pii/S187704281101946X)
 
//        India is a country with a diverse population of over 1.3 billion people, and it is facing numerous challenges that affect the mental health and well-being of its citizens.
// The need for counselling in India is becoming increasingly important due to education system, lack of mental health resources, social and cultural pressures etc
//                      So, to reduce this, we created ‘The Grade Helper’

// Stage 2: Define—State Your Users' Needs and Problems: -
// Stage 3: Ideate: - 
// As per the project, the code was designed to inform the student of his or her grade according to their roll number. However, my group realised that if any student has got lesser grades, they need some help with that. Therefore, we added the input where we would guide the student by making some changes in their schedule by creating a timetable and ensure proper diet, sleep and exercise. And this code also asks the student to make proper notes and ask their doubts to their teachers. This code also asks the student to ask their doubts to their student representatives and mentors if necessary. Also, this code asks the student whether they need personal counselling and assures hm or her that the counsellor will connect with them soon.
// Stage 4: Prototype: - 
// Begin
// For 1st roll no.
// Input subject marks
// Output average grade 
// Avg = (add all subject marks) / 5
// Declare grade (distinction, 1st div, 2nd div, 3rd div or fail)
// Ask if student needs guidance (exception: distinction students are just congratulated)
// If yes inform how to manage studies and ask if counselling is needed if grade is lower ask if they need counselling and assure that counsellor will connect soon
// Thank at the end
// Code loops back and enter marks for next roll no. and this loop goes on until 140 students are reached.
// End 
// Stage 5: TESTING :- We decided to make program to solve the problem of various students who need counselling.
// First of all we made a simple program then we did innovation to that program. There were some errors than with the help of google we rectified that problem.
// The code was not working in one of the computer so we sent it to Piyush’s computer where it worked.


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
