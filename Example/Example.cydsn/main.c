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
#include "project.h"
#include "letters.h"

// M x N matrix
#define ROWS 16
#define COLS 64

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
////    for ( int i = 0; i< 16; ++i){
//        R1_Write(1) ;
//        B1_Write(1);
//        G1_Write(1); 
//        A_Write(1); 
//        B_Write(1); 
//        C_Write(1); 
//        D_Write(1);
//        
//        LAT_Write(0);         
//        CLK_Write(0);
//        CLK_Write(1);
//        CLK_Write(0); 
//        LAT_Write(1) ; 
//        //LAT_Write(0) ; 
//        CyDelay(1);
//        OE_Write(0);  //OE low- turns them all on or off 
////    }
    
    int matrix[ROWS][COLS] = { 0 };
    int size_row = sizeof(T)/sizeof(T[0]);
    int size_col = sizeof(T[0])/sizeof(T[0][0]);

    // fill the 2d array with letters
    int letter[15][11];
    memcpy(letter, H, sizeof(G)); // where to change letter
    for (int r = 0; r < ROWS; r++) {
        if (r == size_row) {
            break;
        }
        
        for (int c = 0; c < COLS; c++) {
            if (c == size_col) {
                break;
            }
            matrix[r][c] = letter[r][c]; 
        }
    }
    
    CLK_Write(0);
    LAT_Write(0);         
    
    for(;;)
    {
        for(int j=0 ; j<ROWS; ++j){
            OE_Write(1); // OE high 
            for(int i=0 ; i<COLS; ++i){         
                R1_Write((matrix[j][i])); 
                B1_Write((matrix[j][i])); // shift to  make it every other dot a dif color 
                G1_Write((matrix[j][i]));
                A_Write(j);
                B_Write(j>>1);
                C_Write(j>>2); 
                D_Write(j>>3);
                R2_Write(0); 
                B2_Write(0);
                G2_Write(0); 
                CLK_Write(0);
                //CyDelay(1);
                CLK_Write(1);
                //CyDelay(1);
                CLK_Write(0);
                
            } // end of row
//            if(j&1){
//                LAT_Write(1) ; 
//            }
//            else{
//                LAT_Write(0);
//            }
        
        LAT_Write(1); 
        
        LAT_Write(0);       
        OE_Write(0);
        CyDelayUs(300);   
            
        }  
              
        
        
        
  }
}

