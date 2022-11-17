/*******************************************************************************
* File Name: G2.h  
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

#if !defined(CY_PINS_G2_H) /* Pins G2_H */
#define CY_PINS_G2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "G2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 G2__PORT == 15 && ((G2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    G2_Write(uint8 value);
void    G2_SetDriveMode(uint8 mode);
uint8   G2_ReadDataReg(void);
uint8   G2_Read(void);
void    G2_SetInterruptMode(uint16 position, uint16 mode);
uint8   G2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the G2_SetDriveMode() function.
     *  @{
     */
        #define G2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define G2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define G2_DM_RES_UP          PIN_DM_RES_UP
        #define G2_DM_RES_DWN         PIN_DM_RES_DWN
        #define G2_DM_OD_LO           PIN_DM_OD_LO
        #define G2_DM_OD_HI           PIN_DM_OD_HI
        #define G2_DM_STRONG          PIN_DM_STRONG
        #define G2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define G2_MASK               G2__MASK
#define G2_SHIFT              G2__SHIFT
#define G2_WIDTH              1u

/* Interrupt constants */
#if defined(G2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in G2_SetInterruptMode() function.
     *  @{
     */
        #define G2_INTR_NONE      (uint16)(0x0000u)
        #define G2_INTR_RISING    (uint16)(0x0001u)
        #define G2_INTR_FALLING   (uint16)(0x0002u)
        #define G2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define G2_INTR_MASK      (0x01u) 
#endif /* (G2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define G2_PS                     (* (reg8 *) G2__PS)
/* Data Register */
#define G2_DR                     (* (reg8 *) G2__DR)
/* Port Number */
#define G2_PRT_NUM                (* (reg8 *) G2__PRT) 
/* Connect to Analog Globals */                                                  
#define G2_AG                     (* (reg8 *) G2__AG)                       
/* Analog MUX bux enable */
#define G2_AMUX                   (* (reg8 *) G2__AMUX) 
/* Bidirectional Enable */                                                        
#define G2_BIE                    (* (reg8 *) G2__BIE)
/* Bit-mask for Aliased Register Access */
#define G2_BIT_MASK               (* (reg8 *) G2__BIT_MASK)
/* Bypass Enable */
#define G2_BYP                    (* (reg8 *) G2__BYP)
/* Port wide control signals */                                                   
#define G2_CTL                    (* (reg8 *) G2__CTL)
/* Drive Modes */
#define G2_DM0                    (* (reg8 *) G2__DM0) 
#define G2_DM1                    (* (reg8 *) G2__DM1)
#define G2_DM2                    (* (reg8 *) G2__DM2) 
/* Input Buffer Disable Override */
#define G2_INP_DIS                (* (reg8 *) G2__INP_DIS)
/* LCD Common or Segment Drive */
#define G2_LCD_COM_SEG            (* (reg8 *) G2__LCD_COM_SEG)
/* Enable Segment LCD */
#define G2_LCD_EN                 (* (reg8 *) G2__LCD_EN)
/* Slew Rate Control */
#define G2_SLW                    (* (reg8 *) G2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define G2_PRTDSI__CAPS_SEL       (* (reg8 *) G2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define G2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) G2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define G2_PRTDSI__OE_SEL0        (* (reg8 *) G2__PRTDSI__OE_SEL0) 
#define G2_PRTDSI__OE_SEL1        (* (reg8 *) G2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define G2_PRTDSI__OUT_SEL0       (* (reg8 *) G2__PRTDSI__OUT_SEL0) 
#define G2_PRTDSI__OUT_SEL1       (* (reg8 *) G2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define G2_PRTDSI__SYNC_OUT       (* (reg8 *) G2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(G2__SIO_CFG)
    #define G2_SIO_HYST_EN        (* (reg8 *) G2__SIO_HYST_EN)
    #define G2_SIO_REG_HIFREQ     (* (reg8 *) G2__SIO_REG_HIFREQ)
    #define G2_SIO_CFG            (* (reg8 *) G2__SIO_CFG)
    #define G2_SIO_DIFF           (* (reg8 *) G2__SIO_DIFF)
#endif /* (G2__SIO_CFG) */

/* Interrupt Registers */
#if defined(G2__INTSTAT)
    #define G2_INTSTAT            (* (reg8 *) G2__INTSTAT)
    #define G2_SNAP               (* (reg8 *) G2__SNAP)
    
	#define G2_0_INTTYPE_REG 		(* (reg8 *) G2__0__INTTYPE)
#endif /* (G2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_G2_H */


/* [] END OF FILE */
