#include "rw_platf_pub.h"
#include "sys_config.h"
#include "reg_mac_core.h"
#include "reg_mac_pl.h"

/*


*/
extern void rwnxl_violence_reset_patch(void);
UINT32 mcu_ps_machw_reset(void);

void rwxl_reset_patch(void)
{
	rwnxl_violence_reset_patch();
    #if CFG_USE_MCU_PS
    mcu_ps_machw_reset();
    #endif
}

void hal_machw_init_diagnostic_ports(void)
{
	// Initialize diagnostic ports
#if (CFG_SOC_NAME == SOC_BK7231)    
    nxmac_debug_port_sel_pack(0x1C, 0x25);
#else
    nxmac_debug_port_sel_pack(0x01, 0x07);

    //bypass buf fix 
    REG_PL_WR(0xc0000700, 0x08);
#endif // (CFG_SOC_NAME == SOC_BK7231)
}

