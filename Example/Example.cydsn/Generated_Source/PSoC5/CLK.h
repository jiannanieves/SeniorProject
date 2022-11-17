/*******************************************************************************
* File Name: CLK.h  
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

#if !defined(CY_PINS_CLK_H) /* Pins CLK_H */
#define CY_PINS_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CLK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CLK__PORT == 15 && ((CLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CLK_Write(uint8 value);
void    CLK_SetDriveMode(uint8 mode);
uint8   CLK_ReadDataReg(void);
uint8   CLK_Read(void);
void    CLK_SetInterruptMode(uint16 position, uint16 mode);
uint8   CLK_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CLK_SetDriveMode() function.
     *  @{
     */
        #define CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CLK_DM_RES_UP          PIN_DM_RES_UP
        #define CLK_DM_RES_DWN         PIN_DM_RES_DWN
        #define CLK_DM_OD_LO           PIN_DM_OD_LO
        #define CLK_DM_OD_HI           PIN_DM_OD_HI
        #define CLK_DM_STRONG          PIN_DM_STRONG
        #define CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CLK_MASK               CLK__MASK
#define CLK_SHIFT              CLK__SHIFT
#define CLK_WIDTH              1u

/* Interrupt constants */
#if defined(CLK__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CLK_SetInterruptMode() function.
     *  @{
     */
        #define CLK_INTR_NONE      (uint16)(0x0000u)
        #define CLK_INTR_RISING    (uint16)(0x0001u)
        #define CLK_INTR_FALLING   (uint16)(0x0002u)
        #define CLK_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CLK_INTR_MASK      (0x01u) 
#endif /* (CLK__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CLK_PS                     (* (reg8 *) CLK__PS)
/* Data Register */
#define CLK_DR                     (* (reg8 *) CLK__DR)
/* Port Number */
#define CLK_PRT_NUM                (* (reg8 *) CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define CLK_AG                     (* (reg8 *) CLK__AG)                       
/* Analog MUX bux enable */
#define CLK_AMUX                   (* (reg8 *) CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define CLK_BIE                    (* (reg8 *) CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define CLK_BIT_MASK               (* (reg8 *) CLK__BIT_MASK)
/* Bypass Enable */
#define CLK_BYP                    (* (reg8 *) CLK__BYP)
/* Port wide control signals */                                                   
#define CLK_CTL                    (* (reg8 *) CLK__CTL)
/* Drive Modes */
#define CLK_DM0                    (* (reg8 *) CLK__DM0) 
#define CLK_DM1                    (* (reg8 *) CLK__DM1)
#define CLK_DM2                    (* (reg8 *) CLK__DM2) 
/* Input Buffer Disable Override */
#define CLK_INP_DIS                (* (reg8 *) CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define CLK_LCD_COM_SEG            (* (reg8 *) CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define CLK_LCD_EN                 (* (reg8 *) CLK__LCD_EN)
/* Slew Rate Control */
#define CLK_SLW                    (* (reg8 *) CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CLK_PRTDSI__CAPS_SEL       (* (reg8 *) CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CLK_PRTDSI__OE_SEL0        (* (reg8 *) CLK__PRTDSI__OE_SEL0) 
#define CLK_PRTDSI__OE_SEL1        (* (reg8 *) CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CLK_PRTDSI__OUT_SEL0       (* (reg8 *) CLK__PRTDSI__OUT_SEL0) 
#define CLK_PRTDSI__OUT_SEL1       (* (reg8 *) CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CLK_PRTDSI__SYNC_OUT       (* (reg8 *) CLK__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CLK__SIO_CFG)
    #define CLK_SIO_HYST_EN        (* (reg8 *) CLK__SIO_HYST_EN)
    #define CLK_SIO_REG_HIFREQ     (* (reg8 *) CLK__SIO_REG_HIFREQ)
    #define CLK_SIO_CFG            (* (reg8 *) CLK__SIO_CFG)
    #define CLK_SIO_DIFF           (* (reg8 *) CLK__SIO_DIFF)
#endif /* (CLK__SIO_CFG) */

/* Interrupt Registers */
#if defined(CLK__INTSTAT)
    #define CLK_INTSTAT            (* (reg8 *) CLK__INTSTAT)
    #define CLK_SNAP               (* (reg8 *) CLK__SNAP)
    
	#define CLK_0_INTTYPE_REG 		(* (reg8 *) CLK__0__INTTYPE)
#endif /* (CLK__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CLK_H */


/* [] END OF FILE */
