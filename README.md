# Project MIPS
Emulator of a MIPS processor
## Goals
As part of our study I will with a classmate create an emulator of a 32 bits MIPS processor.
All the code is written in C
## Instruction list implemented 
Instruction | Format
------------|--------
Add Word| ADD rd, rs, rt
Add Immediate Word | ADDI rt, rs, immediate
And | AND rd, rs, rt
Branch on Equal| BEQ rs, rt, offset
Branch on Greater Than Zero|BGTZ rs, offset
Branch on Less Than or Equal to Zero|BLEZ rs, offset
Branch on Not Equal|BNE rs, rt, offset
Divide Word|DIV rs, rt
Jump| J target
Jump and Link|JAL target
Jump Register|JR rs
Load Upper Immediate|LUI rt, immediate
Load Word|LW rt, offset(base)
Move From HI Register|MFHI rd
Move From LO Register|MFLO rd
Multiply Word|MULT rs, rt
No Operation|NOP
Or|OR rd, rs, rt
Rotate Word Right|ROTR rd, rt, sa
Shift Word Left Logical|SLL rd, rt, sa
Set on Less Than|SLT rd, rs, rt
Shift Word Right Logical|SRL rd, rt, sa
Subtract Word|SUB rd, rs, rt
Store Word|SW rt, offset(base)
System Call|SYSCALL
Exclusive OR|XOR rd, rs, rt
