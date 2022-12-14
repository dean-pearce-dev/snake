#include <iostream>
#include <windows.h>

#include "Config.h"
#include "Game.h"
#include "Helpers.h"

Game::Game()
	: m_gameSpeed		( Config::k_defaultGameSpeed )
	, m_gameScore		( 0 )
	, m_fruit			()
	, m_snake			( m_fruit, m_gameScore )
	, m_uiHandler		( m_stateManager )
	, m_inputManager	( m_snake.getHead() )
	, m_isRunning		( true )
{
	//Resizing the console window, hiding the console cursor, then drawing the map
	Rendering::resizeWindow( Config::k_windowHeight, Config::k_windowWidth );
	Rendering::showConsoleCursor( false );
	m_map.render();
};

void Game::run()
{
	//Game loop, when player quits, m_isRunning is set to false, which will allow the application to close
	while( m_isRunning )
	{
		//Switch case for various game states
		switch( m_stateManager.getState() )
		{
			//Start Screen
			case GameState::Start:
			{
				//Menu handler render is based on game state, so this state will render the main menu screen
				m_uiHandler.render();

				//Input manager is also based on game state, here it will wait until the player presses space
				m_inputManager.takeInput( m_stateManager );

				//After player presses space, these functions are run to setup the game
				m_uiHandler.derender();
				m_snake.initialCheckForFruit();
				m_fruit.render();
				m_snake.render();
			}
			break;
			//Main Game Loop
			case GameState::Game:
			{
				//Using sleep to control the game speed
				Sleep( m_gameSpeed );

				//Derender to clear the screen for updating
				derender();

				//Updates the game objects, then renders them
				update();

				//Check for game over
				if( !m_snake.isAlive() )
				{
					//Derenders everything within the map border
					m_uiHandler.derender();

					//Rerendering the map border incase any were overwritten by the snake head colliding
					m_map.render();

					//Setting up the string to display for the game over screen, then changing the state
					m_uiHandler.setEndScoreString( m_gameScore );
					m_stateManager.setState( GameState::GameOver );

					//Break here to ignore the rest of this loop, since this means the snake has died, there is no point continuing this game state
					break;
				}

				//Render after alive check, prevents snake object over-rendering the map border
				render();
			}
			break;
			//Pause State
			case GameState::Pause:
			{
				//Draw a pause string in the bottom right corner under the map to let the player know they're paused
				m_uiHandler.drawPauseString();

				//Input manager waits here for the input to unpause or exit the game
				m_inputManager.takeInput( m_stateManager );

				//After unpausing, clears the pause string from the bottom right corner
				m_uiHandler.undrawPauseString();
			}
			break;
			//Game Over Screen
			case GameState::GameOver:
			{
				//Renders the screen based on game state
				m_uiHandler.render();

				//Waits here for input to restart or exit
				m_inputManager.takeInput( m_stateManager );
			}
			break;
			//Restart Logic
			case GameState::Restart:
			{
				//Resets all necessary objects and values to restart the game
				m_snake.reset();
				m_gameScore = 0;

				//Derenders then rerenders the objects
				m_uiHandler.derender();
				m_fruit.render();
				m_snake.render();

				//Once everything is ready, sets the state back to the main game loop
				m_stateManager.setState( GameState::Game );
			}
			break;
			//End state
			case GameState::End:
			{
				//Changes m_isRunning to false which will allow the code to exit the while loop and end the application
				m_isRunning = false;
			}
			break;
		}
	}
}

void Game::update()
{
	//Takes input, updates the snake, then updates the score
	m_inputManager.takeInput( m_stateManager );
	m_snake.update();
	updateGameSpeed();
	m_uiHandler.setScoreString( m_gameScore );
}

void Game::render()
{
	//Draw Snake
	m_snake.render();

	//Draws the score string
	m_uiHandler.drawScoreString();
}

void Game::derender()
{
	//Undraw Snake
	m_snake.derender();
}

void Game::updateGameSpeed()
{
	//Temp variable to use to modify the game speed
	int gameSpeedMultiplier = 1;

	//If the game score is less than what the score will be at max speed, then calculates what the speed should be
	if( m_gameScore < ( Config::k_scoreMilestone * Config::k_maxSpeedMultiplier ) )
	{
		//Game score divided by the milestone
		gameSpeedMultiplier = m_gameScore / Config::k_scoreMilestone;
	}
	else
	{
		//If game score is already higher than the score at max speed, then just sets it to max speed;
		gameSpeedMultiplier = Config::k_maxSpeedMultiplier;
	}
	//Multiplying the game speed increment by speed multiplier, then subtracting that from the game speed
	m_gameSpeed = Config::k_defaultGameSpeed - ( Config::k_gameSpeedIncrement * gameSpeedMultiplier );
}