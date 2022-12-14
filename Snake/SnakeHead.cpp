#include <conio.h>

#include "SnakeHead.h"

SnakeHead::SnakeHead()
	: SnakeSegment()
	, m_direction( Direction::Right )
{
	//Setting char of the snake head
	setChar( 'z' );
};

void SnakeHead::move()
{

	switch( m_direction )
	{
	//Up
	case Direction::Up:
	{
		setYPos( getYPos() - 1 );
	}
	break;

	//Down
	case Direction::Down:
	{
		setYPos( getYPos() + 1 );
	}
	break;

	//Left
	case Direction::Left:
	{
		setXPos( getXPos() - 1 );
	}
	break;

	//Right
	case Direction::Right:
	{
		setXPos( getXPos() + 1 );
	}
	break;

	default:
		break;
	}
}

Direction SnakeHead::getDirection()
{
	return m_direction;
}

void SnakeHead::setDirection( Direction direction )
{
	m_direction = direction;
}