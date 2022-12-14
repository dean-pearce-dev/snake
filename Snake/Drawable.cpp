#include "Drawable.h"

Drawable::Drawable()
	: m_char( 'd' )
	, m_pos( 0, 0 )
{
};

void Drawable::render()
{
	Rendering::drawChar( m_char, m_pos.getX(), m_pos.getY() );
}

void Drawable::derender()
{
	Rendering::drawChar( ' ', m_pos.getX(), m_pos.getY());
}

int Drawable::getXPos()
{
	return m_pos.getX();
}

void Drawable::setXPos( const int x )
{
	m_pos.setX( x );
}

int Drawable::getYPos()
{
	return m_pos.getY();
}

void Drawable::setYPos( const int y )
{
	m_pos.setY( y );
}

Vector2& Drawable::getPos()
{
	return m_pos;
}

void Drawable::setPos( const Vector2& position )
{
	m_pos.setX( position.getX() );
	m_pos.setY( position.getY() );
}

void Drawable::setPosByInt( const int x, const int y )
{
	m_pos.setByInt( x, y );
}

void Drawable::setChar( const char character )
{
	m_char = character;
}