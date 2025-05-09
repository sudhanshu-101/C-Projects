// Progress Bar
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

const int BAR_LENGTH = 50;
const int MAX_TASKS = 5;

typedef struct
{
    int id;
    int progress;
    int steps;
} Task;

void print_bar(Task task);
void clear_screen();

int main()
{
    srand(time(NULL));
    Task tasks[MAX_TASKS];

    // Initialize tasks
    for (int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].steps = rand() % 5 + 1;  // Random step increments between 1 and 5
    }

    int tasks_incomplete = 1;
    while (tasks_incomplete)
    {
        tasks_incomplete = 0;  // Assume all tasks are complete initially

        clear_screen();

        // Update and display each task's progress
        for (int i = 0; i < MAX_TASKS; i++)
        {
            tasks[i].progress += tasks[i].steps;  // Increment progress by steps

            // Ensure progress doesn't exceed 100%
            if (tasks[i].progress > 100)
            {
                tasks[i].progress = 100;
            }

            // Check if any task is still incomplete
            if (tasks[i].progress < 100)
            {
                tasks_incomplete = 1;
            }

            print_bar(tasks[i]);  // Print progress bar for each task
        }

        sleep(1); // Sleep for 1 second
    }

    printf("\nAll tasks completed!\n");

    return 0;
}

// Function to clear the screen for better visualization of the progress bar
void clear_screen()
{
#ifdef _WIN32
    system("cls");  // Windows
#else
    system("clear");  // Linux/macOS
#endif
}

// Function to print the progress bar
void print_bar(Task task)
{
    int bars_to_show = (task.progress * BAR_LENGTH) / 100;  // Calculate how many bars to show

    printf("\nTask %d: [", task.id);

    // Print filled bars
    for (int i = 0; i < bars_to_show; i++)
    {
        printf("=");
    }

    // Print empty bars
    for (int i = bars_to_show; i < BAR_LENGTH; i++)
    {
        printf(" ");
    }

    printf("] %d%%", task.progress);  // Display the percentage progress
}
