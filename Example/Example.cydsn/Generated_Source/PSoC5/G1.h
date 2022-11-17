/*******************************************************************************
* File Name: G1.h  
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

#if !defined(CY_PINS_G1_H) /* Pins G1_H */
#define CY_PINS_G1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "G1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 G1__PORT == 15 && ((G1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    G1_Write(uint8 value);
void    G1_SetDriveMode(uint8 mode);
uint8   G1_ReadDataReg(void);
uint8   G1_Read(void);
void    G1_SetInterruptMode(uint16 position, uint16 mode);
uint8   G1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the G1_SetDriveMode() function.
     *  @{
     */
        #define G1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define G1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define G1_DM_RES_UP          PIN_DM_RES_UP
        #define G1_DM_RES_DWN         PIN_DM_RES_DWN
        #define G1_DM_OD_LO           PIN_DM_OD_LO
        #define G1_DM_OD_HI           PIN_DM_OD_HI
        #define G1_DM_STRONG          PIN_DM_STRONG
        #define G1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define G1_MASK               G1__MASK
#define G1_SHIFT              G1__SHIFT
#define G1_WIDTH              1u

/* Interrupt constants */
#if defined(G1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in G1_SetInterruptMode() function.
     *  @{
     */
        #define G1_INTR_NONE      (uint16)(0x0000u)
        #define G1_INTR_RISING    (uint16)(0x0001u)
        #define G1_INTR_FALLING   (uint16)(0x0002u)
        #define G1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define G1_INTR_MASK      (0x01u) 
#endif /* (G1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define G1_PS                     (* (reg8 *) G1__PS)
/* Data Register */
#define G1_DR                     (* (reg8 *) G1__DR)
/* Port Number */
#define G1_PRT_NUM                (* (reg8 *) G1__PRT) 
/* Connect to Analog Globals */                                                  
#define G1_AG                     (* (reg8 *) G1__AG)                       
/* Analog MUX bux enable */
#define G1_AMUX                   (* (reg8 *) G1__AMUX) 
/* Bidirectional Enable */                                                        
#define G1_BIE                    (* (reg8 *) G1__BIE)
/* Bit-mask for Aliased Register Access */
#define G1_BIT_MASK               (* (reg8 *) G1__BIT_MASK)
/* Bypass Enable */
#define G1_BYP                    (* (reg8 *) G1__BYP)
/* Port wide control signals */                                                   
#define G1_CTL                    (* (reg8 *) G1__CTL)
/* Drive Modes */
#define G1_DM0                    (* (reg8 *) G1__DM0) 
#define G1_DM1                    (* (reg8 *) G1__DM1)
#define G1_DM2                    (* (reg8 *) G1__DM2) 
/* Input Buffer Disable Override */
#define G1_INP_DIS                (* (reg8 *) G1__INP_DIS)
/* LCD Common or Segment Drive */
#define G1_LCD_COM_SEG            (* (reg8 *) G1__LCD_COM_SEG)
/* Enable Segment LCD */
#define G1_LCD_EN                 (* (reg8 *) G1__LCD_EN)
/* Slew Rate Control */
#define G1_SLW                    (* (reg8 *) G1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define G1_PRTDSI__CAPS_SEL       (* (reg8 *) G1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define G1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) G1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define G1_PRTDSI__OE_SEL0        (* (reg8 *) G1__PRTDSI__OE_SEL0) 
#define G1_PRTDSI__OE_SEL1        (* (reg8 *) G1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define G1_PRTDSI__OUT_SEL0       (* (reg8 *) G1__PRTDSI__OUT_SEL0) 
#define G1_PRTDSI__OUT_SEL1       (* (reg8 *) G1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define G1_PRTDSI__SYNC_OUT       (* (reg8 *) G1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(G1__SIO_CFG)
    #define G1_SIO_HYST_EN        (* (reg8 *) G1__SIO_HYST_EN)
    #define G1_SIO_REG_HIFREQ     (* (reg8 *) G1__SIO_REG_HIFREQ)
    #define G1_SIO_CFG            (* (reg8 *) G1__SIO_CFG)
    #define G1_SIO_DIFF           (* (reg8 *) G1__SIO_DIFF)
#endif /* (G1__SIO_CFG) */

/* Interrupt Registers */
#if defined(G1__INTSTAT)
    #define G1_INTSTAT            (* (reg8 *) G1__INTSTAT)
    #define G1_SNAP               (* (reg8 *) G1__SNAP)
    
	#define G1_0_INTTYPE_REG 		(* (reg8 *) G1__0__INTTYPE)
#endif /* (G1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_G1_H */


/* [] END OF FILE */
