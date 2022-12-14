#include "Config.h"
#include "SnakeTail.h"
#include "SnakeSegment.h"
#include "Vector2.h"

SnakeTail::SnakeTail()
	: m_totalSegments	( 0 )
	, m_pHeadPos		( nullptr )
{
	//Using Config to setup the array size based on the playable spaces
	m_pTailArray = new SnakeSegment[ Config::calcPlayableSpace() ];
};

SnakeTail::SnakeTail( Vector2& headPos )
	: m_totalSegments	( 0 )
	, m_pHeadPos		( &headPos )
{
	//Using Config to setup the array size based on the playable spaces
	m_pTailArray = new SnakeSegment[ Config::calcPlayableSpace() ];
};

SnakeTail::~SnakeTail()
{
	//Deleting the pointer array for the tail
	delete[] m_pTailArray;
}

void SnakeTail::update()
{
	//Using a for loop in reverse order to move the tail segments back to front
	for( int i = m_totalSegments; i >= 0; i-- )
	{
		//If i == 0, that means the next position to move should be the head position
		//Then the head will move after
		if( i == 0 )
		{
			m_pTailArray[i].setPos( *m_pHeadPos );
		}
		//Moves the tail segment to the position of the one preceding it
		else
		{
			m_pTailArray[i].setPos( m_pTailArray[i - 1].getPos() );
		}
	}
}

void SnakeTail::render()
{
	//Renders each segment via for loop
	for( int i = 0; i < m_totalSegments; i++ )
	{
		m_pTailArray[i].render();
	}
}

void SnakeTail::derender()
{
	//Derenders each segment via for loop
	for( int i = 0; i < m_totalSegments; i++ )
	{
		m_pTailArray[i].derender();
	}
}

void SnakeTail::addSegment()
{
	m_totalSegments++;
}

int& SnakeTail::getLength()
{
	return m_totalSegments;
}

void SnakeTail::setLength( const int lengthToSet )
{
	m_totalSegments = lengthToSet;
}

SnakeSegment& SnakeTail::getSegmentByIndex( const int indexOfTailSegment )
{
	return m_pTailArray[indexOfTailSegment];
}