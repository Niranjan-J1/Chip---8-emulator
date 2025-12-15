#include "Chip 8 Emulator.h"
#include <iostream>
#include <iomanip> // for std::hex formatting

int main() {
    Chip8 chip;
    chip.reset();

    // --- 1?? Load a simple sprite into memory at I ---
    // This represents a 3-row sprite:
    // ####
    // #  #
    // ####
    chip.index = 0x300;
    chip.memory[0x300] = 0xF0; // 11110000
    chip.memory[0x301] = 0x90; // 10010000
    chip.memory[0x302] = 0xF0; // 11110000

    // --- 2?? Set registers for coordinates ---
    chip.registers[0] = 5;  // V0 = x position
    chip.registers[1] = 5;  // V1 = y position

    // --- 3?? Execute draw instruction: D015 (draw 3-byte sprite at (V0,V1)) ---
    chip.execute(0xD013);

    // --- 4?? Print a section of the screen buffer to check drawing ---
    std::cout << "After first draw:\n";
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            std::cout << (chip.video[y * Chip8::W + x] ? "#" : ".");
        }
        std::cout << "\n";
    }

    // --- 5?? Execute the same draw again (XOR toggles pixels back off) ---
    chip.execute(0xD013);

    // --- 6?? Print again to see it erased + check collision flag ---
    std::cout << "\nAfter second draw (erases itself):\n";
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            std::cout << (chip.video[y * Chip8::W + x] ? "#" : ".");
        }
        std::cout << "\n";
    }

    // --- 7?? Check collision flag (VF) ---
    std::cout << "\nCollision flag (VF): " << (int)chip.registers[0xF] << std::endl;

    return 0;
}
