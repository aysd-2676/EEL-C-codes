#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h> // For Sleep() on Windows
#else
#include <unistd.h> // For sleep() on UNIX/Linux
#endif

#define MAX_SPEAR_LENGTH 10 // Maximum length for the spear (in equal signs)

void get_user_spear_design(char *spear_design, int max_length) {
    printf("Create your spear design (length up to %d '=' signs): ", max_length);
    scanf("%s", spear_design);

    // Ensure spear design length is valid
    while (strlen(spear_design) > max_length || strchr(spear_design, '=') == NULL) {
        printf("Invalid design! Please use up to %d '=' signs: ", max_length);
        scanf("%s", spear_design);
    }
}

void extend_user_spear_design(char *spear_design) {
    char extension[MAX_SPEAR_LENGTH + 1]; // Buffer for the extension
    int current_length = strlen(spear_design);
    printf("You can extend your spear design. Add up to %d '=' signs: ", MAX_SPEAR_LENGTH - current_length);
    scanf("%s", extension);

    // Ensure the extension is valid
    while (strlen(extension) + current_length > MAX_SPEAR_LENGTH || strchr(extension, '=') == NULL) {
        printf("Invalid extension! Please use up to %d '=' signs: ", MAX_SPEAR_LENGTH - current_length);
        scanf("%s", extension);
    }

    // Concatenate the extension to the existing design
    strcat(spear_design, extension);
}

void generate_computer_spear_design(char *computer_spear) {
    int length = rand() % MAX_SPEAR_LENGTH + 1; // Random length between 1 and MAX_SPEAR_LENGTH
    for (int i = 0; i < length; i++) {
        computer_spear[i] = '='; // Fill with '=' signs
    }
    computer_spear[length] = '\0'; // Null-terminate the string
}

void play_game() {
    char user_spear_design[MAX_SPEAR_LENGTH + 1]; // +1 for null terminator
    char computer_spear_design[MAX_SPEAR_LENGTH + 1];
    int user_score = 0, computer_score = 0;
    int used_max_length = 0; // Flag to track if max length has been used

    srand(time(0)); // Seed for random number generation

    printf("\n");
    printf("Welcome to the Jousting Game!\n");
    printf("\nInstructions:\nYou will create a spear design using '=' to compete against the computer.\nThe longer spear wins each round!\nBest of three rounds wins the game!\n");
    printf("\n");

    for (int round = 1; round <= 3; round++) {
        printf("Round %d:\n", round);

        // Determine the maximum length for this round
        int max_length = (used_max_length == 0) ? MAX_SPEAR_LENGTH : MAX_SPEAR_LENGTH - 1;

        get_user_spear_design(user_spear_design, max_length);

        // Generate a random spear design for the computer
        generate_computer_spear_design(computer_spear_design);

        // In the second round, ask if the user wants to extend their spear
        if (round == 2 && strlen(user_spear_design) < 9) {
            char extend_choice;
            printf("Your spear length is less than 9. Do you want to extend it? (y/n): ");
            scanf(" %c", &extend_choice); // Added space before %c to consume newline

            if (extend_choice == 'y' || extend_choice == 'Y') {
                extend_user_spear_design(user_spear_design);
                printf("You extended your spear! Your new spear design is now: (o)<>{%s}\n", user_spear_design);
            }
        }

        // Check if user used the max length
        if (strlen(user_spear_design) == MAX_SPEAR_LENGTH) {
            used_max_length = 1; // Mark that user has used max length
        }

        // In the third round, ask if the user wants to switch spears
        if (round == 3) {
            char switch_choice;
            printf("Do you want to switch your spear with the computer's? (y/n): ");
            scanf(" %c", &switch_choice); // Added space before %c to consume newline

            if (switch_choice == 'y' || switch_choice == 'Y') {
                // User switches spears with the computer
                strcpy(user_spear_design, computer_spear_design);
                printf("You switched your spear! Your new spear design is now: (o)<>{%s}\n", user_spear_design);
            }
        }

        // Delay for 5 seconds before displaying spear designs
        printf("Preparing for attack...\n");
        #ifdef _WIN32
        Sleep(5000); // Sleep for 5 seconds on Windows
        #else
        sleep(5); // Sleep for 5 seconds on UNIX/Linux
        #endif

        // Display spear designs
        printf("Your spear design: (o)<>{%s>\n", user_spear_design);
        printf("Computer's spear design: (o)<>{%s>\n", computer_spear_design);

        // Determine the round winner
        int user_length = strlen(user_spear_design);
        int computer_length = strlen(computer_spear_design);

        // Delay for 5 seconds before showing the result
        printf("Attacking the opponent...\n");
        #ifdef _WIN32
        Sleep(5000); // Sleep for 5 seconds on Windows
        #endif

        if (user_length > computer_length) {
            printf("Congratulations! You win this round!\n");
            user_score++;
        } else if (user_length < computer_length) {
            printf("Computer wins this round! Better luck next time.\n");
            computer_score++;
        } else {
            printf("It's a tie this round!\n");
        }

        printf("\n");
    }

    // Determine overall winner
    printf("Final scores:\n");
    printf("Your score: %d\n", user_score);
    printf("Computer's score: %d\n", computer_score);

    if (user_score > computer_score) {
        printf("Congratulations! You are the overall winner!\n");
    } else if (user_score < computer_score) {
        printf("Computer is the overall winner! Better luck next time.\n");
    } else {
        printf("It's an overall tie!\n");
    }
}

int main() {
    play_game();
    return 0;
}
