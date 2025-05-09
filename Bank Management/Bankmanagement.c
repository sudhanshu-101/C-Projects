// Bank Management
#include <stdio.h>
#include <string.h>

void create();
void deposit();
void withdraw();
void check();
void listAccounts(); // New feature to list all accounts

const char *ACCOUNT_FILE = "account.dat";

typedef struct
{
    char name[50];
    int acc_no;
    float balance;
} Account;

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n*** Bank Management System ***\n");
        printf("1. Create Account \n");
        printf("2. Deposit Money \n");
        printf("3. Withdraw Money \n");
        printf("4. Check Balance \n");
        printf("5. List All Accounts \n"); // Option to list all accounts
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            check();
            break;
        case 5:
            listAccounts(); // Call to list all accounts
            break;
        case 6:
            printf("\nExiting...\n");
            return 0;
        default:
            printf("\nPlease enter the correct options. \n");
        }
    }
    return 0;
}

void create()
{
    Account acc;

    FILE *file = fopen(ACCOUNT_FILE, "ab+");
    if (file == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    // Clear the input buffer
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\nEnter your name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0'; // Remove newline character

    printf("Enter your account number: ");
    scanf("%d", &acc.acc_no);
    acc.balance = 0;

    // Write the new account to the file
    if (fwrite(&acc, sizeof(acc), 1, file) != 1)
    {
        printf("Error writing to file!\n");
    }
    else
    {
        printf("\nAccount created successfully!\n");
    }

    fclose(file);
}

void deposit()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    int acc_no;
    float money;
    Account acc_r;
    int found = 0;

    printf("Enter the account number: ");
    scanf("%d", &acc_no);
    printf("Enter amount to deposit: ");
    scanf("%f", &money);

    while (fread(&acc_r, sizeof(acc_r), 1, file))
    {
        if (acc_r.acc_no == acc_no)
        {
            acc_r.balance += money;
            fseek(file, -sizeof(acc_r), SEEK_CUR);
            if (fwrite(&acc_r, sizeof(acc_r), 1, file) != 1)
            {
                printf("Error writing to file!\n");
                fclose(file);
                return;
            }
            printf("\nSuccessfully deposited Rs.%.2f. New balance is Rs.%.2f\n", money, acc_r.balance);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account number %d not found.\n", acc_no);
    }

    fclose(file);
}

void withdraw()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    int acc_no;
    float money;
    Account acc_r;
    int found = 0;

    printf("Enter your account number: ");
    scanf("%d", &acc_no);
    printf("Enter the amount you wish to withdraw: ");
    scanf("%f", &money);

    while (fread(&acc_r, sizeof(acc_r), 1, file))
    {
        if (acc_r.acc_no == acc_no)
        {
            if (acc_r.balance >= money)
            {
                acc_r.balance -= money;
                fseek(file, -sizeof(acc_r), SEEK_CUR);
                if (fwrite(&acc_r, sizeof(acc_r), 1, file) != 1)
                {
                    printf("Error writing to file!\n");
                    fclose(file);
                    return;
                }
                printf("\nSuccessfully withdrawn Rs.%.2f. Remaining balance is Rs.%.2f\n", money, acc_r.balance);
            }
            else
            {
                printf("Insufficient balance!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account number %d not found.\n", acc_no);
    }

    fclose(file);
}

void check()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    int acc_no;
    Account acc_read;
    int found = 0;

    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    while (fread(&acc_read, sizeof(acc_read), 1, file))
    {
        if (acc_read.acc_no == acc_no)
        {
            printf("\nYour account balance is Rs.%.2f\n", acc_read.balance);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nAccount number %d not found.\n", acc_no);
    }

    fclose(file);
}

// New function to list all accounts
void listAccounts()
{
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    Account acc_r;
    int found = 0;

    printf("\nList of All Accounts:\n");
    printf("--------------------------------\n");
    while (fread(&acc_r, sizeof(acc_r), 1, file))
    {
        printf("Account Number: %d\n", acc_r.acc_no);
        printf("Name: %s\n", acc_r.name);
        printf("Balance: Rs.%.2f\n", acc_r.balance);
        printf("--------------------------------\n");
        found = 1;
    }

    if (!found)
    {
        printf("No accounts found.\n");
    }

    fclose(file);
}
