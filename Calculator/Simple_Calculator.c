// Simple calculator
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, res3, choice;
    float num4, num5, res6;

    while (1)
    {
        printf("\n1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Modulus \n6. Square \n7. Cube \n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user's choice

        switch (choice)
        {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f%f", &num4, &num5); // Reading two float numbers for addition
            res6 = num4 + num5;
            printf("The sum is: %.2f\n\n", res6);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f%f", &num4, &num5); // Reading two float numbers for subtraction
            res6 = num4 - num5;
            printf("The subtraction result is: %.2f\n\n", res6);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f%f", &num4, &num5); // Reading two float numbers for multiplication
            res6 = num4 * num5;
            printf("The multiplication result is: %.2f\n\n", res6);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f%f", &num4, &num5); // Reading two float numbers for division
            if (num5 == 0)
            {
                printf("Error! Division by zero is not allowed.\n\n");
            }
            else
            {
                res6 = num4 / num5;
                printf("The division result is: %.2f\n\n", res6);
            }
            break;

        case 5:
            printf("Enter two integers: ");
            scanf("%d%d", &num1, &num2); // Reading two integers for modulus
            if (num2 == 0)
            {
                printf("Error! Modulus by zero is not allowed.\n\n");
            }
            else
            {
                res3 = num1 % num2;
                printf("The modulus result is: %d\n\n", res3);
            }
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%f", &num4); // Reading a single float number for square
            res6 = num4 * num4;
            printf("The square is: %.2f\n\n", res6);
            break;

        case 7:
            printf("Enter a number: ");
            scanf("%f", &num4); // Reading a single float number for cube
            res6 = num4 * num4 * num4;
            printf("The cube is: %.2f\n\n", res6);
            break;

        case 8:
            printf("Exiting...\n");
            exit(0); // Exit the program
            break;

        default:
            printf("Please enter a valid choice.\n\n"); // Invalid choice
        }
    }

    return 0;
}
