#ifndef __DSI_H__
#define __DSI_H__

typedef struct
{
    __IO uint32_t CTRL_0;  //0x00 OFFSET 

    __IO uint32_t CTRL_1;  //0x04 OFFSET 
    __IO uint32_t CTRL_2;  //0x08 OFFSET 
    __IO uint32_t CTRL_3;  //0x0C OFFSET 

    __IO uint32_t IRQ_ST;  //0x10 OFFSET 
    __IO uint32_t IRQ_MASK;  //0x14 OFFSET 
    __IO uint32_t RESERVED0[2];
    __IO uint32_t CPU_CMD_0;  //0x20 OFFSET 

    __IO uint32_t CPU_CMD_1;  //0x24 OFFSET 
    __IO uint32_t CPU_CMD_2;  //0x28 OFFSET 

    __IO uint32_t CPU_CMD_3;  //0x2C OFFSET 

    __IO uint32_t CPU_WDAT_0;  //0x30 OFFSET 
    __IO uint32_t CPU_STATUS0;  //0x34 OFFSET 

    __IO uint32_t CPU_STATUS1;  //0x38 OFFSET 

    __IO uint32_t CPU_STATUS2;  //0x3C OFFSET 
    __IO uint32_t CPU_STATUS3;  //0x40 OFFSET 

    __IO uint32_t CPU_STATUS4;  //0x44 OFFSET 

    __IO uint32_t SMT_STATUS2;  //0x48 OFFSET 
    __IO uint32_t SMT_STATUS1;  //0x4C OFFSET 
    __IO uint32_t SMT_CMD;  //0x50 OFFSET 

    __IO uint32_t SMT_CTRL_0;  //0x54 OFFSET 
    __IO uint32_t SMT_CTRL_1;  //0x58 OFFSET 
    __IO uint32_t RESERVED11;  //0x5C OFFSET 

    __IO uint32_t RX_PKT_ST_0;  //0x60 OFFSET 
    __IO uint32_t RX_PKT_HDR_0;  //0x64 OFFSET 
    __IO uint32_t RX_PKT_ST_1;  //0x68 OFFSET 

    __IO uint32_t RX_PKT_HDR_1;  //0x6C OFFSET 
    __IO uint32_t RX_PKT_CTRL;  //0x70 OFFSET 
    __IO uint32_t RX_PKT_CTRL_1;  //0x74 OFFSET 

    __IO uint32_t RX_PKT_ST_2;  //0x78 OFFSET 
    __IO uint32_t RX_PKT_HDR_2;  //0x7C OFFSET 
    __IO uint32_t PHY_CTRL_0;  //0x80 OFFSET 

    __IO uint32_t PHY_CTRL_1;  //0x84 OFFSET 
    __IO uint32_t PHY_CTRL_2;  //0x88 OFFSET 
    __IO uint32_t PHY_CTRL_3;  //0x8C OFFSET 

    __IO uint32_t PHY_STATUS_0;  //0x90 OFFSET 
    __IO uint32_t PHY_STATUS_1;  //0x94 OFFSET 
    __IO uint32_t PHY_LPRX_0;  //0x98 OFFSET 

    __IO uint32_t PHY_LPRX_1;  //0x9C OFFSET 
    __IO uint32_t PHY_LPTX_0;  //0xA0 OFFSET 
    __IO uint32_t PHY_LPTX_1;  //0xA4 OFFSET 

    __IO uint32_t PHY_LPTX_2;  //0xA8 OFFSET 
    __IO uint32_t PHY_STATUS_2;  //0xAC OFFSET 

    __IO uint32_t PHY_rcomp_0;  //0xB0 OFFSET 

    __IO uint32_t PHY_rcomp_1;  //0xB4 OFFSET 
    __IO uint32_t RESERVED1[2];
     __IO uint32_t PHY_TIME_0;  //0xC0 OFFSET 
     __IO uint32_t PHY_TIME_1;  //0xC4 OFFSET 

    __IO uint32_t PHY_TIME_2;  //0xC8 OFFSET 
    __IO uint32_t PHY_TIME_3;  //0xCC OFFSET 
    __IO uint32_t PHY_CODE_0;  //0xD0 OFFSET 

    __IO uint32_t PHY_CODE_1;  //0xD4 OFFSET 
    __IO uint32_t PHY_TIME_6;  //0xD8 OFFSET 
    __IO uint32_t PHY_TIME_7;  //0xDC OFFSET 
 
    __IO uint32_t MEM_CTRL;  //0xE0 OFFSET 
    __IO uint32_t TX_TIMER;  //0xE4 OFFSET 

    __IO uint32_t RX_TIMER;  //0xE8 OFFSET 

    __IO uint32_t TURN_TIMER;  //0xEC OFFSET 
   __IO uint32_t RESERVED2[(0x100-0xec)/4-1];

    __IO uint32_t LCD1_CTRL_0;  //0x100 OFFSET 
    __IO uint32_t LCD1_CTRL_1;  //0x104 OFFSET 

    __IO uint32_t LCD1_CTRL_2;  //0x108 OFFSET 
    __IO uint32_t LCD1_CTRL_3;  //0x10C OFFSET 
    __IO uint32_t LCD1_TIMING_0;  //0x110 OFFSET 

    __IO uint32_t LCD1_TIMING_1;  //0x114 OFFSET 
    __IO uint32_t LCD1_TIMING_2;  //0x118 OFFSET 
    __IO uint32_t LCD1_TIMING_3;  //0x11C OFFSET 

    __IO uint32_t LCD1_WC_0;  //0x120 OFFSET 
    __IO uint32_t LCD1_WC_1;  //0x124 OFFSET 

    __IO uint32_t LCD1_WC_2;  //0x128 OFFSET 

    __IO uint32_t LCD1_WC_3;  //0x12C OFFSET 
    __IO uint32_t LCD1_SLOT_CNT_0;  //0x130 OFFSET 
    __IO uint32_t LCD1_SLOT_CNT_1;  //0x134 OFFSET 
    __IO uint32_t RESERVED3[2];

    __IO uint32_t LCD1_STATUS_0;  //0x140 OFFSET 
    __IO uint32_t LCD1_STATUS_1;  //0x144 OFFSET 
    __IO uint32_t LCD1_STATUS_2;  //0x148 OFFSET 

    __IO uint32_t LCD1_STATUS_3;  //0x14C OFFSET 
    __IO uint32_t LCD1_STATUS_4;  //0x150 OFFSET 
    __IO uint32_t RESERVED4[(0x180-0x150)/4-1];
    __IO uint32_t LCD2_CTRL_0;  //0x180 OFFSET 
    __IO uint32_t LCD2_CTRL_1;  //0x184 OFFSET 

    __IO uint32_t LCD2_CTRL_2;  //0x188 OFFSET 
    __IO uint32_t LCD2_CTRL_3;  //0x18C OFFSET 
    __IO uint32_t LCD2_TIMING_0;  //0x190 OFFSET 
    __IO uint32_t LCD2_TIMING_1;  //0x194 OFFSET 

    __IO uint32_t LCD2_TIMING_2;  //0x198 OFFSET 
    __IO uint32_t LCD2_TIMING_3;  //0x19C OFFSET 
    __IO uint32_t LCD2_WC_0;  //0x1A0 OFFSET 
    __IO uint32_t LCD2_WC_1;  //0x1A4 OFFSET 

    __IO uint32_t LCD2_WC_2;  //0x1A8 OFFSET 
    __IO uint32_t LCD2_WC_3;  //0x1AC OFFSET 
    __IO uint32_t LCD2_SLOT_CNT_0;  //0x1B0 OFFSET 
    __IO uint32_t LCD2_SLOT_CNT_1;  //0x1B4 OFFSET 
    __IO uint32_t RESERVED5[2];
    __IO uint32_t LCD2_STATUS_0;  //0x1C0 OFFSET 
    __IO uint32_t LCD2_STATUS_1;  //0x1C4 OFFSET 
    __IO uint32_t LCD2_STATUS_2;  //0x1C8 OFFSET 
    __IO uint32_t LCD2_STATUS_3;  //0x1CC OFFSET 

    __IO uint32_t LCD2_STATUS_4;  //0x1D0 OFFSET 
    __IO uint32_t RESERVED6[(0x1e0-0x1d0)/4-1];
    __IO uint32_t TOP_STATUS_0;  //0x1E0 OFFSET 
    __IO uint32_t TOP_STATUS_1;  //0x1E4 OFFSET 
    __IO uint32_t TOP_STATUS_2;  //0x1E8 OFFSET 
    __IO uint32_t TOP_STATUS_3;  //0x1EC OFFSET
    __IO uint32_t RESERVED7[(0x1f4-0x1ec)/4-1];
    __IO uint32_t DSI_CTRL;	//0x1F4 OFFSET

}DSI_TypeDef;

#define DSI_BASE   0xD420B800			//DSI1 4lanes

#define    DSI  (( DSI_TypeDef *) DSI_BASE )

//DSI Control Register 0
#define CTRL_0_CFG_SOFT_RST   BIT_31
#define CTRL_0_CFG_SOFT_RST_REG   BIT_30
#define CTRL_0_CFG_CLR_PHY_FIFO   BIT_29
#define CTRL_0_CFG_RST_TXLP   BIT_28
#define CTRL_0_CFG_RST_CPU   BIT_27
#define CTRL_0_CFG_RST_SMT   BIT_26
#define CTRL_0_CFG_RST_LCD2   BIT_25
#define CTRL_0_CFG_RST_LCD1   BIT_24
#define CTRL_0_CFG_RST_PHY   BIT_23
#define CTRL_0_CFG_HCLK_DIS   BIT_17
#define CTRL_0_CFG_CLK_DIS   BIT_16
#define CTRL_0_CFG_LCD2_TX_EN   BIT_9
#define CTRL_0_CFG_LCD1_TX_EN   BIT_8
#define CTRL_0_CFG_LCD2_SLV   BIT_5
#define CTRL_0_CFG_LCD1_SLV   BIT_4
#define CTRL_0_CFG_SMT_EN   BIT_2
#define CTRL_0_CFG_LCD2_EN   BIT_1
#define CTRL_0_CFG_LCD1_EN   BIT_0


//DSI Control Register 1
#define CTRL_1_CFG_EOTP_EN  BIT_8
#define CTRL_1_Always1    BIT_5
#define CTRL_1_CFG_SMT_VCH_NO_MSK   SHIFT6(0x3)
#define CTRL_1_CFG_SMT_VCH_NO_BASE   6
#define CTRL_1_CFG_CPU_VCH_NO_MSK   SHIFT4(0x3)
#define CTRL_1_CFG_CPU_VCH_NO_BASE   4
#define CTRL_1_CFG_LCD2_VCH_NO_MSK   SHIFT2(0x3)
#define CTRL_1_CFG_LCD2_VCH_NO_BASE   2
#define CTRL_1_CFG_LCD1_VCH_NO_MSK   SHIFT0(0x3)
#define CTRL_1_CFG_LCD1_VCH_NO_BASE   0


//DSI Interrupt Status Register
#define IRQ_ST_IRQ_SMT_TE   BIT_30
#define IRQ_ST_IRQ_TA_TIMEOUT   BIT_29
#define IRQ_ST_IRQ_RX_TIMEOUT   BIT_28
#define IRQ_ST_IRQ_TX_TIMEOUT   BIT_27
#define IRQ_ST_IRQ_RX_STATE_ERR   BIT_26
#define IRQ_ST_IRQ_RX_ERR   BIT_25
#define IRQ_ST_IRQ_RX_FIFO_FULL_ERR   BIT_24
#define IRQ_ST_IRQ_PHY_FIFO_UNDERRUN   BIT_23
#define IRQ_ST_IRQ_REQ_CNT_ERR   BIT_22
#define IRQ_ST_IRQ_L2_REQ_PHY_DLY_ERR   BIT_21
#define IRQ_ST_IRQ_L1_REQ_PHY_DLY_ERR   BIT_20
#define IRQ_ST_IIRQ_L2_REQ_ARB_DLY_ERR   BIT_19
#define IRQ_ST_IRQ_L1_REQ_ARB_DLY_ERR   BIT_18
#define IRQ_ST_IRQ_L2_TIMING_ERR   BIT_17
#define IRQ_ST_IRQ_L1_TIMING_ERR   BIT_16
#define IRQ_ST_IRQ_DPHY_ERR_CONT_LP1   BIT_12
#define IRQ_ST_IRQ_DPHY_ERR_CONT_LP0   BIT_11
#define IRQ_ST_IRQ_DPHY_ERR_SYNC_ESC   BIT_10

#define IRQ_ST_IRQ_DPHY_ERR_ESC   BIT_9
#define IRQ_ST_IRQ_DPHY_RX_LINE_ERR   BIT_8
#define IRQ_ST_IRQ_RX_TRG3   BIT_7
#define IRQ_ST_IRQ_RX_TRG2   BIT_6
#define IRQ_ST_IRQ_RX_TRG1   BIT_5
#define IRQ_ST_IRQ_RX_TRG0   BIT_4
#define IRQ_ST_IRQ_RX_ULPS   BIT_3
#define IRQ_ST_IRQ_RX_PKT   BIT_2
#define IRQ_ST_IRQ_SMT_TX_DONE   BIT_1
#define IRQ_ST_IRQ_IRQ_CPU_TX_DONE   BIT_0


//DSI CPU Packet Command Register 0
#define CPU_CMD_0_CFG_CPU_CMD_REQ  BIT_31
#define CPU_CMD_0_CFG_CPU_SP       BIT_30
#define CPU_CMD_0_CFG_CPU_TURN     BIT_29
#define CPU_CMD_0_CFG_CPU_TXLP     BIT_27
#define CPU_CMD_0_CFG_CPU_WC_MSK   SHIFT0(0xffff)
#define CPU_CMD_0_CFG_CPU_WC_BASE   0

//DSI CPU Packet Command Register 1
#define CPU_CMD_1_CFG_TXLP_LPDT_MSK  SHIFT20(0xf)
#define CPU_CMD_1_CFG_TXLP_LPDT_BASE    20
#define CPU_CMD_1_CFG_TXLP_ULPS_MSK  SHIFT16(0xf)
#define CPU_CMD_1_CFG_TXLP_ULPS_BASE    16
#define CPU_CMD_1_CFG_TXLP_TRIGGER_CODE_MSK  SHIFT0(0xffff)
#define CPU_CMD_1_CFG_TXLP_TRIGGER_CODE_BASE    0


//DSI CPU packet command register 3
#define CPU_CMD_3_CFG_CPU_DAT_REQ  BIT_31
#define CPU_CMD_3_CFG_CPU_DAT_RW  BIT_30
#define CPU_CMD_3_CFG_CPU_DAT_ADDR_MSK  SHIFT16(0xff)
#define CPU_CMD_3_CFG_CPU_DAT_ADDR_BASE   16


//DSI SMT Status 1 Register
#define SMT_STATUS1_SMT_BF_CNT_MSK  SHIFT26(0x2f)
#define SMT_STATUS1_SMT_BF_CNT_BASE  26
#define SMT_STATUS1_SMT_FIFO_BCNT_MSK  SHIFT16(0x2ff)
#define SMT_STATUS1_SMT_FIFO_BCNT_BASE  16
#define SMT_STATUS1_SMT_CS_MSK  SHIFT8(0x1f)
#define SMT_STATUS1_SMT_CS_BASE  8
#define SMT_STATUS1_SMT_WR_ON  BIT_5
#define SMT_STATUS1_SMT_DMA_ON  BIT_4
#define SMT_STATUS1_SMT_FIFO_EMPTY  BIT_3
#define SMT_STATUS1_SMT_BF_EMPTY  BIT_2
#define SMT_STATUS1_SMF_FIFO_FULL  BIT_1
#define SMT_STATUS1_SMT_BF_FULL  BIT_0

//DSI Smart Panel Command Register
#define SMT_CMD_CFG_SMT_TE_EN_MSK  SHIFT28(0xf)
#define SMT_CMD_CFG_SMT_TE_EN_BASE  28
#define SMT_CMD_CFG_DMT_RGB_TYPE_MSK  SHIFT24(0x7)
#define SMT_CMD_CFG_DMT_RGB_TYPE_BASE  24
#define SMT_CMD_CFG_SMT_2CYC_EN_   BIT_4
#define SMT_CMD_CFG_SMT_DIN_565SWAP   BIT_2
#define SMT_CMD_CFG_CFG_SMT_DMA_DIS   BIT_1
#define SMT_CMD_CFG_SMT_ADDR0_EN   BIT_0

//DSI Smart Panel Control 0 Register
#define SMT_CTRL_0_CFG_DCS_LONGWR_CODE_MSK  SHIFT16(0x2f)
#define SMT_CTRL_0_CFG_DCS_LONGWR_CODE_BASE  16
#define SMT_CTRL_0_CFG_DCS_WR_CON_CODE_MSK  SHIFT8(0xff)
#define SMT_CTRL_0_CFG_DCS_WR_CON_CODE_BASE  8
#define SMT_CTRL_0_CFG_DCS_WR_STR_CODE_MSK  SHIFT0(0xff)
#define SMT_CTRL_0_CFG_DCS_WR_STR_CODE_BASE  0

//DSI Smart Panel Control 1 Register
#define SMT_CTRL_1_CFG_SMT_PKT_CNT_MSK  SHIFT16(0x2ff)
#define SMT_CTRL_1_CFG_SMT_PKT_CNT_BASE   16
#define SMT_CTRL_1_CFG_SMT_FIFO_FULL_LEVEL_MSK  SHIFT0(0x2ff)
#define SMT_CTRL_1_CFG_SMT_FIFO_FULL_LEVEL_BASE   0

//DSI RX Packet 0 Status Register
#define RX_PKT_ST_0_RX_PKT0_CRC_ERR     BIT_0
#define RX_PKT_ST_0_RX_PKT0_ECC_ERR     BIT_1
#define RX_PKT_ST_0_RX_PKT0_ST_ERR     BIT_2
#define RX_PKT_ST_0_RX_PKT0_UNKNOWN_ERR     BIT_3
#define RX_PKT_ST_0_RX_PKT0_NO_CRC     BIT_4
#define RX_PKT_ST_0_RX_PKT0_ST_SP     BIT_24
#define RX_PKT_ST_0_RX_PKT0_ST_ACK     BIT_25
#define RX_PKT_ST_0_RX_PKT0_ST_EOTP     BIT_26
#define RX_PKT_ST_0_RX_PKT0_ST_VLD     BIT_31
#define RX_PKT_ST_0_RX_PKT0_VCH_MSK    SHIFT14(0x3)    
#define RX_PKT_ST_0_RX_PKT0_VCH_BASE    14
#define RX_PKT_ST_0_RX_PKT0_ECC_FLAGS_MSK    SHIFT8(0xf)    
#define RX_PKT_ST_0_RX_PKT0_ECC_FLAGS_BASE    8
#define RX_PKT_ST_0_RX_PKT0_PKT_PTR_MSK    SHIFT16(0x2f)    
#define RX_PKT_ST_0_RX_PKT0_PKT_PTR_BASE    16


//DSI RX Packet 1 Status Register
#define RX_PKT_ST_1_RX_PKT1_CRC_ERR     BIT_0
#define RX_PKT_ST_1_RX_PKT1_ECC_ERR     BIT_1
#define RX_PKT_ST_1_RX_PKT1_ST_ERR     BIT_2
#define RX_PKT_ST_1_RX_PKT1_UNKNOWN_ERR     BIT_3
#define RX_PKT_ST_1_RX_PKT1_NO_CRC     BIT_4
#define RX_PKT_ST_1_RX_PKT1_ST_SP     BIT_24
#define RX_PKT_ST_1_RX_PKT1_ST_ACK     BIT_25
#define RX_PKT_ST_1_RX_PKT1_ST_EOTP     BIT_26
#define RX_PKT_ST_1_RX_PKT1_ST_VLD     BIT_31
#define RX_PKT_ST_1_RX_PKT1_VCH_MSK    SHIFT14(0x3)    
#define RX_PKT_ST_1_RX_PKT1_VCH_BASE    14
#define RX_PKT_ST_1_RX_PKT1_ECC_FLAGS_MSK    SHIFT8(0xf)    
#define RX_PKT_ST_1_RX_PKT1_ECC_FLAGS_BASE    8
#define RX_PKT_ST_1_RX_PKT1_PKT_PTR_MSK    SHIFT16(0x2f)    
#define RX_PKT_ST_1_RX_PKT1_PKT_PTR_BASE    16


//DSI RX Packet Read Control Register
#define RX_PKT_CTRL_RX_PKT_RD_REQ    BIT_31
#define RX_PKT_CTRL_RX_PKT_RD_PTR_MSK  SHIFT16(0x2f)
#define RX_PKT_CTRL_RX_PKT_RD_PTR_BASE  16
#define RX_PKT_CTRL_RX_PKT_RD_DATAMSK  SHIFT0(0xff)
#define RX_PKT_CTRL_RX_PKT_RD_DATA_BASE  0


//DSI RX Packet Read Control 1 Register
#define RX_PKT_CTRL_1_RX_PKT_CNT_MSK   SHIFT8(0xf)
#define RX_PKT_CTRL_1_RX_PKT_CNT_BASE    8
#define RX_PKT_CTRL_1_RX_PKT_BCNT_MSK   SHIFT0(0xff)
#define RX_PKT_CTRL_1_RX_PKT_BCNT_BASE    0

//DSI RX Packet 2 Status Register
#define RX_PKT_ST_2_RX_PKT2_CRC_ERR     BIT_0
#define RX_PKT_ST_2_RX_PKT2_ECC_ERR     BIT_1
#define RX_PKT_ST_2_RX_PKT2_ST_ERR     BIT_2
#define RX_PKT_ST_2_RX_PKT2_UNKNOWN_ERR     BIT_3
#define RX_PKT_ST_2_RX_PKT2_NO_CRC     BIT_4
#define RX_PKT_ST_2_RX_PKT2_ST_SP     BIT_24
#define RX_PKT_ST_2_RX_PKT2_ST_ACK     BIT_25
#define RX_PKT_ST_2_RX_PKT2_ST_EOTP     BIT_26
#define RX_PKT_ST_2_RX_PKT2_ST_VLD     BIT_31
#define RX_PKT_ST_2_RX_PKT2_VCH_MSK    SHIFT14(0x3)    
#define RX_PKT_ST_2_RX_PKT2_VCH_BASE    14
#define RX_PKT_ST_2_RX_PKT2_ECC_FLAGS_MSK    SHIFT8(0xf)    
#define RX_PKT_ST_2_RX_PKT2_ECC_FLAGS_BASE    8
#define RX_PKT_ST_2_RX_PKT2_PKT_PTR_MSK    SHIFT16(0x2f)    
#define RX_PKT_ST_2_RX_PKT2_PKT_PTR_BASE    16

//DPHY Control Register 0
#define PHY_CTRL_0_CFG_RX_TRG_REG_DIS   BIT_31
#define PHY_CTRL_0_CFG_TX_LANE_0   BIT_30
#define PHY_CTRL_0_CFG_L2_TIMING_CHECK   BIT_29
#define PHY_CTRL_0_CFG_L1_TIMING_CHECK   BIT_28
#define PHY_CTRL_0_CFG_FCLK_NOT   BIT_27
#define PHY_CTRL_0_CFG_STOP_ST_CNT_MSK     SHIFT16(0xff)
#define PHY_CTRL_0_CFG_STOP_ST_CNT_BASE      16
#define PHY_CTRL_0_CFG_RX_DLY_CNT_MSK     SHIFT8(0xff)
#define PHY_CTRL_0_CFG_RX_DLY_CNT_BASE      8
#define PHY_CTRL_0_CFG_PHY_FULL_LEVEL_MSK     SHIFT0(0xff)
#define PHY_CTRL_0_CFG_PHY_FULL_LEVEL_BASE      0

//DPHY Control Register 1
#define PHY_CTRL_1_CFG_ULPS_REQ_BYTE    BIT_2
#define PHY_CTRL_1_CFG_TX_ULPS_CLK_ESC    BIT_1
#define PHY_CTRL_1_CFG_CONT_CLK_HS    BIT_0

//DPHY Control Register 2
#define PHY_CTRL_2_CFG_CSR_LANE_RESC_EN_MSK   SHIFT8(0xf)
#define PHY_CTRL_2_CFG_CSR_LANE_RESC_EN_BASE     8
#define PHY_CTRL_2_CFG_CSR_LANE_EN_MSK   SHIFT4(0xf)
#define PHY_CTRL_2_CFG_CSR_LANE_EN_BASE     4
#define PHY_CTRL_2_CFG_CSR_LANE_TURN_MSK   SHIFT0(0xf)
#define PHY_CTRL_2_CFG_CSR_LANE_TURN_BASE     0

//DPHY Control Register 3
#define PHY_CTRL_3_CFG_FORCECLK_HIZ_HS  BIT_9
#define PHY_CTRL_3_CFG_FORCECLK_HIZ_LP  BIT_8
#define PHY_CTRL_3_CFG_FORCE_HIZ_HS_MSK  SHIFT4(0xf)
#define PHY_CTRL_3_CFG_FORCE_HIZ_HS_BASE  4
#define PHY_CTRL_3_CFG_FORCE_HIZ_LP_MSK  SHIFT0(0xf)
#define PHY_CTRL_3_CFG_FORCE_HIZ_LP_BASE  0

//DPHY Status Register 0
#define PHY_STATUS_0_DPHY_LANE_RX_LINE_ERR_MSK    SHIFT16(0xf)
#define PHY_STATUS_0_DPHY_LANE_RX_LINE_ERR_BASE   16
#define PHY_STATUS_0_DPHY_ERR_SYNC_ESC_MSK    SHIFT12(0xf)
#define PHY_STATUS_0_DPHY_ERR_SYNC_ESC_BASE   12
#define PHY_STATUS_0_DPHY_ERR_ESC_MSK    SHIFT9(0x7)
#define PHY_STATUS_0_DPHY_ERR_ESC_BASE   9
#define PHY_STATUS_0_DPHY_ERR_CONT_LP0_MSK    SHIFT4(0xf)
#define PHY_STATUS_0_DPHY_ERR_CONT_LP0_BASE   4
#define PHY_STATUS_0_DPHY_ERR_CONT_LP1_MSK    SHIFT0(0xf)
#define PHY_STATUS_0_DPHY_ERR_CONT_LP1_BASE   0


//DPHY Status Register 1
#define PHY_STATUS_1_DPHY_ULP_STATE_BYTE    BIT_31
#define PHY_STATUS_1_DPHY_STOP_STATE_BYTE    BIT_30
#define PHY_STATUS_1_DPHY_CLK_ULPS_ACTIVE_N    BIT_29
#define PHY_STATUS_1_DPHY_RX_CLK_ULPS_N    BIT_28
#define PHY_STATUS_1_DPHY_LANE_DIR_MSK    SHIFT24(0xf)
#define PHY_STATUS_1_DPHY_LANE_DIR_BASE     24
#define PHY_STATUS_1_DPHY_ULPS_ACTIVE_N_MSK   SHIFT20(0xf)
#define PHY_STATUS_1_DPHY_ULPS_ACTIVE_N_BASE     20
#define PHY_STATUS_1_DPHY_LANE_RX_LINE_ERR_MSK    SHIFT16(0xf)
#define PHY_STATUS_1_DPHY_LANE_RX_LINE_ERR_BASE     16
#define PHY_STATUS_1_DPHY_ERR_ESC_MSK    SHIFT12(0xf)
#define PHY_STATUS_1_DPHY_ERR_ESC_BASE     12
#define PHY_STATUS_1_DPHY_ERR_SYNC_ESC_MSK    SHIFT8(0xf)
#define PHY_STATUS_1_DPHY_ERR_SYNC_ESC_BASE     8
#define PHY_STATUS_1_DPHY_ERR_CONT_LP0_MSK    SHIFT4(0xf)
#define PHY_STATUS_1_DPHY_ERR_CONT_LP0_BASE     4
#define PHY_STATUS_1_DPHY_ERR_CONT_LP1_MSK    SHIFT0(0xf)
#define PHY_STATUS_1_DPHY_ERR_CONT_LP1_BASE     0

//DPHY LP RX Register 0
#define PHY_LPRX_0_DPHY_LANE_RX_TRG3_MSK   SHIFT28(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_TRG3_BASE     28
#define PHY_LPRX_0_DPHY_LANE_RX_TRG2_MSK   SHIFT24(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_TRG2_BASE     24
#define PHY_LPRX_0_DPHY_LANE_RX_TRG1_MSK   SHIFT20(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_TRG1_BASE     20
#define PHY_LPRX_0_DPHY_LANE_RX_TRG0_MSK   SHIFT16(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_TRG0_BASE     16
#define PHY_LPRX_0_DPHY_LANE_RX_ULPS_MSK   SHIFT12(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_ULPS_BASE     12
#define PHY_LPRX_0_DPHY_LANE_RX_LPDT_MSK   SHIFT8(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_LPDT_BASE     8
#define PHY_LPRX_0_DPHY_LANE_RX_DVALID_MSK   SHIFT4(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_DVALID_BASE     4
#define PHY_LPRX_0_DPHY_LANE_RX_CLK_MSK   SHIFT0(0xf)
#define PHY_LPRX_0_DPHY_LANE_RX_CLK_BASE     0


//DPHY LP TX Register 0
#define PHY_LPTX_0_DPHY_LANE_RDY_ESC_MSK  SHIFT0(0xf)
#define PHY_LPTX_0_DPHY_LANE_RDY_ESC_BASE     0
#define PHY_LPTX_0_DPHY_TX_REQ_ESC_MSK  SHIFT4(0xf)
#define PHY_LPTX_0_DPHY_TX_REQ_ESC_BASE     4
#define PHY_LPTX_0_DPHY_TX_VALID_ESC_MSK  SHIFT8(0xf)
#define PHY_LPTX_0_DPHY_TX_VALID_ESC_BASE     8
#define PHY_LPTX_0_DPHY_TX_LPDT_ESC_MSK  SHIFT12(0xf)
#define PHY_LPTX_0_DPHY_TX_LPDT_ESC_BASE     12
#define PHY_LPTX_0_DPHY_TX_ULPS_ESC_MSK  SHIFT4(0xf)
#define PHY_LPTX_0_DPHY_TX_ULPS_ESC_BASE     4
#define PHY_LPTX_0_DPHY_TX_TRIGGER_ESC_L_MSK  SHIFT20(0xfff)
#define PHY_LPTX_0_DPHY_TX_TRIGGER_ESC_L_BASE     20


//DPHY Rcomp Control Register 0
#define PHY_rcomp_0_mipi_rcomp_valid  BIT_23
#define PHY_rcomp_0_mipi_rcomp_clk_sel  BIT_10
#define PHY_rcomp_0_mipi_bg_vref_en  BIT_9
#define PHY_rcomp_0_mipi_rcomp_load  BIT_8
#define PHY_rcomp_0_mipi_ren_MSK      SHIFT24(0xff)
#define PHY_rcomp_0_mipi_ren_BASE      24
#define PHY_rcomp_0_mipi_ren_bypass_MSK      SHIFT0(0xff)
#define PHY_rcomp_0_mipi_ren_bypass_BASE      0


//DPHY Timing Control Register 0
#define PHY_TIME_0_CFG_CSR_TIME_HS_EXIT_MSK      SHIFT24(0xff)
#define PHY_TIME_0_CFG_CSR_TIME_HS_EXIT_BASE       24
#define PHY_TIME_0_CFG_CSR_TIME_HS_TRAIL_MSK      SHIFT16(0xff)
#define PHY_TIME_0_CFG_CSR_TIME_HS_TRAIL_BASE       16
#define PHY_TIME_0_CDG_CSR_TIME_ZERO_MSK      SHIFT8(0xff)
#define PHY_TIME_0_CDG_CSR_TIME_ZERO_BASE       8
#define PHY_TIME_0_CFG_CSR_TIME_HS_PREP_MSK      SHIFT0(0xff)
#define PHY_TIME_0_CFG_CSR_TIME_HS_PREP_BASE       0

//DPHY Timing Control Register 1
#define PHY_TIME_1_CFG_CSR_TIME_TA_GET_MSK          SHIFT24(0xff)
#define PHY_TIME_1_CFG_CSR_TIME_TA_GET_BASE           24
#define PHY_TIME_1_CFG_CSR_TIME_TA_GO_MSK          SHIFT16(0xff)
#define PHY_TIME_1_CFG_CSR_TIME_TA_GO_BASE          16
#define PHY_TIME_1_CFG_CSR_TIME_WAKEUP_MSK          SHIFT0(0xffff)
#define PHY_TIME_1_CFG_CSR_TIME_WAKEUP_BASE           0

//DPHY Timing Control Register 2
#define PHY_TIME_2_CFG_CSR_TIME_CK_EXIT_MSK     SHIFT24(0xff)   
#define PHY_TIME_2_CFG_CSR_TIME_CK_EXIT_BASE       24
#define PHY_TIME_2_CFG_CSR_TIME_CK_TRAIL_MSK     SHIFT16(0xff)   
#define PHY_TIME_2_CFG_CSR_TIME_CK_TRAIL_BASE      16
#define PHY_TIME_2_CDG_CSR_TIME_CK_ZERO_MSK     SHIFT8(0xff)   
#define PHY_TIME_2_CFG_CSR_TIME_CK_ZERO_BASE      8
#define PHY_TIME_2_CFG_CSR_TIME_CK_LPX_MSK     SHIFT0(0xff)   
#define PHY_TIME_2_CFG_CSR_TIME_CK_LPX_BASE       0


//DPHY Timing Control Register 3
#define PHY_TIME_3_CFG_CSR_TIME_LPX_MSK   SHIFT8(0xff)
#define PHY_TIME_3_CFG_CSR_TIME_LPX_BASE   8
#define PHY_TIME_3_CFG_CSR_TIME_REQRDY_MSK   SHIFT0(0xff)
#define PHY_TIME_3_CFG_CSR_TIME_REQRDY_BASE   0



//DPHY Code Control Register 0
#define   PHY_CODE_0_CFG_TRIG3_CODE_MSK  SHIFT24(0xff)   
#define   PHY_CODE_0_CFG_TRIG3_CODE_BASE     24
#define   PHY_CODE_0_CFG_TRIG2_CODE_MSK  SHIFT16(0xff)   
#define    PHY_CODE_0_CFG_TRIG2_CODE_BASE   16
#define  PHY_CODE_0_CFG_TRIG1_CODE_MSK   SHIFT8(0xff)   
#define   PHY_CODE_0_CFG_TRIG1_CODE_BASE    8
#define   PHY_CODE_0_CFG_TRIG0_CODE_MSK   SHIFT0(0xff)   
#define     PHY_CODE_0_CFG_TRIG0_CODE_BASE   0

//DSI Memory Timing Control Register
#define  MEM_CTRL_CFG_PDWN_8x16   BIT_28
#define  MEM_CTRL_CFG_PDWN_64x8   BIT_27
#define  MEM_CTRL_CFG_PDWN_64x33   BIT_26
#define  MEM_CTRL_CFG_PDWN_512x16   BIT_25
#define  MEM_CTRL_CFG_PDWN_1024x24   BIT_24
#define  MEM_CTRL_CFG_WTC_8x16_MSK   SHIFT18(0x3)
#define  MEM_CTRL_CFG_WTC_8x16_BASE    18
#define  MEM_CTRL_CFG_RTC_8x16_MSK   SHIFT16(0x3)
#define  MEM_CTRL_CFG_RTC_8x16_BASE    16
#define  MEM_CTRL_CFG_WTC_64x8_MSK   SHIFT14(0x3)
#define  MEM_CTRL_CFG_WTC_64x8_BASE    14
#define  MEM_CTRL_CFG_RTC_64x8_MSK   SHIFT12(0x3)
#define  MEM_CTRL_CFG_RTC_64x8_BASE    12
#define  MEM_CTRL_CFG_WTC_64x33_MSK   SHIFT10(0x3)
#define  MEM_CTRL_CFG_WTC_64x33_BASE    10
#define  MEM_CTRL_CFG_RTC_64x33_MSK   SHIFT8(0x3)
#define  MEM_CTRL_CFG_RTC_64x33_BASE    8
#define  MEM_CTRL_CFG_WTC_512x16_MSK   SHIFT6(0x3)
#define  MEM_CTRL_CFG_WTC_512x16_BASE    6
#define  MEM_CTRL_CFG_RTC_512x16_MSK   SHIFT4(0x3)
#define  MEM_CTRL_CFG_RTC_512x16_BASE    4
#define  MEM_CTRL_CFG_WTC_1024x24_MSK   SHIFT2(0x3)
#define  MEM_CTRL_CFG_WTC_1024x24_BASE    2
#define  MEM_CTRL_CFG_RTC_1024x24_MSK   SHIFT0(0x3)
#define  MEM_CTRL_CFG_RTC_1024x24_BASE    0

//DSI Active Panel 1 Control Register 0
#define  LCD1_CTRL_0_CFG_L1_TX_DLY_CNT_MSK   SHIFT0(0xff)
#define  LCD1_CTRL_0_CFG_L1_TX_DLY_CNT_BASE    0
#define  LCD1_CTRL_0_CFG_L1_PXL_DLY_CNT_MSK   SHIFT8(0xff)
#define  LCD1_CTRL_0_CFG_L1_PXL_DLY_CNT_BASE    8
#define  LCD1_CTRL_0_CFG_L1_DLY_CNT_MSK   SHIFT16(0xffff)
#define  LCD1_CTRL_0_CFG_L1_DLY_CNT_BASE    16

//DSI Active Panel 1 Control Register 1
#define  LCD1_CTRL_1_CFG_L1_VSYNC_RST_EN    BIT_31
#define  LCD1_CTRL_1_CFG_L1_M2K_EN          BIT_30
#define  LCD1_CTRL_1_CFG_L1_HLP_PKT_EN    BIT_22
#define  LCD1_CTRL_1_CFG_L1_HEX_PKT_EN    BIT_21
#define  LCD1_CTRL_1_CFG_L1_HFP_PKT_EN    BIT_20
#define  LCD1_CTRL_1_CFG_L1_HACT_PKT_EN    BIT_19
#define  LCD1_CTRL_1_CFG_L1_HBP_PKT_EN    BIT_18
#define  LCD1_CTRL_1_CFG_L1_HSE_PKT_EN    BIT_17
#define  LCD1_CTRL_1_CFG_L1_HSA_PKT_EN    BIT_16
#define  LCD1_CTRL_1_CFG_L1_ALL_SLOT_EN    BIT_15
#define  LCD1_CTRL_1_CFG_L1_HEX_SLOT_EN    BIT_14
#define  LCD1_CTRL_1_CFG_L1_LAST_LINE_TURN    BIT_10
#define  LCD1_CTRL_1_CFG_L1_LPM_FRAME_EN    BIT_9
#define  LCD1_CTRL_1_CFG_L1_LPM_LINE_EN    BIT_8
#define  LCD1_CTRL_1_CFG_L1_BURST_MODE_MSK  SHIFT2(0x3)
#define  LCD1_CTRL_1_CFG_L1_BURST_MODE_BASE   2
#define  LCD1_CTRL_1_CFG_L1_RGB_TYPE_MSK  SHIFT0(0x3)
#define  LCD1_CTRL_1_CFG_L1_RGB_TYPE_BASE   0


//DSI LCD1 Status Register 0
#define  LCD1_STATUS_0_CFG_LCD1_RD_ERR   BIT_31
#define  LCD1_STATUS_0_CFG_LCD1_LINE_MIS   BIT_30
#define  LCD1_STATUS_0_CFG_LCD1_RD_2EARLY   BIT_29
#define  LCD1_STATUS_0_CFG_LCD1_RD_UNDERRUN   BIT_28
#define  LCD1_STATUS_0_CFG_LCD1_BF_FULL   BIT_27
#define  LCD1_STATUS_0_CFG_LCD1_RD_DELAY_ERR   BIT_26
#define  LCD1_STATUS_0_CFG_LCD1_STATUS_0_MSK   SHIFT0(0x1fffff)
#define  LCD1_STATUS_0_CFG_LCD1_STATUS_0_BASE    0

//DSI Active Panel 2 Control Register 0
#define  LCD2_CTRL_0_CFG_L2_DLY_CNT_MSK  SHIFT16(0xffff)
#define  LCD2_CTRL_0_CFG_L2_DLY_CNT_BASE    16
#define  LCD2_CTRL_0_CFG_L2_PXL_DLY_CNT_MSK  SHIFT8(0xff)
#define  LCD2_CTRL_0_CFG_L2_PXL_DLY_CNT_BASE    8
#define  LCD2_CTRL_0_CFG_L2_TX_DLY_CNT_MSK  SHIFT0(0xff)
#define  LCD2_CTRL_0_CFG_L2_TX_DLY_CNT_BASE    0

//DSI Active Panel 2 Control Register 1
#define  LCD2_CTRL_1_CFG_L2_VSYNC_RST_EN    BIT_31
#define  LCD2_CTRL_1_CFG_L2_M2K_EN          BIT_30
#define  LCD2_CTRL_1_CFG_L2_HLP_PKT_EN    BIT_22
#define  LCD2_CTRL_1_CFG_L2_HEX_PKT_EN    BIT_21
#define  LCD2_CTRL_1_CFG_L2_HFP_PKT_EN    BIT_20
#define  LCD2_CTRL_1_CFG_L2_HACT_PKT_EN    BIT_19
#define  LCD2_CTRL_1_CFG_L2_HBP_PKT_EN    BIT_18
#define  LCD2_CTRL_1_CFG_L2_HSE_PKT_EN    BIT_17
#define  LCD2_CTRL_1_CFG_L2_HSA_PKT_EN    BIT_16
#define  LCD2_CTRL_1_CFG_L2_ALL_SLOT_EN    BIT_15
#define  LCD2_CTRL_1_CFG_L2_HEX_SLOT_EN    BIT_14
#define  LCD2_CTRL_1_CFG_L2_LAST_LINE_TURN    BIT_10
#define  LCD2_CTRL_1_CFG_L2_LPM_FRAME_EN    BIT_9
#define  LCD2_CTRL_1_CFG_L2_LPM_LINE_EN    BIT_8
#define  LCD2_CTRL_1_CFG_L2_BURST_MODE_MSK  SHIFT2(0x3)
#define  LCD2_CTRL_1_CFG_L2_BURST_MODE_BASE   2
#define  LCD2_CTRL_1_CFG_L2_RGB_TYPE_MSK  SHIFT0(0x3)
#define  LCD2_CTRL_1_CFG_L2_RGB_TYPE_BASE   0

//DSI LCD 2 Status Register 0
#define  LCD2_STATUS_0_CFG_LCD2_RD_ERR  BIT_31
#define  LCD2_STATUS_0_CFG_LCD2_LINE_MISS  BIT_30
#define  LCD2_STATUS_0_CFG_LCD2_RD_2EARLY  BIT_29
#define  LCD2_STATUS_0_CFG_LCD2_RD_UNDERRUN  BIT_28
#define  LCD2_STATUS_0_CFG_LCD2_BF_FULL  BIT_27
#define  LCD2_STATUS_0_CFG_LCD2_RD_DELAY_ERR  BIT_26
#define  LCD2_STATUS_0_CFG_LCD2_STATUS_0_MSK  SHIFT0(0x1fffff)
#define  LCD2_STATUS_0_CFG_LCD2_STATUS_0_BASE    0

//DSI top level Status Register
#define  TOP_STATUS_2_CFG_TX_REQ_CNT_R_MSK  SHIFT8(0xff)
#define  TOP_STATUS_2_CFG_TX_REQ_CNT_R_BASE   8
#define  TOP_STATUS_2_CFG_TX_REQ_CNT_MSK  SHIFT0(0xff)
#define  TOP_STATUS_2_CFG_TX_REQ_CNT_BASE   0

#endif
