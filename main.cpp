#include <stdio.h>
#include <stdlib.h>

// http://www.obelisk.me.uk/6502/
/*
https://www.youtube.com/watch?v=qJgsuQoy9bc&list=PLLwK93hM93Z13TRzPx9JqTIn33feefl37
*/

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct Mem
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise()
    {
        for (u32 i = 0; i < MAX_MEM; i++)
        {
            Data[i] = 0;
        }
    }
};

struct CPU
{

    Word PC; // program counter
    Word SP; // stack pointer

    // registers
    Byte A;
    Byte X;
    Byte Y;

    // status flags
    Byte C : 1;
    Byte Z : 1;
    Byte I : 1;
    Byte D : 1;
    Byte B : 1;
    Byte V : 1;
    Byte N : 1;

    void Reset(Mem &memory)
    {
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;
        memory.Initialise();
    }
};

int main()
{
    Mem mem;
    CPU cpu;
    cpu.Reset(mem);
    return 0;
}
