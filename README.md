# Tic Tac Toe Game

This is a simple console-based Tic Tac Toe game implemented in C++.

## Features
- Two-player gameplay.
- Players can choose their markers (X or O).
- Prevents players from selecting a column that is already fully occupied.
- Displays warnings if a player tries to select an already occupied slot or column.
- Declares the winner or a tie at the end of the game.

## How to Play
1. Player 1 chooses their marker (X or O).
2. Players take turns entering the slot number (1-9) where they want to place their marker.
3. The game board is updated after each move.
4. If a player tries to select a slot in a fully occupied column, a warning is displayed, and the player is prompted to choose a different slot.
5. The game ends when one player wins or all slots are filled, resulting in a tie.

## Compilation and Execution

### Prerequisites
- A C++ compiler (e.g., `g++`).

### Steps
1. Compile the code using the following command:
   ```bash
   g++ -o tictacto tictacto.cpp
   ```
2. Run the compiled program:
   ```bash
   ./tictacto
   ```

## Game Rules
- The game is played on a 3x3 grid.
- Players take turns placing their marker (X or O) in an empty slot.
- A player wins by placing three of their markers in a horizontal, vertical, or diagonal row.
- If all slots are filled and no player has won, the game ends in a tie.

## Example Gameplay
```
Player 1, choose your marker (X or O): X
-------------
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
-------------
It's Player 1's turn. Enter your slot: 5
-------------
| 1 | 2 | 3 |
-------------
| 4 | X | 6 |
-------------
| 7 | 8 | 9 |
-------------
```

## Author
This game was developed by Muhammed Rasil.

## License
This project is licensed under the MIT License.
