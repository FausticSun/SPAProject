#pragma once

#include<stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
typedef short PROC;

class TNode;

class VarTable {  // no need to #include "VarTable.h" as all I need is pointer
public:
	VarTable();
	int add(string s);
	bool contains(string s);
	unordered_set<string> getVarList();
 	string toString();

private:
	unordered_set<string> varList;
	int numOfVars;
};

class ProcTable {
public:
	ProcTable();
	int add(string s);
	bool contains(string s);
	unordered_set<string> getProcList();
	string toString();

private:
	unordered_set<string> procList;
	int numOfProcs;
};

class PKB {
public:
	static VarTable* varTable; 
	static ProcTable* procTable;
	static int setProcToAST(PROC p, TNode* r);
	static TNode* getRootAST (PROC p);

};