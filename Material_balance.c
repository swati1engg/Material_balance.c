

#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int c; // Variable used to clear the input buffer
    
    // Core variables for the chemical math
    double a1, x1, x3;
    double a2, a3;
    double fraction_x1, fraction_x3;

    do {
        // --- DISPLAY 
        printf("     CHEMICAL PROCESS MATERIAL BALANCE SOLVER\n");
        printf("===================================================\n");
        printf("  1. Solve Mixing/Dilution Tank Balance\n");
        printf("  2. Project Specifications & Engineering Principles\n");
        printf("  3. Exit Program\n");
        printf("---------------------------------------------------\n");
        printf("Enter your choice (1-3): ");
        
        // Input validation to check if the user entered a valid number
        if (scanf("%d", &choice) != 1) {
            printf("\n Invalid input format!enter a number.\n");
            // Clear input buffer manually inline
            while ((c = getchar()) != '\n' && c != EOF); 
            continue;
        }
        
        // --- PROCESS USER MENU CHOICE ---
        if (choice == 1) {
            printf("\n--- Stream 1: Inlet Concentration Stream ---\n");
            printf("Enter mass flow rate a1 (kg/hr): ");
            if (scanf("%lf", &a1) != 1) { 
                printf(" Invalid numeric value.\n"); 
                while ((c = getchar()) != '\n' && c != EOF); 
                continue; 
            }
            
            printf("Enter feed chemical concentration x1 (%%): ");
            if (scanf("%lf", &x1) != 1) { 
                printf("[ERROR] Invalid numeric value.\n"); 
                while ((c = getchar()) != '\n' && c != EOF); 
                continue; 
            }
            
            printf("\n--- Stream 3: Desired Target Product Stream ---\n");
            printf("Enter target concentration x3 (%%): ");
            if (scanf("%lf", &x3) != 1) { 
                printf("[ERROR] Invalid numeric value.\n"); 
                while ((c = getchar()) != '\n' && c != EOF); 
                continue; 
            }
            
            // --- INDUSTRIAL CONSTRAINT VALIDATION LAYER ---
            if (a1 <= 0 || x1 <= 0 || x3 <= 0) {
                printf("\n[PROCESS ERROR] Physical flow rates and concentrations must be greater than zero!\n");
                continue;
            }
            if (x1 > 100.0 || x3 > 100.0) {
                printf("\n[PROCESS ERROR] Mass fractions/concentrations cannot exceed 100%%!\n");
                continue;
            }
            if (x3 >= x1) {
                printf("\n[PROCESS ERROR] Target concentration (%.2f%%) must be LESS than inlet feed (%.2f%%) to achieve dilution via pure solvent stream!\n", x3, x1);
                continue;
            }
            
            // --- CORE MASS BALANCE ALGORITHM ---
            // Convert percentage parameters to decimal fractions
            fraction_x1 = x1 / 100.0;
            fraction_x3 = x3 / 100.0;
            
            // Algebraic solution matrix for steady-state equations
            a3 = (a1 * fraction_x1) / fraction_x3; // Solute balance tracking
            a2 = a3 - a1;                           // Bulk fluid balance tracking
            
            // --- DATA DISPLAY REPORT ---
            printf("\n================= CORRELATION REPORT =================\n");
            printf(" Process Configuration: Dilution of %.2f%% stream to %.2f%%\n", x1, x3);
            printf("------------------------------------------------------\n");
            printf(" -> Input Feed Flow (a1)        : %10.2f kg/hr\n", a1);
            printf(" -> Required Pure Solvent (a2)  : %10.2f kg/hr\n", a2);
            printf(" -> Total Blended Product (a3)  : %10.2f kg/hr\n", a3);
            printf("======================================================\n");
            
        } else if (choice == 2) {
            printf("\n===================================================\n");
            printf("            ENGINEERING SPECIFICATIONS\n");
            printf("===================================================\n");
            printf(" Equations:\n");
            printf("  1. Total Mass Conservation: a1 + a2 = a3\n");
            printf("  2. Component Mass Conservation: a1*x1 = a3*x3\n\n");
            printf("Assumptions:\n");
            printf("  - Steady-state operation (no mass accumulation)\n");
            printf("  - Perfect binary mixing condition\n");
            printf("  - Stream 2 is a pure solvent/water stream (x2 = 0%%)\n");
            printf("===================================================\n");
            
        } else if (choice == 3) {
            printf("\nExiting solver. Framework ready for 2nd-year Stoichiometry!\n");
            
        } else {
            printf("\n[ERROR] Invalid choice. Please enter a value between 1 and 3.\n");
        }
        
    } while(choice != 
      return 0; 

      
