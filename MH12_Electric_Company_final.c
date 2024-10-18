#include <stdio.h>
#include <string.h> // For strcmp
#include <stdlib.h> // For malloc and free
#include <ctype.h>  // For tolower

#define RATE_PER_UNIT 5.0  // Cost per unit of electricity

// Function to calculate bill for a device
float calculate_bill(float power_rating, float hours) {
    float units_consumed = power_rating * hours;  // in kWh
    return units_consumed * RATE_PER_UNIT;
}

// Function to print the bill details
void print_bill(const char *month, const char *name, const char *type, const char *cust_id, long int telephone, double total_bill, int units) {
    printf("In that case the bill is generated as follows:\n\n");
    printf("||-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-||\n");
    printf("||  MH12 Electric Company Bill for month %s.                                                                                       \n", month);
    printf("||                                                                                                                                       ||\n");
    printf("|| Name of the consumer: %s                                                                                                          \n", name);
    printf("|| Type of the customer: %s                                                                                                         \n", type);
    printf("|| Customer id of the consumer: %s                                                                                              \n", cust_id);
    printf("|| Telephone number of the consumer: +91 %ld                                                                                   \n", telephone);
    printf("|| The units consumed by the consumer: %d kWh                                                                                          \n", units);
    printf("|| Rate per unit is: Rs. %.2lf                                                                                                            \n", RATE_PER_UNIT);
    printf("|| The total bill in rupees: %.2lf                                                                                                    \n", total_bill);
    printf("||                                                                                                                                       \n");
    printf("|| In case of a delay of more than 10 days, the consumer would be fined Rs. 2000                                                         \n");
    printf("|| as delay charges and would be incremented by 100 as each day passes.                                                                  \n");
    printf("||                                                                                                                                       ||\n");
    printf("|| Thank You!                                                                                                                            \n");
    printf("||-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-||\n\n");
}

int main() {
    // Rules to be followed by end user for input
    printf("This code is made for the company employee to enter the consumer details,\n");
    printf("their consumption in kWh which will generate a bill for the consumer\n");
    printf("to be paid within 10 days.\n");
    printf("Follow the rules given below to ensure a flawless electricity bill generation.\n");
    printf("1) Enter all alphabetical data in small case. No caps allowed!\n");
    printf("2) Using of any symbols is strictly prohibited as it may result\n   in failure of the calculation of the bill.\n");
    printf("3) Numerical data should be entered accurately to avoid miscalculation\n");
    printf("4) In case of an error or a miscalculation on the part of the software contact\n   the responsible employees as unnecessary and uninformed may\n   lead to further problems.\n");
    printf("5) Please read the instructions before input carefully. If in any case\n   the instruction is absent, type the answer in small case words.\n");

    char name[100];
    long int telephone;
    char cust_id[9]; // Increased to 9 to accommodate null terminator
    char type[15];
    char month[10];
    double total_power = 0.0;

    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nMH12 Electric Company\n");
    printf("\n");
    printf("Electric Bill Calculator\n");
    printf("\n");
    printf("Enter the information to generate the bill\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your telephone number: ");
    scanf("%ld", &telephone);
    printf("Enter your alphanumeric Customer Id (8 digits necessary): ");
    scanf("%s", cust_id);
    printf("Enter the month for which the bill is to be made:\n");
    scanf("%s", month);

    printf("Are you a domestic user or a commercial user? Answer below(commercial/domestic):\n   ");
    scanf("%s", type);

    if (strcmp(type, "commercial") == 0) {
        int com_type;
        printf("What is the type of your commercial space? (answer in 1 or 2)\n 1) Office\n 2) Factory\n");
        scanf("%d", &com_type);
        
        if (com_type == 1) {
            // Variables for office
            int lights, fans, desk_pcs, acs, floors, elevator, elev_time, light_time, fans_time, desk_pc_time, ac_time;
            double pow_elev, pow_light, pow_fan, pow_pc, pow_ac;
            double power = 0;
            int units;

            printf("Enter the number of floors in the office: ");
            scanf("%d", &floors);
            if (floors > 1) {
                printf("How many elevators does the office have? (input 0 if none): ");
                scanf("%d", &elevator);
                if (elevator > 0) {
                    printf("Enter the daily usage of the elevators in hours (integers only): ");
                    scanf("%d", &elev_time);
                    printf("Enter the Power consumed by each in kW (decimal up to 2 digits is permitted): ");
                    scanf("%lf", &pow_elev);
                    power += pow_elev * elev_time * elevator * 30; // Total for the month
                }
            }  

            printf("No. of lights/tubes in office: ");
            scanf("%d", &lights);
            printf("Enter the daily usage of the lights in hours (integers only): ");
            scanf("%d", &light_time);
            printf("Enter the Power consumed by each light in kW (decimal up to 2 digits is permitted): ");
            scanf("%lf", &pow_light);
            power += pow_light * light_time * lights * 30; // Total for the month

            printf("No. of fans in office: ");
            scanf("%d", &fans);
            printf("Enter the daily usage of the fans in hours (integers only): ");
            scanf("%d", &fans_time);
            printf("Enter the Power consumed by each fan in kW (decimal up to 2 digits is permitted): ");
            scanf("%lf", &pow_fan);
            power += pow_fan * fans_time * fans * 30; // Total for the month

            printf("No. of desk computers in office: ");
            scanf("%d", &desk_pcs);
            printf("Enter the daily usage of the computers in hours (integers only): ");
            scanf("%d", &desk_pc_time);
            printf("Enter the Power consumed by each desk PC in kW (decimal up to 2 digits is permitted): ");
            scanf("%lf", &pow_pc);
            power += pow_pc * desk_pc_time * desk_pcs * 30; // Total for the month

            printf("No. of air conditioners in office: ");
            scanf("%d", &acs);
            printf("Enter the daily usage of the ACs in hours (integers only): ");
            scanf("%d", &ac_time);
            printf("Enter the Power consumed by each AC in kW (decimal up to 2 digits is permitted): ");
            scanf("%lf", &pow_ac);
            power += pow_ac * ac_time * acs * 30; // Total for the month

            units = (int)(power + 0.5);  // Rounding to nearest integer
            double Bill = calculate_bill(power, 1); // power is in kWh, hours is effectively 1 for the total bill

            // Print bill details
            print_bill(month, name, type, cust_id, telephone, Bill, units);

        } else if (com_type == 2) {
            int num_machines;
            int i;
            double power = 0;
            double total_bill = 0.0;
            double pow_light, pow_fan;
            int units;

            // Input for machines
            printf("Enter the number of machines: ");
            scanf("%d", &num_machines);

            // Use dynamic memory allocation
            float *machine_power_ratings = malloc(num_machines * sizeof(float));
            float *machine_hours_used = malloc(num_machines * sizeof(float));

            // Check for successful allocation
            if (machine_power_ratings == NULL || machine_hours_used == NULL) {
                printf("Memory allocation failed!\n");
                return 1; // Exit on memory allocation failure
            }

            // Input power ratings and hours used for each machine
            for (i = 0; i < num_machines; i++) {
                printf("Enter power rating (in kW) for machine %d: ", i + 1);
                scanf("%f", &machine_power_ratings[i]);
                printf("Enter hours used for machine %d: ", i + 1);
                scanf("%f", &machine_hours_used[i]);
            }

            // Calculate the bill for machines
            for (i = 0; i < num_machines; i++) {
                float bill = calculate_bill(machine_power_ratings[i], machine_hours_used[i]);
                printf("Bill for machine %d: Rs. %.2f\n", i + 1, bill);
                total_bill += bill;
                power += machine_power_ratings[i] * machine_hours_used[i];
            }

            units = (int)(power + 0.5); // Total kWh consumed
            free(machine_power_ratings); // Free the dynamically allocated memory
            free(machine_hours_used);

            // Print bill details
            print_bill(month, name, type, cust_id, telephone, total_bill, units);
        } else {
            printf("Invalid commercial type selected!\n");
            return 1; // Exit on invalid selection
        }
    } else if (strcmp(type, "domestic") == 0) {
        int dom_type;
        printf("What is the type of your domestic space? (answer in 1 or 2)\n 1) House\n 2) Society\n");
        scanf("%d", &dom_type);
        
        // double total_power = 0.0;
        int total_units = 0;

        if (dom_type == 1) {
            // House
            int lights, fans, acs, days;
            double pow_light, pow_fan, pow_ac;
            int light_time, fans_time, ac_time;

            printf("Enter the number of days in the month for billing: ");
            scanf("%d", &days);
            printf("Enter number of lights: ");
            scanf("%d", &lights);
            printf("Enter power consumed by each light in kW: ");
            scanf("%lf", &pow_light);
            printf("Enter daily usage of the lights in hours: ");
            scanf("%d", &light_time);
            total_power += calculate_bill(pow_light * lights, light_time * days);

            printf("Enter number of fans: ");
            scanf("%d", &fans);
            printf("Enter power consumed by each fan in kW: ");
            scanf("%lf", &pow_fan);
            printf("Enter daily usage of the fans in hours: ");
            scanf("%d", &fans_time);
            total_power += calculate_bill(pow_fan * fans, fans_time * days);

            printf("Enter number of air conditioners: ");
            scanf("%d", &acs);
            printf("Enter power consumed by each AC in kW: ");
            scanf("%lf", &pow_ac);
            printf("Enter daily usage of the ACs in hours: ");
            scanf("%d", &ac_time);
            total_power += calculate_bill(pow_ac * acs, ac_time * days);

            total_units = (int)(total_power + 0.5); // Total kWh consumed
        } else if (dom_type == 2) {
            // Society
            int num_flats, lights_per_flat, fans_per_flat, acs_per_flat, sec_cams, days, light_time, fans_time, ac_time, cam_time;
            double pow_light, pow_fan, pow_ac, pow_cam;

            printf("Enter the number of floors in the society: ");
            scanf("%d", &num_flats);
            printf("Enter the number of days in the month for billing: ");
            scanf("%d", &days);
            printf("Enter the power consumed by each light in kW: ");
            scanf("%lf", &pow_light);
            printf("Enter the number of lights per looby on all flors: ");
            scanf("%d", &lights_per_flat);
            printf("Enter the daily usage of the lights in hours: ");
            scanf("%d", &light_time);

            total_power += calculate_bill(pow_light * lights_per_flat * num_flats, light_time * days);

            printf("Enter the power consumed by each fan in kW: ");
            scanf("%lf", &pow_fan);
            printf("Enter the number of fans in club house and security cabin (if it exists): ");
            scanf("%d", &fans_per_flat);
            printf("Enter the daily usage of the fans in hours: ");
            scanf("%d", &fans_time);

            total_power += calculate_bill(pow_fan * fans_per_flat, fans_time * days);

            printf("Enter the power consumed by each AC in kW (if it is present in the clubhouse, 0 if not present): ");
            scanf("%lf", &pow_ac);
            printf("Enter the number of ACs in the club house (0 if not present): ");
            scanf("%d", &acs_per_flat);
            printf("Enter the daily usage of the ACs in hours (0 if not present): ");
            scanf("%d", &ac_time);

            printf("Enter the number of cctv cameras in the society: ");
            scanf("%d", &sec_cams);
            printf("Enter the power consumed by each light in kW: ");
            scanf("%lf", &pow_cam);
            printf("Enter the daily usage of the lights in hours: ");
            scanf("%d", &cam_time);

            total_power += calculate_bill(pow_cam * sec_cams, cam_time * days);

            // total_power += calculate_bill(pow_light * lights_per_flat * num_flats, light_time * days);

            total_power += calculate_bill(pow_ac * acs_per_flat * num_flats, ac_time * days);

            total_units = (int)(total_power + 0.5); // Total kWh consumed
        } else {
            printf("Invalid domestic type selected!\n");
            return 1; // Exit on invalid selection
        }

        // Print the total bill
        double total_bill = calculate_bill(total_power, 1); // Total power is in kWh
        print_bill(month, name, type, cust_id, telephone, total_bill, total_units);
    } else {
        printf("Invalid customer type entered!\n");
        return 1; // Exit on invalid selection
    }

    // Delay handling
    int delay;
    printf("How many days have passed since the bill was given to the consumer? ");
    scanf("%d", &delay);

    if (delay > 10) {
        double total_bill = calculate_bill(total_power, 1);
        total_bill += 2000 + (delay - 10) * 100;  // Adding fines
        printf("Total bill after delay penalties: Rs. %.2lf\n", total_bill);
    }

    return 0;
}
