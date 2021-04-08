#include "UndoRedo.h"

void UndoRedo::Execute() {
	board->SetTile(tileIndex, number);
}

void UndoRedo::Undo() {
	board->SetTile(tileIndex, '.');
}

//4210191015 - Vivian Azalia A