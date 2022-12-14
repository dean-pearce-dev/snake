#include "Helpers.h"
#include "InputManager.h"
#include "SnakeHead.h"
#include "StateManager.h"
#include "Windows.h"

InputManager::InputManager()
	: m_waitForInput	( true )
	, m_pSnakeHead		( nullptr )
{

};

InputManager::InputManager( SnakeHead& snakeHead)
	: m_waitForInput( true )
	, m_pSnakeHead( &snakeHead )
{

};

void InputManager::takeInput( StateManager& stateManager )
{
	//Using switch for the game state to determine what the input should do
	switch( stateManager.getState() )
	{
	//Menu screen
	case GameState::Start:
	{
		//Using m_waitForInput to effectively pause the code until the player presses the input
		//Once input is taken, m_waitForInput is set to false, and the while loop is exited
		while( m_waitForInput )
		{
			//Space bar input, starts the game
			if( Input::checkButton( VK_SPACE ) )
			{
				stateManager.setState( GameState::Game );
				m_waitForInput = false;
			}

			//Escape input, quits the game
			if( Input::checkButton( VK_ESCAPE ) )
			{
				stateManager.setState( GameState::End );
				m_waitForInput = false;
			}
		}
	}
	break;
	//Main game loop
	case GameState::Game:
	{
		//Taking in input and setting direction to the reference of the snake head
		//If snake is travelling in the opposite direction of the input, the input is ignored

		//Up
		if( Input::checkButton( 'w' ) )
		{
			if( m_pSnakeHead->getDirection() != Direction::Down )
			{
				m_pSnakeHead->setDirection( Direction::Up );
			}
		}

		//Down
		if( Input::checkButton( 's' ) )
		{
			if( m_pSnakeHead->getDirection() != Direction::Up )
			{
				m_pSnakeHead->setDirection( Direction::Down );
			}
		}

		//Left
		if( Input::checkButton( 'a' ) )
		{
			if( m_pSnakeHead->getDirection() != Direction::Right )
			{
				m_pSnakeHead->setDirection( Direction::Left );
			}
		}

		//Right
		if( Input::checkButton( 'd' ) )
		{
			if( m_pSnakeHead->getDirection() != Direction::Left )
			{
				m_pSnakeHead->setDirection( Direction::Right );
			}
		}

		//Pause
		if( Input::checkButton( 'p' ) )
		{
			//Set state to pause the game
			stateManager.setState( GameState::Pause );			
		}

		//Quit
		if( Input::checkButton( VK_ESCAPE ) )
		{
			//Set state to quit the game
			stateManager.setState( GameState::End );
		}
	}
	break;
	//Pause State
	case GameState::Pause:
	{
		//Using wait for input again to effectively pause the game
		m_waitForInput = true;

		while( m_waitForInput )
		{
			//Unpause
			if( Input::checkButton( VK_SPACE ) )
			{
				//Set state to unpause the game
				stateManager.setState( GameState::Game );
				m_waitForInput = false;
			}

			//Quit
			if( Input::checkButton( VK_ESCAPE ) )
			{
				//Set state to quit the game
				stateManager.setState( GameState::End );
				m_waitForInput = false;
			}
		}
	}
	break;
	//Game over screen
	case GameState::GameOver:
	{
		m_waitForInput = true;

		//m_waitForInput to pause the code again, then gives player choice the restart or quit
		while( m_waitForInput )
		{
			if( Input::checkButton( 'r' ) )
			{
				//Set state to restart the game
				stateManager.setState( GameState::Restart );
				m_waitForInput = false;
			}
			else if( Input::checkButton( VK_ESCAPE ) )
			{
				//Set state to quit the game
				stateManager.setState( GameState::End );
				m_waitForInput = false;
			}
		}
	}
	break;
	}
}