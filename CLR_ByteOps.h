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

#ifndef __CLRBYTEOPS_H__
#define __CLRBYTEOPS_H__

/*
 * Returns the byte n_byte from the register d.
 *
 * \param d field to get the byte from.
 * \param n_byte byte position (considering 0 the least significant byte)
 *
 * \returns the byte read
 *
 * */
#define BYTE_GET(d,n_byte) ((d >> (n_byte << 3)) & 0xFF)

/*
 * Sets the byte n_byte from the register d.
 *
 * \param d field to set the byte.
 * \param n_byte byte to set position (considering 0 the least significant byte)
 *
 * \returns a copy of the register with the byte set to all 1.
 *
 * */
#define BYTE_SET(d,n_byte) (d|(0xFF << (n_byte << 3)))

/*
 * Clears the byte n_byte from the register d.
 *
 * \param d field to clear the byte .
 * \param n_byte byte to clear position (considering 0 the least significant byte)
 *
 * \returns a copy of the register with the byte set to all 0.
 *
 * */
#define BYTE_CLEAR(d,n_byte) (d&(~(0xFF << (n_byte << 3))))

/*
 * Writes the byte n_byte into the register d.
 *
 * \param d field to write the byte to.
 * \param n_byte position of the byte to write to (considering 0 the least significant byte)
 * \param value the byte to write [0x00,0xFF]
 *
 * \returns a copy of the register with value written in the position indicated.
 *
 * */
#define BYTE_WRITE(d,n_byte,value) (d&(~(0xFF << (n_byte << 3))))|((value&0xFF)<<(n_byte << 3))

/*
 * Returns the word n_word from the register d.
 *
 * \param d field to get the word from.
 * \param n_word word position (considering 0 the least significant word)
 *
 * \returns the word read
 *
 * */
#define WORD_GET(d,n_word) ((d >> (n_word << 4)) & 0xFFFF)

/*
 * Sets the word n_word from the register d.
 *
 * \param d field to set the word.
 * \param n_word word to set position (considering 0 the least significant word)
 *
 * \returns a copy of the register with the word set to all 1.
 *
 * */
#define WORD_SET(d,n_word) (d|(0xFFFF << (n_word << 4)))

/*
 * Clears the word n_word from the register d.
 *
 * \param d field to clear the word .
 * \param n_word word to clear position (considering 0 the least significant word)
 *
 * \returns a copy of the register with the word set to all 0.
 *
 * */
#define WORD_CLEAR(d,n_word) (d&(~(0xFFFF << (n_word << 4))))

/*
 * Writes the word n_word into the register d.
 *
 * \param d field to write the word to.
 * \param n_word position of the word to write to (considering 0 the least significant word)
 * \param value the word to write [0x0000,0xFFFF]
 *
 * \returns a copy of the register with value written in the position indicated.
 *
 * */
#define WORD_WRITE(d,n_word,value) (d&(~(0xFFFF << (n_word << 4))))|((value&0xFFFF)<<(n_word << 4))

/**
 * Swaps the endianess of the 16 bit field passed as parameter d.
 * \param d 16 bit field to swap endianess
 * \returns
 * \li The byte.
 * */
#define WORD_SWAP_ENDIANESS(d) ((d & 0x00FF) << 8) | ((d & 0xFF00) >> 8)

/**
 * Swaps the endianess of the 32 bit field passed as parameter d.
 * \param d 32 bit field to swap endianess
 * \returns
 * \li The Word.
 * */
#define LONG_SWAP_ENDIANESS(d) ((d & 0xFF000000) >> 24) | ((d & 0x00FF0000) >> 8) | ((d & 0x0000FF00) << 8) | ((d & 0x000000FF) << 24)

/**
 * Generates a 16 bit word from two 8 bytes, msb and lsb
 * \param msb most significant bit of the word to create
 * \param lsb least significant bit of the word to create
 * \returns
 * \li The 32 bit field.
 * */
#define WORD_GEN_BYTES(msb,lsb) ((msb << 8) | lsb)

/**
 * Generates a 32 bit word from four 8 bytes, mswub, mswlb, lswub and lswlb
 * \param mswub upper byte of the most significant word of the 32 bit field to create
 * \param mswlb lower byte of the most significant word of the 32 bit field to create
 * \param lswub upper byte of the least significant word of the 32 bit field to create
 * \param lswlb lower byte of the least significant word of the 32 bit field to create
 * \returns
 * \li The Word.
 * */
#define LONG_GEN_BYTES(mswub, mswlb, lswub, lswlb) ((mswub << 24) | (mswlb << 16) | (lswub << 8) | lswlb)

/**
 * Generates a 32 bit word from two 16 bit words, msw and lsw
 * \param msw most significant word of the 32 bit field to create
 * \param lsw least significant word of the 32 bit field to create
 * \returns
 * \li The 32 bit field.
 * */
#define LONG_GEN_WORDS(msw,lsw) ((msw << 16) | lsw)

#endif // __CLRBYTEOPS_H__
