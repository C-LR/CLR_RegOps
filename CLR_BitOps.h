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

#ifndef __CLRBITOPS_H__
#define __CLRBITOPS_H__


/**
 * Reads the bit at the index "index" (starting at 0) from the bit field "reg"
 * 
 * \param reg bit field to read from
 * \param index position of the byte to read
 * 
 * */
#define BIT_READ(reg,index) ((reg >> index) & 1)

/**
 * Writes 1 at the index "index" (starting at 0) of the bit field "reg"
 *
 * \param reg bit field to write to
 * \param index position of the byte to write
 *
 * */
#define BIT_SET(reg,index) (reg|(1<<index))

/**
 * Writes 0 at the index "index" (starting at 0) of the bit field "reg"
 *
 * \param reg bit field to write to
 * \param index position of the byte to write
 *
 * */
#define BIT_CLEAR(reg,index) ((~(1<<index)&reg))

/**
 * Writes the bit "value" at the index "index" (starting at 0) of the bit field "reg"
 * 
 * \param reg bit field to write to
 * \param index position of the byte to write
 * \param value value to write
 * 
 * */
#define BIT_WRITE(reg,index,value) ((~(1<<index)&reg)|(value<<index))

/**
 * Reads the number of bits "nbits" at the index "index" (starting at 0) from the bit field "reg"
 * 
 * \param reg bit field to read from
 * \param index position of the byte to read
 * \param nbits number of bits to read
 * 
 * */
#define BITS_READ(reg,index,nbits) ((reg >> index) & ~(-1 << nbits))


/**
 * Sets the bits at the index "index" (starting at 0) of the bit field "reg" to 1
 *
 * \param reg bit field to read from
 * \param index position of the byte to read
 * \param nbits number of bits for writing width
 *
 * */
#define BITS_SET(reg,index,nbits) (reg|(~(-1<<nbits)<<index));

/**
 * Clears the bits at the index "index" (starting at 0) of the bit field "reg" to 1
 *
 * \param reg bit field to read from
 * \param index position of the byte to read
 * \param nbits number of bits for writing width
 *
 * */
#define BITS_CLEAR(reg,index,nbits) (reg&(~(~(-1<<nbits)<<index)));


/**
 * Writes the bits "value" (with a bit width of "nbits" at the index "index" (starting at 0) of the bit field "reg"
 * 
 * \param reg bit field to read from
 * \param index position of the byte to read
 * \param nbits number of bits for writing width
 * \param value value to write
 * 
 * */
#define BITS_WRITE(reg,index,nbits,value) ((~((~(-1 << nbits))<<index))&reg)|(value<<index)


#endif // __CLRBITOPS_H__
