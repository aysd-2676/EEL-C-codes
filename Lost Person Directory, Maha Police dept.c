#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

#define MAX_ENTRIES 100
#define PHONE_LENGTH 15
#define NAME_LENGTH 50
#define LOCATION_LENGTH 100
#define CASE_LENGTH 200

// Structure to store missing person information
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char location[LOCATION_LENGTH];
    char countryCode[6]; // Adjusted to allow + and a digit
    char caseDetails[CASE_LENGTH]; // Additional details about the case
    int found; // To track if the person has been found (1 = found, 0 = still missing)
} MissingPerson;

// Structure to track locations where missing persons were last seen
typedef struct {
    char location[LOCATION_LENGTH];
    int count; // Number of times this location was mentioned
} LocationStats;

// Function to simulate live tracking updates
void liveTracking(MissingPerson *person, MissingPerson directory[]) {
    const char *locations[][5] = {
        {"Ideal Colony Ground", "Ideal Colony Metro Station", "Kasba Peth Metro Station", "Vishrambag Wada", "Tulshi Baug"},
        {"Pune Station", "Pune Station Metro Station", "Mandai Metro Station", "Yashwantrao Chavhan Drutagati Marg", "Wakad Mall"}, 
        {"Shaniwar wada", "Mangalwar Peth", "Sadashiv Peth", "Jangli Maharaj Road", "Bookstore"},
        {"Shahapurji Palunji", "Oxford Golf Club", "Sant Tukaram International Airport", "Pheonix Mall of The Millenium", "Cafe Coffee Day, Kothrud"},
        {"Bank of Maharashtra, Bajirao Road", "Shukravar Peth", "Kasba Peth", "Lal Mahal", "Home"}, 
        {"Senapati Bapat Road", "Nal Stop", "Pu. La. Deshpande Okayama Garden", "Vadgaon Budruk", "Sinhagad"},
        {"Karve Road Irani Cafe", "Nal Stop", "Lakdi Bridge", "Sadashiv Peth", "Raja Dinkar Kelkar Vastu Sangrahalay"}, 
        {"Home", "Karve Road", "Dashabhuja Ganpati Temple", "Gopal Krushna Gokhale Road", "Bruhan Maharashtra College of Commerce"} 
    };

    int index = person - &directory[0]; // Calculate the index of the person

    printf("\nChecking last updates for %s...\n", person->name);
    for (int i = 0; i < 5; i++) {
        strcpy(person->location, locations[index][i]);
        printf("Location: %s\n", person->location);
        sleep(3); // Wait for 3 seconds to simulate time delay
    }
    printf("Tracking ended for %s.\n", person->name);
}

// Function to search for missing person and update statistics
void searchForMissingPerson(MissingPerson directory[], int size, const char *searchTerm, int searchByName, LocationStats locationStats[], int *foundCount, int *missingCount) {
    char fullPhone[PHONE_LENGTH + 6]; // To store the full phone number with country code
    for (int i = 0; i < size; i++) {
        if (searchByName) {
            // Search by name
            if (strcmp(directory[i].name, searchTerm) == 0) {
                printf("Missing Person Found:\n");
                printf("Name: %s\nPhone: %s\nLocation: %s\nCase Details: %s\n", 
                       directory[i].name, directory[i].phone, directory[i].location, directory[i].caseDetails);
                
                // Mark the person as found
                if (directory[i].found == 0) {
                    directory[i].found = 1;
                    (*foundCount)++;
                    (*missingCount)--;
                }
                
                // Update location statistics
                int locationFound = 0;
                for (int j = 0; j < MAX_ENTRIES; j++) {
                    if (locationStats[j].count == 0) break;
                    if (strcmp(locationStats[j].location, directory[i].location) == 0) {
                        locationStats[j].count++;
                        locationFound = 1;
                        break;
                    }
                }
                if (!locationFound) {
                    for (int j = 0; j < MAX_ENTRIES; j++) {
                        if (locationStats[j].count == 0) {
                            strcpy(locationStats[j].location, directory[i].location);
                            locationStats[j].count = 1;
                            break;
                        }
                    }
                }
                liveTracking(&directory[i], directory); // Start live tracking for the found person

                // Display the updated counts
                printf("\nUpdated Counts: Found: %d, Missing: %d\n", *foundCount, *missingCount);
                return;
            }
        } else {
            // Search by phone number
            snprintf(fullPhone, sizeof(fullPhone), "%s%s", directory[i].countryCode, directory[i].phone);
            if (strcmp(fullPhone, searchTerm) == 0) {
                printf("Missing Person Found:\n");
                printf("Name: %s\nPhone: %s\nLocation: %s\nCase Details: %s\n", 
                       directory[i].name, fullPhone, directory[i].location, directory[i].caseDetails);
                
                // Mark the person as found
                if (directory[i].found == 0) {
                    directory[i].found = 1;
                    (*foundCount)++;
                    (*missingCount)--;
                }
                
                // Update location statistics
                int locationFound = 0;
                for (int j = 0; j < MAX_ENTRIES; j++) {
                    if (locationStats[j].count == 0) break;
                    if (strcmp(locationStats[j].location, directory[i].location) == 0) {
                        locationStats[j].count++;
                        locationFound = 1;
                        break;
                    }
                }
                if (!locationFound) {
                    for (int j = 0; j < MAX_ENTRIES; j++) {
                        if (locationStats[j].count == 0) {
                            strcpy(locationStats[j].location, directory[i].location);
                            locationStats[j].count = 1;
                            break;
                        }
                    }
                }
                liveTracking(&directory[i], directory); // Start live tracking for the found person

                // Display the updated counts
                printf("\nUpdated Counts: Found: %d, Missing: %d\n", *foundCount, *missingCount);
                return;
            }
        }
    }
    printf("Missing person not found for: %s\n", searchTerm);
}

// Function to generate the statistics report
void generateReport(MissingPerson directory[], int size, LocationStats locationStats[]) {
    int foundCount = 0, missingCount = 0;
    printf("\nMissing Person Report:\n");

    for (int i = 0; i < size; i++) {
        if (directory[i].found == 1) {
            foundCount++;
        } else {
            missingCount++;
        }
    }

    printf("Total Found Persons: %d\n", foundCount);
    printf("Total Missing Persons: %d\n", missingCount);

    printf("\nLocations Where Missing Persons Were Last Seen:\n");
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (locationStats[i].count == 0) break;
        printf("Location: %s, Count: %d\n", locationStats[i].location, locationStats[i].count);
    }
}

int main() {
    MissingPerson directory[MAX_ENTRIES];
    LocationStats locationStats[MAX_ENTRIES] = {0};

    int numContacts = 0;
    int foundCount = 0, missingCount = 0;

    // Adding missing person details
    strcpy(directory[numContacts++].name, "Shantanu Deshmukh");
    strcpy(directory[numContacts - 1].phone, "+91 9824836481");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+91");
    strcpy(directory[numContacts - 1].caseDetails, "Last seen near Tulshi Baug.");
    directory[numContacts - 1].found = 0;
    missingCount++;

    strcpy(directory[numContacts++].name, "Arnav Chowdhary");
    strcpy(directory[numContacts - 1].phone, "+91 9748627158");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+1");
    strcpy(directory[numContacts - 1].caseDetails, "Missing since October 1st; last contacted via text.");
    directory[numContacts - 1].found = 0;
    missingCount++;

    // Additional entries:
    strcpy(directory[numContacts++].name, "Vibhav Deshpande");
    strcpy(directory[numContacts - 1].phone, "+91 9247621586");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+34"); // Spain country code
    strcpy(directory[numContacts - 1].caseDetails, "Disappeared after leaving a party.");
    directory[numContacts - 1].found = 0;
    missingCount++;

    strcpy(directory[numContacts++].name, "Sarika Patel");
    strcpy(directory[numContacts - 1].phone, "+91 9846872568");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+52");
    strcpy(directory[numContacts - 1].caseDetails, "Last seen at the Pheonix mall.");
    directory[numContacts - 1].found = 0;
    missingCount++;
    
    strcpy(directory[numContacts++].name, "Pranav Nikam");
    strcpy(directory[numContacts - 1].phone, "+91 9735486521");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+1");
    strcpy(directory[numContacts - 1].caseDetails, "Vanished from home.");
    directory[numContacts - 1].found = 0;
    missingCount++;
    
    strcpy(directory[numContacts++].name, "Aarti Sharma");
    strcpy(directory[numContacts - 1].phone, "+91 9824568751");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+971");
    strcpy(directory[numContacts - 1].caseDetails, "Missing during a trip to Sinhagad.");
    directory[numContacts - 1].found = 0;
    missingCount++;
    
    strcpy(directory[numContacts++].name, "Aarti Sharma");
    strcpy(directory[numContacts - 1].phone, "+91 9824568751");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+86");
    strcpy(directory[numContacts - 1].caseDetails, "Disappeared near Raja Dinkar Kelkar Vastu Sangrahalay.");
    directory[numContacts - 1].found = 0;
    missingCount++;

    strcpy(directory[numContacts++].name, "Arnav Vaishampayan");
    strcpy(directory[numContacts - 1].phone, "+91 9748759645");
    strcpy(directory[numContacts - 1].location, "Unknown");
    //strcpy(directory[numContacts - 1].countryCode, "+20");
    strcpy(directory[numContacts - 1].caseDetails, "Lost near his college.");
    directory[numContacts - 1].found = 0;
    missingCount++;


    // Menu for user input
    while (1) {
        printf("\n\n\nMISSING PERSONS TELEPHONE TRACK DATA\nMaharashtra Police, Division Pune,\n\n All city missing persons mobile tracking data\n\n");
        printf("The data below represents the data of all the missing persons that were lost in last 28 days (irrespective of their current status i.e. some of them could be found) in the Pune City Division.\nThe list of the missing persons is given below as well as phone numbers and you can see their last 5 locations that were tracked in and around Pune.\n");
        printf("The data related to status of the persons would be given below at the end. \nEnter valid info and avoid spelling mistakes.\n");
        printf("\nEnter option (numerically) :\n1. Search by Name\n2. Search by Phone Number\n3. Exit\n> ");
        int option;
        char searchTerm[PHONE_LENGTH + 6]; // For phone or name search term
        scanf("%d", &option);
        getchar(); // Consume newline after input

        if (option == 1) {
            printf("Name Directory:\n1) Shantanu Deshmukh\n2) Arnav Chowdhary\n3) Vibhav Deshpande\n4) Sarika Patel\n5) Pranav Nikam\n6) Aarti Sharma\n7) Aarti Sharma\n8) Arnav Vaishampayan\nEnter Name: ");
            fgets(searchTerm, sizeof(searchTerm), stdin);
            searchTerm[strcspn(searchTerm, "\n")] = '\0'; // Remove newline

            searchForMissingPerson(directory, numContacts, searchTerm, 1, locationStats, &foundCount, &missingCount);
        } else if (option == 2) {
            char countryCode[6], phoneNumber[PHONE_LENGTH];
            // printf("Enter Country Code: ");
            // // fgets(countryCode, sizeof(countryCode), stdin);
            // countryCode[strcspn(countryCode, "\n")] = '\0'; // Remove newline

            printf("Telephone Directory:\n1) +91 9824836481\n2) +91 9748627158\n3) +91 9247621586\n4) +91 9846872568\n5) +91 9367246868\n6) +91 9735486521\n7) +91 9824568751\n8) +91 9748759645\nEnter Phone Number (with country code): ");
            fgets(phoneNumber, sizeof(phoneNumber), stdin);
            phoneNumber[strcspn(phoneNumber, "\n")] = '\0'; // Remove newline

            snprintf(searchTerm, sizeof(searchTerm), "%s%s", countryCode, phoneNumber);
            searchForMissingPerson(directory, numContacts, searchTerm, 0, locationStats, &foundCount, &missingCount);
        } else if (option == 3) {
            generateReport(directory, numContacts, locationStats);
            break;
        }
    }

    return 0;
}