#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <iostream>

class StateManager;

class UIHandler
{
private:
	int m_borderWidth;
	int m_borderHeight;

	std::string m_welcomeString;
	std::string m_inputString;
	std::string m_secondInputString;
	std::string m_beginString;

	std::string m_gameOverString;
	std::string m_restartOrExitString;

	std::string m_pauseString;
	std::string m_scoreString;
	std::string m_endScoreString;

	StateManager* m_pStateManager;

public:
	UIHandler();
	UIHandler( StateManager& stateManager );

	//-------------------------------------------------------
	//	Function	:	render
	//	Purpose		:	Draws the current menu screen by switch case
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void render();

	//-------------------------------------------------------
	//	Function	:	derender
	//	Purpose		:	Uses a for loop to clear the playable area without touching the map border
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void derender();

	//-------------------------------------------------------
	//	Function	:	drawScoreString
	//	Purpose		:	Displays the current score as a string underneath the map border
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void drawScoreString();

	//-------------------------------------------------------
	//	Function	:	drawPauseString
	//	Purpose		:	Displays the pause string underneath the map border when paused
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void drawPauseString();

	//-------------------------------------------------------
	//	Function	:	undrawPauseString
	//	Purpose		:	Removes the pause string underneath the map border when paused
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void undrawPauseString();

	//-------------------------------------------------------
	//	Function	:	setScoreString
	//	Purpose		:	Sets the string to display the current score correctly
	//	Parameters  :	int& scoreToSet
	//	Returns		:	void
	//-------------------------------------------------------
	void setScoreString( int scoreToSet );

	//-------------------------------------------------------
	//	Function	:	setEndScoreString
	//	Purpose		:	Sets the string to display the score for the game over screen
	//	Parameters  :	int& scoreToSet
	//	Returns		:	void
	//-------------------------------------------------------
	void setEndScoreString( int scoreToSet );

};

#endif // End of '#ifndef UIHANDLER_H'
