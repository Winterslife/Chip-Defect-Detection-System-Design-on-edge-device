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

# Utility rule file for combine.

# Include any custom commands dependencies for this target.
include CMakeFiles/combine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/combine.dir/progress.make

CMakeFiles/combine:
	cd /d C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0 && .\..\..\..\tools\bflb_tools\bflb_fw_post_proc\bflb_fw_post_proc --chipname=bl616 --imgfile=C:/Users/sxs/Desktop/bouffalo_sdk_vmg0/examples/A_work/_project_cam_g0/build/build_out/_project_cam_g0_bl616.bin --brdcfgdir=./../../../bsp/board/bl616g0/config

combine: CMakeFiles/combine
combine: CMakeFiles/combine.dir/build.make
.PHONY : combine

# Rule to build all files generated by this target.
CMakeFiles/combine.dir/build: combine
.PHONY : CMakeFiles/combine.dir/build

CMakeFiles/combine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\combine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/combine.dir/clean

CMakeFiles/combine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0 C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0 C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build C:\Users\sxs\Desktop\bouffalo_sdk_vmg0\examples\A_work\_project_cam_g0\build\CMakeFiles\combine.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/combine.dir/depend
