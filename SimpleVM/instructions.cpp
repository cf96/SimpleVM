#include "instructions.h"
#include "functions.h"
#include "stdafx.h"

extern Stack CallStack;

void _push(int val){
	*(int*)CallStack.stack = val;
}

void _pop(int reg){
	int num = *(int*)CallStack.stack;
	CallStack.registers[reg] = (DWORD)num;
}

void _popr(int reg){
	*(int*)CallStack.stack = (int)CallStack.registers[reg];

}

void _add(int regOrStack){
	switch(regOrStack){
	case 0: //store on stack
		{
			CallStack.registers[2] = CallStack.registers[0] + CallStack.registers[1];
			break;
		}
	case 1: //store in register3
		{
			*(DWORD*)CallStack.stack = CallStack.registers[0] + CallStack.registers[1];
			break;
		}
	}
}

void _mul(int regOrStack){
	switch(regOrStack){
	case 0: //store on stack
		{
			CallStack.registers[2] = CallStack.registers[0] * CallStack.registers[1];
			break;
		}
	case 1: //store in register3
		{
			*(DWORD*)CallStack.stack = CallStack.registers[0] * CallStack.registers[1];
			break;
		}
	}
}

void _sub(int regOrStack){
	switch(regOrStack){
	case 0: //store on stack
		{
			CallStack.registers[2] = CallStack.registers[0] - CallStack.registers[1];
			break;
		}
	case 1: //store in register3
		{
			*(DWORD*)CallStack.stack = CallStack.registers[0] - CallStack.registers[1];
			break;
		}
	}
}

void _pushx(int val, int multiplier){
	memcpy((void*)(&CallStack.stack + 4*multiplier), (void*)val, sizeof(val));
}

void _jump(int line){
	CallStack.ci = line - 1;
}

void _prnt(){
	printf("\n\nStack:\n%i \n%i \n%i \n%i\nR1: %i\nR2: %i\nR3: %i\n\n",*(int*)(CallStack.stack),*(int*)(CallStack.stack+4),*(int*)(CallStack.stack+8),
		*(int*)(CallStack.stack+12),CallStack.registers[0],CallStack.registers[1],CallStack.registers[2]);
}

void _setctr(int ct){
	CallStack.ctr = ct;
}

void _loop(int ln){
	if(CallStack.ctr != 0){
		CallStack.ctr--;
		_jump(ln);
	}
}