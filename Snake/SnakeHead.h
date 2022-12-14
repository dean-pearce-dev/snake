#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "Direction.h"
#include "SnakeSegment.h"

class SnakeHead : public SnakeSegment
{
private:
	Direction m_direction;

public:
	SnakeHead();

	//-------------------------------------------------------
	//	Function	:   move
	//	Purpose		:   Controls movement of the SnakeHead object based on a Direction enum
	//					which is changed using input	
	//	Parameters  :   none
	//	Returns		:   void
	//-------------------------------------------------------
	void move();

	//-------------------------------------------------------
	//	Function	:   getDirection
	//	Purpose		:   Returns the current direction the snake head is travelling
	//	Parameters  :   none
	//	Returns		:   Direction
	//-------------------------------------------------------
	Direction getDirection();

	//-------------------------------------------------------
	//	Function	:   setDirection
	//	Purpose		:   Sets the direction for the snake head to travel via parameter
	//	Parameters  :   Direction direction
	//	Returns		:   void
	//-------------------------------------------------------
	void setDirection( Direction direction );
};

#endif // End of '#ifndef SNAKEHEAD_H'