
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/riscv_fpu.S" "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/riscv_fpu.S.obj"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/start.S" "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start.S.obj"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/vector.S" "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/vector.S.obj"
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
  "CONFIG_CLI_CMD_ENABLE"
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
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/bsp/board/bl616g0/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/bsp/common/lcd"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/bsp/common/image_sensor"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/ai/TinyMaix/src"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/ai/TinyMaix/tools"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/ai/TinyMaix/examples"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/crypto/mbedtls/mbedtls/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/crypto/mbedtls/port"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/crypto/mbedtls/port/hw_acc"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/libc/newlib/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/libc/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/mm/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/mm/tlsf/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/net/lib/mqtt/inc"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/net/lwip/lwip/system"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/net/lwip/lwip/src/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/net/lwip/lwip/src/include/compat/posix"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/net/lwip/lwip_apps/dhcpd/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/portable/GCC/RISC-V/common"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/portable/GCC/RISC-V/common/chip_specific_extensions/RV32I_CLINT_no_extensions"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/shell/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/utils/log"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/utils/ring_buffer"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/utils/bflb_block_pool"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/utils/bflb_timestamp"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/utils/getopt"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/wireless/wifi6/inc"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/wireless/wifi6/bl6_os_adapter/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/include/arch"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/include/arch/risc-v/t-head"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/include/arch/risc-v/t-head/Core/Include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/include/arch/risc-v/t-head/csi_dsp/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/config/bl616"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/src/flash"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/include"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/include/hardware"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/rf/inc"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/rfparam/Inc"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/."
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/inc"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/inc/tinymaix"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/port/bl616_clock.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/port/bl616_clock.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/port/bl616_clock.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_aon.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_aon.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_aon.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_common.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_common.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_common.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_ef_cfg.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_ef_cfg.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_ef_cfg.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_mfg_efuse.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_efuse.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_efuse.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_mfg_flash.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_flash.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_flash.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_mfg_media.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_media.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_mfg_media.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_pm.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_pm.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_pm.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_psram.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_psram.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_psram.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_romapi_e907.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_e907.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_e907.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_romapi_patch.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_patch.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_romapi_patch.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_sdh.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_sdh.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_sdh.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/src/bl616_tzc_sec.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_tzc_sec.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/src/bl616_tzc_sec.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/interrupt.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/interrupt.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/interrupt.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/start_load.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start_load.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/start_load.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/std/startup/system_bl616.c" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/system_bl616.c.obj" "gcc" "build_out/drivers/soc/bl616/std/CMakeFiles/std.dir/startup/system_bl616.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
