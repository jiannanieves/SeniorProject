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
#define COLS 192 // 192
#define TEXT_CMD_ID1     0x24
#define TEXT_CMD_ID2     0x25
#define COLOR_CMD_ID     0x26
#define SCROLL_CMD_ID    0x27
#define ANIMATION_CMD_ID 0x28
#define CLEAR_CMD_ID     0x29

// Buffer for UART data
char input[16];
int i = 0; // index of buffer
// Store user text
char text[16];

char text_line_one[16]; // store text on line one
char text_line_two[16]; // store text on line two
char color_opt[1];      // store color option
char scroll_opt[1];     // store scroll option
char animation_opt[1];  // store animation option
char clear_screen[1];   // toggle clear screen command

void set_LED_color (int matrix[ROWS][COLS], int j, int i, int s);
letter2d get_letter_matrix(char c);

CY_ISR(RxIsr)
{
    rx_isr_ClearPending();
    while (UART_GetRxBufferSize() > 0) 
    {
        input[i] = UART_GetByte();
        i++;
    }
}

void parseSerialBytes() {
    if (UART_GetRxBufferSize() == 0) {
        char cmd_id = input[0];       // store 1st byte of input buffer as command ID
        int data_len = (int)input[1]; // store 2nd byte of input buffer as length of data
        char data[data_len];          // create data array
        
        // copy input buffer from index 2 into data array
        strcpy(data, input + 2);
        data[strlen(data)] = '\0'; // add null terminator
        
        // changing text line one
        if (cmd_id == TEXT_CMD_ID1) {
            // TODO: clear text_line_one here?
            strcpy(text_line_one, data);
        }
        // changing text line two
        else if (cmd_id == TEXT_CMD_ID2) {
            strcpy(text_line_two, data);
        }
        // changing color of text
        else if (cmd_id == COLOR_CMD_ID) {
            strcpy(color_opt, data);
        } 
        // changing scroll speed of text
        else if (cmd_id == SCROLL_CMD_ID) {
            strcpy(scroll_opt, data);
        }
        // changing animations
        else if (cmd_id == ANIMATION_CMD_ID) {
            strcpy(animation_opt, data);
        }
        // clearing screen
        else if (cmd_id == CLEAR_CMD_ID) {
            strcpy(clear_screen, data);
        }
        // command ID not recognized
        else {
            
        }
    }
}

int main(void)
{   
    UART_ClearRxBuffer();
    UART_ClearTxBuffer();
    rx_isr_ClearPending();
    rx_isr_StartEx(RxIsr);
    UART_Start();
     
    CyGlobalIntEnable; /* Enable global interrupts. */

    CLK_Write(0);
    LAT_Write(0);
    
    for(;;)
    {
        // parse serial commands
        parseSerialBytes();
        
        // matrix to display pixels
        int matrix[ROWS][COLS] = { 0 };
      
        // concatenate the letters together into letters_concat
        letter2d letter;
        int letters_concat[16][sizeof text_line_one * 11] = { 0 };
        int start_col;
        int letter_row_sz;
        int letter_col_sz;
        for (int d = 0; d < (int)sizeof text_line_one; d++) {
            letter = get_letter_matrix(text_line_one[d]); // get letter bitmapping for the current character
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
        
        int rows_tot;
        for (int s = 0; s < COLS; s++) {
            if (scroll_opt[0] == 0x01) {
                rows_tot = ROWS + 1;
            }
            else {
                rows_tot = ROWS;
            }
            
            // turn on LEDs of the displays
            // scrolling needs ROWS-1, stationary needs just ROWS
            for(int j=0; j<(rows_tot-1); ++j){ 
                OE_Write(1); // OE high 
                for(int i=0; i<COLS; ++i){  
                    // get color for top half
                    if (scroll_opt[0] == 0x01) {
                        set_LED_color(matrix, j, i, 0);
                    }
                    else {
                        set_LED_color(matrix, j, i, s);
                    }
                    A_Write(j);
                    B_Write(j>>1);
                    C_Write(j>>2); 
                    D_Write(j>>3);
                    R2_Write(0); 
                    B2_Write(0);
                    G2_Write(0);
                    CLK_Write(1);
                    //CyDelayUs(1);
                    CLK_Write(0);
                } // end of col loop
                LAT_Write(1);
                //CyDelayUs(1);
                LAT_Write(0);       
                OE_Write(0);
                CyDelayUs(200); // BRIGHTNESS
                 //delay half second
            } // end of row loop
            R1_Write(0); 
            B1_Write(0); 
            G1_Write(0);
        } // end of s loop
        i = 0;
    }
}

void set_LED_color (int matrix[ROWS][COLS], int j, int i, int s) {
    switch (color_opt[0]) {
        case 'R': // red
            R1_Write((matrix[j][i+s])); 
            break;
        case 'Y': // yellow
            R1_Write((matrix[j][i+s])); 
            G1_Write((matrix[j][i+s]));
            break;
        case 'G': // green
            G1_Write((matrix[j][i+s]));
            break;
        case 'C': // cyan
            B1_Write((matrix[j][i+s]));
            G1_Write((matrix[j][i+s]));
            break;
        case 'B': // blue
            B1_Write((matrix[j][i+s]));
            break;
        case 'P': // purple 
            B1_Write((matrix[j][i+s]));
            R1_Write((matrix[j][i+s]));
            break;
        case 'W': // white
        default: 
            R1_Write((matrix[j][i+s])); 
            B1_Write((matrix[j][i+s]));
            G1_Write((matrix[j][i+s]));
            break;
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
        case '1':
            memcpy(result.m, one, sizeof(one));
            break;
        case '2':
            memcpy(result.m, two, sizeof(two));
            break;
        case '3':
            memcpy(result.m, three, sizeof(three));
            break;
        case '4':
            memcpy(result.m, four, sizeof(four));
            break;
        case '5':
            memcpy(result.m, five, sizeof(five));
            break;
        case '6':
            memcpy(result.m, six, sizeof(six));
            break;
        case '7':
            memcpy(result.m, seven, sizeof(seven));
            break;
        case '8':
            memcpy(result.m, eight, sizeof(eight));
            break;
        case '9':
            memcpy(result.m, nine, sizeof(nine));
            break;
        case '!':
            memcpy(result.m, exclamation, sizeof(exclamation));
            break;
        case '0':
            memcpy(result.m, zero, sizeof(zero));
            break;
        default:
            memcpy(result.m, empty, sizeof(empty));
            break;
    }
    return result;
}
