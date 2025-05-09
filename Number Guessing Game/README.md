# 🎯 Number Guessing Game (C)

This is a **simple number guessing game** implemented in **C**. The program randomly generates a number between **1 and 10** 🔢, and the user 🎮 has to guess it. After each guess, the game provides feedback and keeps track of how many attempts 🧠 you made. The game ends when the correct number is guessed ✅.

---

## ✨ Features

- 🎲 Random number generation using the `rand()` function.
- 🚧 Input validation to ensure the guess is within the range (1–10).
- 🔢 Tracks the number of guesses and displays the count at the end.
- 📣 Provides feedback for each guess:
  - ✅ Correct guess
  - ❌ Incorrect guess
- 🧾 Reveals the correct number after the game ends.

---

## 🛠️ How to Run

### 1️⃣ Clone the Repository

Download or clone this repository to your local machine 🖥️.

### 2️⃣ Compile the Code

Use a C compiler such as **GCC** to compile the program. Open your terminal and navigate to the folder where the `.c` file is saved. Run the following command:

```bash
gcc number_guessing_game.c -o number_guessing_game
