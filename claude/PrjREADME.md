# Bare-bones project

A minimal FreeRTOS app that runs **on Linux** using the kernel's POSIX port
(each FreeRTOS task is a pthread), so no board or emulator is needed.

```
.
├── CMakeLists.txt          # picks the port (GCC_POSIX) + heap, builds the app
├── config/FreeRTOSConfig.h # kernel configuration
├── src/main.c              # two tasks talking over a queue
└── FreeRTOS-Kernel/        # git submodule, pinned to V11.3.1
```

### Build and run

```sh
git submodule update --init        # first time only
cmake -B build
cmake --build build
./build/app                        # Ctrl+C to stop
```

Expected output:

```
[producer] sending 1
[consumer] got     1
[producer] sending 2
[consumer] got     2
...
```

### Moving to real hardware

Change `FREERTOS_PORT` in `CMakeLists.txt` (e.g. `GCC_ARM_CM4F`), use a cross
compiler toolchain file, shrink `configTOTAL_HEAP_SIZE` /
`configMINIMAL_STACK_SIZE`, and set `configCPU_CLOCK_HZ` to the real clock.
You will also need the vendor's startup code and linker script.
