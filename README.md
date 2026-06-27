# Connect 4 Game (C++)

A robust, console-based implementation of the classic **Connect 4** game written in C++. This project was developed as part of **Task 4** during my internship at **InternPe**.

The game features a standard $6 \times 7$ grid where two players take turns dropping their tokens from the top into a column of their choice. The first player to form a horizontal, vertical, or diagonal line of four of their own tokens wins the game!

---

## 🚀 Features

* **Interactive Command Line Interface:** Clean, text-based grid visualization rendered dynamically in the console.
* **Realistic Gravity Logic:** Tokens fall to the lowest available row within the selected column.
* **Robust Input Validation:** Prevents out-of-bounds selections, handles invalid non-integer inputs without crashing, and alerts players if a column is already full.
* **Comprehensive Win Detection:** Automatically scans the board for 4-in-a-row matches across all axes:
  * Horizontal (`-`)
  * Vertical (`|`)
  * Descending Diagonal (`\`)
  * Ascending Diagonal (`/`)
* **Draw Condition Handling:** Detects when the board is completely filled without a winner.

---
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/41d09acb-6142-43d4-9884-b3627b20772d" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/f2bc7959-6a49-4ef9-bbe8-e091bc5748e8" />


## 🛠️ Requirements & Compilation

To compile and run this game, you will need a C++ compiler supporting at least **C++11** (such as GCC/G++ or Clang).

### Step-by-Step Compilation

1. **Clone or download** the repository containing the source code file (e.g., `main.cpp`).
2. Open your terminal or command prompt and navigate to the project directory.
3. Compile the code using `g++`:
   ```bash
   g++ -std=c++11 main.cpp -o connect4
