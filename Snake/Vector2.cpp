#include "Vector2.h"

Vector2::Vector2()
	: m_xPos( 0 )
	, m_yPos( 0 )
{
};

Vector2::Vector2( const int x, const int y )
	: m_xPos( x )
	, m_yPos( y )
{
};

int Vector2::getX() const
{
	return m_xPos;
}

void Vector2::setX( int x )
{
	m_xPos = x;
}

int Vector2::getY() const
{
	return m_yPos;
}

void Vector2::setY( int y )
{
	m_yPos = y;
}

void Vector2::set( Vector2 positionToSet )
{
	m_xPos = positionToSet.getX();
	m_yPos = positionToSet.getY();
}

void Vector2::setByInt( int x, int y )
{
	m_xPos = x;
	m_yPos = y;
}