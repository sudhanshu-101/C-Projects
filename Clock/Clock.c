// Clock
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void fill_time(char *, int);
void fill_date(char *);
int input_format();
void clear_screen();

int main()
{
    char buffer[50], date[100]; // Allocate buffers
    int format = input_format();

    while (1)
    {
        fill_time(buffer, format); // Refresh time
        fill_date(date);           // Refresh date
        clear_screen();            // Clear the screen

        printf("\n\nCurrent Time: %s\n", buffer); // Print time
        printf("Date: %s\n", date);               // Print date

        sleep(1); // Delay 1 second
    }

    return 0;
}

void fill_time(char *buffer, int format)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    if (format == 1)
        strftime(buffer, 50, "%H:%M:%S", current_time); // 24-hour format
    else
        strftime(buffer, 50, "%I:%M:%S %p", current_time); // 12-hour format
}

void fill_date(char *buffer)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 100, "%A, %B %d, %Y", current_time); // Full date format
}

void clear_screen()
{
#ifdef _WIN32
    system("cls"); // Windows - Clear the console screen
#else
    system("clear"); // Linux/macOS - Clear the console screen
#endif
}

int input_format()
{
    int format;
    printf("\nChoose the time format:");
    printf("\n1. 24 Hour format");
    printf("\n2. 12 Hour format");
    printf("\nMake a choice (1/2): ");
    scanf("%d", &format);

    // Validate input
    while (format != 1 && format != 2)
    {
        printf("Invalid choice! Please enter 1 or 2: ");
        scanf("%d", &format);
    }

    return format;
}
