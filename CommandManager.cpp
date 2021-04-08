#include "CommandManager.h"

void CommandManager::ExecuteCommand(ICommand* c) {
	ClearRedoStack();
	c->Execute();
	undoStack.push(c);
}

void CommandManager::UndoCommand() {
	if (undoStack.empty())
	{
		return;
	}

	undoStack.top()->Undo();
	redoStack.push(undoStack.top());
	undoStack.pop();
}

void CommandManager::RedoCommand() {
	if (redoStack.empty())
	{
		return;
	}

	redoStack.top()->Execute();
	undoStack.push(redoStack.top());
	redoStack.pop();
}

void CommandManager::ClearRedoStack() {
	while (!redoStack.empty())
	{
		redoStack.pop();
	}
}

//4210191015 - Vivian Azalia A