#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct PoliceStation {
    char area[100];
    char phone_number[20];
};


struct Hospital {
    char area[100];
    char hospital_type[20];
    char hospital_name[100];
    char phone_number[20];
};


struct FireStation {
    char area[100];
    char phone_number[20];
};


void find_police_station(struct PoliceStation stations[], int size, const char *area) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(stations[i].area, area) == 0) {
            printf("\nPolice station for area '%s':\n", area);
            printf("Phone Number: %s\n", stations[i].phone_number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No police station found for the area '%s'. Please check the area name.\n", area);
    }
}


void find_government_hospitals(struct Hospital hospitals[], int size) {
    printf("\nGovernment Hospitals in all areas:\n");
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(hospitals[i].hospital_type, "Government") == 0) {
            printf("\nHospital Name: %s\n", hospitals[i].hospital_name);
            printf("Area: %s\n", hospitals[i].area);
            printf("Phone Number: %s\n", hospitals[i].phone_number);
            found = 1;
        }
    }

    if (!found) {
        printf("No government hospitals found.\n");
    }
}


void find_private_hospitals_in_area(struct Hospital hospitals[], int size, const char *area) {
    printf("\nPrivate Hospitals in the area '%s':\n", area);
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(hospitals[i].area, area) == 0 && strcmp(hospitals[i].hospital_type, "Private") == 0) {
            printf("\nHospital Name: %s\n", hospitals[i].hospital_name);
            printf("Phone Number: %s\n", hospitals[i].phone_number);
            found = 1;
        }
    }

    if (!found) {
        printf("No private hospitals found in the area '%s'.\n", area);
    }
}


void find_fire_station(struct FireStation stations[], int size, const char *area) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(stations[i].area, area) == 0) {
            printf("\nFire station for area '%s':\n", area);
            printf("Phone Number: %s\n", stations[i].phone_number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No fire station found for the area '%s'. Please check the area name.\n", area);
    }
}


void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
   
    struct PoliceStation police_stations[] = {
        {"Kothrud", "123-456-7890"},
        {"Shivaji Nagar", "987-654-3210"},
        {"Kasba Peth", "555-123-4567"},
        {"Kondhwa", "555-765-4321"}
    };
    int police_size = sizeof(police_stations) / sizeof(police_stations[0]);

    
    struct Hospital hospitals[] = {
        {"Kothrud", "Private", "Sahyadri Hospital", "111-222-3333"},
        {"Shivaji Nagar", "Government", "Naidu Hospital", "444-555-6666"},
        {"Kasba Peth", "Private", "Peshwa Health Clinic", "777-888-9999"},
        {"Kondhwa", "Government", "Col. Sardesai Memorial Hospital", "555-123-4567"},
        {"Kothrud", "Government", "Sutar Hospital", "222-333-4444"},
        {"Shivaji Nagar", "Private", "Deenanath Mangeshkar Hospital", "999-888-7777"}
    };
    int hospital_size = sizeof(hospitals) / sizeof(hospitals[0]);

    
    struct FireStation fire_stations[] = {
        {"Kothrud", "333-444-5555"},
        {"Shivaji Nagar", "555-666-7777"},
        {"Kasba Peth", "888-999-0000"},
        {"Kondhwa", "123-456-7891"}
    };
    int fire_size = sizeof(fire_stations) / sizeof(fire_stations[0]);

    char area[100];
    char continue_search;

    do {
        
        printf("\nChoose an option:\n");
        printf("1. Find Police Station by Area\n");
        printf("2. List All Government Hospitals\n");
        printf("3. Find Private Hospitals in a Specific Area\n");
        printf("4. Find Fire Station by Area\n");
        printf("Enter your choice (1-4): ");
        int choice;
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                
                printf("\nEnter the area to find the police station phone number: ");
                fgets(area, sizeof(area), stdin);
                area[strcspn(area, "\n")] = '\0'; 

                find_police_station(police_stations, police_size, area);
                break;

            case 2:
                
                find_government_hospitals(hospitals, hospital_size);
                break;

            case 3:
                
                printf("\nEnter the area to find private hospitals: ");
                fgets(area, sizeof(area), stdin);
                area[strcspn(area, "\n")] = '\0';  

                find_private_hospitals_in_area(hospitals, hospital_size, area);
                break;

            case 4:
                
                printf("\nEnter the area to find the fire station phone number: ");
                fgets(area, sizeof(area), stdin);
                area[strcspn(area, "\n")] = '\0';  

                find_fire_station(fire_stations, fire_size, area);
                break;

            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }
        
        printf("\nDo you want to search again? (y/n): ");
        scanf("%c", &continue_search);
        getchar();  

    } while (continue_search == 'y' || continue_search == 'Y');

    return 0;
}