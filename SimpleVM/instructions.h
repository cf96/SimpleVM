#include "stdafx.h"

#pragma once

void _push(int val);
void _pop(int reg);
void _popr(int reg);
void _add(int stackOrReg);
void _mul(int stackOrReg);
void _pushx(int val, int multiplier);
void _jump(int line);
void _prnt();
void _setctr(int ct);
void _loop(int line);
void _sub(int regOrStack);
/*
enum instructions
{
	push, //pushes number to first 4 bytes of stack -> push,48 pushes the value 48 to 
	pop, //pushes number at top of stack to specified register -> pop,1
	popr, //pushes number from register(x) to top of stack -> popr,3
	add, //adds register 1 and register 2 and stores result in r3 or top of stack (0 for r3, 1 for stack)-> add,1
	mul, //multiplies register 1 and 2 and stores result in r3 or top of stack (0 for r3, 1 for stack -> mul,1
	pushx, //stores integer value at specified part of stack (0 for 1, 1 for 2, 2 for 3, 3 for 4) -> pushx,203,2  //stores the value 203 at stack[0x4*2]
	jump, //jumps to instruction # -> jump,12 -> jumps to the 12th instruction
	prnt, //prints the value at the top of the stack -> prnt
	setctr, //sets the counter register -> setctr,4
	loop, //similar to jump but only jumps if the counter register is != 0 -> loop,3 !!!Don't create an infinite loop!
};
*/
