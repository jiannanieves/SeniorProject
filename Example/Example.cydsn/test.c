// gcc test.c -o test
// .\test

#include <stdio.h>
#include <string.h>

// M x N matrix
#define ROWS 16
#define COLS 64



typedef struct {
    int m[15][11];
} letter2d;

letter2d get_letter_matrix(char c) {
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
    letter2d result;
    if (c == 'T') {
        // result.m = T;
        memcpy(result.m, T, sizeof(T));
    }
    else {
        memcpy(result.m, 0, sizeof(0));
    }
    return result;
}

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

    char text[3] = {'T', 'T', 'T'};

    letter2d letter;
    int letters_concat[15][sizeof text * 11] = { 0 };
    
    int start_col;
    int letter_row_sz;
    int letter_col_sz;
    for (int d = 0; d < sizeof text; d++) {
        letter = get_letter_matrix(text[d]);
        letter_row_sz = sizeof(letter.m)/sizeof(letter.m[0]);
        letter_col_sz = sizeof(letter.m[0])/sizeof(letter.m[0][0]);
        start_col = 11 * d;

        for (int r = 0; r < letter_row_sz; r++) {
            start_col = 11 * d;
            for (int c = 0; c < letter_col_sz; c++) {
                // matrix[r][start_col] = letter.m[r][c];
                letters_concat[r][start_col] = letter.m[r][c];
                start_col++;
            }
        }
    }

    // print the 2D array
    int sr = sizeof(letters_concat)/sizeof(letters_concat[0]);
    int sc = sizeof(letters_concat[0])/sizeof(letters_concat[0][0]);
    // for (int i = 0; i < sr; i++) {
    //     for (int j = 0; j < sc; j++) {
    //         printf("%d ", letters_concat[i][j]);
    //     }
    //     printf("\n");
    // }

    // fill the 2d array with letters
    for (int r = 0; r < sr; r++) {
        for (int c = 0; c < sc; c++) {
            matrix[r+1][c+1] = letters_concat[r][c];
        }
    }

    // print the 2d array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


