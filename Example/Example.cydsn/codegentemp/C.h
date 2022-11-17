/*******************************************************************************
* File Name: C.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_C_H) /* Pins C_H */
#define CY_PINS_C_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C__PORT == 15 && ((C__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C_Write(uint8 value);
void    C_SetDriveMode(uint8 mode);
uint8   C_ReadDataReg(void);
uint8   C_Read(void);
void    C_SetInterruptMode(uint16 position, uint16 mode);
uint8   C_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C_SetDriveMode() function.
     *  @{
     */
        #define C_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C_DM_RES_UP          PIN_DM_RES_UP
        #define C_DM_RES_DWN         PIN_DM_RES_DWN
        #define C_DM_OD_LO           PIN_DM_OD_LO
        #define C_DM_OD_HI           PIN_DM_OD_HI
        #define C_DM_STRONG          PIN_DM_STRONG
        #define C_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C_MASK               C__MASK
#define C_SHIFT              C__SHIFT
#define C_WIDTH              1u

/* Interrupt constants */
#if defined(C__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C_SetInterruptMode() function.
     *  @{
     */
        #define C_INTR_NONE      (uint16)(0x0000u)
        #define C_INTR_RISING    (uint16)(0x0001u)
        #define C_INTR_FALLING   (uint16)(0x0002u)
        #define C_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C_INTR_MASK      (0x01u) 
#endif /* (C__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C_PS                     (* (reg8 *) C__PS)
/* Data Register */
#define C_DR                     (* (reg8 *) C__DR)
/* Port Number */
#define C_PRT_NUM                (* (reg8 *) C__PRT) 
/* Connect to Analog Globals */                                                  
#define C_AG                     (* (reg8 *) C__AG)                       
/* Analog MUX bux enable */
#define C_AMUX                   (* (reg8 *) C__AMUX) 
/* Bidirectional Enable */                                                        
#define C_BIE                    (* (reg8 *) C__BIE)
/* Bit-mask for Aliased Register Access */
#define C_BIT_MASK               (* (reg8 *) C__BIT_MASK)
/* Bypass Enable */
#define C_BYP                    (* (reg8 *) C__BYP)
/* Port wide control signals */                                                   
#define C_CTL                    (* (reg8 *) C__CTL)
/* Drive Modes */
#define C_DM0                    (* (reg8 *) C__DM0) 
#define C_DM1                    (* (reg8 *) C__DM1)
#define C_DM2                    (* (reg8 *) C__DM2) 
/* Input Buffer Disable Override */
#define C_INP_DIS                (* (reg8 *) C__INP_DIS)
/* LCD Common or Segment Drive */
#define C_LCD_COM_SEG            (* (reg8 *) C__LCD_COM_SEG)
/* Enable Segment LCD */
#define C_LCD_EN                 (* (reg8 *) C__LCD_EN)
/* Slew Rate Control */
#define C_SLW                    (* (reg8 *) C__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C_PRTDSI__CAPS_SEL       (* (reg8 *) C__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C_PRTDSI__OE_SEL0        (* (reg8 *) C__PRTDSI__OE_SEL0) 
#define C_PRTDSI__OE_SEL1        (* (reg8 *) C__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C_PRTDSI__OUT_SEL0       (* (reg8 *) C__PRTDSI__OUT_SEL0) 
#define C_PRTDSI__OUT_SEL1       (* (reg8 *) C__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C_PRTDSI__SYNC_OUT       (* (reg8 *) C__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C__SIO_CFG)
    #define C_SIO_HYST_EN        (* (reg8 *) C__SIO_HYST_EN)
    #define C_SIO_REG_HIFREQ     (* (reg8 *) C__SIO_REG_HIFREQ)
    #define C_SIO_CFG            (* (reg8 *) C__SIO_CFG)
    #define C_SIO_DIFF           (* (reg8 *) C__SIO_DIFF)
#endif /* (C__SIO_CFG) */

/* Interrupt Registers */
#if defined(C__INTSTAT)
    #define C_INTSTAT            (* (reg8 *) C__INTSTAT)
    #define C_SNAP               (* (reg8 *) C__SNAP)
    
	#define C_0_INTTYPE_REG 		(* (reg8 *) C__0__INTTYPE)
#endif /* (C__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C_H */


/* [] END OF FILE */
