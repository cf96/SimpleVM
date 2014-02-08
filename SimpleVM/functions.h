#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include "instructions.h"
//BEGIN USER DEFINED VARS
#pragma once
using namespace std;

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
	loop,
	sub//similar to jump but only jumps if the counter register is != 0 -> loop,3 !!!Don't create an infinite loop!
};

struct Command{
	BYTE instruction;
	DWORD value;
	DWORD ext;
};

struct Stack{
	BYTE stack[16];
	array<DWORD, 3> registers;
	DWORD eqr;
	DWORD ctr;
	DWORD ci;
};

int GetInstructionIndex(const char *instruc);
void readfile(const std::string &filepath,std::string &buffer);
vector<string> split(const string& s, const string& delim, const bool keep_empty = true);
Command * CompileStringCommand(const char *strCmd);
void ExecuteInstructions();