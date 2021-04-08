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
	void ExecuteCommand(ICommand* c) {
		ClearRedoStack();
		c->Execute();
		undoStack.push(c);
	}

	void UndoCommand() {
		if (undoStack.empty())
		{
			return;
		}

		undoStack.top()->Undo();
		redoStack.push(undoStack.top());
		undoStack.pop();
	}

	void RedoCommand() {
		if (redoStack.empty())
		{
			return;
		}

		redoStack.top()->Execute();
		undoStack.push(redoStack.top());
		redoStack.pop();
	}

	void ClearRedoStack() {
		while (!redoStack.empty())
		{
			redoStack.pop();
		}
	}
};

