# 🏦 Bank Management System 💰

A simple Bank Management System built in **C**. It allows users to perform basic banking operations like creating an account, depositing money, withdrawing money, checking the balance, and listing all accounts. The system uses a file-based approach to store account information and perform transactions.

## 📋 Features ✨

- **Create Account**: 🎉 Allows users to create a new bank account.
- **Deposit Money**: 💵 Users can deposit money into their account.
- **Withdraw Money**: 💸 Allows users to withdraw money from their account.
- **Check Balance**: 💳 Users can check the balance of their account.
- **List All Accounts**: 📜 Displays a list of all accounts stored in the system.

## 🚀 How to Run 🖥️

1. **Clone the Repository** or **Download the Files** 📥.
2. Open the terminal or command prompt and navigate to the folder where you saved the files 🖱️.
3. **Compile the C Code** using your preferred compiler ⚙️:
   - For GCC: `gcc -o bank_system bank_system.c`
4. **Run the Program**:
   - On Windows: `bank_system.exe`
   - On Linux/Mac: `./bank_system`
5. The menu will be displayed where you can choose to create an account, deposit, withdraw, check balance, or list all accounts 🔄.

## 🛠 Technologies Used 🧰

- **Programming Language**: C 🖥️
- **File Handling**: Used to store account information and transactions in a binary file (`account.dat`) 📁.

## 🔧 Functions 🧑‍💻

### 1. `create()`
- **Purpose**: 🏠 Creates a new account with a name and account number. The initial balance is set to 0.
- **File**: `account.dat`

### 2. `deposit()`
- **Purpose**: 💳 Deposits money into an existing account.
- **Input**: Account number and amount to deposit 💵.
- **Output**: Updates the balance in the file 📝.

### 3. `withdraw()`
- **Purpose**: 🏧 Withdraws money from an existing account, if the balance is sufficient.
- **Input**: Account number and amount to withdraw 💸.
- **Output**: Updates the balance in the file 📝.

### 4. `check()`
- **Purpose**: 💳 Checks the balance of an account.
- **Input**: Account number 🔢.
- **Output**: Displays the balance 🏦.

### 5. `listAccounts()`
- **Purpose**: 📑 Lists all the bank accounts stored in the system, displaying their account number, name, and balance.
- **Output**: Displays all account information 👥.

## ⚙️ File Operations 💾

The system performs the following file operations:

- **Opening the file**: All operations that modify account details (create, deposit, withdraw) require reading and writing to a binary file `account.dat` 📁.
- **File format**: The accounts are stored in the binary format using `fwrite()` and `fread()` 📝.
- **Error handling**: ❌ If the file cannot be opened (e.g., if it doesn’t exist), an error message is displayed ⚠️.

## 📂 Files 📁

- **account.dat**: This file is used to store account details in binary format.
  - Each account contains:
    - **Name**: Account holder’s name (string) ✍️.
    - **Account Number**: Unique account number (integer) 🔢.
    - **Balance**: Current balance in the account (float) 💵.

## 📝 Example Workflow 💼

1. **Create Account**: 🏠
   - The user is prompted to enter their name and a unique account number.
   - The account is created with an initial balance of Rs. 0.00 💸.

2. **Deposit Money**: 💵
   - The user enters their account number and the amount they want to deposit 💰.
   - The balance is updated accordingly 💳.

3. **Withdraw Money**: 🏧
   - The user enters their account number and the amount they wish to withdraw 💸.
   - If sufficient funds are available, the withdrawal is successful; otherwise, an error message is displayed 🚫.

4. **Check Balance**: 💳
   - The user enters their account number 🔢 to view their current balance 🏦.

5. **List All Accounts**: 📜
   - The system displays a list of all accounts with their details (account number, name, and balance) 📑.


## 🚧 Limitations 🚫

- The system does not support account deletion 🗑️.
- The user must remember the account number for depositing, withdrawing, and checking the balance 🔢.
- No advanced security features (e.g., password protection) are implemented 🔒.

## 💡 Future Improvements 🔮

- Implement user authentication (username/password) 🔑.
- Support for deleting accounts 🗑️.
- Transaction history tracking 📜.
- More user-friendly interfaces, such as a graphical user interface (GUI) 🖥️.

## 📄 License 📜

This project is open-source and available under the MIT License. Feel free to fork, modify, and contribute to the project 🙌.

---

### 🛠 Built with 💻
- **C** programming language 🖥️
- **File handling** for storing account data 💾

---

### 😊 If you found this project helpful, feel free to star ⭐ this repository or share it! 📤

## 📣 Feedback 💬

If you have any feedback, please reach out to us at 📧 **sudhanshu95084145@gmail.com**. We would love to hear from you! 💌
