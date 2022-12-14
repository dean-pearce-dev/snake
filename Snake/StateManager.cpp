#include "StateManager.h"

StateManager::StateManager()
	: m_currentState ( GameState::Start )
{

};

GameState StateManager::getState()
{
	return m_currentState;
}

void StateManager::setState( const GameState stateToSet )
{
	m_currentState = stateToSet;
}