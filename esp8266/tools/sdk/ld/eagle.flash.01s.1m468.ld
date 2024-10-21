/* Flash Split for 1M chips */
/* sketch @0x40200000 (500KB) (512000B) */
/* empty  @0x4027D000 (32KB) (32768B) */
/* spiffs @0x40285000 (468KB) (479232B) */
/* eeprom @0x402FA000 (2x4KB) */
/* rfcal  @0x402FC000 (4KB) */
/* wifi   @0x402FD000 (12KB) */

MEMORY
{
  dport0_0_seg :                        org = 0x3FF00000, len = 0x10
  dram0_0_seg :                         org = 0x3FFE8000, len = 0x14000
  irom0_0_seg :                         org = 0x40201010, len = 0x7bff0
}

PROVIDE ( _FS_start = 0x40285000);
PROVIDE ( _FS_end = 0x402FA000 );
PROVIDE ( _FS_page = 0x100 );
PROVIDE ( _FS_block = 0x1000 );
PROVIDE ( _EEPROM_start = 0x402fb000 );
/* The following symbols are DEPRECATED and will be REMOVED in a future release */
PROVIDE ( _SPIFFS_start = 0x40285000 );
PROVIDE ( _SPIFFS_end = 0x402FA000 );
PROVIDE ( _SPIFFS_page = 0x100 );
PROVIDE ( _SPIFFS_block = 0x1000 );

INCLUDE "local.eagle.app.v6.common.ld"
