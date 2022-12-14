#ifndef GAME_H
#define GAME_H

#include "Fruit.h"
#include "InputManager.h"
#include "Map.h"
#include "Snake.h"
#include "StateManager.h"
#include "UIHandler.h"

class Game
{
private:
	int m_gameSpeed;

	int m_gameScore;

	Fruit m_fruit;

	Snake m_snake;

	UIHandler m_uiHandler;

	InputManager m_inputManager;

	StateManager m_stateManager;

	bool m_isRunning;

	Map m_map;

public:
	Game();

	//-------------------------------------------------------
	//	Function	:	run
	//	Purpose		:	Main game loop, update, render, and derender functions go here
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void run();

	//-------------------------------------------------------
	//	Function	:	update
	//	Purpose		:	Updates game logic, any object that needs to update is placed here
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void update();

	//-------------------------------------------------------
	//	Function	:	render
	//	Purpose		:	Renders the game objects
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void render();

	//-------------------------------------------------------
	//	Function	:	derender
	//	Purpose		:	Derenders the game objects to allow them to be re-rendered after update
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void derender();

	//-------------------------------------------------------
	//	Function	:	updateGameSpeed
	//	Purpose		:	Controls the game speed based on the current score
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void updateGameSpeed();
};

#endif // End of '#ifndef SNAKE_H'