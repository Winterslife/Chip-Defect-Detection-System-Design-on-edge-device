
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/riscv_fpu.S" "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/examples/A_work/lvgl_wifi/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/riscv_fpu.S.obj"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/start.S" "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/examples/A_work/lvgl_wifi/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start.S.obj"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/vector.S" "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/examples/A_work/lvgl_wifi/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/vector.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "ARCH_RISCV"
  "BFLB_TIMESTAMP_TIMEZONE=8"
  "BFLB_USE_HAL_DRIVER"
  "BFLB_USE_ROM_DRIVER"
  "BL616"
  "BOUFFALO_SDK"
  "CONFIG_BSP_SDH_SDCARD"
  "CONFIG_CLI_CMD_ENABLE"
  "CONFIG_FATFS"
  "CONFIG_FATFS_SDH_SDCARD"
  "CONFIG_FREERTOS"
  "CONFIG_IRQ_NUM=80"
  "CONFIG_LIBC_FLOAT=1"
  "CONFIG_LIBC_FLOAT_EX=1"
  "CONFIG_LIBC_LONG_LONG=1"
  "CONFIG_LOG_LEVEL=3"
  "CONFIG_LWIP"
  "CONFIG_MAC_RXQ_DEPTH=12"
  "CONFIG_MAC_TXQ_DEPTH=16"
  "CONFIG_MBEDTLS"
  "CONFIG_POSIX"
  "CONFIG_PSRAM"
  "CONFIG_SHELL"
  "CONFIG_STA_MAX=4"
  "CONFIG_TLSF"
  "CONFIG_VIF_MAX=2"
  "MBEDTLS_CONFIG_FILE=\"mbedtls_sample_config.h\""
  "MBEDTLS_NET_C"
  "RFPARAM_BL616"
  "WL_BL616=1"
  "WL_BL618M=0"
  "WL_WB03=0"
  "configSTACK_ALLOCATION_FROM_SEPARATE_HEAP=1"
  "default_interrupt_handler=freertos_risc_v_trap_handler"
  "portasmHANDLE_INTERRUPT=interrupt_entry"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/bsp/board/bl616g0/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/bsp/common/sdcard"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/bsp/common/lcd"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/bsp/common/touch"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/bsp/common/image_sensor"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/ai/TinyMaix/src"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/ai/TinyMaix/tools"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/ai/TinyMaix/examples"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/crypto/mbedtls/mbedtls/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/crypto/mbedtls/port"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/crypto/mbedtls/port/hw_acc"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/fs/fatfs/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/fs/fatfs/port/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/graphics/lvgl/port"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/graphics/lvgl/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/libc/newlib/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/libc/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/mm/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/mm/tlsf/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/net/lib/mqtt/inc"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/net/lwip/lwip/system"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/net/lwip/lwip/src/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/net/lwip/lwip/src/include/compat/posix"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/net/lwip/lwip_apps/dhcpd/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/os/freertos/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/os/freertos/portable/GCC/RISC-V/common"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/os/freertos/portable/GCC/RISC-V/common/chip_specific_extensions/RV32I_CLINT_no_extensions"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/os/freertos/posix/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/shell/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/utils/log"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/utils/ring_buffer"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/utils/bflb_block_pool"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/utils/bflb_timestamp"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/utils/getopt"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/wireless/wifi6/inc"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/components/wireless/wifi6/bl6_os_adapter/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/lhal/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/lhal/include/arch"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/lhal/include/arch/risc-v/t-head"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/lhal/include/arch/risc-v/t-head/Core/Include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/lhal/include/arch/risc-v/t-head/csi_dsp/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/lhal/config/bl616"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/lhal/src/flash"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/include"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/include/hardware"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/rf/inc"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/rfparam/Inc"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/examples/A_work/lvgl_wifi/."
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/examples/A_work/lvgl_wifi/inc"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/examples/A_work/lvgl_wifi/inc/tinymaix"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/port/bl616_clock.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/port/bl616_clock.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/port/bl616_clock.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_aon.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_aon.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_aon.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_common.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_common.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_common.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_ef_cfg.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_ef_cfg.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_ef_cfg.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_mfg_efuse.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_efuse.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_efuse.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_mfg_flash.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_flash.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_flash.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_mfg_media.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_media.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_media.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_pm.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_pm.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_pm.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_psram.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_psram.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_psram.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_romapi_e907.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_e907.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_e907.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_romapi_patch.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_patch.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_patch.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_sdh.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_sdh.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_sdh.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_tzc_sec.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_tzc_sec.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_tzc_sec.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/interrupt.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/interrupt.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/interrupt.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/start_load.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start_load.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start_load.c.obj.d"
  "D:/sxs/Desktop/bouffalo/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/system_bl616.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/system_bl616.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/system_bl616.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
