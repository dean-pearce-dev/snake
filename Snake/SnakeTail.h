#ifndef SNAKETAIL_H
#define SNAKETAIL_H

//#include "SnakeHead.h"

class SnakeSegment;
class Vector2;

class SnakeTail
{
private:
	SnakeSegment* m_pTailArray = nullptr;
	int m_totalSegments;
	Vector2* m_pHeadPos;

public:
	SnakeTail();
	SnakeTail( Vector2& headPos );

	~SnakeTail();


	//-------------------------------------------------------
	//	Function	:   update
	//	Purpose		:   Updates the whole SnakeTail object
	//	Parameters  :   none
	//	Returns		:   void
	//-------------------------------------------------------
	void update();

	//-------------------------------------------------------
	//	Function	:   render
	//	Purpose		:   Renders each segment of the SnakeTail object based on their position
	//	Parameters  :   none
	//	Returns		:   void
	//-------------------------------------------------------
	void render();

	//-------------------------------------------------------
	//	Function	:   derender
	//	Purpose		:   Derenders each segment of the SnakeTail object so that they can
	//					be redrawn at different positions
	//	Parameters  :   none
	//	Returns		:   void
	//-------------------------------------------------------
	void derender();

	//-------------------------------------------------------
	//	Function	:	addSegment
	//	Purpose		:   Increases the number of tail segments by 1
	//	Parameters  :   none
	//	Returns		:   void
	//-------------------------------------------------------
	void addSegment();

	//-------------------------------------------------------
	//	Function	:   getLength
	//	Purpose		:   Returns the total length of the tail
	//	Parameters  :   none
	//	Returns		:   int&
	//-------------------------------------------------------
	int& getLength();

	//-------------------------------------------------------
	//	Function	:   setLength
	//	Purpose		:   Sets the length of the tail
	//	Parameters  :   const int& lengthToSet
	//	Returns		:   void
	//-------------------------------------------------------
	void setLength( const int lengthToSet );

	//-------------------------------------------------------
	//	Function	:	getSegmentByIndex
	//	Purpose		:	Returns a tail segment by the specified index number
	//	Parameters  :	const int& indexOfSegment
	//	Returns		:	SnakeSegment
	//-------------------------------------------------------
	SnakeSegment& getSegmentByIndex( const int indexOfSegment );
};

#endif // End of '#ifndef SNAKETAIL_H'