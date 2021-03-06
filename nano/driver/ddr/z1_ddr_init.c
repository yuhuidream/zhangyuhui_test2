#include "bbu.h"

#define REG32 BU_REG_READ

#define DDR_FPGA_PHY
//#define NO_FAST_BANK

//#define DDR_1TO1

void init_lpddr2() // lpddr2_400_init
{
 unsigned read_data;
  //unsigned short read_data_16; 
  //int i;

  unsigned DDRC_BASE, MC_CH0_BASE, MC_CH0_PHY_BASE;
  unsigned DPHY0_BASE;
  //unsigned test_num;

  read_data = 0x0;
  DDRC_BASE = 0xc0100000;
  //DDRC_BASE = 0xd4200000;
  MC_CH0_BASE = 0x200;
  MC_CH0_PHY_BASE = 0x1000;
  DPHY0_BASE = DDRC_BASE + 0x40000;


//#ifdef DDR_533
//  enb_pll_ssc(2050, 2, 0x3);
//#else // DDR_312
//  enb_pll_ssc(1248, 2, 0x3);
//#endif
//
//  pmu_ap_fc_internal (0, 0, 1, 0,  // ddr_fc
//		      0, 0, 
//		      0, 0, 
//		      0, 0, 
//		      0, 0, 
//		      4, 0, // sel pll2
//		      0, 0, 0, 0,
//		      0); // before ddr init
//
//  // ???
//  REG32(0xd42828b0) |= 0x80400000;
//
//#ifndef DDR_POP
//  REG32(PMUA_MC_HW_SLP_TYPE) &= 0xFFEFFFFF;
//#endif


  //REG32(MSG_PORT)   = 0xffff1111;
 
 //enable mck6 hclk
  //REG32(0xd42828f4)= 0x400000003;
  REG32(0xd42828f4)= 0x3;
 
#ifdef DDR_BOOT_AT_LOW
  REG32(0xd4282800+0x15c) |= 0x8; 	  //sel div3
  //REG32(0xd4282800+0x15c) |= 0x4; 	  //sel div2
  REG32(0xd4282800+0x0b0) |= 0x02000000 ; //force fc 
#endif
  REG32(0xd4282c00+0x118) = 0x33221133 ; 
 
//enable 4to1 phy mode
#ifdef DDR_1TO1
#else
  REG32(0xd42828b0) |= 0x100;
#endif

  //set phy to lpddr2 mode
  REG32(DPHY0_BASE+0x00c00) =  0x11; 

 // intial lpddr2 here for MCK6+DFI phy (533Mhz)
  //MCK6 module
  REG32(DDRC_BASE+0x0044) = 0x00030a00;	//MC_Control_0
  //REG32(DDRC_BASE+0x0058) = 0x10356284;	
  REG32(DDRC_BASE+0x0058) = 0x10356285;	
  REG32(DDRC_BASE+0x005c) = 0x000494e4;	
  REG32(DDRC_BASE+0x0048) = 0x00000001;	//MC_excu_en
  REG32(DDRC_BASE+0x0180) = 0x00030200;	
  REG32(DDRC_BASE+0x0050) = 0x000003ff;	
  REG32(DDRC_BASE+0x004c) = 0x00000000;	
  REG32(DDRC_BASE+0x0054) = 0x00000480;	
  //REG32(DDRC_BASE+0x0064) = 0x0e0e0e05;	//RDP_Control

  REG32(DDRC_BASE+MC_CH0_BASE+0x000) = 0x000b0001;	//Memory Address Map Register Low  CS0
  REG32(DDRC_BASE+MC_CH0_BASE+0x004) = 0x0;		//Memory Address Map Register high CS0
  //REG32(DDRC_BASE+MC_CH0_BASE+0x008) = 0x000b0001;	//Memory Address Map Register Low  CS1
  //REG32(DDRC_BASE+MC_CH0_BASE+0x00c) = 0x1;		//Memory Address Map Register high CS1

#ifdef NO_FAST_BANK
  REG32(DDRC_BASE+MC_CH0_BASE+0x020) = 0x00000332;	//Configuration Register CS0
  //REG32(DDRC_BASE+MC_CH0_BASE+0x024) = 0x04000332;	//Configuration Register CS1
#else
  REG32(DDRC_BASE+MC_CH0_BASE+0x020) = 0x04000332;	//Configuration Register CS0
  //REG32(DDRC_BASE+MC_CH0_BASE+0x024) = 0x02000332;	//Configuration Register CS1
#endif
  REG32(DDRC_BASE+MC_CH0_BASE+0x0c0) = 0x0000e000;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x0c4) = 0x00000098;	//MC_Control_2

// high for 1066
  REG32(DDRC_BASE+MC_CH0_BASE+0x104) = 0x40800400;	//DRAM Config 2 FSP WR FSP OP FSP=01

  REG32(DDRC_BASE+MC_CH0_BASE+0x100) = 0x00000008;	//DRAM Config 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x10c) = 0x00000050;
  REG32(DDRC_BASE+MC_CH0_BASE+0x110) = 0x00000000;
 //REG32(DDRC_BASE+MC_CH0_BASE+0x114) = 0x00000000;
  
  REG32(DDRC_BASE+MC_CH0_BASE+0x180) = 0x00000200;	//DDR init timing Control 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x184) = 0x00000036;	//DDR init timing Control 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x188) = 0x09600040;	//DDR init timing Control 2
  REG32(DDRC_BASE+MC_CH0_BASE+0x18c) = 0x001b0216;	//ZQC timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x190) = 0x003000c0;	//ZQC timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x194) = 0x004603cf;	//Refresh timing 
  //REG32(DDRC_BASE+MC_CH0_BASE+0x198) = 0x004b004b;	//SelfRefresh timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x198) = 0x01000100;	//SelfRefresh timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x19c) = 0x00200808;	//SelfRefresh timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1a0) = 0x01080404;	//Power down timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x1a4) = 0x00000001;	//Power down timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1a8) = 0x00000205;	//MRS timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1ac) = 0x1b200a17;	//ACT timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1b0) = 0x0c08040a;	//Pre-Charge timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1b4) = 0x02000400;	//CAS/RAS timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x1b8) = 0x00010600;	//CAS/RAS timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1d8) = 0x025a812d;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x1bc) = 0x02020404;	//Off-spec timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x1c0) = 0x00000002;	//Off-spec timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1c4) = 0x00140a03;	//DRAM_read timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1dc) = 0x41081239;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x1e0) = 0x00000605;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x148) = 0x00000000;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x14c) = 0x00000000;	

  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3e4) = 0x05000300;	//MCK6 DFI phy ctrl register 1 (4to1)
  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3ec) = 0x0000047e;	

// high for 1066 end

// low for 533 
  REG32(DDRC_BASE+MC_CH0_BASE+0x104) = 0x00800400;	//DRAM Config 2 FSP WR FSP OP FSP=01

  REG32(DDRC_BASE+MC_CH0_BASE+0x100) = 0x00000003;	//DRAM Config 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x10c) = 0x00000050;
  REG32(DDRC_BASE+MC_CH0_BASE+0x110) = 0x00000000;
 //REG32(DDRC_BASE+MC_CH0_BASE+0x114) = 0x00000000;
  
  #ifdef DDR_BOOT_AT_LOW
  REG32(DDRC_BASE+MC_CH0_BASE+0x180) = 0x000000c0;	//DDR init timing Control 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x184) = 0x00000018;	//DDR init timing Control 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x188) = 0x09600014;	//DDR init timing Control 2
  #endif
  REG32(DDRC_BASE+MC_CH0_BASE+0x18c) = 0x000a00c8;	//ZQC timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x190) = 0x00120048;	//ZQC timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x194) = 0x001a03cf;	//Refresh timing 
  //REG32(DDRC_BASE+MC_CH0_BASE+0x198) = 0x001c001c;	//SelfRefresh timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x198) = 0x00960096;	//SelfRefresh timing 0
  //REG32(DDRC_BASE+MC_CH0_BASE+0x19c) = 0x00000A0A;	//SelfRefresh timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x19c) = 0x00200303;	//SelfRefresh timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1a0) = 0x01030202;	//Power down timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x1a4) = 0x00000001;	//Power down timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1a8) = 0x00000205;	//MRS timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1ac) = 0x0a0c0409;	//ACT timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1b0) = 0x05030204;	//Pre-Charge timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1b4) = 0x02000300;	//CAS/RAS timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x1b8) = 0x00010200;	//CAS/RAS timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1d8) = 0x025a812d;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x1bc) = 0x02020404;	//Off-spec timing 0
  REG32(DDRC_BASE+MC_CH0_BASE+0x1c0) = 0x00000002;	//Off-spec timing 1
  REG32(DDRC_BASE+MC_CH0_BASE+0x1c4) = 0x00140a01;	//DRAM_read timing
  REG32(DDRC_BASE+MC_CH0_BASE+0x1dc) = 0x41081239;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x1e0) = 0x00000605;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x148) = 0x00000000;	
  REG32(DDRC_BASE+MC_CH0_BASE+0x14c) = 0x00000000;	

  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3e4) = 0x02000000;	//MCK6 DFI phy ctrl register 1 (4to1)
  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3ec) = 0x0000047e;	
// low for 533 end

  #ifdef DDR_BOOT_AT_LOW
      REG32(DDRC_BASE+MC_CH0_BASE+0x0104) = 0x00800400;	//CH0_DRAM_Config_2
  #else // 1066
      REG32(DDRC_BASE+MC_CH0_BASE+0x0104) = 0x50800400;	//CH0_DRAM_Config_2
  #endif 
  
 // set dfi_frequency for as same as fsp op
  read_data = REG32(DDRC_BASE+MC_CH0_BASE+0x0104);//CH0_DRAM_Config_2
  read_data = (read_data >> 28);
  read_data &= 3;
  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3e0) &= ~(0x1f<<2);
  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3e0) |= (read_data<<2);

  //REG32(DDRC_BASE+0x0064) = 0x00000906;	//RDP_Control
  REG32(DDRC_BASE+0x0064) = 0x0a030501;	//RDP_Control
 
  //init ddrc and ddrphy
  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3d0) = 0x11000001;	//MCK6 DFI phy user cmd

  read_data = REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3fc);
  while((read_data & 0x80000000) != 0x80000000) {
  	read_data = REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3fc);
  }

  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3d0) = 0x11000100;	//MCK6 DFI phy user cmd
  REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3d0) = 0x00000000;	//MCK6 DFI phy user cmd
  
  //start init
  REG32(DDRC_BASE+0x0020) = 0x11000001;

  read_data = REG32(DDRC_BASE+0x0008);
  while((read_data & 0x00000001) != 0x1) {
  	read_data = REG32(DDRC_BASE+0x0008);
  }

  REG32(DDRC_BASE+0x0024) = 0x13020002;
  REG32(DDRC_BASE+0x0024) = 0x13020001;
  REG32(DDRC_BASE+0x0020) = 0x11002000;
  REG32(DDRC_BASE+0x0020) = 0x11001000;
 
/*
  REG32(DPHY0_BASE+0x00c14) =  0x21f83;
  REG32(DPHY0_BASE+0x01c14) =  0x21f83;
  REG32(DPHY0_BASE+0x00064) =  0xf90;
  REG32(DPHY0_BASE+0x01064) =  0xf90; //p1
  REG32(DPHY0_BASE+0x00070) =  0x5;
  REG32(DPHY0_BASE+0x00470) =  0x5;
*/
	REG32(DPHY0_BASE+0x10024) |= 0x33;

#ifdef DDR_FPGA_PHY
  //#ifdef DDR_1TO1
  REG32(DPHY0_BASE+0x0068)= 0x0089;
  REG32(DPHY0_BASE+0x1068)= 0x0089;
 // REG32(DPHY0_BASE+0x2068)= 0x008b;
 // REG32(DPHY0_BASE+0x3068)= 0x008b;
 //#else
  REG32(DPHY0_BASE+0x0064)= 0x0087;
  REG32(DPHY0_BASE+0x1064)= 0x0087;
 // REG32(DPHY0_BASE+0x2064)= 0x008b;
 // REG32(DPHY0_BASE+0x3064)= 0x008b;
 //#endif
#else
   // add read gate training
   REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3d0) =(0x1<<28)|(0x1<<24)|(0x1<<20);//MCK6 DFI phy user cmd
   read_data = REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3fc);
   while((read_data & 0x00000006) != 0x00000006) {
   	read_data = REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3fc);
   }
   REG32(DPHY0_BASE+0x10000) |= 0x10; //enable FP1
   REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3d0) =(0x1<<28)|(0x1<<24)|(0x1<<20);//MCK6 DFI phy user cmd
   read_data = REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3fc);
   while((read_data & 0x000800006) != 0x00000006) {
       read_data = REG32(DDRC_BASE+MC_CH0_PHY_BASE+0x3fc);
   }
#endif  
  REG32(DPHY0_BASE+0x10000) |= 0x1; //enable ffc
/*
  REG32(DPHY0_BASE+0x002c0) =  0x6000;
  REG32(DPHY0_BASE+0x00c10) =  0x1d4028;
  REG32(DPHY0_BASE+0x01c10) =  0x1d4028;
  REG32(DPHY0_BASE+0x02c10) =  0x1d4028;
  REG32(DPHY0_BASE+0x03c10) =  0x1d4028;
*/
// fill MC6 tables
// remove all RDG training from table for SOC, by weima
// LJ_DEBUG, program table DFC_LC;
// DFC_TB Halt Scheduler and Set DFC Mode= 1!;
REG32(DDRC_BASE + 0x74) = 0x00030a03;
REG32(DDRC_BASE + 0x78) = 0x00000044;
REG32(DDRC_BASE + 0x70) = 0x00000000;
// Write Reg Tb 0.0: Addr: 44, Data: 30a03, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
// DFC_TB User_CMD_0 in CH0001CS0001, reg=11000008!;
REG32(DDRC_BASE + 0x74) = 0x11000008;
REG32(DDRC_BASE + 0x78) = 0x00000020;
REG32(DDRC_BASE + 0x70) = 0x00000001;
// Write Reg Tb 0.1: Addr: 20, Data: 11000008, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00000004;
REG32(DDRC_BASE + 0x78) = 0x00002008;
REG32(DDRC_BASE + 0x70) = 0x00000002;
// Write Reg Tb 0.2: Addr: 8, Data: 4, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00000004;
REG32(DDRC_BASE + 0x78) = 0x00002008;
REG32(DDRC_BASE + 0x70) = 0x00000003;
// Write Reg Tb 0.3: Addr: 8, Data: 4, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x11000001;
REG32(DDRC_BASE + 0x78) = 0x000013d0;
REG32(DDRC_BASE + 0x70) = 0x00000004;
// Write Reg Tb 0.4: Addr: 13d0, Data: 11000001, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00008000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000005;
// Write Reg Tb 0.5: Addr: 13fc, Data: 8000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00000000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000006;
// Write Reg Tb 0.6: Addr: 13fc, Data: 0, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
// DFC_TB Halt Scheduler and Set DFC Mode= 1!;
REG32(DDRC_BASE + 0x74) = 0x00030a03;
REG32(DDRC_BASE + 0x78) = 0x00010044;
REG32(DDRC_BASE + 0x70) = 0x00000007;
// Write Reg Tb 0.7: Addr: 44, Data: 30a03, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 1, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x10000100;
REG32(DDRC_BASE + 0x78) = 0x000013d0;
REG32(DDRC_BASE + 0x70) = 0x00000008;
// Write Reg Tb 0.8: Addr: 13d0, Data: 10000100, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00008000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000009;
// Write Reg Tb 0.9: Addr: 13fc, Data: 8000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00008000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x0000000a;
// Write Reg Tb 0.10: Addr: 13fc, Data: 8000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
// DFC_TB Halt Scheduler and Set DFC Mode= 0!;
REG32(DDRC_BASE + 0x74) = 0x00030a02;
REG32(DDRC_BASE + 0x78) = 0x00010044;
REG32(DDRC_BASE + 0x70) = 0x0000000b;
// Write Reg Tb 0.11: Addr: 44, Data: 30a02, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 1, EOP: 0, RD=0;
// DFC_TB User_CMD_0 in CH0001CS0001, reg=11000004!;
REG32(DDRC_BASE + 0x74) = 0x11000004;
REG32(DDRC_BASE + 0x78) = 0x00000020;
REG32(DDRC_BASE + 0x70) = 0x0000000c;
// Write Reg Tb 0.12: Addr: 20, Data: 11000004, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
// DFC_TB MRW to Reg1 in CH0001CS0001;
REG32(DDRC_BASE + 0x74) = 0x11020001;
REG32(DDRC_BASE + 0x78) = 0x00000024;
REG32(DDRC_BASE + 0x70) = 0x0000000d;
// Write Reg Tb 0.13: Addr: 24, Data: 11020001, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
// DFC_TB MRW to Reg2 in CH0001CS0001;
REG32(DDRC_BASE + 0x74) = 0x11020002;
REG32(DDRC_BASE + 0x78) = 0x00000024;
REG32(DDRC_BASE + 0x70) = 0x0000000e;
// Write Reg Tb 0.14: Addr: 24, Data: 11020002, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
/*
// CH0 PHY CS1 write table for training RDG;
REG32(DDRC_BASE + 0x74) = 0x11100000;
REG32(DDRC_BASE + 0x78) = 0x000013d0;
REG32(DDRC_BASE + 0x70) = 0x0000000f;
// Write Reg Tb 0.15: Addr: 13d0, Data: 11100000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00000006;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000010;
// Write Reg Tb 0.16: Addr: 13fc, Data: 6, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00000006;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000011;
// Write Reg Tb 0.17: Addr: 13fc, Data: 6, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
*/
// DFC_TB MRR to Reg0 in CH0001CS0001;
REG32(DDRC_BASE + 0x74) = 0x11010000;
REG32(DDRC_BASE + 0x78) = 0x00000024;
REG32(DDRC_BASE + 0x70) = 0x0000000f;
// Write Reg Tb 0.18: Addr: 24, Data: 11010000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
// DFC_TB Resume Scheduler and Clear DFC Mode= 0!;
REG32(DDRC_BASE + 0x74) = 0x00030a00;
REG32(DDRC_BASE + 0x78) = 0x00020044;
REG32(DDRC_BASE + 0x70) = 0x00000010;
// Write Reg Tb 0.19: Addr: 44, Data: 30a00, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 1, RD=0;
//====================================================================================================
// LJ_DEBUG, program table LP;
// DFC_TB Halt Scheduler and Set DFC Mode= 1!;
REG32(DDRC_BASE + 0x74) = 0x00030a03;
REG32(DDRC_BASE + 0x78) = 0x00000044;
REG32(DDRC_BASE + 0x70) = 0x00000060;
// Write Reg Tb 3.0: Addr: 44, Data: 30a03, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00000004;
REG32(DDRC_BASE + 0x78) = 0x00002008;
REG32(DDRC_BASE + 0x70) = 0x00000061;
// Write Reg Tb 3.1: Addr: 8, Data: 4, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00000004;
REG32(DDRC_BASE + 0x78) = 0x00002008;
REG32(DDRC_BASE + 0x70) = 0x00000062;
// Write Reg Tb 3.2: Addr: 8, Data: 4, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x11000001;
REG32(DDRC_BASE + 0x78) = 0x000013d0;
REG32(DDRC_BASE + 0x70) = 0x00000063;
// Write Reg Tb 3.3: Addr: 13d0, Data: 11000001, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00008000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000064;
// Write Reg Tb 3.4: Addr: 13fc, Data: 8000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00000000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000065;
// Write Reg Tb 3.5: Addr: 13fc, Data: 0, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
// DFC_TB Halt Scheduler and Set DFC Mode= 1!;
REG32(DDRC_BASE + 0x74) = 0x00030a03;
REG32(DDRC_BASE + 0x78) = 0x00010044;
REG32(DDRC_BASE + 0x70) = 0x00000066;
// Write Reg Tb 3.6: Addr: 44, Data: 30a03, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 1, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x10000100;
REG32(DDRC_BASE + 0x78) = 0x000013d0;
REG32(DDRC_BASE + 0x70) = 0x00000067;
// Write Reg Tb 3.7: Addr: 13d0, Data: 10000100, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00008000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000068;
// Write Reg Tb 3.8: Addr: 13fc, Data: 8000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00008000;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x00000069;
// Write Reg Tb 3.9: Addr: 13fc, Data: 8000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
// DFC_TB Halt Scheduler and Set DFC Mode= 0!;
REG32(DDRC_BASE + 0x74) = 0x00030a02;
REG32(DDRC_BASE + 0x78) = 0x00010044;
REG32(DDRC_BASE + 0x70) = 0x0000006a;
// Write Reg Tb 3.10: Addr: 44, Data: 30a02, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 1, EOP: 0, RD=0;
/*
// CH0 PHY CS1 write table for training RDG;
REG32(DDRC_BASE + 0x74) = 0x11100000;
REG32(DDRC_BASE + 0x78) = 0x000013d0;
REG32(DDRC_BASE + 0x70) = 0x0000006b;
// Write Reg Tb 3.11: Addr: 13d0, Data: 11100000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
REG32(DDRC_BASE + 0x74) = 0x00000006;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x0000006c;
// Write Reg Tb 3.12: Addr: 13fc, Data: 6, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
REG32(DDRC_BASE + 0x74) = 0x00000006;
REG32(DDRC_BASE + 0x78) = 0x000033fc;
REG32(DDRC_BASE + 0x70) = 0x0000006d;
// Write Reg Tb 3.13: Addr: 13fc, Data: 6, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=1;
*/
// DFC_TB MRR to Reg0 in CH0001CS0001;
REG32(DDRC_BASE + 0x74) = 0x11010000;
REG32(DDRC_BASE + 0x78) = 0x00000024;
REG32(DDRC_BASE + 0x70) = 0x0000006b;
// Write Reg Tb 3.14: Addr: 24, Data: 11010000, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 0, RD=0;
// DFC_TB Resume Scheduler and Clear DFC Mode= 0!;
REG32(DDRC_BASE + 0x74) = 0x00030a00;
REG32(DDRC_BASE + 0x78) = 0x00020044;
REG32(DDRC_BASE + 0x70) = 0x0000006c;
// Write Reg Tb 3.15: Addr: 44, Data: 30a00, REG_WRITE_DISABLE: 0, REQ_PHY: 0, REQ_PMU: 0, EOP: 1, RD=0;
#ifdef DDR_1TO1
bbu_printf("NANO: Z1 LPDDR2 initialized, 1:1 mode\n\r");
#else
bbu_printf("NANO: Z1 LPDDR2 initialized, 2:1 mode\n\r");
#endif
}
