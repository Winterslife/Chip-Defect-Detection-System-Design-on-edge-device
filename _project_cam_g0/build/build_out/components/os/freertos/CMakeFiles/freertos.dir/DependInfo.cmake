
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/portable/GCC/RISC-V/common/portASM.S" "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/components/os/freertos/CMakeFiles/freertos.dir/portable/GCC/RISC-V/common/portASM.S.obj"
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
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/croutine.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/croutine.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/croutine.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/event_groups.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/event_groups.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/event_groups.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/freertos_port.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/freertos_port.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/freertos_port.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/list.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/list.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/list.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/portable/GCC/RISC-V/common/port.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/portable/GCC/RISC-V/common/port.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/portable/GCC/RISC-V/common/port.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/portable/MemMang/heap_3.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/portable/MemMang/heap_3.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/portable/MemMang/heap_3.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_clock.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_clock.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_clock.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_mqueue.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_mqueue.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_mqueue.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_pthread.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_pthread_barrier.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread_barrier.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread_barrier.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_pthread_cond.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread_cond.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread_cond.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_pthread_mutex.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread_mutex.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_pthread_mutex.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_sched.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_sched.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_sched.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_semaphore.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_semaphore.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_semaphore.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_timer.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_timer.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_timer.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_unistd.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_unistd.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_unistd.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/posix/source/FreeRTOS_POSIX_utils.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_utils.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/posix/source/FreeRTOS_POSIX_utils.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/queue.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/queue.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/queue.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/tasks.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/tasks.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/tasks.c.obj.d"
  "C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/os/freertos/timers.c" "build_out/components/os/freertos/CMakeFiles/freertos.dir/timers.c.obj" "gcc" "build_out/components/os/freertos/CMakeFiles/freertos.dir/timers.c.obj.d"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
