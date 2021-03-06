/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // 异或就是相同为0不同为1
    // 与是同1则1 有0则0
    // 可以通过 取反的操作来获得
  return ~(x&y) & ~(~x&~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // 学过 CSAPP 的人都知道
    return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    int i = x+1; //1000
    x = x+i;  // 1111
    x = ~x; //0000
    i = !i;
    x = x+i;
    return !x;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   如果位编码的所有奇数位都为1 返回1 否则为0
 *   最低权重位规定为第0位 最高权重位 为第31位
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

int allOddBits(int x) {
    //
    int mask = 0xAA;
    mask = (mask<<8) + mask;
    mask = (mask<<16) + mask;
    // x&mask 用来屏蔽偶数位 使偶数为全部变成0
    // 然后在 ^mask 找出 奇数位 不同的 如果不同 结果就位真
    // 然后取反 就是结果
    return !((x&mask)^mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // 取反加一 EZ
    // Tmin 默认是例外的吗？
    return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // 如果 在这个区间内 x-0x30 和 0x39-x 的符号位都为正
    // 不给减号操作就用取反加一
    // down =  x-0x31 的符号位
    // up = 0x39-x 的符号位
    int down = ((x + (~0x30+1))) >>31;
    int up = ((0x39 + (~x+1))) >>31;
    return !(down | up);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int aFlag = (!x)+ (~0x1+1);
    int bFlag = ~aFlag;
    return (aFlag & y) | (bFlag & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int i = y + (~x+1);
    return !(i>>31);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    int xx = ~x ;
    int a = (xx>>31) & 0x1 ;
    int b = ((xx+1) >>31) & 0x1;
    return (a^b) & (a&0x1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int b16,b8,b4,b2,b1,b0;
    // 获取x的符号位 ，正为000...0000 负为111....1111
    int sign = x >>31;
    // x 为正则不变 ~（000....0000）& x => 111....1111 & x
    // x 为负则按位取反 111....1111 & (~x)
    x = (~sign&x) | (sign & ~x);

    // 为什么负数要按位取反？
    // 一个正数 要找到他最高位的1是第n位 结果就是 n 加上符号位 （n+1）
    // 一个负数 要找到他第一个出现0的最高位n 结果就是 n+符号位1
    // 例如 -3 11111...1111101 和 101 是等价的 0的位置在2 所以最少需要 n+1 位
    // 对于 负数取反得0000....000010  找出是1 的最高位 再加1 就是答案
    // 发现负数取反之后和正数的操作逻辑就会变得一样了 所以对负数取反 统一之后的逻辑

    // 取反再取反相当于 ！= 0
    b16 = (!!(x >>16))<<4;
    // 如果高16位有 就把低16位忽略
    // 如果高16位无 则 b16为 0 相当于没有操作
    x = x >>b16;
    b8 = (!!(x>>8))<<3;

    x = x >>b8;
    b4 = (!!(x>>4)) <<2;

    x = x>>b4;
    b2 = (!!(x>>2)) <<1;

    x = x >>b2;
    b1 = (!!(x>>1));

    x =x >>b1;
    b0 = x;

  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    // 先处理特殊值 正负无穷 NaN 均返回本身
    // 阶码
    int exp = (uf&0x7f800000)>>23;
    int sign = uf&(1<<31);
    // 阶码全为1  无穷 或者 NaN
    // 返回本身
    if (exp == 255) {
        return uf;
    }
    // 当阶码全为0的时候 在0~1 的范围内
    // 出看起来完全不符合逻辑
    // 但是你用草稿纸推一遍你就会发现这个的神奇之处
    if (exp == 0) {
        return (uf << 1) | sign;
    }

    // 规格化情况
    exp++;
    // 溢出 返回无穷
    if (exp==255) {
        return 0x7f800000|sign;
    }
    //清除原本uf的exp位 并且填入新的exp
    return (uf&0x807fffff) | (exp<<23);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    // 浮点数转为整数
    int sign = uf>>31;
    int E = ((uf & 0x7f800000)>>23)-127;
    // 获得尾数
    // 为什么要 | 0x00800000 规格化的表示 个位1是隐藏的 通过这个操作增补回去
    int frac = (uf&0x007fffff) | 0x00800000;

    // 值为0的情况
    if (!(uf&0x7ffffff)) {
        return 0;
    }

    // 因为int32 最多能表示 2^31-1 所以如果 1.xxx * 2^31  的时候直接溢出了
    // 按照要求返回 0x80000000u
    if (E >= 31) {
        return 0x80000000;
    }
    // 这里包含了几种情况
    // 1.非规格化的表示 0.xxx * 2 ^(1-127)
    // 2.规格化的表示 1.xxx * 2^i (i为负数)
    // 无论如何值都落在 0~1 内 转成 int 都是0
    if (E < 0) {
        return 0;
    }
    // 为什么要23判断一下
    // 因为小数点在第23位后面 frac 相当于小数点 向右移了23位
    // 所以这里要补回来
    if (E >23) frac = frac <<(E-23);
    else frac = frac >>(23-E);

    // 符号位和原来的浮点数相同
    if (!((frac >>31)^sign)) return frac;
    // 符号位和原来的不同
    else return ~frac+1;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    if (x < -150) {
        return 0;
    }

    if (x>=-150 && x <=-127) {
        int shift = -x-127;
        int frac = 1<< shift;
        return  frac;
    }

    if (x>=-127 && x<=127) {
        int exp = (x+127) <<23;
        return  exp;
    }

    if (x>=128) {
        int inf =0xff<<23;
        return inf;
    }
    return 0;
}
