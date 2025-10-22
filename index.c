#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "logic.h"

// Function to clear the console based on the operating system
void cls() {
    #if defined(_WIN32) || defined(_WIN64)  // If the program is running on Windows
        system("cls");                     // Clear console in Windows
    #else                                   // For Linux, macOS, and Unix-like systems
        system("clear");                   // Clear console in Linux/macOS
    #endif
}

// Main function of the Tic-Tac-Toe game
int main() {

    // Initialize the game board (three rows with three cells each)
    char rowA[3] = {' ',' ',' '};
    char rowB[3] = {' ',' ',' '};
    char rowC[3] = {' ',' ',' '};

    // Current player index (0 - X, 1 - O)
    int currentPlayerIndex = 0;
    // Move counter
    int moveCount = 0;

    char currentPlayer = 'X'; // Start with player X
    char message[50] = "";    // Message to display to the user (errors, winner, etc.)

    // Main game loop
    while (1) {
        int validMove = 0; // Flag to indicate whether the move is valid

        // Print the current game board
        printf("    1   2   3  \n");
        printf("  ┌───┬───┬───┐ \n");
        printf("A │ %c │ %c │ %c │ \n", rowA[0], rowA[1], rowA[2]);
        printf("  ├───┼───┼───┤\n");
        printf("B │ %c │ %c │ %c │\n", rowB[0], rowB[1], rowB[2]);
        printf("  ├───┼───┼───┤\n");
        printf("C │ %c │ %c │ %c │\n", rowC[0], rowC[1], rowC[2]);
        printf("  └───┴───┴───┘\n");

        // Display message (errors, winner, etc.)
        printf("%s\n", message);

        // Read user input (e.g., "1A", "2B", "3C")
        char userInput[10];
        fgets(userInput, sizeof(userInput), stdin);
        userInput[1] = toupper((unsigned char)userInput[1]); // Convert second character to uppercase

        // If user enters 'q' — quit the game
        if (userInput[0] == 'q') {
            break;
        }
        // If user enters 'r' — restart the game
        else if (userInput[0] == 'r') {
            // Reset all cells to empty
            for (int i = 0; i < 3; i++) {
                rowA[i] = ' ';
                rowB[i] = ' ';
                rowC[i] = ' ';
            }

            // Reset game state
            moveCount = 0;              // Reset move counter
            currentPlayerIndex = 0;     // Set player index to X
            currentPlayer = 'X';        // Current player is X
            message[0] = '\0';          // Clear message text

            cls();                      // Clear console
            continue;                   // Restart the game loop
        }

        // Remove newline character from input if present
        size_t len = strlen(userInput);
        if (len > 0 && userInput[len - 1] == '\n') {
            userInput[len - 1] = '\0';
        }

        // Validate input format: number (1-3) + letter (A-C)
        if ((userInput[0] == '1' || userInput[0] == '2' || userInput[0] == '3') &&
            (userInput[1] == 'A' || userInput[1] == 'B' || userInput[1] == 'C')) {

            // Assign the move to the correct cell
            switch (userInput[0]) {
                case '1':
                    if (userInput[1] == 'A' && rowA[0] == ' ') { rowA[0] = currentPlayer; validMove = 1; }
                    else if (userInput[1] == 'B' && rowB[0] == ' ') { rowB[0] = currentPlayer; validMove = 1; }
                    else if (userInput[1] == 'C' && rowC[0] == ' ') { rowC[0] = currentPlayer; validMove = 1; }
                    else strcpy(message, "Cell is occupied!\n");
                break;

                case '2':
                    if (userInput[1] == 'A' && rowA[1] == ' ') { rowA[1] = currentPlayer; validMove = 1; }
                    else if (userInput[1] == 'B' && rowB[1] == ' ') { rowB[1] = currentPlayer; validMove = 1; }
                    else if (userInput[1] == 'C' && rowC[1] == ' ') { rowC[1] = currentPlayer; validMove = 1; }
                    else strcpy(message, "Cell is occupied!\n");
                break;

                case '3':
                    if (userInput[1] == 'A' && rowA[2] == ' ') { rowA[2] = currentPlayer; validMove = 1; }
                    else if (userInput[1] == 'B' && rowB[2] == ' ') { rowB[2] = currentPlayer; validMove = 1; }
                    else if (userInput[1] == 'C' && rowC[2] == ' ') { rowC[2] = currentPlayer; validMove = 1; }
                    else strcpy(message, "Cell is occupied!\n");
                break;
            }
        }
        else {
            strcpy(message, "Incorrect character!\n"); // Invalid input
        }

        // If the move was valid
        if (validMove) {
            moveCount += 1;        // Increment move counter
            strcpy(message, "");   // Clear previous messages
            strcpy(userInput, ""); // Clear input buffer

            // Check for a winner
            if (moveCount > 4 && Logic(rowA, rowB, rowC, currentPlayer))
                sprintf(message, "Winner: %c", currentPlayer);

            // Switch player for next turn
            currentPlayerIndex = 1 - currentPlayerIndex;
            currentPlayer = (currentPlayerIndex == 0) ? 'X' : 'O';
        }

        // If all cells are filled — draw
        if (moveCount == 9) {
            strcpy(message, "Draw! No winner.\n");
            cls(); // Clear console
            continue;
        }

        // Clear console before next move
        cls();
        continue;
    }
}
