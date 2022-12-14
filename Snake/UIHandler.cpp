#include <sstream>

#include "Config.h"
#include "Helpers.h"
#include "UIHandler.h"
#include "StateManager.h"

//Using constructors to setup the UI strings
UIHandler::UIHandler()
	: m_borderWidth			( Config::k_mapWidth )
	, m_borderHeight		( Config::k_mapHeight )
	, m_welcomeString		( "Welcome to Snake!" )
	, m_inputString			( "Use 'W' 'A' 'S' 'D' for movement." )
	, m_secondInputString	( "Press 'P' to pause and 'Space' to unpause. Press 'Esc' to quit." )
	, m_beginString			( "Press 'Space' to begin." )
	, m_gameOverString		( "Game Over!" )
	, m_restartOrExitString	( "Press 'R' to try again. Press 'Esc' to quit." )
	, m_pauseString			( "Paused" )
	, m_scoreString			( "Score: 0" )
	, m_endScoreString		( "You scored 0!" )
	, m_pStateManager		( nullptr )
{

};

UIHandler::UIHandler( StateManager& stateManager)
	: m_borderWidth( Config::k_mapWidth )
	, m_borderHeight( Config::k_mapHeight )
	, m_welcomeString( "Welcome to Snake!" )
	, m_inputString( "Use 'W' 'A' 'S' 'D' for movement." )
	, m_secondInputString( "Press 'P' to pause and 'Space' to unpause. Press 'Esc' to quit." )
	, m_beginString( "Press 'Space' to begin." )
	, m_gameOverString( "Game Over!" )
	, m_restartOrExitString( "Press 'R' to try again. Press 'Esc' to quit." )
	, m_pauseString( "Paused" )
	, m_scoreString( "Score: 0" )
	, m_endScoreString( "You scored 0!" )
	, m_pStateManager( &stateManager )
{

};

void UIHandler::render()
{
	switch( m_pStateManager->getState() )
	{
		//Strings to display on start screen
		case GameState::Start:
		{
			//Line 1
			Rendering::centerString( m_welcomeString.length(), m_borderWidth, ( m_borderHeight >> 1 ) - 4 );
			std::cout << m_welcomeString;
			//Line 2
			Rendering::centerString( m_inputString.length(), m_borderWidth, ( m_borderHeight >> 1 ) - 2 );
			std::cout << m_inputString;
			//Line 3
			Rendering::centerString( m_secondInputString.length(), m_borderWidth, ( m_borderHeight >> 1 ) );
			std::cout << m_secondInputString;
			//Line 4
			Rendering::centerString( m_beginString.length(), m_borderWidth, ( m_borderHeight >> 1 ) + 2 );
			std::cout << m_beginString;
		}
		break;
		//Strings to display on game over screen
		case GameState::GameOver:
		{
			//Line 1
			Rendering::centerString( m_gameOverString.length(), m_borderWidth, ( m_borderHeight >> 1 ) - 2 );
			std::cout << m_gameOverString;
			//Line 2
			Rendering::centerString( m_endScoreString.length(), m_borderWidth, ( m_borderHeight >> 1 ) );
			std::cout << m_endScoreString;
			//Line 3
			Rendering::centerString( m_restartOrExitString.length(), m_borderWidth, ( m_borderHeight >> 1 ) + 2);
			std::cout << m_restartOrExitString;
		}
		break;
	}
}

void UIHandler::derender()
{
	for( int i = 0; i < m_borderHeight; i++ )
	{
		for( int j = 0; j < m_borderWidth; j++ )
		{
			//Similar to the map render, but the opposite way, so that the space within the border can be cleared
			//See Map.render() for reference
			if( i != 0 && i != m_borderHeight && j != 0 && j != m_borderWidth )
			Rendering::drawChar( ' ', j, i );
		}
	}

	//Clears anything underneath the map border, as strings are used there for the UI
	for( int i = 0; i < m_borderWidth; i++ )
	{
		Rendering::drawChar( ' ', i, m_borderHeight + 1 );
	}
}

void UIHandler::drawScoreString()
{
	//Drawing the score string underneath the map border
	Rendering::gotoXY( 0, m_borderHeight + 1 );
	std::cout << m_scoreString;
}

void UIHandler::drawPauseString()
{
	//Drawing the pause string underneath the bottom right of the map border
	//Used to let the player know the game is paused
	Rendering::gotoXY( m_borderWidth - m_pauseString.length(), m_borderHeight + 1 );
	std::cout << m_pauseString;
}
void UIHandler::undrawPauseString()
{
	//Clearing the pause string underneath the bottom right of the map border
	//Used when unpausing the game
	Rendering::gotoXY( m_borderWidth - m_pauseString.length(), m_borderHeight + 1 );

	//int i needs to be unsigned to match m_pauseString.length() type
	for( unsigned int i = 0; i < m_pauseString.length(); i++ )
	{
		Rendering::drawChar( ' ', ( m_borderWidth - 1 ) - i, m_borderHeight + 1 );
	}
}

void UIHandler::setScoreString( int scoreToSet )
{
	//Using <sstream> to append an int to the score string so it can be displayed correctly
	std::stringstream stringStream;
	stringStream << "Score: " << scoreToSet;
	m_scoreString = stringStream.str();
}

void UIHandler::setEndScoreString( int scoreToSet )
{
	//Using <sstream> to append an int to the end score string so it can be displayed correctly
	std::stringstream stringStream;
	stringStream << "You scored " << scoreToSet << '!';
	m_endScoreString = stringStream.str();
}