// Chip 8 Emulator.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <cstdint>
#include <cstddef>

// TODO: Reference additional headers your program requires here.

class Chip8 {

public:
	//screen dimensions 
	static constexpr int W = 64;
	static constexpr int H = 32;

	//Memory Layout 
	static constexpr uint16_t P_START = 0x200;
	static constexpr uint16_t FONT_ADDR = 0x50;

	void reset();
	void loadFont(const uint8_t* data, std::size_t n); // copy font bytes 
	void LoadROM(const char* filename);
	uint16_t fetch();
	void cycle();
	void execute(uint16_t opcode);
	

	uint8_t registers[16]{};
	uint8_t memory[4096]{};
	uint16_t index{};
	uint16_t pc{};
	uint16_t stack[16]{};
	uint8_t sp{};
	uint8_t delayT{};
	uint8_t soundT{};
	uint8_t keypad[16]{};
	uint32_t video[W * H]{};
	uint16_t opcode;
};