#include <stdio.h>

/**
 * main - Entry point for the simple calculator program
 *
 * Description: Prints a simple calculator menu and reads the user's
 * selection. Loops until the user selects 0 to quit, and validates
 * inputs.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int choice;
    float A;
    float B;
    int c;

    do {
        printf("Simple Calculator\n");
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");

        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid choice\n");
            while ((c = getchar()) != '\n' && c != EOF);
            choice = -1; 
            continue;
        }

        if (choice == 0)
        {
            printf("Bye!\n");
        }
        else if (choice < 1 || choice > 4)
        {
            printf("Invalid choice\n");
        }
        else
        {
            while (1)
            {
                printf("A: ");
                if (scanf("%f", &A) == 1)
                {
                    break;
                }
                printf("Invalid number\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }

            while (1)
            {
                printf("B: ");
                if (scanf("%f", &B) == 1)
                {
                    break;
                }
                printf("Invalid number\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }

            switch (choice)
            {
            case 1:
                printf("Result: %g\n", A + B);
                break;
            case 2:
                printf("Result: %g\n", A - B);
                break;
            case 3:
                printf("Result: %g\n", A * B);
                break;
            case 4:
                if (B == 0)
                {
                    printf("Error: division by zero\n");
                }
                else
                {
                    printf("Result: %g\n", A / B);
                }
                break;
            }
        }

    } while (choice != 0);

    return (0);
}
