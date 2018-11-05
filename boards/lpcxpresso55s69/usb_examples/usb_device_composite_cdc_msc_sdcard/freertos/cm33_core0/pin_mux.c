/*
 * Copyright 2017-2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v4.1
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 0.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '78', peripheral: USBFSH, signal: USB_VBUS, pin_signal: PIO0_22/FC6_TXD_SCL_MISO_WS/UTICK_CAP1/CT_INP15/SCT0_OUT3/USB0_VBUS/SD1_D0/PLU_OUT7/SECURE_GPIO0_22,
    mode: inactive, slew_rate: standard, invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '92', peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI_DATA, pin_signal: PIO0_29/FC0_RXD_SDA_MOSI_DATA/SD1_D2/CTIMER2_MAT3/SCT0_OUT8/CMP0_OUT/PLU_OUT2/SECURE_GPIO0_29,
    mode: inactive, slew_rate: standard, invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '94', peripheral: FLEXCOMM0, signal: TXD_SCL_MISO_WS, pin_signal: PIO0_30/FC0_TXD_SCL_MISO_WS/SD1_D3/CTIMER0_MAT0/SCT0_OUT9/SECURE_GPIO0_30, mode: inactive,
    slew_rate: standard, invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '8', peripheral: SDIF, signal: SD0_CARD_DET, pin_signal: PIO0_17/FC4_SSEL2/SD0_CARD_DET_N/SCT_GPI7/SCT0_OUT0/SD0_CARD_INT_N/PLU_IN2/SECURE_GPIO0_17,
    mode: inactive, slew_rate: standard, invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '6', peripheral: SDIF, signal: SD0_CLK, pin_signal: PIO0_7/FC3_RTS_SCL_SSEL1/SD0_CLK/FC5_SCK/FC1_SCK/SECURE_GPIO0_7, mode: inactive, slew_rate: fast,
    invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '26', peripheral: SDIF, signal: SD0_CMD, pin_signal: PIO0_8/FC3_SSEL3/SD0_CMD/FC5_RXD_SDA_MOSI_DATA/SWO/SECURE_GPIO0_8, mode: inactive, slew_rate: fast,
    invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '55', peripheral: SDIF, signal: SD0_POW_EN, pin_signal: PIO0_9/ACMP0_B/FC3_SSEL2/SD0_POW_EN/FC5_TXD_SCL_MISO_WS/SECURE_GPIO0_9, mode: inactive, slew_rate: standard,
    invert: disabled, digi_mode: digital, open_drain: disabled, asw: enabled}
  - {pin_num: '70', peripheral: SDIF, signal: 'SD0_D, 0', pin_signal: PIO0_24/FC0_RXD_SDA_MOSI_DATA/SD0_D0/CT_INP8/SCT_GPI0/SECURE_GPIO0_24, mode: inactive, slew_rate: fast,
    invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '79', peripheral: SDIF, signal: 'SD0_D, 1', pin_signal: PIO0_25/FC0_TXD_SCL_MISO_WS/SD0_D1/CT_INP9/SCT_GPI1/SECURE_GPIO0_25, mode: inactive, slew_rate: fast,
    invert: disabled, digi_mode: digital, open_drain: disabled}
  - {pin_num: '23', peripheral: SDIF, signal: 'SD0_D, 2', pin_signal: PIO0_31/ADC0_3/FC0_CTS_SDA_SSEL0/SD0_D2/CTIMER0_MAT1/SCT0_OUT3/SECURE_GPIO0_31, mode: inactive,
    slew_rate: fast, invert: disabled, digi_mode: digital, open_drain: disabled, asw: enabled}
  - {pin_num: '11', peripheral: SDIF, signal: 'SD0_D, 3', pin_signal: PIO1_0/ADC0_11/FC0_RTS_SCL_SSEL1/SD0_D3/CT_INP2/SCT_GPI4/PLU_OUT3, mode: inactive, slew_rate: fast,
    invert: disabled, digi_mode: digital, open_drain: disabled, asw: enabled}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M33 (Core #0) */
void BOARD_InitPins(void)
{
    /* Enables the clock for the I/O controller.: Enable Clock. */
    CLOCK_EnableClock(kCLOCK_Iocon);

    const uint32_t port0_pin17_config = (/* Pin is configured as SD0_CARD_DET_N */
                                         IOCON_PIO_FUNC2 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN17 (coords: 8) is configured as SD0_CARD_DET_N */
    IOCON_PinMuxSet(IOCON, 0U, 17U, port0_pin17_config);

    const uint32_t port0_pin22_config = (/* Pin is configured as USB0_VBUS */
                                         IOCON_PIO_FUNC7 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN22 (coords: 78) is configured as USB0_VBUS */
    IOCON_PinMuxSet(IOCON, 0U, 22U, port0_pin22_config);

    const uint32_t port0_pin24_config = (/* Pin is configured as SD0_D0 */
                                         IOCON_PIO_FUNC2 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN24 (coords: 70) is configured as SD0_D0 */
    IOCON_PinMuxSet(IOCON, 0U, 24U, port0_pin24_config);

    const uint32_t port0_pin25_config = (/* Pin is configured as SD0_D1 */
                                         IOCON_PIO_FUNC2 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN25 (coords: 79) is configured as SD0_D1 */
    IOCON_PinMuxSet(IOCON, 0U, 25U, port0_pin25_config);

    const uint32_t port0_pin29_config = (/* Pin is configured as FC0_RXD_SDA_MOSI_DATA */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN29 (coords: 92) is configured as FC0_RXD_SDA_MOSI_DATA */
    IOCON_PinMuxSet(IOCON, 0U, 29U, port0_pin29_config);

    const uint32_t port0_pin30_config = (/* Pin is configured as FC0_TXD_SCL_MISO_WS */
                                         IOCON_PIO_FUNC1 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Standard mode, output slew rate control is enabled */
                                         IOCON_PIO_SLEW_STANDARD |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN30 (coords: 94) is configured as FC0_TXD_SCL_MISO_WS */
    IOCON_PinMuxSet(IOCON, 0U, 30U, port0_pin30_config);

    const uint32_t port0_pin31_config = (/* Pin is configured as SD0_D2 */
                                         IOCON_PIO_FUNC2 |
                                         /* No addition pin function */
                                         IOCON_PIO_MODE_INACT |
                                         /* Fast mode, slew rate control is disabled */
                                         IOCON_PIO_SLEW_FAST |
                                         /* Input function is not inverted */
                                         IOCON_PIO_INV_DI |
                                         /* Enables digital function */
                                         IOCON_PIO_DIGITAL_EN |
                                         /* Open drain is disabled */
                                         IOCON_PIO_OPENDRAIN_DI |
                                         /* Analog switch input control is enabled */
                                         IOCON_PIO_ASW_EN);
    /* PORT0 PIN31 (coords: 23) is configured as SD0_D2 */
    IOCON_PinMuxSet(IOCON, 0U, 31U, port0_pin31_config);

    const uint32_t port0_pin7_config = (/* Pin is configured as SD0_CLK */
                                        IOCON_PIO_FUNC2 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN7 (coords: 6) is configured as SD0_CLK */
    IOCON_PinMuxSet(IOCON, 0U, 7U, port0_pin7_config);

    const uint32_t port0_pin8_config = (/* Pin is configured as SD0_CMD */
                                        IOCON_PIO_FUNC2 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI);
    /* PORT0 PIN8 (coords: 26) is configured as SD0_CMD */
    IOCON_PinMuxSet(IOCON, 0U, 8U, port0_pin8_config);

    const uint32_t port0_pin9_config = (/* Pin is configured as SD0_POW_EN */
                                        IOCON_PIO_FUNC2 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Standard mode, output slew rate control is enabled */
                                        IOCON_PIO_SLEW_STANDARD |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI |
                                        /* Analog switch input control is enabled */
                                        IOCON_PIO_ASW_EN);
    /* PORT0 PIN9 (coords: 55) is configured as SD0_POW_EN */
    IOCON_PinMuxSet(IOCON, 0U, 9U, port0_pin9_config);

    const uint32_t port1_pin0_config = (/* Pin is configured as SD0_D3 */
                                        IOCON_PIO_FUNC2 |
                                        /* No addition pin function */
                                        IOCON_PIO_MODE_INACT |
                                        /* Fast mode, slew rate control is disabled */
                                        IOCON_PIO_SLEW_FAST |
                                        /* Input function is not inverted */
                                        IOCON_PIO_INV_DI |
                                        /* Enables digital function */
                                        IOCON_PIO_DIGITAL_EN |
                                        /* Open drain is disabled */
                                        IOCON_PIO_OPENDRAIN_DI |
                                        /* Analog switch input control is enabled */
                                        IOCON_PIO_ASW_EN);
    /* PORT1 PIN0 (coords: 11) is configured as SD0_D3 */
    IOCON_PinMuxSet(IOCON, 1U, 0U, port1_pin0_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
