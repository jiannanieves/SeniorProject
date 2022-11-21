// gcc test.c -o test
// .\test

#include <stdio.h>

// M x N matrix
#define ROWS 16
#define COLS 64

int main(void)
{
    int matrix[ROWS][COLS] = { 0 };

    int T[10][7] = {  
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
    };

    int size_row = sizeof(T)/sizeof(T[0]);
    int size_col = sizeof(T[0])/sizeof(T[0][0]);

    // fill the 2d array
    for (int r = 0; r < ROWS; r++) {
        if (r == size_row) {
            break;
        }
        
        for (int c = 0; c < COLS; c++) {
            if (c == size_col) {
                break;
            }
            matrix[r][c] = T[r][c];
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