/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Functions and registers to access AC200 IC.
 *
 * Copyright (C) 2019 Jernej Skrabec <jernej.skrabec@siol.net>
 */

#ifndef __LINUX_MFD_AC200_H
#define __LINUX_MFD_AC200_H

#include <linux/types.h>
#include <linux/regmap.h>
#include <linux/clk.h>

/* interface registers (can be accessed from any page) */
#define AC200_TWI_CHANGE_TO_RSB		0x3E
#define AC200_TWI_PAD_DELAY		0xC4
#define AC200_TWI_REG_ADDR_H		0xFE

/* General registers */
#define AC200_SYS_VERSION		0x0000
#define AC200_SYS_CONTROL		0x0002
#define AC200_SYS_IRQ_ENABLE		0x0004
#define AC200_SYS_IRQ_STATUS		0x0006
#define AC200_SYS_CLK_CTL		0x0008
#define AC200_SYS_DLDO_OSC_CTL		0x000A
#define AC200_SYS_PLL_CTL0		0x000C
#define AC200_SYS_PLL_CTL1		0x000E
#define AC200_SYS_AUDIO_CTL0		0x0010
#define AC200_SYS_AUDIO_CTL1		0x0012
#define AC200_SYS_EPHY_CTL0		0x0014
#define AC200_SYS_EPHY_CTL1		0x0016
#define AC200_SYS_TVE_CTL0		0x0018
#define AC200_SYS_TVE_CTL1		0x001A


/* Audio Codec registers */
#define AC200_AC_SYS_CLK_CTL            0x2000
#define AC200_SYS_MOD_RST               0x2002
#define AC200_SYS_SAMP_CTL              0x2004
#define AC200_I2S_CTL                   0x2100
#define AC200_I2S_CLK                   0x2102
#define AC200_I2S_FMT0                  0x2104
#define AC200_I2S_FMT1                  0x2108
#define AC200_I2S_MIX_SRC               0x2114
#define AC200_I2S_MIX_GAIN              0x2116
#define AC200_I2S_DACDAT_DVC            0x2118
#define AC200_I2S_ADCDAT_DVC            0x211A
#define AC200_AC_DAC_DPC                0x2200
#define AC200_AC_DAC_MIX_SRC            0x2202
#define AC200_AC_DAC_MIX_GAIN           0x2204
#define AC200_DACA_OMIXER_CTRL          0x2220
#define AC200_OMIXER_SR                 0x2222
#define AC200_LINEOUT_CTRL              0x2224
#define AC200_AC_ADC_DPC                0x2300
#define AC200_MBIAS_CTRL                0x2310
#define AC200_ADC_MIC_CTRL              0x2320
#define AC200_ADCMIXER_SR               0x2322
#define AC200_ANALOG_TUNING0            0x232A
#define AC200_ANALOG_TUNING1            0x232C
#define AC200_AC_AGC_SEL                0x2480
#define AC200_ADC_DAPLCTRL              0x2500
#define AC200_ADC_DAPRCTRL              0x2502
#define AC200_ADC_DAPLSTA               0x2504
#define AC200_ADC_DAPRSTA               0x2506
#define AC200_ADC_DAPLTL                0x2508
#define AC200_ADC_DAPRTL                0x250A
#define AC200_ADC_DAPLHAC               0x250C
#define AC200_ADC_DAPLLAC               0x250E
#define AC200_ADC_DAPRHAC               0x2510
#define AC200_ADC_DAPRLAC               0x2512
#define AC200_ADC_DAPLDT                0x2514
#define AC200_ADC_DAPLAT                0x2516
#define AC200_ADC_DAPRDT                0x2518
#define AC200_ADC_DAPRAT                0x251A
#define AC200_ADC_DAPNTH                0x251C
#define AC200_ADC_DAPLHNAC              0x251E
#define AC200_ADC_DAPLLNAC              0x2520
#define AC200_ADC_DAPRHNAC              0x2522
#define AC200_ADC_DAPRLNAC              0x2524
#define AC200_AC_DAPHHPFC               0x2526
#define AC200_AC_DAPLHPFC               0x2528
#define AC200_AC_DAPOPT                 0x252A
#define AC200_AC_DAC_DAPCTRL            0x3000
#define AC200_AC_DRC_HHPFC              0x3002
#define AC200_AC_DRC_LHPFC              0x3004
#define AC200_AC_DRC_CTRL               0x3006
#define AC200_AC_DRC_LPFHAT             0x3008
#define AC200_AC_DRC_LPFLAT             0x300A
#define AC200_AC_DRC_RPFHAT             0x300C
#define AC200_AC_DRC_RPFLAT             0x300E
#define AC200_AC_DRC_LPFHRT             0x3010
#define AC200_AC_DRC_LPFLRT             0x3012
#define AC200_AC_DRC_RPFHRT             0x3014
#define AC200_AC_DRC_RPFLRT             0x3016
#define AC200_AC_DRC_LRMSHAT            0x3018
#define AC200_AC_DRC_LRMSLAT            0x301A
#define AC200_AC_DRC_RRMSHAT            0x301C
#define AC200_AC_DRC_RRMSLAT            0x301E
#define AC200_AC_DRC_HCT                0x3020
#define AC200_AC_DRC_LCT                0x3022
#define AC200_AC_DRC_HKC                0x3024
#define AC200_AC_DRC_LKC                0x3026
#define AC200_AC_DRC_HOPC               0x3028
#define AC200_AC_DRC_LOPC               0x302A
#define AC200_AC_DRC_HLT                0x302C
#define AC200_AC_DRC_LLT                0x302E
#define AC200_AC_DRC_HKI                0x3030
#define AC200_AC_DRC_LKI                0x3032
#define AC200_AC_DRC_HOPL               0x3034
#define AC200_AC_DRC_LOPL               0x3036
#define AC200_AC_DRC_HET                0x3038
#define AC200_AC_DRC_LET                0x303A
#define AC200_AC_DRC_HKE                0x303C
#define AC200_AC_DRC_LKE                0x303E
#define AC200_AC_DRC_HOPE               0x3040
#define AC200_AC_DRC_LOPE               0x3042
#define AC200_AC_DRC_HKN                0x3044
#define AC200_AC_DRC_LKN                0x3046
#define AC200_AC_DRC_SFHAT              0x3048
#define AC200_AC_DRC_SFLAT              0x304A
#define AC200_AC_DRC_SFHRT              0x304C
#define AC200_AC_DRC_SFLRT              0x304E
#define AC200_AC_DRC_MXGHS              0x3050
#define AC200_AC_DRC_MXGLS              0x3052
#define AC200_AC_DRC_MNGHS              0x3054
#define AC200_AC_DRC_MNGLS              0x3056
#define AC200_AC_DRC_EPSHC              0x3058
#define AC200_AC_DRC_EPSLC              0x305A
#define AC200_AC_DRC_HPFHGAIN           0x305E
#define AC200_AC_DRC_HPFLGAIN           0x3060
#define AC200_AC_DRC_BISTCR             0x3100
#define AC200_AC_DRC_BISTST             0x3102

/* TVE registers */
#define AC200_TVE_CTL0                  0x4000
#define AC200_TVE_CTL1                  0x4002
#define AC200_TVE_MOD0                  0x4004
#define AC200_TVE_MOD1                  0x4006
#define AC200_TVE_DAC_CFG0              0x4008
#define AC200_TVE_DAC_CFG1              0x400A
#define AC200_TVE_YC_DELAY              0x400C
#define AC200_TVE_YC_FILTER             0x400E
#define AC200_TVE_BURST_FRQ0            0x4010
#define AC200_TVE_BURST_FRQ1            0x4012
#define AC200_TVE_FRONT_PORCH           0x4014
#define AC200_TVE_BACK_PORCH            0x4016
#define AC200_TVE_TOTAL_LINE            0x401C
#define AC200_TVE_FIRST_ACTIVE          0x401E
#define AC200_TVE_BLACK_LEVEL           0x4020
#define AC200_TVE_BLANK_LEVEL           0x4022
#define AC200_TVE_PLUG_EN               0x4030
#define AC200_TVE_PLUG_IRQ_EN           0x4032
#define AC200_TVE_PLUG_IRQ_STA          0x4034
#define AC200_TVE_PLUG_STA              0x4038
#define AC200_TVE_PLUG_DEBOUNCE         0x4040
#define AC200_TVE_DAC_TEST              0x4042
#define AC200_TVE_PLUG_PULSE_LEVEL      0x40F4
#define AC200_TVE_PLUG_PULSE_START      0x40F8
#define AC200_TVE_PLUG_PULSE_PERIOD     0x40FA
#define AC200_TVE_IF_CTL                0x5000
#define AC200_TVE_IF_TIM0               0x5008
#define AC200_TVE_IF_TIM1               0x500A
#define AC200_TVE_IF_TIM2               0x500C
#define AC200_TVE_IF_TIM3               0x500E
#define AC200_TVE_IF_SYNC0              0x5010
#define AC200_TVE_IF_SYNC1              0x5012
#define AC200_TVE_IF_SYNC2              0x5014
#define AC200_TVE_IF_TIM4               0x5016
#define AC200_TVE_IF_STATUS             0x5018

/* eFuse registers (0x8000 - 0x9FFF, layout unknown) */

/* RTC registers */
#define AC200_LOSC_CTRL0                0xA000
#define AC200_LOSC_CTRL1                0xA002
#define AC200_LOSC_AUTO_SWT_STA         0xA004
#define AC200_INTOSC_CLK_PRESCAL        0xA008
#define AC200_RTC_YY_MM_DD0             0xA010
#define AC200_RTC_YY_MM_DD1             0xA012
#define AC200_RTC_HH_MM_SS0             0xA014
#define AC200_RTC_HH_MM_SS1             0xA016
#define AC200_ALARM0_CUR_VLU0           0xA024
#define AC200_ALARM0_CUR_VLU1           0xA026
#define AC200_ALARM0_ENABLE             0xA028
#define AC200_ALARM0_IRQ_EN             0xA02C
#define AC200_ALARM0_IRQ_STA            0xA030
#define AC200_ALARM1_WK_HH_MM_SS0       0xA040
#define AC200_ALARM1_WK_HH_MM_SS1       0xA042
#define AC200_ALARM1_ENABLE             0xA044
#define AC200_ALARM1_IRQ_EN             0xA048
#define AC200_ALARM1_IRQ_STA            0xA04C
#define AC200_ALARM_CONFIG              0xA050
#define AC200_LOSC_OUT_GATING           0xA060
#define AC200_GP_DATA(x)                (0xA100 + (x) * 2)
#define AC200_RTC_DEB                   0xA170
#define AC200_GPL_HOLD_OUTPUT           0xA180
#define AC200_VDD_RTC                   0xA190
#define AC200_IC_CHARA0                 0xA1F0
#define AC200_IC_CHARA1                 0xA1F2

/* EPHY registers */
#define AC200_EPHY_CTL			0x6000
#define AC200_EPHY_BIST			0x6002

struct ac200_dev {
        struct clk                    *clk;
        /*
         * Lock is needed for serializing concurrent access to
         * AC200 registers in order not to mess with register page.
         */
        //struct mutex    lock;
        struct regmap   *regmap;
        struct regmap_irq_chip_data     *regmap_irqc;
};

//int ac200_reg_read(struct ac200_dev *ac200, u16 reg, u16 *value);
//int ac200_reg_write(struct ac200_dev *ac200, u16 reg, u16 value);
//int ac200_reg_mod(struct ac200_dev *ac200, u16 reg, u16 mask, u16 value);

#endif /* __LINUX_MFD_AC200_H */
