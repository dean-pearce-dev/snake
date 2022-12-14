#include "Config.h"
#include "Helpers.h"
#include "Map.h"

Map::Map()
	: m_height		( Config::k_mapHeight )
	, m_width		( Config::k_mapWidth )
	, m_borderChar	( '*' )
{
};

void Map::render()
{
	//Using for loop to render the border, and ignore the spaces inbetween
	for( int i = 0; i <= m_height; i++ )
	{
		for( int j = 0; j <= m_width; j++ )
		{
			//If any of these are true, then the current position is a border piece
			if( i == 0 || i == m_height || j == 0 || j == m_width )
			{
				Rendering::drawChar( m_borderChar, j, i );
			}
		}
	}
}

int Map::getHeight()
{
	return m_height;
}

void Map::setHeight( const int height )
{
	m_height = height;
}

int Map::getWidth()
{
	return m_width;
}

void Map::setWidth( const int width)
{
	m_width = width;
}