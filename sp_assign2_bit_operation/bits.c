/* 
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */



/* 
 * bitXor - XOR operation of x and y at bit level using only <~, &> 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	//TODO
	int Xor_1, Xor_0, result;
	
	Xor_1 = ~(x&y); 		// exclude case of x=1, y=1.
	Xor_0 = ~(~x&~y);		// exclude case of x=0, y=0.
	result = (Xor_1&Xor_0);		// return 1 if only x!=y.
	return result;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	//TODO
	int overf, result;
	
	overf = 1<<31;		// -2^31 is stored at overf due to overflow.
	result = ~overf;	// 100...0(31 zero) changed into 111...1(31 one)
	return result;
}
/* 
 * isNotEqual - return 1 if x != y, and 0 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	//TODO
	int same, result;
	
	same = x^y;		// if x=y, return 0 by XOR.
	result = !!same;	// for output 1 when x is not equal to y, use !! operation.
	return result;
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10 
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
	//TODO
	int shift_byte, replace_space, x_r_s, insert_value, result;

	shift_byte = (n<<3); // n is byte, which is 8bits, so we should n<<3, not just n.
	replace_space = (0xFF << shift_byte); // 0xFF represents 8bits will be replaced.
	x_r_s = x & ~replace_space;	// replaced space of x is filled with 00000000.
	insert_value = (c<<shift_byte); // 8bits will be moved to same position with 00000000 of x.
	
	result = x_r_s | insert_value;  // just merge both value with OR operation.
					    // In result, 8bits will be inserted into 00000000 of x.
	return result;
}
/* 
 * fitsBits - returns 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	//TODO
	int check_sign, check_sign2, bits_need, bits_n, result;

	check_sign = (x>>31)&1;			// if x>=0, 0; if x<0, 1;
	check_sign2 = ~((check_sign)+(~0));	// if x>=0, ~(~0)=0; if x<0, ~0; which is form for XOR operation.
	bits_need = x^check_sign2;		// bits_need means that required bits to express the x.
	bits_n = n+(~0);	// n+(~0) = n-1, because in frong of result there is ! operation, so we use n-1, not n.

	result = !(bits_need >> bits_n);	// compare length of bits_need with bits_n.
	return result;
}

/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */

int rotateLeft(int x, int n) {
	//TODO
	int bits_n, bits_live, LtoR1, del_sign, LtoR2, RtoL, result;

	bits_n = ~n+1;		// because ~n = -(n+1), ~n+1 = -n.
	bits_live = 32+bits_n;	// This bits will remain after shifting.
	LtoR1 = (x>>bits_live);	// Applying shift to x, if x>=0, then 0000..00 n bits of x from left.
	del_sign = ~((1<<31)>>(31+bits_n)); 	// del_sign is for case of x<0
						// del_sign will be ~(1000..00 n+1 bits of 1<<31 from left.) = 0111..11011..
	LtoR2 = LtoR1 & del_sign;	// LtoR2 is consider the case both of x>=0 and x<0.
	RtoL = x<<n; 	// RtoL is shifted x up to n from right to left, then n bits of x from right 000..00.
			// In RtoL, we don't have to consider the case of x<0, because shifting is from right to left.
	result = LtoR2|RtoL; // Then just merge LtoR2 and RtoL by OR operation, they fill each other at zero section.
	return result;
}

/*
 * isPower2 - returns 1 if x is a power of 2, and else 0 
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
	//TODO
	int check_sign, check_sign2, count_one, check_ispower2, result;

	check_sign = x>>31;		// if x>=0, 0; if x<0, -1;
	check_sign2 = (~0)^check_sign;	// if x>=0, ~0; if x<0, 0;
	count_one = x + check_sign2;	// if x<0, x; if x>=0, x+(~0)=x-1.
	check_ispower2 = x & count_one;	// When x>=0, if x has only one of 1, x&(x+(~0)) shoule be zero.
						//	      if x has more one of 1, x&(x+(~0)) is not zero.
	result = !(check_ispower2 + !x);	// !x means that if x=0, 1; else 0.
						// That is, it is only for case of x=0.
	return result;
}

/* 
 * rempwr2 - Compute x%(2^n), which is remainder for x divided by (2^n) for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

int rempwr2(int x, int n) {
	//TODO
	int powOf2, restOf, restOf_x, isThereRest, neg, neg_c, result;

	powOf2 = 1<<n;		// which is 2^n, ex)000..010000
	restOf = (powOf2)+(~0);	// which makes all bits in right side of 2^n into 1, that is rest(%)
	restOf_x = x&restOf; // which means that all bits in right side of most significant 1 bit are 1 in x.
					// Above code is not consider the case of x<0.
	isThereRest = !!restOf_x;	// if there is rest, 1; if there is no rest, 0;
	neg = ~(isThereRest << n) + 1;	// make all bits in left side of 2^n into 1, containing 2^n
						// which is 111...11000
	neg_c = (x>>31);			// neg_c let us use neg when x<0.
						// If x>=0, neg_c must be zero, so (neg&neg_c) also must be zero.
	result = restOf_x + (neg&neg_c);	// By using + operation, we can get output both case of x>=0 and x<0.
	return result;
}

/* 
 * conditional - Returns y if x is not 0, else z same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */

int conditional(int x, int y, int z) {
	//TODO
	int check_xzero, output_z, output_y, result;

	check_xzero = (!x+(~0));	// if x=0, 1; else 0.

	output_z = (~check_xzero)&z;	// if x=0, z; else 0.
	output_y = (check_xzero)&y;	// if x!=0, y; else 0.

	result = output_z|output_y;	// just merge output z and y with OR operation.
					// output z and y has opposite condition each other, so use OR operation.
	return result;
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's, else 0
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

int bitParity(int x) {
	//TODO
	int result;
	
	x = x^(x>>16);	// Compare left side 16bits with right side 16 bits.
	x = x^(x>>8);	// Then we don't think about left side 16bits of x.
	x = x^(x>>4);	// We just compare each other with dividing x by 2 section.
	x = x^(x>>2);	// When comparing, 1 bits in same position disappear,
	x = x^(x>>1);	// which can't affect whether the number of 0's in origin x is odd or not.
			// because they always disappear with a pair.

	result = x&1; // So, we just check the last 1 bit. If it is odd, odd number of 0's is also odd.
	return result;
}

/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
	//TODO
	int case_normal, case_negative, result;

	x |= x>>16;	// This 5 lines makes all bits in right side of most significant 1 bit of x into 1.
	x |= x>>8;	// Because it keeps dividing 2 section upto 1-1bits,
	x |= x>>4;	// and it uses OR operation.
	x |= x>>2;	//
	x |= x>>1;	// That is, 000001(most significant bit)111..111.

	case_normal = x&(~x>>1);	// By shifting ~x to right in 1 bit, we get only one of 1 that is most significant bit.
					// which considers only the case of x>=0.
	case_negative = x&(~!x<<31);	// This is considering case of x<0.
	result = case_normal^case_negative; // For get only most significant bit, we should use XOR operation.
	return result;
}

/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

int logicalNeg(int x) {
	//TODO
	int left, right, result, result_modify;

	left = x>>31;	// if x>=0, 0; if x<0, -1;
	right = (~x+1)>>31; // because ~x = -(x+1), ~x+1 = -x.
				// if x<=0, 0; if x>0, -1;
	result = left|right;	// just merge the range of left and right.
					// if x=0, 0; if x>0 or x<0, -1;
	result_modify = result + 1;	// Adjust output into if x=0, 1; else 0;
	return result_modify;
}

/* 
 * bitAnd - AND operation of x and y at bit level using only <~, |>
 *	Example : bitAnd(12, 25) = (0000 1100) & (0001 1001) = 0000 1000 = 8 
 *	Legal ops : ~ |
 *	Max ops : 8
 *	Rating : 1
 */
int bitAnd(int x, int y) {
	//TODO
	int result, result_modify;

	result = ~x|~y;
	result_modify = ~result;	// for output And operation, we should ~result.
	return result_modify;
}

/* logical_OR - implement the || operator
 *	Examples : logical_OR(1, 2) = 1, logical_OR(0, 0) = 0
 *	Legal ops : ~ & ^ | ! >> << 
 *	Max ops : 10
 *	Rating : 2
 */
int logical_OR(int x, int y) {
	//TODO
	int oper_or, result;
	
	oper_or = x|y;		// bit OR operation.
	result = !!oper_or;	// convert bit operation to logical OR operation.
	return result;
}

/* concatenate - bitwise concatenate two input x, y
 *  You can assume that x, y is consist of 8 bits, that is 0 <= x,y <= 255
 *	Examples : concatenate(2, 3) = (0000 0010) * (0000 0011) = (0000 0010 0000 0011) = 515
 *	Legal ops : ~ & | >> << + 
 *	Max ops : 10
 *	Rating : 2
 */
int concatenate(int x, int y) {
	//TODO
	int shift_x, result;

	shift_x = x<<8;		// shift x to right by 8bts
	result = shift_x|y;	// merge shift_x and y with OR operation
	return result;	
}

/* 
 * isMult4 - return 1 if n is multiple of 4, else 0
 *   You can assume that 1 < n
 *   Examples: isMult4(1024) = 1, isMult4(1025) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: N/A
 */
int isMult4(int x) {
	//TODO
	int restOf, restOfx, isThereRest, result;

	restOf = (1<<2)+(~0); 		// for make 000..00100
	restOfx = x&restOf;		// restOfn means n%4
	isThereRest = restOfx&3;	// if there is a rest, rest; else, 0;
	result = !isThereRest;		// if there is a rest, 0; else, 1;
	return result;
}
