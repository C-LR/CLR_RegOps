/////////////////////////////////////////////////
//	V1.0
//	made by CLR in his spare time during 2017
//
//	This file is part of CLR_RegOps.
//
//	CLR_RegOps is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	CLR_RegOps is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU Lesser General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with CLR_RegOps.  If not, see <https://www.gnu.org/licenses/>.
//
/////////////////////////////////////////////////

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "CLR_BitOps.h"
#include "CLR_ByteOps.h"

uint32_t base_register = 0;

void print_base_register_value(void){
	printf("Register value is %08X \n\n", base_register);
}

void single_bit_operations(void){

	int read_data = 0;

	printf("SINGLE BIT OPERATIONS\n");
	printf("--------------\n");
	printf("INITIAL VALUE\n");
	print_base_register_value();
	printf("--------------\n");

	printf("Setting bit 24... \n");

	base_register = BIT_SET(base_register,24);	//Set bit 24 of base_register to 1

	print_base_register_value();

	printf("Reading bit 24 from the register... \n");

	read_data = BIT_READ(base_register,24);		//Read bit 24 into read_data

	printf("Bit 24 value is %d\n\n", read_data);

	printf("Clearing bit 24... \n");

	base_register = BIT_CLEAR(base_register,24);	//Clear bit 24 of base_register

	print_base_register_value();

	printf("Writing 1 on bit 13... \n");

	base_register = BIT_WRITE(base_register,13,1);	//Write a 1 to bit 13 of base_register

	print_base_register_value();

	printf("Writing 0 on bit 13... \n");

	base_register = BIT_WRITE(base_register,13,0); //Write a 0 to bit 13 of base_register

	print_base_register_value();
}

void multiple_bit_operations(void){

	int read_data = 0;


	printf("MULTIPLE BIT OPERATIONS\n");
	printf("--------------\n");
	printf("INITIAL VALUE\n");
	print_base_register_value();
	printf("--------------\n");

	printf("Setting bits [5,10] to 1... \n");

	base_register = BITS_SET(base_register,5,6);	//Set 6 bits width, starting at bit 5, in base_register

	print_base_register_value();

	printf("Clearing bits [8,10]... \n");

	base_register = BITS_CLEAR(base_register,8,3);	//Clear 3 bits width, starting at bit 8, in base_register

	print_base_register_value();

	printf("Reading bits [5,10] from the register... \n");

	read_data = BITS_READ(base_register,5,6); //Read 6 bits width, starting at bit 5, in base_register and copy them to read_data

	printf("Bits value read is %02X\n\n", read_data);

	read_data = 0xCABE;

	printf("Writing %04X in bit 16...\n", read_data);

	base_register = BITS_WRITE(base_register,16,16,read_data);	//Write 16 bits of read_data into bit 16 of base_register

	print_base_register_value();

	read_data = 0xA5A5;

	printf("Writing %04X in bit 16...\n", read_data);			//Write 16 bits of read_data into bit 16 of base_register

	base_register = BITS_WRITE(base_register,16,16,read_data);

	print_base_register_value();

}

void byte_operations(void){

	base_register = 0;

	int read_data = 0xA5;

	uint8_t byte_0 = 0xB0;
	uint8_t byte_1 = 0xB1;
	uint8_t byte_2 = 0xB2;
	uint8_t byte_3 = 0xB3;

	uint16_t word_0 = 0xC0DE;
	uint16_t word_1 = 0xDEAD;

	printf("BYTE OPERATIONS\n");
	printf("--------------\n");
	printf("INITIAL VALUE\n");
	print_base_register_value();
	printf("--------------\n");

	printf("Setting byte 1...\n");

	base_register = BYTE_SET(base_register,1);	//Set byte 1 of base_register

	print_base_register_value();

	printf("Clearing byte 1...\n");

	base_register = BYTE_CLEAR(base_register,1);	//Clear byte 1 of base_register

	print_base_register_value();

	printf("Writing %02X to byte 2...\n", read_data);

	base_register = BYTE_WRITE(base_register,2,read_data); //Write read_data into byte 2 of base_register

	print_base_register_value();

	read_data = BYTE_GET(base_register,2); //Read byte 2 of base_register into read_data

	printf("Read %02X from byte 2...\n\n", read_data);

	printf("Setting word 1...\n");

	base_register = WORD_SET(base_register,1);	//Set word 1 of base_register

	print_base_register_value();

	printf("Clearing word 1...\n");

	base_register = WORD_CLEAR(base_register,1);	//Clear word 1 of base_register

	print_base_register_value();

	read_data = 0xCAFE;

	printf("Writing %04X to word 0...\n", read_data);

	base_register = WORD_WRITE(base_register,0,read_data);	//Write read_data into word 0 of base_register

	print_base_register_value();

	read_data = WORD_GET(base_register,0);	//Read word 0 of base_register into read_data

	printf("Read %04X from word 0...\n\n", read_data);

	printf("Swapping endianess of the first word of the register...\n");

	base_register = WORD_SWAP_ENDIANESS(base_register);	//Swap endianess of the 16 least significant bytes of base_register

	print_base_register_value();

	printf("Swapping endianess of the whole register...\n");

	base_register = LONG_SWAP_ENDIANESS(base_register);	//Swap endianess of the whole base_register

	print_base_register_value();

	printf("Generating a word in the first word of the register with byte 0=%02X and byte 1=%02X (Rest will be 0)...\n",byte_0,byte_1);

	base_register = WORD_GEN_BYTES(byte_1,byte_0);	//Generate a new word from byte 1 and byte 0

	print_base_register_value();

	printf("Generating a register with byte 0=%02X, byte 1=%02X, byte 2=%02X and byte 3=%02X...\n",byte_0,byte_1,byte_2,byte_3);

	base_register = LONG_GEN_BYTES(byte_3,byte_2,byte_1,byte_0);	//Generate new word from byte 3, byte 2, byte 1 and byte 0

	print_base_register_value();

	printf("Generating a register with word 0=%04X and word 1=%04X...\n", word_0, word_1);

	base_register = LONG_GEN_WORDS(word_1,word_0);	//Generate new word from word 1 and word 2

	print_base_register_value();

}

int main(void){

	single_bit_operations();

	multiple_bit_operations();

	byte_operations();

	system("pause");

	return 0;
}
