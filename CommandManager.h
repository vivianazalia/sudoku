#pragma once
#include<stack>
#include"ICommand.h"

using namespace std;

class CommandManager
{
private:
	stack<ICommand*> undoStack;
	stack<ICommand*> redoStack;
public:
	void ExecuteCommand(ICommand* c) {
		c->Execute();
		undoStack.push(c);
	}

	void UndoCommand(ICommand* c) {
		if (undoStack.size() <= 0)
		{
			return;
		}

		undoStack.top()->Undo();
		undoStack.pop();
	}
};

