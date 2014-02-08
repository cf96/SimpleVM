#include "stdafx.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
#define elif else if
using namespace std;

std::array<std::string, 11> instructionsList = { "push", "pop", "popr", "add", "mul", "pushx", "jump", "prnt", "setctr", "loop", "sub" };

Stack CallStack;
std::vector<Command> CommandList;

int GetInstructionIndex(const char *instruc){
	for(size_t i = 0;i <= instructionsList.size();i++){
		if(instructionsList[i] == instruc)
			return i;
	}
	return 0;
}


void readfile(const std::string &filepath,std::string &buffer){
    std::ifstream fin(filepath.c_str());
    getline(fin, buffer, char(-1));
    fin.close();
}

vector<string> split(const string& s, const string& delim,bool keep_empty) {
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}

#pragma optimize("", off)
Command * CompileStringCommand(const char *strCmd){
	Command *command = new Command();
	std::string cmdString = strCmd;
	cmdString.erase(remove_if(cmdString.begin(), cmdString.end(), isspace), cmdString.end());
	size_t commaCount = std::count(cmdString.begin(), cmdString.end(), ',');
	const vector<string> instruction = split(cmdString, ",");
	command->instruction = GetInstructionIndex(instruction[0].c_str());
	switch(commaCount){
		/////////////////////////////////////////////////
	case 0:{
				break; // NO OTHER PARAMS, CAN BREAK AND RETURN
		   }
		/////////////////////////////////////////////////
	case 1:
			{
				command->value = atoi(instruction[1].c_str());
				command->instruction = GetInstructionIndex(instruction[0].c_str());
				break;
			}
	case 2:
		{
				command->value = atoi(instruction[1].c_str());
				command->ext = (atoi(instruction[2].c_str()));
				break;
		}
		break;
	}
	return command;
}
extern int numCmds;
void ExecuteInstructions(){
	if(CallStack.ci > numCmds)
		printf("Execution completed");
	else
	{
		Command cmd = CommandList[CallStack.ci];
		if(cmd.instruction == push)
				_push(cmd.value);
		elif(cmd.instruction == pop)
				_pop(cmd.value);
		elif(cmd.instruction == popr)
				_popr(cmd.value);
		elif(cmd.instruction == add)
				_add(cmd.value);
		elif(cmd.instruction == mul)
				_mul(cmd.value);
		elif(cmd.instruction == pushx)
				_pushx(cmd.value, cmd.ext);
		elif(cmd.instruction == jump)
				_jump(cmd.value);
		elif(cmd.instruction == prnt)
				_prnt();
		elif(cmd.instruction == setctr)
				_setctr(cmd.value);
		elif(cmd.instruction == loop)
				_loop(cmd.value);
		CallStack.ci++;
		ExecuteInstructions();
	}
}