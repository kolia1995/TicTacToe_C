#include <stdio.h>

// Function to check if the current player has won
// Returns 1 if the player wins, 0 otherwise
int Logic(char rowA[3], char rowB[3], char rowC[3], char currentPlayer) {
    
    // Check horizontal lines
    if ((rowA[0] == currentPlayer && rowA[1] == currentPlayer && rowA[2] == currentPlayer) || // Top row
        (rowB[0] == currentPlayer && rowB[1] == currentPlayer && rowB[2] == currentPlayer) || // Middle row
        (rowC[0] == currentPlayer && rowC[1] == currentPlayer && rowC[2] == currentPlayer) || // Bottom row

        // Check vertical lines
        (rowA[0] == currentPlayer && rowB[0] == currentPlayer && rowC[0] == currentPlayer) || // Left column
        (rowA[1] == currentPlayer && rowB[1] == currentPlayer && rowC[1] == currentPlayer) || // Middle column
        (rowA[2] == currentPlayer && rowB[2] == currentPlayer && rowC[2] == currentPlayer) || // Right column

        // Check diagonals
        (rowA[0] == currentPlayer && rowB[1] == currentPlayer && rowC[2] == currentPlayer) || // Diagonal from top-left to bottom-right
        (rowA[2] == currentPlayer && rowB[1] == currentPlayer && rowC[0] == currentPlayer))   // Diagonal from top-right to bottom-left
    {
        return 1; // The player wins
    } 
    else {
        return 0; // No winner
    }
};
