#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

class SnakeHead;
class StateManager;

class InputManager
{
private:
	bool m_waitForInput;

	SnakeHead* m_pSnakeHead;

public:
	InputManager();
	InputManager( SnakeHead& snakeHead );

	//-------------------------------------------------------
	//	Function	:	takeInput
	//	Purpose		:	Takes in input, uses state manager reference to get the current state of the game
	//	Parameters  :	StateManager& stateManager
	//	Returns		:	void
	//-------------------------------------------------------
	void takeInput( StateManager& stateManager );
};

#endif // End of '#ifndef INPUTMANAGER_H'