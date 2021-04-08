#pragma once
#include<stack>
#include<iostream>
#include"ICommand.h"

using namespace std;

class CommandManager
{
private:
	stack<ICommand*> undoStack;
	stack<ICommand*> redoStack;
public:
	void ExecuteCommand(ICommand* c);
	void UndoCommand();
	void RedoCommand();
	void ClearRedoStack();
};

