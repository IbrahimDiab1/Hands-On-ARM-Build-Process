# Hands-On-ARM-Build-Process

This repository serves as a hands-on study of the STM32F103C8 microcontroller build process using the ARM GCC toolchain. It provides insights into the development flow of embedded systems by showcasing the creation of essential files such as a custom Makefile, linker script, and startup file. By understanding and implementing these components from scratch, developers can gain a deep understanding of the embedded development process.

## Build Process Overview

The build process in this repository encompasses the following key components:

## Makefile

The Makefile in this repository simplifies the compilation process for ARM controller programs.

- **Compilation Automation**:
    - The Makefile automates the compilation process for the ARM controller program by defining compiler settings and flags.

- **Project Structure Organization**:
    - It organizes the project structure by creating separate directories for debug output, ensuring clarity and cleanliness in the development environment.

- **Notable Rules**:
    - Notable rules include:
        - `Project`: Builds the final ELF file.
        - `APP`: Builds the application layer files.
        - `MCAL`: Builds the MCAL (Micro-controller Abstraction Layer) files.
        - `startup`: Builds the startup file for the ARM controller.

- **Debug Folder Creation**:
    - The Makefile creates a `debug` folder to save the outputs of the building process, ensuring a clean project structure and organization.

- **Map File Generation**:
    - Additionally, the Makefile generates a map file (`App.map`) during the linking process. This map file provides valuable insights into the memory usage and allocation of different sections of the program, aiding in debugging and optimization efforts.


## Linker Script

A linker script is crucial for organizing the memory layout of embedded systems during compilation. It specifies where different parts of the program should be stored in memory, such as code in flash and data in RAM.

- **Memory Organization**:
  - It defines memory regions like flash and RAM and determines the sizes and locations of each.

- **Section Placement**:
  - The script decides where code, read-only data, initialized data, and uninitialized data should be placed in memory.

- **Symbol Definition**:
  - Additionally, it sets symbols representing the start and end addresses of memory regions and sections, aiding in linking.

Customizing the linker script helps optimize memory usage and ensures efficient program execution on the target micro-controller.



## Startup Code

The startup code is an essential part of embedded systems programming, responsible for initializing the micro-controller and preparing it for running the application code. This startup file (`STM32F103c8Startup.c`) is tailored for the STM32F103C8 micro-controller.

### Purpose:

- **Initialization**:
  - The startup code initializes the micro-controller by setting up necessary hardware configurations and initializing variables.

- **Memory Management**:
  - It manages memory by defining symbols for memory boundaries obtained from the linker script, such as the start and end addresses of the `.data` and `.bss` sections.

- **Reset Handler**:
  - The `Reset_Handler` function is the entry point of the application. It initializes the `.bss` section by zeroing out uninitialized variables and copies initialized data from flash memory to RAM. Finally, it calls the `main()` function to start the application.

### Key Functions:

- **Default_Handler**:
  - This function serves as the default handler for all interrupts. It enters an infinite loop, indicating an unexpected event.

- **Reset_Handler**:
  - The `Reset_Handler` function initializes the micro-controller upon reset. It initializes memory sections, copies initialized data from flash to RAM, and calls the `main()` function to start the application.

### Interrupt Vector Table:

- The `isr_vector` array defines the interrupt vector table. Each entry in the array corresponds to a specific interrupt handler function. Weak aliases are used to assign default handler functions to unused interrupts.

By customizing the startup code, developers can tailor the initialization process to suit specific hardware requirements and improve system reliability and performance.
