;
; File Name: cyfitteriar.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* A */
A__0__INTTYPE EQU CYREG_PICU5_INTTYPE6
A__0__MASK EQU 0x40
A__0__PC EQU CYREG_PRT5_PC6
A__0__PORT EQU 5
A__0__SHIFT EQU 6
A__AG EQU CYREG_PRT5_AG
A__AMUX EQU CYREG_PRT5_AMUX
A__BIE EQU CYREG_PRT5_BIE
A__BIT_MASK EQU CYREG_PRT5_BIT_MASK
A__BYP EQU CYREG_PRT5_BYP
A__CTL EQU CYREG_PRT5_CTL
A__DM0 EQU CYREG_PRT5_DM0
A__DM1 EQU CYREG_PRT5_DM1
A__DM2 EQU CYREG_PRT5_DM2
A__DR EQU CYREG_PRT5_DR
A__INP_DIS EQU CYREG_PRT5_INP_DIS
A__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
A__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
A__LCD_EN EQU CYREG_PRT5_LCD_EN
A__MASK EQU 0x40
A__PORT EQU 5
A__PRT EQU CYREG_PRT5_PRT
A__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
A__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
A__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
A__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
A__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
A__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
A__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
A__PS EQU CYREG_PRT5_PS
A__SHIFT EQU 6
A__SLW EQU CYREG_PRT5_SLW

/* B */
B__0__INTTYPE EQU CYREG_PICU5_INTTYPE7
B__0__MASK EQU 0x80
B__0__PC EQU CYREG_PRT5_PC7
B__0__PORT EQU 5
B__0__SHIFT EQU 7
B__AG EQU CYREG_PRT5_AG
B__AMUX EQU CYREG_PRT5_AMUX
B__BIE EQU CYREG_PRT5_BIE
B__BIT_MASK EQU CYREG_PRT5_BIT_MASK
B__BYP EQU CYREG_PRT5_BYP
B__CTL EQU CYREG_PRT5_CTL
B__DM0 EQU CYREG_PRT5_DM0
B__DM1 EQU CYREG_PRT5_DM1
B__DM2 EQU CYREG_PRT5_DM2
B__DR EQU CYREG_PRT5_DR
B__INP_DIS EQU CYREG_PRT5_INP_DIS
B__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
B__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
B__LCD_EN EQU CYREG_PRT5_LCD_EN
B__MASK EQU 0x80
B__PORT EQU 5
B__PRT EQU CYREG_PRT5_PRT
B__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
B__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
B__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
B__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
B__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
B__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
B__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
B__PS EQU CYREG_PRT5_PS
B__SHIFT EQU 7
B__SLW EQU CYREG_PRT5_SLW

/* C */
C__0__INTTYPE EQU CYREG_PICU5_INTTYPE4
C__0__MASK EQU 0x10
C__0__PC EQU CYREG_PRT5_PC4
C__0__PORT EQU 5
C__0__SHIFT EQU 4
C__AG EQU CYREG_PRT5_AG
C__AMUX EQU CYREG_PRT5_AMUX
C__BIE EQU CYREG_PRT5_BIE
C__BIT_MASK EQU CYREG_PRT5_BIT_MASK
C__BYP EQU CYREG_PRT5_BYP
C__CTL EQU CYREG_PRT5_CTL
C__DM0 EQU CYREG_PRT5_DM0
C__DM1 EQU CYREG_PRT5_DM1
C__DM2 EQU CYREG_PRT5_DM2
C__DR EQU CYREG_PRT5_DR
C__INP_DIS EQU CYREG_PRT5_INP_DIS
C__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
C__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
C__LCD_EN EQU CYREG_PRT5_LCD_EN
C__MASK EQU 0x10
C__PORT EQU 5
C__PRT EQU CYREG_PRT5_PRT
C__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
C__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
C__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
C__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
C__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
C__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
C__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
C__PS EQU CYREG_PRT5_PS
C__SHIFT EQU 4
C__SLW EQU CYREG_PRT5_SLW

/* D */
D__0__INTTYPE EQU CYREG_PICU5_INTTYPE5
D__0__MASK EQU 0x20
D__0__PC EQU CYREG_PRT5_PC5
D__0__PORT EQU 5
D__0__SHIFT EQU 5
D__AG EQU CYREG_PRT5_AG
D__AMUX EQU CYREG_PRT5_AMUX
D__BIE EQU CYREG_PRT5_BIE
D__BIT_MASK EQU CYREG_PRT5_BIT_MASK
D__BYP EQU CYREG_PRT5_BYP
D__CTL EQU CYREG_PRT5_CTL
D__DM0 EQU CYREG_PRT5_DM0
D__DM1 EQU CYREG_PRT5_DM1
D__DM2 EQU CYREG_PRT5_DM2
D__DR EQU CYREG_PRT5_DR
D__INP_DIS EQU CYREG_PRT5_INP_DIS
D__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
D__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
D__LCD_EN EQU CYREG_PRT5_LCD_EN
D__MASK EQU 0x20
D__PORT EQU 5
D__PRT EQU CYREG_PRT5_PRT
D__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
D__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
D__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
D__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
D__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
D__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
D__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
D__PS EQU CYREG_PRT5_PS
D__SHIFT EQU 5
D__SLW EQU CYREG_PRT5_SLW

/* B1 */
B1__0__INTTYPE EQU CYREG_PICU1_INTTYPE4
B1__0__MASK EQU 0x10
B1__0__PC EQU CYREG_PRT1_PC4
B1__0__PORT EQU 1
B1__0__SHIFT EQU 4
B1__AG EQU CYREG_PRT1_AG
B1__AMUX EQU CYREG_PRT1_AMUX
B1__BIE EQU CYREG_PRT1_BIE
B1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
B1__BYP EQU CYREG_PRT1_BYP
B1__CTL EQU CYREG_PRT1_CTL
B1__DM0 EQU CYREG_PRT1_DM0
B1__DM1 EQU CYREG_PRT1_DM1
B1__DM2 EQU CYREG_PRT1_DM2
B1__DR EQU CYREG_PRT1_DR
B1__INP_DIS EQU CYREG_PRT1_INP_DIS
B1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
B1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
B1__LCD_EN EQU CYREG_PRT1_LCD_EN
B1__MASK EQU 0x10
B1__PORT EQU 1
B1__PRT EQU CYREG_PRT1_PRT
B1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
B1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
B1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
B1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
B1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
B1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
B1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
B1__PS EQU CYREG_PRT1_PS
B1__SHIFT EQU 4
B1__SLW EQU CYREG_PRT1_SLW

/* B2 */
B2__0__INTTYPE EQU CYREG_PICU2_INTTYPE2
B2__0__MASK EQU 0x04
B2__0__PC EQU CYREG_PRT2_PC2
B2__0__PORT EQU 2
B2__0__SHIFT EQU 2
B2__AG EQU CYREG_PRT2_AG
B2__AMUX EQU CYREG_PRT2_AMUX
B2__BIE EQU CYREG_PRT2_BIE
B2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
B2__BYP EQU CYREG_PRT2_BYP
B2__CTL EQU CYREG_PRT2_CTL
B2__DM0 EQU CYREG_PRT2_DM0
B2__DM1 EQU CYREG_PRT2_DM1
B2__DM2 EQU CYREG_PRT2_DM2
B2__DR EQU CYREG_PRT2_DR
B2__INP_DIS EQU CYREG_PRT2_INP_DIS
B2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
B2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
B2__LCD_EN EQU CYREG_PRT2_LCD_EN
B2__MASK EQU 0x04
B2__PORT EQU 2
B2__PRT EQU CYREG_PRT2_PRT
B2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
B2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
B2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
B2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
B2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
B2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
B2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
B2__PS EQU CYREG_PRT2_PS
B2__SHIFT EQU 2
B2__SLW EQU CYREG_PRT2_SLW

/* G1 */
G1__0__INTTYPE EQU CYREG_PICU1_INTTYPE7
G1__0__MASK EQU 0x80
G1__0__PC EQU CYREG_PRT1_PC7
G1__0__PORT EQU 1
G1__0__SHIFT EQU 7
G1__AG EQU CYREG_PRT1_AG
G1__AMUX EQU CYREG_PRT1_AMUX
G1__BIE EQU CYREG_PRT1_BIE
G1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
G1__BYP EQU CYREG_PRT1_BYP
G1__CTL EQU CYREG_PRT1_CTL
G1__DM0 EQU CYREG_PRT1_DM0
G1__DM1 EQU CYREG_PRT1_DM1
G1__DM2 EQU CYREG_PRT1_DM2
G1__DR EQU CYREG_PRT1_DR
G1__INP_DIS EQU CYREG_PRT1_INP_DIS
G1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
G1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
G1__LCD_EN EQU CYREG_PRT1_LCD_EN
G1__MASK EQU 0x80
G1__PORT EQU 1
G1__PRT EQU CYREG_PRT1_PRT
G1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
G1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
G1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
G1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
G1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
G1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
G1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
G1__PS EQU CYREG_PRT1_PS
G1__SHIFT EQU 7
G1__SLW EQU CYREG_PRT1_SLW

/* G2 */
G2__0__INTTYPE EQU CYREG_PICU2_INTTYPE3
G2__0__MASK EQU 0x08
G2__0__PC EQU CYREG_PRT2_PC3
G2__0__PORT EQU 2
G2__0__SHIFT EQU 3
G2__AG EQU CYREG_PRT2_AG
G2__AMUX EQU CYREG_PRT2_AMUX
G2__BIE EQU CYREG_PRT2_BIE
G2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
G2__BYP EQU CYREG_PRT2_BYP
G2__CTL EQU CYREG_PRT2_CTL
G2__DM0 EQU CYREG_PRT2_DM0
G2__DM1 EQU CYREG_PRT2_DM1
G2__DM2 EQU CYREG_PRT2_DM2
G2__DR EQU CYREG_PRT2_DR
G2__INP_DIS EQU CYREG_PRT2_INP_DIS
G2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
G2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
G2__LCD_EN EQU CYREG_PRT2_LCD_EN
G2__MASK EQU 0x08
G2__PORT EQU 2
G2__PRT EQU CYREG_PRT2_PRT
G2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
G2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
G2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
G2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
G2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
G2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
G2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
G2__PS EQU CYREG_PRT2_PS
G2__SHIFT EQU 3
G2__SLW EQU CYREG_PRT2_SLW

/* OE */
OE__0__INTTYPE EQU CYREG_PICU5_INTTYPE0
OE__0__MASK EQU 0x01
OE__0__PC EQU CYREG_PRT5_PC0
OE__0__PORT EQU 5
OE__0__SHIFT EQU 0
OE__AG EQU CYREG_PRT5_AG
OE__AMUX EQU CYREG_PRT5_AMUX
OE__BIE EQU CYREG_PRT5_BIE
OE__BIT_MASK EQU CYREG_PRT5_BIT_MASK
OE__BYP EQU CYREG_PRT5_BYP
OE__CTL EQU CYREG_PRT5_CTL
OE__DM0 EQU CYREG_PRT5_DM0
OE__DM1 EQU CYREG_PRT5_DM1
OE__DM2 EQU CYREG_PRT5_DM2
OE__DR EQU CYREG_PRT5_DR
OE__INP_DIS EQU CYREG_PRT5_INP_DIS
OE__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
OE__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
OE__LCD_EN EQU CYREG_PRT5_LCD_EN
OE__MASK EQU 0x01
OE__PORT EQU 5
OE__PRT EQU CYREG_PRT5_PRT
OE__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
OE__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
OE__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
OE__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
OE__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
OE__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
OE__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
OE__PS EQU CYREG_PRT5_PS
OE__SHIFT EQU 0
OE__SLW EQU CYREG_PRT5_SLW

/* R1 */
R1__0__INTTYPE EQU CYREG_PICU1_INTTYPE6
R1__0__MASK EQU 0x40
R1__0__PC EQU CYREG_PRT1_PC6
R1__0__PORT EQU 1
R1__0__SHIFT EQU 6
R1__AG EQU CYREG_PRT1_AG
R1__AMUX EQU CYREG_PRT1_AMUX
R1__BIE EQU CYREG_PRT1_BIE
R1__BIT_MASK EQU CYREG_PRT1_BIT_MASK
R1__BYP EQU CYREG_PRT1_BYP
R1__CTL EQU CYREG_PRT1_CTL
R1__DM0 EQU CYREG_PRT1_DM0
R1__DM1 EQU CYREG_PRT1_DM1
R1__DM2 EQU CYREG_PRT1_DM2
R1__DR EQU CYREG_PRT1_DR
R1__INP_DIS EQU CYREG_PRT1_INP_DIS
R1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
R1__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
R1__LCD_EN EQU CYREG_PRT1_LCD_EN
R1__MASK EQU 0x40
R1__PORT EQU 1
R1__PRT EQU CYREG_PRT1_PRT
R1__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
R1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
R1__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
R1__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
R1__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
R1__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
R1__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
R1__PS EQU CYREG_PRT1_PS
R1__SHIFT EQU 6
R1__SLW EQU CYREG_PRT1_SLW

/* R2 */
R2__0__INTTYPE EQU CYREG_PICU2_INTTYPE4
R2__0__MASK EQU 0x10
R2__0__PC EQU CYREG_PRT2_PC4
R2__0__PORT EQU 2
R2__0__SHIFT EQU 4
R2__AG EQU CYREG_PRT2_AG
R2__AMUX EQU CYREG_PRT2_AMUX
R2__BIE EQU CYREG_PRT2_BIE
R2__BIT_MASK EQU CYREG_PRT2_BIT_MASK
R2__BYP EQU CYREG_PRT2_BYP
R2__CTL EQU CYREG_PRT2_CTL
R2__DM0 EQU CYREG_PRT2_DM0
R2__DM1 EQU CYREG_PRT2_DM1
R2__DM2 EQU CYREG_PRT2_DM2
R2__DR EQU CYREG_PRT2_DR
R2__INP_DIS EQU CYREG_PRT2_INP_DIS
R2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
R2__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
R2__LCD_EN EQU CYREG_PRT2_LCD_EN
R2__MASK EQU 0x10
R2__PORT EQU 2
R2__PRT EQU CYREG_PRT2_PRT
R2__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
R2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
R2__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
R2__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
R2__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
R2__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
R2__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
R2__PS EQU CYREG_PRT2_PS
R2__SHIFT EQU 4
R2__SLW EQU CYREG_PRT2_SLW

/* CLK */
CLK__0__INTTYPE EQU CYREG_PICU5_INTTYPE2
CLK__0__MASK EQU 0x04
CLK__0__PC EQU CYREG_PRT5_PC2
CLK__0__PORT EQU 5
CLK__0__SHIFT EQU 2
CLK__AG EQU CYREG_PRT5_AG
CLK__AMUX EQU CYREG_PRT5_AMUX
CLK__BIE EQU CYREG_PRT5_BIE
CLK__BIT_MASK EQU CYREG_PRT5_BIT_MASK
CLK__BYP EQU CYREG_PRT5_BYP
CLK__CTL EQU CYREG_PRT5_CTL
CLK__DM0 EQU CYREG_PRT5_DM0
CLK__DM1 EQU CYREG_PRT5_DM1
CLK__DM2 EQU CYREG_PRT5_DM2
CLK__DR EQU CYREG_PRT5_DR
CLK__INP_DIS EQU CYREG_PRT5_INP_DIS
CLK__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
CLK__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
CLK__LCD_EN EQU CYREG_PRT5_LCD_EN
CLK__MASK EQU 0x04
CLK__PORT EQU 5
CLK__PRT EQU CYREG_PRT5_PRT
CLK__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
CLK__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
CLK__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
CLK__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
CLK__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
CLK__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
CLK__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
CLK__PS EQU CYREG_PRT5_PS
CLK__SHIFT EQU 2
CLK__SLW EQU CYREG_PRT5_SLW

/* LAT */
LAT__0__INTTYPE EQU CYREG_PICU5_INTTYPE3
LAT__0__MASK EQU 0x08
LAT__0__PC EQU CYREG_PRT5_PC3
LAT__0__PORT EQU 5
LAT__0__SHIFT EQU 3
LAT__AG EQU CYREG_PRT5_AG
LAT__AMUX EQU CYREG_PRT5_AMUX
LAT__BIE EQU CYREG_PRT5_BIE
LAT__BIT_MASK EQU CYREG_PRT5_BIT_MASK
LAT__BYP EQU CYREG_PRT5_BYP
LAT__CTL EQU CYREG_PRT5_CTL
LAT__DM0 EQU CYREG_PRT5_DM0
LAT__DM1 EQU CYREG_PRT5_DM1
LAT__DM2 EQU CYREG_PRT5_DM2
LAT__DR EQU CYREG_PRT5_DR
LAT__INP_DIS EQU CYREG_PRT5_INP_DIS
LAT__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
LAT__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
LAT__LCD_EN EQU CYREG_PRT5_LCD_EN
LAT__MASK EQU 0x08
LAT__PORT EQU 5
LAT__PRT EQU CYREG_PRT5_PRT
LAT__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
LAT__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
LAT__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
LAT__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
LAT__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
LAT__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
LAT__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
LAT__PS EQU CYREG_PRT5_PS
LAT__SHIFT EQU 3
LAT__SLW EQU CYREG_PRT5_SLW

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
