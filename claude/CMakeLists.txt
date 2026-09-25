cmake_minimum_required(VERSION 3.15)
project(freertos_bare_bones C)

# --- Tell the kernel where FreeRTOSConfig.h lives ---------------------------
# The kernel's CMake looks for an INTERFACE target named `freertos_config`.
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config SYSTEM INTERFACE config)

# --- Pick the port and heap -------------------------------------------------
# GCC_POSIX runs FreeRTOS as a normal Linux process (each task is a pthread),
# so no hardware or emulator is needed. Swap this for e.g. GCC_ARM_CM4F when
# you move to a real board.
set(FREERTOS_PORT GCC_POSIX CACHE STRING "FreeRTOS port")
# heap_4: first-fit allocator that coalesces free blocks. A sensible default.
set(FREERTOS_HEAP 4 CACHE STRING "FreeRTOS heap implementation (1-5)")

add_subdirectory(../FreeRTOS-Kernel build)

# --- The application --------------------------------------------------------
add_executable(app src/main.c)
target_compile_options(app PRIVATE -Wall -Wextra)
target_link_libraries(app PRIVATE freertos_kernel freertos_config)
