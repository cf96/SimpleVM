// SimpleVM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
#define elif else if
using namespace std;
extern std::vector<Command> CommandList;
extern Stack CallStack;

extern int numCmds;
#pragma optimize("", off)
int numCmds = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	printf("Please drop a .cj file into the program!\n");
	char *filePath = (char*)malloc(100);
	scanf_s("%s", filePath);
	//FILE *file;
	//file = fopen(filePath, "r");
	std::string code;
	readfile(filePath, code);
	const char *codeBuffer = code.c_str();
	char *cmd = strtok((char*)codeBuffer, "\n");
	while(cmd != NULL){
		Command *cmdExec = CompileStringCommand(cmd);
		CommandList.push_back((Command)*cmdExec);
		cmd = strtok (NULL, "\n");
		numCmds++;
	}
	ExecuteInstructions();
	scanf("%s");
	return 0;
}

