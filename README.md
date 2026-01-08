# Chip---8-emulator

CHIP-8 Emulator in C++

A CHIP-8 emulator written in C++ with an SDL2-based frontend to execute and render classic CHIP-8 programs (ROMs).
This emulator faithfully implements the fetch–decode–execute cycle, supports keyboard input mapping, and provides real-time graphics rendering.

Features

Full CHIP-8 CPU Emulation
Registers, stack, memory, and timers.

Opcode Pipeline
Fetch–decode–execute cycle for all CHIP-8 instructions.

Graphics
Sprite rendering with XOR logic and collision detection.

SDL2 Frontend
Windowed display with pixel scaling for retro aesthetics.

Keyboard Input Mapping
Map CHIP-8 hex keypad to standard PC keys.

Automatic ROM Key Detection
Detects used keys and displays a control menu.

Timers
60 Hz emulation for delay and sound timers.

CHIP-8 → Keyboard Mapping
CHIP-8 Key	PC Key
1 2 3 C	1 2 3 4
4 5 6 D	Q W E R
7 8 9 E	A S D F
A 0 B F	Z X C V

Controls

ENTER → Start execution

ESC → Quit emulator

How to Run
1. Build Requirements

C++17 or later

SDL2

A CHIP-8 ROM file (.ch8)

Ensure SDL2 is installed and properly linked.

2. Compile

Example (using g++ on Windows/Linux):

g++ *.cpp -o chip8 -lSDL2


⚠️ Compilation flags may vary depending on your SDL2 installation.

3. Load a ROM

Update the ROM path inside main.cpp:

std::string romPath = "path/to/your/rom.ch8";
chip.LoadROM(romPath.c_str());

4. Run the Emulator
./chip8


The emulator will automatically detect which CHIP-8 keys are used and display the control menu.

Project Structure
Chip 8 Emulator.cpp / .h   → Core CPU (memory, registers, opcodes, timers)
sdl_frontend.cpp / .h      → SDL2-based rendering & input handling
main.cpp                   → Emulator loop, timing, ROM loading, key detection

Technical Highlights

Full opcode support (0x0NNN – 0xFxxx)

Accurate sprite rendering using XOR pixel toggling

Collision detection via VF register

Instruction timing decoupled from frame rate

Clear separation of CPU logic and frontend rendering

Future Improvements

Sound output via SDL audio

Configurable key bindings

ROM selection menu

Debugger / step-through execution

Save/load emulator state
