# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\tools\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\tools\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build

# Include any dependencies generated for this target.
include CMakeFiles/_project_cam_g0_bl616.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/_project_cam_g0_bl616.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/_project_cam_g0_bl616.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_project_cam_g0_bl616.elf.dir/flags.make

CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.obj: CMakeFiles/_project_cam_g0_bl616.elf.dir/flags.make
CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.obj: C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/main.c
CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.obj: CMakeFiles/_project_cam_g0_bl616.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.obj"
	C:\Users\sxs\Desktop\toolchain_gcc_t-head_windows\bin\riscv64-unknown-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.obj -MF CMakeFiles\_project_cam_g0_bl616.elf.dir\main.c.obj.d -o CMakeFiles\_project_cam_g0_bl616.elf.dir\main.c.obj -c C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\main.c

CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.i"
	C:\Users\sxs\Desktop\toolchain_gcc_t-head_windows\bin\riscv64-unknown-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\main.c > CMakeFiles\_project_cam_g0_bl616.elf.dir\main.c.i

CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.s"
	C:\Users\sxs\Desktop\toolchain_gcc_t-head_windows\bin\riscv64-unknown-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\main.c -o CMakeFiles\_project_cam_g0_bl616.elf.dir\main.c.s

# Object files for target _project_cam_g0_bl616.elf
_project_cam_g0_bl616_elf_OBJECTS = \
"CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.obj"

# External object files for target _project_cam_g0_bl616.elf
_project_cam_g0_bl616_elf_EXTERNAL_OBJECTS =

build_out/_project_cam_g0_bl616.elf: CMakeFiles/_project_cam_g0_bl616.elf.dir/main.c.obj
build_out/_project_cam_g0_bl616.elf: CMakeFiles/_project_cam_g0_bl616.elf.dir/build.make
build_out/_project_cam_g0_bl616.elf: build_out/lib/libTinyMaix.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libmbedtls.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/liblibc.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libmm.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libmqtt.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/liblwip.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libdhcpd.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libping.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libfreertos.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libshell.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libutils.a
build_out/_project_cam_g0_bl616.elf: C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/components/wireless/wifi6/lib/libwifi6.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libbl6_os_adapter.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/liblhal.a
build_out/_project_cam_g0_bl616.elf: C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/include/arch/risc-v/t-head/csi_dsp/lib/libcsi_xt900p32f_dsp.a
build_out/_project_cam_g0_bl616.elf: C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/lhal/src/pka/libpka.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libstd.a
build_out/_project_cam_g0_bl616.elf: C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/drivers/soc/bl616/rf/lib/librf.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/librfparam.a
build_out/_project_cam_g0_bl616.elf: build_out/lib/libapp.a
build_out/_project_cam_g0_bl616.elf: C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/bsp/board/bl616g0/bl616_flash.ld
build_out/_project_cam_g0_bl616.elf: CMakeFiles/_project_cam_g0_bl616.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable build_out\_project_cam_g0_bl616.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\_project_cam_g0_bl616.elf.dir\link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generate C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/_project_cam_g0_bl616.bin"
	riscv64-unknown-elf-objcopy -Obinary C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/_project_cam_g0_bl616.elf C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/_project_cam_g0_bl616.bin
	riscv64-unknown-elf-objdump -d -S C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/_project_cam_g0_bl616.elf >C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/_project_cam_g0_bl616.asm

# Rule to build all files generated by this target.
CMakeFiles/_project_cam_g0_bl616.elf.dir/build: build_out/_project_cam_g0_bl616.elf
.PHONY : CMakeFiles/_project_cam_g0_bl616.elf.dir/build

CMakeFiles/_project_cam_g0_bl616.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\_project_cam_g0_bl616.elf.dir\cmake_clean.cmake
.PHONY : CMakeFiles/_project_cam_g0_bl616.elf.dir/clean

CMakeFiles/_project_cam_g0_bl616.elf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0 C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0 C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build\CMakeFiles\_project_cam_g0_bl616.elf.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_project_cam_g0_bl616.elf.dir/depend

