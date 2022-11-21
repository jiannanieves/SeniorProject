// gcc test.c -o test
// .\test

#include <stdio.h>
#include <string.h>

// M x N matrix
#define ROWS 16
#define COLS 64

int main(void)
{
    int matrix[ROWS][COLS] = { 0 };

    int T[15][11] = {  
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}
    };

    // Kristella - A B C D E F G H
    // Jianna    - I J K L M N O P
    // Nicolette - Q R S T U V X Y Z

    int size_row = sizeof(T)/sizeof(T[0]);
    int size_col = sizeof(T[0])/sizeof(T[0][0]);

    // fill the 2d array with letters
    char text[]= "T";
    int letter[15][11];
    memcpy(letter, T, sizeof(T)); // where to change letter

    // fill the 2d array with letters
    for (int r = 0; r < size_row; r++) {
        if (r == size_row) {
            break;
        }
        
        for (int c = 0; c < size_col; c++) {
            if (c == size_col) {
                break;
            }
            matrix[r][c] = letter[r][c];
        }
    }

    // print the 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}