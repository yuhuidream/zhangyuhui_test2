/*
 * arch/marvell/trace/fault.c
*
 * This file contain functions to output detailed aborts source to help debug when 
 * exception(Data/Prefetch abort) happen.
*
 * VMSA memory aborts:
 * 	Debug exception: An exception caused by the debug configuration.
 * 	Alignment fault: 
 *			An Alignment fault is generated if the address used for a memory 
 *			access does not have the required alignment for the operation.
 * 	MMU fault: 
 *			An MMU fault is a fault generated by the fault checking sequence for the 
 *			current translation regime.
 * 	External abort: 
 *			Any memory system fault other than a Debug exception, an Alignment 
 *			fault, or an MMU fault.
*
 * MMU fault:
 * 	External abort on a translation table walk.
 * 	Translation fault.
 * 	Access flag fault.
 * 	Domain fault, Short-descriptor format translation tables only.
 * 	Permission fault.
*
 * VMSAv7 permits external aborts on data accesses, translation table walks, and instruction 
 * fetches to be either synchronous or asynchronous.
 *  
*/
#include "predefines.h"
#include "bbu.h"
#include "ptrace.h"
#include "fault.h"

#define FSR_LNX_PF		(1 << 31)
#define FSR_FS4			(1 << 10)
#define FSR_FS3_0		(15)

/* Combine fault status bits bits[10,3:0] */
static inline uint8_t fsr_fs(uint32_t fsr)
{
	return (fsr & FSR_FS3_0) | (fsr & FSR_FS4) >> 6;
}

/*
 * This abort handler always returns "fault".
 */
static uint8_t do_nothing_abort(uint32_t addr, uint32_t fsr, struct pt_regs *regs)
{
	(void)addr;  /* avoid warning */
	(void)fsr;
	(void)regs;
	return 1;
}

/*
 * This variable save information about data abort. member "fn" of struct fsr_info is
 * reserved for future use because fo some aborts can resume.
*/
static const struct fsr_info dfsr_info[] = {
	{ do_nothing_abort, "Unknown 0"		   		},
	{ do_nothing_abort, "Alignment fault"		   },
	{ do_nothing_abort, "Unknown 2"		   		},
	{ do_nothing_abort, "Acess flag fault"		   },
	{ do_nothing_abort, "Fault on instruction cache maintenance"	},
	{ do_nothing_abort, "Translation fault"	   },
	{ do_nothing_abort, "Access flag fault"	   },
	{ do_nothing_abort, "Translation fault"	   },
	{ do_nothing_abort, "Synchronous external abort" 	},
	{ do_nothing_abort, "Domain fault"		   	},
	{ do_nothing_abort, "Unknown 10"  				},
	{ do_nothing_abort, "Domain fault"		   	},
	{ do_nothing_abort, "Synchronous external abort on translation table walk"	},
	{ do_nothing_abort, "Permission fault"	   	},
	{ do_nothing_abort, "Synchronous external abort on translation table walk"	},
	{ do_nothing_abort, "Permission fault"		   },
	{ do_nothing_abort, "TLB conflict abort"	 	},
	{ do_nothing_abort, "Unknown 17"			   	},
	{ do_nothing_abort, "Unknown 18"			   	},
	{ do_nothing_abort, "Unknown 19"			   	},
	{ do_nothing_abort, "Unknown 20"			   	}, 
	{ do_nothing_abort, "Unknown 21"			   	},
	{ do_nothing_abort, "Asynchronous external abort"	}, 
	{ do_nothing_abort, "Unknown 23"			   	},
	{ do_nothing_abort, "Asynchronous parity error on memory access"	}, 
	{ do_nothing_abort, "Synchronous parity error on memory access"	},
	{ do_nothing_abort, "Unknown 26"			   	},
	{ do_nothing_abort, "Unknown 27"			   	},
	{ do_nothing_abort, "Synchronous parity error on translation table walk"	},
	{ do_nothing_abort, "Unknown 29"			   	},
	{ do_nothing_abort, "Synchronous parity error on translation table walk"	},
	{ do_nothing_abort, "Unknown 31"			   	}
};


/*
 * Dispatch a data abort to the relevant handler.
 */
void do_DataAbort(uint32_t addr, uint32_t fsr, struct pt_regs *regs)
{
	uint8_t fs = fsr_fs(fsr);
	const struct fsr_info *inf = dfsr_info + fs;

	if (!inf->fn(addr, fsr & ~FSR_LNX_PF, regs))
		return;
	if(fs == 22 || fs == 24)  /* FAR register is unknown when fault is asynchronous */
		bbu_printf("\r\nFault Source: %s (DFSR: 0x%03x)\r\n",inf->name, fsr);
	else	
		bbu_printf("\r\nFault Source: %s (DFSR: 0x%03x) at 0x%08lx\n",inf->name, fsr, addr);

}

/*
 * This variable save information about prefetch abort. member "fn" of struct fsr_info is
 * reserved for future use because fo some aborts can resume.
*/
static const struct fsr_info ifsr_info[] = {
	{ do_nothing_abort, "Unknown 0"		   		},
	{ do_nothing_abort, "Unknown 1"		   		},
	{ do_nothing_abort, "Unknown 2"		   		},
	{ do_nothing_abort, "Acess flag fault"		   },
	{ do_nothing_abort, "Unknown 4"	   			},
	{ do_nothing_abort, "Translation fault"	   },
	{ do_nothing_abort, "Access flag fault"	   },
	{ do_nothing_abort, "Translation fault"	   },
	{ do_nothing_abort, "Synchronous external abort"  },
	{ do_nothing_abort, "Domain fault"		   	},
	{ do_nothing_abort, "Unknown 10"  				},
	{ do_nothing_abort, "Domain fault"		   	},
	{ do_nothing_abort, "Synchronous external abort on translation table walk"	   },
	{ do_nothing_abort, "Permission fault"	   	},
	{ do_nothing_abort, "Synchronous external abort on translation table walk"	   },
	{ do_nothing_abort, "Permission fault"		   },
	{ do_nothing_abort, "TLB conflict abort"		},
	{ do_nothing_abort, "Unknown 17"			   	},
	{ do_nothing_abort, "Unknown 18"			  	 	},
	{ do_nothing_abort, "Unknown 19"			   	},
	{ do_nothing_abort, "Unknown 20"			   	}, 
	{ do_nothing_abort, "Unknown 21"			   	},
	{ do_nothing_abort, "Unknown 22"	   			}, 
	{ do_nothing_abort, "Unknown 23"			   	},
	{ do_nothing_abort, "Unknown 24"		   		}, 
	{ do_nothing_abort, "Synchronous parity error on memory access"	},
	{ do_nothing_abort, "Unknown 26"			   	},
	{ do_nothing_abort, "Unknown 27"			   	},
	{ do_nothing_abort, "Synchronous parity error on translation table walk"		},
	{ do_nothing_abort, "Unknown 29"			   	},
	{ do_nothing_abort, "Synchronous parity error on translation table walk"		},
	{ do_nothing_abort, "Unknown 31"			   	}
};

/*
 * Dispatch a prefetch abort to the relevant handler.
 */
void do_PrefetchAbort(uint32_t addr, uint32_t fsr, struct pt_regs *regs)
{
	const struct fsr_info *inf = ifsr_info + fsr_fs(fsr);

	if (!inf->fn(addr, fsr & ~FSR_LNX_PF, regs))
		return;

	bbu_printf("\r\nFault Source: %s (IFSR: 0x%03x) at 0x%08lx\n",inf->name, fsr, addr);

}




