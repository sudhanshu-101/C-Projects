// User Management

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#include <conio.h> // Windows-specific for getch()
#else
#include <termios.h> // POSIX-specific for tcgetattr, tcsetattr
#endif

#define MAX_USER 10
#define CREDENTIAL_LENGTH 30

typedef struct
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH]; // Passwords should be stored securely (consider hashing)
} User;

User users[MAX_USER];
int user_count = 0;

int login_user(); // Return the user index
void register_user();
void fix_fgets_input(char *);
void input_credentials(char *, char *);

int main()
{
    int option, user_index;
    while (1)
    {
        printf("\n1. Register \n2. Login \n3. Exit\nSelect an option: ");
        scanf("%d", &option);
        getchar(); // Consume extra newline

        switch (option)
        {
        case 1:
            register_user();
            break;
        case 2:
            user_index = login_user();
            if (user_index >= 0)
            {
                printf("\nLogin successful! Welcome, %s!\n", users[user_index].username);
            }
            else
            {
                printf("\nLogin failed! Incorrect username or password.\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("\nPlease enter a valid option.\n");
            break;
        }
    }
    return 0;
}

void register_user()
{
    if (user_count >= MAX_USER)
    {
        printf("\nMaximum %d users supported! No more registrations allowed!\n", MAX_USER);
        return;
    }

    int new_index = user_count;
    printf("\nRegister a new user:");
    input_credentials(users[new_index].username, users[new_index].password);

    user_count++;
    printf("\nRegistration successful!\n");
}

int login_user()
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    input_credentials(username, password);

    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            return i; // User found, return index
        }
    }

    return -1; // Login failed
}

// Function to input username and password securely
void input_credentials(char *username, char *password)
{
    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);

    printf("Enter password: ");

#ifdef _WIN32
    // Windows: Use getch() to read password without echoing
    int i = 0;
    char ch;
    while ((ch = _getch()) != '\r') // Enter key ('\r') stops input
    {
        if (i < CREDENTIAL_LENGTH - 1)
        {
            if (ch == '\b' && i > 0) // Handle backspace
            {
                i--;
                printf("\b \b");
            }
            else if (ch != '\b')
            {
                password[i++] = ch;
                printf("*"); // Print * instead of character
            }
        }
    }
    password[i] = '\0';
    printf("\n"); // Move to the next line after password input

#else
    // Linux/macOS: Use termios to disable echo
    struct termios old_props, new_props;
    tcgetattr(STDIN_FILENO, &old_props); // Get current terminal properties
    new_props = old_props;
    new_props.c_lflag &= ~ECHO;                   // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props); // Apply new settings

    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < CREDENTIAL_LENGTH - 1)
    {
        if (ch == 127 || ch == '\b') // Handle backspace
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            password[i++] = ch;
            printf("*"); // Print * instead of character
        }
    }
    password[i] = '\0';
    printf("\n"); // Move to the next line after password input

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
#endif
}

// Function to fix fgets newline issue
void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0'; // Remove the newline character
}
