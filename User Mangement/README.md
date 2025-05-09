# 👤 User Management System in C

This is a simple **User Management System** developed in C for educational purposes. It allows users to register and log in, with secure password input (masked using asterisks `*`). It supports both **Windows** and **Linux/macOS** platforms.

---

## 🚀 Features

- ✅ Register new users (up to 10 users)
- 🔐 Secure password entry (input masked)
- 📲 Login verification
- 💾 Uses in-memory storage (struct-based)
- 🖥️ Cross-platform terminal handling

---

## 🧠 Concepts Used

- Structures in C
- String handling
- Secure terminal input using `conio.h` (Windows) and `termios.h` (Linux/macOS)
- Cross-platform compatibility
- Command-line menu interaction

---

## 🔧 How to Compile and Run

### On Windows:
```bash
gcc user_management.c -o user_management.exe
user_management.exe
