// Number guessing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, random1, min = 1, max = 10, count = 0;
    srand(time(0)); // Seed the random number generator with the current time

    // Generate random number only once
    random1 = min + (rand() % (max - min + 1));

    do
    {
        printf("\nGuess the number from %d to %d: ", min, max);
        scanf("%d", &guess);
        count++;

        if (guess < min || guess > max)
        {
            printf("Please enter a number between %d and %d.\n", min, max);
            continue;
        }

        if (guess == random1)
        {
            printf("🎉 Congratulations! You guessed the number in %d attempt(s)!\n", count);
            break;
        }
        else
        {
            printf("❌ Wrong guess!\n");
            printf("Computer had: %d\n", random1); // optional: reveal after game instead
            printf("You guessed: %d\n", guess);
        }

    } while (guess != random1);

    return 0;
}
