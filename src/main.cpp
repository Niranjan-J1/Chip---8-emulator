#include "Chip 8 Emulator.h"
#include <iostream>


int main() {
	Chip8 chip;
	chip.reset();

	chip.video[100] = 1;  // pretend pixel is “on”
	chip.memory[0x200] = 0x00;
	chip.memory[0x201] = 0xE0;  // CLS opcode

	chip.cycle();
	
	bool cleared = true;
	for (int i = 0; i < Chip8::W * Chip8::H; i++) {
		if (chip.video[i] != 0) { cleared = false; break; }
	}
	std::cout << "CLS worked? " << (cleared ? "yes" : "no") << std::endl;
	/*chip.LoadROM("../../../roms/Airplane.ch8");
	for (int i = 0; i < 5; i++) {
		chip.cycle();
	}

	// Print registers to confirm LD Vx,kk worked
	std::cout << "VA = " << std::hex << (int)chip.registers[0xA] << std::endl;
	std::cout << "VB = " << std::hex << (int)chip.registers[0xB] << std::endl;
	std::cout << "VC = " << std::hex << (int)chip.registers[0xC] << std::endl;
	std::cout << "VD = " << std::hex << (int)chip.registers[0xD] << std::endl;
	std::cout << "VE = " << std::hex << (int)chip.registers[0xE] << std::endl;*/
}
