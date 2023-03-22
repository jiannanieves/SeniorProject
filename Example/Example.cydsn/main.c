/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <stdlib.h>
#include "project.h"
#include "letters.h"

// M x N matrix
#define ROWS 16
#define COLS 192
#define TEXT_CMD_ID1     0x24
#define TEXT_CMD_ID2     0x25
#define COLOR_CMD_ID     0x26
#define SCROLL_CMD_ID    0x27
#define ANIMATION_CMD_ID 0x28
#define CLEAR_CMD_ID     0x29

// Buffer for UART data
//char input[1];
char input[16];
int i = 0; // index 
// Store user text
//char text[1];
char text[16];

char text_line_one[16]; // store text on line one
char text_line_two[16]; // store text on line two
char color_opt[1];      // store color option
char scroll_opt[1];     // store scroll option
char animation_opt[1];  // store animation option
char clear_screen[1];   // toggle clear screen command

CY_ISR(RxIsr)
{
    rx_isr_ClearPending();
    while (UART_GetRxBufferSize() > 0) 
    {
        input[i] = UART_GetByte();
        i++;
    }
}

letter2d get_letter_matrix(char c) 
{
    letter2d result;
    int empty[15][11] = { 0 };
    switch (c) {
        case 'A':
            memcpy(result.m, A, sizeof(A));
            return result;
            break;
        case 'B':
            memcpy(result.m, B, sizeof(B));
            break;
        case 'C':
            memcpy(result.m, C, sizeof(C));
            break;
        case 'D':
            memcpy(result.m, D, sizeof(D));
            break;
        case 'E':
            memcpy(result.m, E, sizeof(E));
            break;
        case 'F':
            memcpy(result.m, F, sizeof(F));
            break;
        case 'G':
            memcpy(result.m, G, sizeof(G));
            break;
        case 'H':
            memcpy(result.m, H, sizeof(H));
            break;
        case 'I':
            memcpy(result.m, I, sizeof(I));
            break;
        case 'J':
            memcpy(result.m, J, sizeof(J));
            break;
        case 'K':
            memcpy(result.m, K, sizeof(K));
            break;
        case 'L':
            memcpy(result.m, L, sizeof(L));
            break;
        case 'M':
            memcpy(result.m, M, sizeof(M));
            break;
        case 'N':
            memcpy(result.m, N, sizeof(N));
            break;
        case 'O':
            memcpy(result.m, O, sizeof(O));
            break;
        case 'P':
            memcpy(result.m, P, sizeof(P));
            break;
        case 'Q':
            memcpy(result.m, Q, sizeof(Q));
            break;
        case 'R':
            memcpy(result.m, R, sizeof(R));
            break;
        case 'S':
            memcpy(result.m, S, sizeof(S));
            break;
        case 'T':
            memcpy(result.m, T, sizeof(T));
            break;
        case 'U':
            memcpy(result.m, U, sizeof(U));
            break;
        case 'V':
            memcpy(result.m, V, sizeof(V));
            break;
        case 'W':
            memcpy(result.m, W, sizeof(W));
            break;
        case 'X':
            memcpy(result.m, X, sizeof(X));
            break;
        case 'Y':
            memcpy(result.m, Y, sizeof(Y));
            break;
        case 'Z':
            memcpy(result.m, Z, sizeof(Z));
            break;
        default:
            memcpy(result.m, empty, sizeof(empty));
            break;
    }
    return result;
}

void parseSerialBytes() {
    //if (UART_GetRxBufferSize() <= 0) {
        char cmd_id = input[0];
        int data_len = (int)input[1];
        char data[16];
        //char data[16] = "TEST";

//        for (int i = 0; i < data_len; i++) {
//            data[i] = (char)input[i + 2];
//        }
        
        strcpy(data, input + 2);
        data[strlen(data)] = '\0';

        if (cmd_id == TEXT_CMD_ID1) {
            // strcpy(text_line_one, data);
            // char input[1] = "A";
            strcpy(text, data);
        }
        else if (cmd_id == TEXT_CMD_ID2) {
            strcpy(text_line_two, data);
            char input[1] = "B";
            strcpy(text, input);
        }
        else if (cmd_id == COLOR_CMD_ID) {
            strcpy(color_opt, data);
            char input[1] = "C";
            strcpy(text, input);
        }
        else if (cmd_id == SCROLL_CMD_ID) {
            strcpy(scroll_opt, data);
            char input[1] = "D";
            strcpy(text, input);
        }
        else if (cmd_id == ANIMATION_CMD_ID) {
            strcpy(animation_opt, data);
            char input[1] = "E";
            strcpy(text, input);
        }
        else if (cmd_id == CLEAR_CMD_ID) {
            strcpy(clear_screen, data);
            char input[1] = "F";
            strcpy(text, input);
        }
        else {
            //char input[1] = "G";
            //strcpy(text, input);
        }
    //}
}

int main(void)
{
    UART_ClearRxBuffer();
    UART_ClearTxBuffer();
    rx_isr_ClearPending();
    rx_isr_StartEx(RxIsr);
    UART_Start();
    
    int matrix[ROWS][COLS] = { 0 };
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    CLK_Write(0);
    LAT_Write(0);
    
    for(;;)
    {
        //strcpy(text, input); // copy input buffer into text
        parseSerialBytes();
        
        // concatenate the letters together into letters_concat
        letter2d letter;
        int letters_concat[15][sizeof text * 11] = { 0 };
        int start_col;
        int letter_row_sz;
        int letter_col_sz;
        for (int d = 0; d < (int)sizeof text; d++) {
            letter = get_letter_matrix(text[d]); // get letter bitmapping for the current character
            letter_row_sz = sizeof(letter.m)/sizeof(letter.m[0]);
            letter_col_sz = sizeof(letter.m[0])/sizeof(letter.m[0][0]);
            
            // loop through bitmapping of current letter
            for (int r = 0; r < letter_row_sz; r++) {
                start_col = 11 * d; // start col of next letter
                                    // 1st letter starts col 0, 2nd starts col 11, 3rd starts col 22, etc.
                for (int c = 0; c < letter_col_sz; c++) {
                    letters_concat[r][start_col] = letter.m[r][c]; // insert into letters_concat
                    start_col++;
                }
            }
        }

        int sr = sizeof(letters_concat)/sizeof(letters_concat[0]);
        int sc = sizeof(letters_concat[0])/sizeof(letters_concat[0][0]);
        if (sc > COLS) { // if col size of letters_concat is greater than the col size of matrix
            sc = COLS;   // reduce to col size of matrix
        }
        // fill the banner matrix array with letters
        for (int r = 0; r < sr; r++) {
            for (int c = 0; c < sc; c++) {
                matrix[r][c] = letters_concat[r][c];
            }
        }
        
        // turn on LEDs of the displays
        for(int j=0; j<ROWS; ++j){
            OE_Write(1); // OE high 
            for(int i=0; i<COLS; ++i){         
                R1_Write((matrix[j][i])); 
                B1_Write((matrix[j][i]));
                G1_Write((matrix[j][i]));
                A_Write(j);
                B_Write(j>>1);
                C_Write(j>>2); 
                D_Write(j>>3);
                R2_Write(0); 
                B2_Write(0);
                G2_Write(0); 
                CLK_Write(0);
                CLK_Write(1);
                CLK_Write(0);
            } // end of col loop
            LAT_Write(1);
            LAT_Write(0);       
            OE_Write(0);
            CyDelayUs(300);
        } // end of row loop
        
        i = 0;
    
    
    
    }
}
