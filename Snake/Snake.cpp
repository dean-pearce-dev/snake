#include "Config.h"
#include "Snake.h"
#include "Fruit.h"

Snake::Snake()
	: m_bounds		( Config::k_mapWidth, Config::k_mapHeight )
	, m_isAlive		( true )
	, m_tail		( m_head.getPos() )
	, m_pFruit		( nullptr )
	, m_pGameScore	( nullptr )
{
	m_head.setXPos( Config::k_mapWidth >> 1 );
	m_head.setYPos( Config::k_mapHeight >> 1 );
};

Snake::Snake( Fruit& fruit, int& gameScore )
	: m_bounds		( Config::k_mapWidth, Config::k_mapHeight )
	, m_isAlive		( true )
	, m_tail		( m_head.getPos() )
	, m_pFruit		( &fruit )
	, m_pGameScore	( &gameScore )
{
	m_head.setXPos( Config::k_mapWidth >> 1 );
	m_head.setYPos( Config::k_mapHeight >> 1 );
};

Snake::~Snake()
{
}

void Snake::update()
{
	//Moving the snake back to front
	//Eliminates need for a previous position variable
	m_tail.update();

	//Moving the head
	m_head.move();

	//Collision detections
	checkForCollision();
	checkForFruit();
}

void Snake::render()
{
	m_head.render();
	m_tail.render();
}

void Snake::derender()
{
	m_head.derender();
	m_tail.derender();
}

void Snake::reset()
{
	//Setting the neccessary values to reset the game correctly

	//Tail back to 0
	m_tail.setLength( 0 );

	//Snake head back to center
	m_head.setXPos( m_bounds.getX() >> 1 );
	m_head.setYPos( m_bounds.getY() >> 1 );

	//Resetting fruit, then checking it's not touching the snake
	m_pFruit->changePos();
	initialCheckForFruit();

	//Resetting the head direction
	m_head.setDirection( Direction::Right );

	//Setting the snake back to alive
	m_isAlive = true;
}

bool Snake::isAlive()
{
	return m_isAlive;
}

void Snake::setBounds( const int x, const int y )
{
	m_bounds.setByInt( x, y );
}

void Snake::checkForCollision()
{
	//Checking if the snake is within the bounds, then checking if the head is touching a tail segment
	if( m_head.getXPos() >= m_bounds.getX() || m_head.getYPos() >= m_bounds.getY() || m_head.getXPos() <= 0 || m_head.getYPos() <= 0 || headCollisionCheck() )
	{
		m_isAlive = false;
	}	
}

void Snake::checkForFruit()
{
	//Checking Vector2 using operator overload
	if( m_head.getPos() == m_pFruit->getPos() )
	{
		//Adds tail segment, then changes the fruit pos
		m_tail.addSegment();
		m_pFruit->changePos();

		//Fruit spawn detection
		//Makes sure fruit can't spawn on a snake segment
		for( int i = 0; i < getTailLength(); i++ )
		{
			if( getTailPosByIndex( i ) == m_pFruit->getPos() || m_head.getPos() == m_pFruit->getPos() )
			{
				m_pFruit->changePos();
				i = 0;
			}
		}
		//Increment game score
		(*m_pGameScore)++;
	}
}

void Snake::initialCheckForFruit()
{
	for( int i = 0; i < getTailLength(); i++ )
	{
		//Checking each snake segment position with a for loop to ensure the fruit doesn't start on a snake segment
		if( getTailPosByIndex( i ) == m_pFruit->getPos() || m_head.getPos() == m_pFruit->getPos() )
		{
			//If the fruit is detected by a snake segment, the fruit position is changed, and the for loop is reset to 0
			m_pFruit->changePos();
			i = 0;
		}
	}
}

int& Snake::getTailLength()
{
	return m_tail.getLength();
}

Vector2 Snake::getTailPosByIndex( const int indexOfTailSegment )
{
	return m_tail.getSegmentByIndex( indexOfTailSegment ).getPos();
}

SnakeHead& Snake::getHead()
{
	return m_head;
}

bool Snake::headCollisionCheck()
{
	bool m_isTouchingHead = false;

	for( int i = 0; i < getTailLength(); i++ )
	{
		//Loops through the tail segments and checks their position against the head position
		//Function returns true if any are colliding
		if( getTailPosByIndex(i) == m_head.getPos() )
		{
			m_isTouchingHead = true;
		}
	}

	return m_isTouchingHead;
}