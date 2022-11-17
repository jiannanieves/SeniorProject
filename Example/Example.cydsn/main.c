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
    CLK_Write(0);
    LAT_Write(0) ;         
    
    for(;;)
    {
      
        for( int j= 0 ; j<16; ++j){
            OE_Write(1);  //OE high 
            for(int i =0 ; i<64; ++i){         
                R1_Write((j & 1) & i  ); 
                B1_Write(((j>>1) & 1) & i  ); // shift to  make it every other dot a dif color 
                G1_Write(((j>>2) & 1) & i );        
                A_Write(j);
                B_Write(j>>1); 
                C_Write(j>>2); 
                D_Write(j>>3);
                R2_Write(0) ; 
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
        
        LAT_Write(1) ; 
        
        LAT_Write(0) ;       
        OE_Write(0);
        CyDelayUs(300);   
            
        }      
              
        
        
        
  }
}

