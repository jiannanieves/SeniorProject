/*******************************************************************************
* File Name: LAT.h  
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

#if !defined(CY_PINS_LAT_H) /* Pins LAT_H */
#define CY_PINS_LAT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LAT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LAT__PORT == 15 && ((LAT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LAT_Write(uint8 value);
void    LAT_SetDriveMode(uint8 mode);
uint8   LAT_ReadDataReg(void);
uint8   LAT_Read(void);
void    LAT_SetInterruptMode(uint16 position, uint16 mode);
uint8   LAT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LAT_SetDriveMode() function.
     *  @{
     */
        #define LAT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LAT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LAT_DM_RES_UP          PIN_DM_RES_UP
        #define LAT_DM_RES_DWN         PIN_DM_RES_DWN
        #define LAT_DM_OD_LO           PIN_DM_OD_LO
        #define LAT_DM_OD_HI           PIN_DM_OD_HI
        #define LAT_DM_STRONG          PIN_DM_STRONG
        #define LAT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LAT_MASK               LAT__MASK
#define LAT_SHIFT              LAT__SHIFT
#define LAT_WIDTH              1u

/* Interrupt constants */
#if defined(LAT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LAT_SetInterruptMode() function.
     *  @{
     */
        #define LAT_INTR_NONE      (uint16)(0x0000u)
        #define LAT_INTR_RISING    (uint16)(0x0001u)
        #define LAT_INTR_FALLING   (uint16)(0x0002u)
        #define LAT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LAT_INTR_MASK      (0x01u) 
#endif /* (LAT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LAT_PS                     (* (reg8 *) LAT__PS)
/* Data Register */
#define LAT_DR                     (* (reg8 *) LAT__DR)
/* Port Number */
#define LAT_PRT_NUM                (* (reg8 *) LAT__PRT) 
/* Connect to Analog Globals */                                                  
#define LAT_AG                     (* (reg8 *) LAT__AG)                       
/* Analog MUX bux enable */
#define LAT_AMUX                   (* (reg8 *) LAT__AMUX) 
/* Bidirectional Enable */                                                        
#define LAT_BIE                    (* (reg8 *) LAT__BIE)
/* Bit-mask for Aliased Register Access */
#define LAT_BIT_MASK               (* (reg8 *) LAT__BIT_MASK)
/* Bypass Enable */
#define LAT_BYP                    (* (reg8 *) LAT__BYP)
/* Port wide control signals */                                                   
#define LAT_CTL                    (* (reg8 *) LAT__CTL)
/* Drive Modes */
#define LAT_DM0                    (* (reg8 *) LAT__DM0) 
#define LAT_DM1                    (* (reg8 *) LAT__DM1)
#define LAT_DM2                    (* (reg8 *) LAT__DM2) 
/* Input Buffer Disable Override */
#define LAT_INP_DIS                (* (reg8 *) LAT__INP_DIS)
/* LCD Common or Segment Drive */
#define LAT_LCD_COM_SEG            (* (reg8 *) LAT__LCD_COM_SEG)
/* Enable Segment LCD */
#define LAT_LCD_EN                 (* (reg8 *) LAT__LCD_EN)
/* Slew Rate Control */
#define LAT_SLW                    (* (reg8 *) LAT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LAT_PRTDSI__CAPS_SEL       (* (reg8 *) LAT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LAT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LAT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LAT_PRTDSI__OE_SEL0        (* (reg8 *) LAT__PRTDSI__OE_SEL0) 
#define LAT_PRTDSI__OE_SEL1        (* (reg8 *) LAT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LAT_PRTDSI__OUT_SEL0       (* (reg8 *) LAT__PRTDSI__OUT_SEL0) 
#define LAT_PRTDSI__OUT_SEL1       (* (reg8 *) LAT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LAT_PRTDSI__SYNC_OUT       (* (reg8 *) LAT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LAT__SIO_CFG)
    #define LAT_SIO_HYST_EN        (* (reg8 *) LAT__SIO_HYST_EN)
    #define LAT_SIO_REG_HIFREQ     (* (reg8 *) LAT__SIO_REG_HIFREQ)
    #define LAT_SIO_CFG            (* (reg8 *) LAT__SIO_CFG)
    #define LAT_SIO_DIFF           (* (reg8 *) LAT__SIO_DIFF)
#endif /* (LAT__SIO_CFG) */

/* Interrupt Registers */
#if defined(LAT__INTSTAT)
    #define LAT_INTSTAT            (* (reg8 *) LAT__INTSTAT)
    #define LAT_SNAP               (* (reg8 *) LAT__SNAP)
    
	#define LAT_0_INTTYPE_REG 		(* (reg8 *) LAT__0__INTTYPE)
#endif /* (LAT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LAT_H */


/* [] END OF FILE */
