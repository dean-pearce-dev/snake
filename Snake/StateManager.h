#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "GameState.h"

class StateManager
{
private:
	GameState m_currentState;
	
public:
	StateManager();

	//-------------------------------------------------------
	//	Function	:	getState
	//	Purpose		:	Returns the current game state
	//	Parameters  :	none
	//	Returns		:	GameState&
	//-------------------------------------------------------
	GameState getState();

	//-------------------------------------------------------
	//	Function	:	setState
	//	Purpose		:	Sets the current game state by parameter
	//	Parameters  :	const GameState& stateToSet
	//	Returns		:	void
	//-------------------------------------------------------
	void setState( const GameState stateToSet );

};

#endif // End of '#ifndef STATEMANAGER_H'
